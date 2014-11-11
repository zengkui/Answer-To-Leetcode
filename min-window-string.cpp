#include<iostream>
#include<string>

using namespace std;
class Solution {
    public:
        string minWindow(string S, string T) 
        {
            int min_left = -1;
            int min_right = 10000000;
            int target[128];
            int hash[128];
            int uniq = 0;
            for(int i = 0; i < 128; ++i)
            {
                target[i] = 0;
                hash[i] = 0;
            }
            for(int i = 0; T[i] != 0; ++i)
            {
                uniq++;
                target[T[i]]++;
            }
            int left = 0;
            int right = 0;
            int now = 0;
            int idx;
            while(S[right] != 0)
            {
                while( now != uniq && S[right] != 0)
                {
                    idx = S[right];
                    if(target[idx] > 0)
                    {
                        if(hash[idx] < target[idx])
                        {
                            now++;
                        }
                        hash[idx]++;
                    }
                    right++;
                }
                while(now == uniq && left < right)
                {
                    if(right - left < min_right - min_left)
                    {
                        min_right = right;
                        min_left = left;
                    }
                    idx = S[left];
                    if(target[idx] > 0)
                    {
                        hash[idx]--;
                        if(hash[idx] < target[idx])
                        {
                            now--;
                        }
                    }
                    left++;
                }
            }
            if(min_left == -1)
            {
                return "";
            }
            return S.substr(min_left, min_right - min_left);
        }
};

int main()
{
    Solution slt;

    cout << slt.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << slt.minWindow("ADOBECODEBANC", "AB") << endl;
    cout << slt.minWindow("A", "B") << endl;
    cout << slt.minWindow("A", "AA") << endl;
    cout << slt.minWindow("AA", "AA") << endl;
    cout << slt.minWindow("AA", "A") << endl;

}

