// https://leetcode.com/problems/count-complete-tree-nodes/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode *l = root, *r = root;
        int hl = 0, hr = 0;
        while (l) {
            ++hl;
            l = l->left;
        }
        while (r) {
            ++hr;
            r = r->right;
        }
        if (hl == hr) return (1<<hl) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};