#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x)
        {
            ans = ans * 10 + x % 10;
            x = x / 10;
        }
        return ans;
    }
};
int main()
{
    Solution slt;

    cout << slt.reverse(1) << endl;
    cout << slt.reverse(12) << endl;
    cout << slt.reverse(123) << endl;
    cout << slt.reverse(1234) << endl;
}

