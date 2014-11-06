#include<iostream>

using namespace std;

//this proble is called Catalan Number
//see also : http://baike.baidu.com/view/2499752.htm?fr=aladdin 
class Solution {
private:
    int memory[1024];
public:
    Solution()
    {
        for(int i = 0 ; i < 1024; ++i)
        {
            memory[i] = 0;
        }
        memory[0] = 1;
        memory[1] = 1;
    }
public:
    int numTrees(int n) {
        if(n < 1024 && memory[n] > 0)
        {
            return memory[n];
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            ans +=  numTrees(i - 1) * numTrees(n - i); 
        }
        memory[n] = ans;
        return ans;
    }
};
int main()
{
    Solution slt;
        
    for(int i = 0; i <= 20; ++i)
    {
        cout << i << " " << slt.numTrees(i) << endl;
    }
}
