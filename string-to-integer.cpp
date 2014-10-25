#include<iostream>

using namespace std;


class Solution {
public:
    int atoi(const char *str) {
        const int s0 = 1000;
        const int s1 = 1001;
        const int s2 = 1002;
        const int s3 = 1003;
        const int s4 = 1004;

        long long ans = 0;
        int sign = 1;
        int s = s0;
        while(*str)
        {
            switch(s)
            {
                case s0 :
                    if(*str == '+')
                    {
                        s = s1;
                        sign = 1;
                    }
                    else if(*str == '-')
                    {
                        s = s1;
                        sign = -1;
                    }
                    else if(*str >= '0'  && *str <='9')
                    {
                        s = s2;
                        sign = 1;
                        continue;
                    }
                    else if( *str != ' ') 
                    {
                        s = s4;
                    }
                    break;
                case s1:
                    if(*str >= '0' && *str <= '9')
                    {
                        s = s2;
                        continue; 
                    }
                    else
                    {
                        return ans * sign;
                    }
                    break;
                case s2:
                    if(*str >= '0' && *str <= '9')
                    {
                        ans = ans * 10 + *str - '0';
                        if( ans * sign > INT_MAX)
                        {
                            return INT_MAX;
                        }
                        if(ans * sign < INT_MIN)
                        {
                            return INT_MIN;
                        }
                    }
                    else if(*str == ' ')
                    {
                        s = s3;
                    }
                    else
                    {
                        return ans * sign;
                    }
                    break;
                case s3:
                    if(*str != ' ')
                    {
                        return ans * sign;
                    }
                    break;
                case s4:
                    return 0;
            }
            str++;
        }
        if(s == s4)
        {
            return 0;
        }
        return ans * sign;
    }
};


const char *test_case[] = {
    "0",
    "",
    "+0",
    "-0",
    "ab",
    "1ab",
    "ab1",
    "-11.0",
    "123456",
    "  +123456",
    "-123456",
    "  -123456 ",
    "  -123456   ",
    "23982739827392943223232424",
    "  -0012a42 ",
    "-2147483648",
    NULL
};
int main()
{
    Solution slt;

    int idx = 0;
    int ans;
    while(test_case[idx])
    {
        printf("[%s] => [%d]\n", test_case[idx], slt.atoi(test_case[idx]));
        idx++;
    }
}
