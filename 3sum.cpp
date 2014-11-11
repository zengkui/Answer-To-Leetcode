#include<string>
#include<set>
#include<vector>

using namespace std;

typedef vector<int> VINT;
typedef vector<int> :: iterator ITR;

class Solution {
    private:
        set<string> uniq;
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            vector<VINT > ans;
            char buffer[1024];
            int left;
            int right;
            int sum;
            set<string> uniq;

            sort(num.begin(), num.end()); 
            for(int i = 0; i < num.size() && num[i] <= 0; ++i)
            {
                if(i > 0 && num[i] == num[i - 1])
                {
                    continue;
                }
                left = i + 1;
                right = num.size() - 1;
                sum = -1;
                while(left < right)
                {
                    sum = num[i] + num[left] + num[right]; 
                    if(sum > 0)
                    {
                        right--; 
                    }
                    else if(sum < 0)
                    {
                        left++;
                    }
                    else
                    {
                        VINT t;
                        t.push_back(num[i]);
                        t.push_back(num[left]);
                        t.push_back(num[right]);
                        ans.push_back(t);
                        int a = num[left++];
                        while(left < right && num[left] == a)
                        {
                            left++;
                        }
                        a = num[right--];
                        while(left < right && num[right] == a)
                        {
                            right--;
                        }
                    }
                }
            }
            return ans;
        }

};
const int case_test[] = {4,-10,-11,-12,-8,-12,-14,-11,-6,2,-4,2,3,12,-3,-12,-14,-12,-8,-9,-6,-3,10,2,14,10,7,-7,-9,0,-9,10,-2,-5,14,5,-9,7,9,0,-14,12,10,4,9,-8,8,11,-5,-15,-13,-3,-11,4,14,11,-1,-2,-11,5,14,-4,-8,-3,6,-9,9,12,6,3,-10,7,0,-15,-3,-13,-8,12,13,-5,12,-15,7,8,-4,-2,4,2,3,9,-8,2,-10,-1,6,3,-2,0,-7,11,-12,-2,3,-4,-2,7,-2,-3,4,-12,-1,1,10,13,-5,-9,-12,6,8,7,0,7,-6,5,13,8,-14,-12};

int main()
{
    vector<int> num;
    int size = sizeof(case_test) / sizeof(int);

    for(int i = 0 ; i < size; ++i)
    {
        num.push_back(case_test[i]);
    }
    Solution slt;
    vector<VINT > ans = slt.threeSum(num);
    for(vector<VINT > :: iterator number = ans.begin(); number != ans.end(); ++number)
    {
        printf("%d, %d, %d\n", (*number)[0],(*number)[1], (*number)[2]);
    }
    return 0;
}
