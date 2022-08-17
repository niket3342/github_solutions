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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ptr = 0;//ptr points to element in the tree
        return build(preorder,ptr,INT_MAX);
        
    }
    TreeNode* build(vector<int>& preorder, int& ptr, int bound)//ptr has been take as reference bcoz it will keep changing
    {
        if(ptr == preorder.size() || preorder[ptr] > bound) return NULL;
        
        TreeNode* node = new TreeNode(preorder[ptr++]);
        node->left = build(preorder, ptr, node->val);
        node->right = build(preorder, ptr, bound);
        return node;
    }
};