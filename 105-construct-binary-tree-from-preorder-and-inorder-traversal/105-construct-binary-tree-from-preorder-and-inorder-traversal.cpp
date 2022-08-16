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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int rootIdx=0;
        return build(preorder,inorder,rootIdx,0,preorder.size()-1);
        
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right)
    {
        // int left = 0;
        // int right = preorder.size()-1;
        if(left>right) return NULL;
        int pivot = left;
        while(preorder[rootIdx] != inorder[pivot]) pivot++;
        
        rootIdx++;
        
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        
        newNode->left = build(preorder, inorder, rootIdx, left, pivot-1);
        newNode->right = build(preorder, inorder, rootIdx, pivot+1, right);
        return newNode;
        
    }
};