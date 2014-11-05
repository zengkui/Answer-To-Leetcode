class Solution 
{
    class path_t
    {
        public :
            string word;
            vector<string> path;
            int step;
        public :
            path_t()
            {
                word = "";
                step = 0;
                path.clear();
            }
    };
    class Trie
    {
        private :
            Trie *child[26];
            bool leaf;
        public :
            Trie()
            {
                for(int i = 0 ; i < 26; ++i )
                {
                    child[i] = NULL; 
                }
                leaf = false;
            }
            ~Trie()
            {
                for(int i = 0 ; i < 26; ++i )
                {
                    if ( child[i] )
                    {
                        delete child[i];
                        child[i] = NULL; 
                    }
                }
            }
        public :
            bool insert( const char *word )
            {
                if ( *word == 0 )
                {
                    leaf = true;
                    return true;
                }
                int idx = *word - 'a';
                if ( NULL == child[idx] )
                {
                    child[idx] = new Trie();
                }
                return child[idx]->insert(word + 1);
            }
            void query(const char *word, vector<string> &words )
            {
                char newword[1024];
                find_similar_words(word, false, newword, 0, words); 
            }
            void find_similar_words( const char *word, const bool &changed, char *s, int len,vector<string> &result)  
            {                
                if (  *word == 0 )  
                {                    
                    if ( leaf && changed )
                    {                        
                        s[len] = 0;
                        result.push_back(s);
                    }
                    return ;
                }       
                int idx = *word - 'a';    
                if ( changed && child[idx] == NULL )
                {
                    return ;
                }
                for( int i = 0 ; i < 26; ++i )    
                {        
                    if( child[i] )     
                    {          
                        s[len] = (i + 'a');         
                        s[len+1] = 0;
                        if( idx == i )      
                        {          
                            child[i]->find_similar_words( word + 1, changed, s, len + 1, result);          
                        }        
                        else if( !changed )      
                        {            
                            child[i]->find_similar_words( word + 1, true, s, len + 1, result);    
                        }        
                    }        
                }         
            }

    };
    private :
    vector< vector<string> >  result;
    int min_step;
    Trie trie;
    public:    
    vector< vector<string> > findLadders(string start, string end, unordered_set<string> &dict) 
    {           
        if ( start == end )
        {
            return result; 
        }
        unordered_set<string> :: iterator sitr;
        vector<string> :: iterator vitr;
        

        dict.insert(start.c_str());
        dict.insert(end.c_str());
        for( sitr = dict.begin(); sitr != dict.end(); ++sitr )
        {
            trie.insert((*sitr).c_str()); 
        }

        map<string, vector<string> > post_node;
        unordered_set<string> candidate[2];
        vector<string> words;


        int now = 0;
        int next = 1;
        candidate[0].insert(start);
        while ( dict.size() > 0 && candidate[now].size() > 0 )
        {
            for(sitr = candidate[now].begin(); sitr != candidate[now].end(); ++sitr )
            {
                dict.erase(*sitr);
            }
            candidate[next].clear();
            for(sitr = candidate[now].begin(); sitr != candidate[now].end(); ++sitr )
            {
                trie.query( sitr->c_str(), words);
                for(vitr = words.begin(); vitr != words.end(); ++vitr )
                {
		            if ( dict.find(*vitr) != dict.end() )
                    {
                        candidate[next].insert(*vitr); 
                        post_node[*sitr].push_back(*vitr);
                    }
                }
                words.clear();
            }
            now = 1 - now;
            next = 1 - next;
        }
        find_path(post_node, words, start, end);
        return result;
    }
    void find_path( map<string, vector<string> > &post_node, vector<string> path, const string &start, const string &end  )
    {
        if ( start == end )
        {
            path.push_back(start);
            result.push_back(path);
            path.pop_back();
            return;
        }
        for( vector<string> :: iterator itr = post_node[start].begin(); itr != post_node[start].end(); ++ itr )
        {
            path.push_back(start);
            find_path(post_node, path, *itr, end);
            path.pop_back();
        }
    }
};
