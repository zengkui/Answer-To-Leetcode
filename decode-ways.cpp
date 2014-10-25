#include<iostream>

using namespace std;

class Solution {
    public:
        int numDecodings(string s) {
            if(s.length() < 1)
            {
                return 0;
            }
            int c = 0;
            int a = 1;
            int b = 1;
            if(s[0] >= '1' && s[0] <= '9')
            {
                a = 1; 
                b = 1;
                c = 1;
            }
            else
            {
                a = 0;
                b = 0;
                c = 0;
            }
            for(int i = 1 ; s[i] != 0; ++i)
            {
                int one = to_int('0', s[i]);
                int two = 0;
                if(s[i - 1] != '0')
                {
                    two = to_int(s[i - 1], s[i]);
                }
                c = 0;
                if(one > 0)
                {
                    c = c + b; 
                }
                if( two >= 1 && two <= 26)
                {
                    c = c + a;
                }
                a = b;
                b = c;
            }
            return c;
        }
        int to_int(char a, char b)
        {
            return  (a - '0') * 10  + b - '0'; 
        }
};

char *test_case[] = { "12",
                      "32", 
                       "0",
                       "1",
                       "101",
                      "11111",  
                      "", 
                      "28",
                      "26801",
                      "261001",
                      "268000012121212",
                      NULL}; 
int main()
{
    Solution slt;
    for(int i = 0 ; test_case[i]; ++i)
    {
        printf("%s => %d\n", test_case[i], slt.numDecodings(test_case[i]));
    }
    return 0;
}
