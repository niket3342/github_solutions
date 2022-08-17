// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// class BSTIterator
// {
//     stack<TreeNode*> mystack;
//     bool reverse = true;
//     public:
//         BSTIterator(TreeNode* root, bool isreverse)
//         {
//             reverse = isreverse;
//             pushAll(root);
//         }
    
//     //return whether we have next smallest number
//     bool hasnext()
//     {
//         return !mystack.empty();
//     }
    
//     //return the next smallest number
//     int next()
//     {
//         TreeNode* tempnode = mystack.top();
//         mystack.pop();
//         if(!reverse) pushAll(tempnode->right);
//         else pushAll(tempnode->left);
//         return tempnode->val;
//     }
    
// private:
//     void pushAll(TreeNode* node)
//     {
//         for(;node!=NULL;)
//         {
//             mystack.push(node);
//             if(reverse == true)
//             {
//                 node = node->right;
//             }
//             else
//             {
//                 node = node->left;
//             }
//         }
//     }
// };






// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         if(!root) return false;
//         BSTIterator l(root, false);
//         BSTIterator r(root, true);
        
//         int i = l.next();
//         int j = r.next();
        
//         while(i<j)
//         {
//             if(i+j == k) return true;
//             else if(i+k<k) i= l.next();
//             else j= r.next();
//         }
        
//         return false;
        
        
//     }
// };
class BSTIterator {
    stack<TreeNode *> myStack;
    bool reverse = true; 
public:
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse = isReverse; 
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for(;node != NULL; ) {
             myStack.push(node);
             if(reverse == true) {
                 node = node->right; 
             } else {
                 node = node->left; 
             }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false; 
        BSTIterator l(root, false); 
        BSTIterator r(root, true); 
        
        int i = l.next(); 
        int j = r.next(); 
        while(i<j) {
            if(i + j == k) return true; 
            else if(i + j < k) i = l.next(); 
            else j = r.next(); 
        }
        return false; 
    }
};