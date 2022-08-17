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
private:
    TreeNode* first;
    TreeNode* last;
    TreeNode* prev;
    TreeNode* middle;
private:
    void inorder(TreeNode* root)
    {
        if(root == NULL) return ;
        
        inorder(root->left);
        if(prev != NULL && root->val < prev->val)
        {
            if(first == NULL)//first violation
            {
                first = prev;
                middle = root;
            }
            else                //second violation
            {
                last = root;
            }       
            
            
        }
        
        //mark these node as prev
            prev = root;
            inorder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};