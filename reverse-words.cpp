class Solution {
    public:
        bool find_word(string &s, int &idx, string &word )
        {
            while(s[idx] && s[idx] == ' ')
            {
                idx++;
            }
            if(s[idx] == 0)
            {
                return false;
            }
            int len = 0;
            while(s[idx + len] && s[idx + len] != ' ')
            {
                len++;
            }
            word = s.substr(idx, len);
            idx = idx + len;
            return true;
        }
        void dfs(vector<string> &v, string &s, int idx)
        {
            string word;
            if(find_word(s, idx, word))
            {
                dfs(v, s, idx);
                v.push_back(word);
            }
        }
        void reverseWords(string &s) {
            if(s.length() <= 0)
            {
                return ;
            }
            vector<string> v;
            dfs(v, s, 0);
            if(v.size() == 0)
            {
                s = "";
                return ;
            }

           vector<string> :: iterator itr = v.begin(); 
            s = *itr++; 
            while(itr != v.end())
            {
                s += " " + *itr;
                itr++;
            }
            return ;
        }
};
