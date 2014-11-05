#include<iostream>
#include<cstring>
using namespace std;


class Solution {
    public:
        bool isNumber(const char *s) {
            bool ans = false;
            int len = strlen(s);
            char *kstr = new char[len + 1];
            strncpy(kstr, s, len);
            kstr[len] = 0;
            
            char *nstr = trim(kstr);
            if( is_exp(nstr))
            {
                ans = true;
            }
            if(is_integer(nstr))
            {
                ans = true;
            }
            if(is_float(nstr))
            {
                ans = true;
            }
            delete kstr;
            return ans;
        }
        char *trim( char *s)
        {
            char *p  = s + strlen(s) - 1;
            while(*s == ' ')
            {
                *s++ = 0;
            }
            while(*p == ' ' && p >= s)
            {
                *p-- = 0;
            }
            return s;
        }
        bool is_integer( char *s)
        {
            if(*s == '+' or *s == '-')
            {
                s++; 
            }
            return is_unsign_int(s);
        }
        bool is_float( char *s)
        {
            if(*s == '+' or *s == '-')
            {
                s++; 
            }
            char *p = strchr(s, '.');
            if(p)
            {
                if(strlen(s) == 1)
                {
                    return false;
                }
                *p = 0;
                if((strlen(s) == 0 or is_unsign_int(s)) and (is_unsign_int(p + 1) or strlen(p+1)<=0))
                {
                    *p = '.';
                    return true;
                }
                *p = '.';
            }
            return false;
        }

        bool is_exp(char *s)
        {
            if(*s == '+' or *s == '-')
            {
                s++; 
            }
            char *p = strchr(s, 'e');
            if(p)
            {
                *p=0;
                if(strlen(s) <= 0 or strlen(p + 1) <= 0)
                {
                    *p = 'e';
                    return false;
                }
                if((is_integer(s) or is_float(s)) and is_integer(p+1))
                {
                    *p = 'e';
                    return true;
                }
                *p = 'e';
            }
            return false;
        
        }
        bool is_unsign_int(const char *s)
        {
            if(*s == 0)
            {
                return false;
            }
            const char *p = s;
            while(*s)
            {
                if(*s < '0' or *s > '9')
                {
                    return false;
                }
                s++;
            }
            return true;
        }
};

const char *case_true[] = { "0", 
                            "+0",
                            " +0 ",
                            "0.0",
                            "-0",
                            "0.1", 
                            "+0.1", 
                            "-0.1", 
                            "2e10", 
                            "+2e10", 
                            "+2e-10", 
                            "+2e+10", 
                            "-2e10", 
                            "-2e-10", 
                            "-2e+10", 
                             ".1", 
                            ".1e+10", 
                            "+.1e+10", 
                            "-.1e+10", 
                             "1.", 
                            NULL
};
const char *case_false[] = { "abc", 
                             "1 a", 
                             ".",
                             "e",
                             "+",
                             "-",
                            "+.1e.1", 
                            "+.1e+.1", 
                            "0e", 
                            "0e.", 
                             NULL
};
int main()
{
    Solution slt;
    int i = 0;
    int error = 0;
    while(case_true[i])
    {
        if(!slt.isNumber(case_true[i]))
        {
            printf("ERROR: [%s]\n", case_true[i]); 
            error++;
        }
        i++;
    }
    i = 0;
    while(case_false[i])
    {
        printf("\nCASE : [%s]\n", case_false[i]);
        if(slt.isNumber(case_false[i]))
        {
            printf("ERROR: [%s]\n", case_false[i]); 
            error++;
        }
        i++;
    }
    if(error)
    {
        printf("find %d cases error\n", error);
    }
    else
    {
        printf("all test pass\n");
    }
}

