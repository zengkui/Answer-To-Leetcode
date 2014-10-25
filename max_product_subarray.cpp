#include<iostream>

class Solution {
public:
    int maxProduct(int A[], int n) {
        int ans = A[0];
        int maxp = A[0];
        int minp = A[0];
        for(int i = 1; i < n; ++i)
        {
            int a = maxp *  A[i];
            int b = minp *  A[i];
            int c = A[i];
            maxp = max(max(a, b), c);
            minp = min(min(a, b), c);
            ans = max(ans, maxp);
        }
        return ans;
    }
    int max(const int &a, const int &b)
    {
        return a > b ? a : b;
    }
    int min(const int &a, const int &b)
    {
        return a < b ? a : b;
    }
};

int test[] = {-3, 3, 4, -1, 0, 4, 2 ,3};
int main()
{
    Solution slt;
    int ans = slt.maxProduct(test, sizeof(test)/sizeof(int));
    printf("ans = %d\n", ans);
}
