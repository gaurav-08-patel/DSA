/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans = 0;

    // Helper DFS returns {sum, count} of subtree
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0,0};
        
        auto [lsum, lcount] = dfs(node->left);
        auto [rsum, rcount] = dfs(node->right);
        
        int totalSum = lsum + rsum + node->val;
        int totalCount = lcount + rcount + 1;
        
        if (node->val == totalSum / totalCount) {
            ans++;
        }
        
        return {totalSum, totalCount};
    }
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
