/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {

public:
    // this function finds left or right height of tree while saving maxi of
    // left + right in diameter variable which is diameter of
    // that binary tree
    int height(TreeNode* node, int& diameter) {
        if (node == NULL)
            return 0;

        int left = height(node->left,diameter);
        int right = height(node->right,diameter);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter =0;

        height(root, diameter);
        return diameter;
    }
};