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
    int countNodes(TreeNode* root) 
    {
        if(root == NULL) return 0;
        
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        
        if(lh == rh) return (1<<lh)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
    
    int findLeftHeight(TreeNode* node)
    {
        int hgt = 0;
        while(node)
        {
            hgt++;
            node = node->left;
        }
        return hgt;
    }
    
    int findRightHeight(TreeNode* node)
    {
        int hgt = 0;
        while(node)
        {
            hgt++;
            node = node->right;
        }
        return hgt;
    }
};