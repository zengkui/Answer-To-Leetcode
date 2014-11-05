class Solution {
    public:
        int singleNumber(int A[], int n) {
            int sn = 0;
            for(int i = 0; i < n; ++i)
            {
                sn ^= A[i];
            }
            return sn;
        }
};

