/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        int maxDepth(TreeNode *root) {
            if(NULL == root)
            {
                return 0;
            }
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    private:
        int max(const int &a, const int &b)
        {
            return a > b ? a : b;
        }
};
