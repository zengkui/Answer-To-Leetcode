#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<int> word_count;
        vector<string> result;
        vector<string> part;
        int n = 0;
        int length = 0;
        vector<string> :: iterator itr = words.begin();
        while(itr != words.end())
        {
            if((*itr).length() + length + n <= L)
            {
                part.push_back(*itr);
                n++;
                length = length + (*itr).length();
                itr++;
            }
            else
            {
                result.push_back(format(part, length, L));
                part.clear();
                n = 0;
                length = 0;
            }
        }
        if(n)
        {
            string mystr = format(part, length, length + part.size() - 1);
            for(int i = mystr.length(); i < L; ++i)
            {
                mystr += " ";
            }
            result.push_back(mystr);
        }
        return result; 
    }
    //format a line just as the description in the problem
    string format(vector<string> &words, int length, int L)
    {
        string txt = words[0];
        int n = words.size();
        if(n == 1)
        {
            while(L - length > 0)
            {
                txt += " ";
                length++;
            }
            return txt;
        }
        int even_space = (L - length) / (n - 1);
        int other_space = L - length - even_space * (n - 1); 
        for(int i = 1; i < n; ++i)
        {
            for(int k = 0; k < even_space; ++k)
            {
                txt += " ";
            }
            if(other_space)
            {
                txt += " ";
                other_space--;
            }
            txt += words[i];
        }
        return txt;
    }
};
//const char *test_case[] =   {"This", "is", "an", "example", "of", "text", "justification.", "what", "is", "your", "name", NULL}; 
//const char *test_case[] =   {"This", "this", "this", "this", NULL}; 
const char *test_case[] =   {"a", NULL}; 
int main()
{
    Solution slt;

    vector<string> words;
    for(int i = 0; test_case[i]; ++i)
    {
       words.push_back(test_case[i]);
    }
    vector<string> result = slt.fullJustify(words, 9);
    vector<string> :: iterator itr = result.begin();
    while(itr != result.end())
    {
        printf("#%s#\n", (*itr).c_str());
        itr++;
    }

}
