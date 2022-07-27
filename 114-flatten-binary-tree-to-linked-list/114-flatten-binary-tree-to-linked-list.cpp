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
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        // while(root != NULL)
        // {
        //     if(root->left != NULL)
        //     {
        //         TreeNode *left = root->left;
        //         TreeNode *current = left;
        //         while(current->right != NULL) current = current->right;
        //         current->right = root->right;
        //         root->left = NULL;
        //         root->right = left;
        //     }
        // }
        TreeNode *tempLeft = root->left;
        TreeNode *tempRight = root->right;
        root->left = NULL;
        
        flatten(tempLeft);
        flatten(tempRight);
        root->right = tempLeft;
        TreeNode *current = root;
        while(current->right != NULL) current = current->right;
        current->right = tempRight;
        
    }
};