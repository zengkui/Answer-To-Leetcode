#include<iostream>
#include<vector>
#include<set>

using namespace std;



class Trie
{
    public:
        Trie *child[26];
        bool finish;
    public:
        Trie()
        {
            for(int i = 0; i < 26; ++i)
            {
                child[i] = NULL;
            }
            finish = false;
        }
        ~Trie()
        {
            for(int i = 0; i < 26; ++i)
            {
                if(child[i])
                {
                    delete child[i];
                }
            }
        }
        void insert(const char *s)
        {
            if(*s == 0)
            {
                finish = true;
                return;
            }
            int idx = *s - 'a';
            if(child[idx] == NULL)
            {
                child[idx] = new Trie();
            }
            child[idx]->insert(s + 1);
        }
        int match(const char *s)
        {
            if(*s == 0)
            {
                if(finish)
                {
                    return 0;
                }
                return -1;
            }
            int idx = *s - 'a';
            if(child[idx] != NULL)
            {
                int len =  child[idx]->match(s + 1);
                if(len != -1)
                {
                    return len + 1;
                }
            }
            if(finish)
            {
                return 0;
            }
            return -1;
        }
};

class Solution {
    private:
        Trie trie;
        vector<string> sen;
    public:
        vector<string> wordBreak(string s, set<string> &dict) {
            set<string> :: iterator itr = dict.begin();
            while(itr != dict.end())
            {
                trie.insert(itr->c_str());
                itr++;
            }
            char buffer[102400];
            const char *p = s.c_str();
            int max_pos = -1;
            int len = 0;
            for(int i = 0;  p[i] !=0; ++i)
            {
                len = trie.match(p + i); 
                if(len != -1 && i + len > max_pos)
                {
                    max_pos = i  + len; 
                }
                if(i >= max_pos)
                {
                    return sen;
                }
            }
            search(s.c_str(), buffer, 0, trie);
            return sen;
        }
        void search(const char *s, char buffer[], int len, const Trie &dict)
        {
            buffer[len] = 0;
            if(*s == 0)
            {
                if(dict.finish)
                {
                    sen.push_back(buffer);
                }
                return;
            }
            int idx = *s - 'a'; 
            if(dict.finish)
            {
                buffer[len] = ' ';
                search(s, buffer, len + 1, trie);
            }
            if(dict.child[idx] != NULL)
            {
                buffer[len] = *s;
                search(s + 1, buffer, len + 1, *(dict.child[idx]));
            }
            return;
        }
};

const char * test = "aaaaaaaaaaaaaaaaaaaaaaaaab";

int main()
{
    Solution slt;
    set<string> dict;
    dict.insert("a");
    dict.insert("aa");
    dict.insert("aaaa");
    dict.insert("aaaaab");
    vector<string> v = slt.wordBreak(test, dict);
    vector<string> :: iterator itr = v.begin(); 
    while(itr != v.end())
    {
        cout << *itr << endl;
        itr++;
    }

}
