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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int, map<int, multiset<int>>> nodes;//multiset bcoz tree can have same values (vert, lev, set) 
        queue<pair<TreeNode*, pair<int, int>>> todo;    //(node, vert,lev)
        todo.push({root, {0,0}});//pushing the root onto queue
        
        while(!todo.empty())
        {
            auto p = todo.front();// here p points to node at the front
            todo.pop();   //popping the frontmost from queue (FIFO)
            TreeNode* temp = p.first;
            
            int x= p.second.first, y=p.second.second; // x= vertical, y= level
            nodes[x][y].insert(temp->val); // inserting nodes value onto map
            
            if(temp->left)
            {
                todo.push({temp->left,{x-1,y+1}});//when going to left vectical decreases by 1 and 
                                                 // level increases by 1
            }
            if(temp->right)
            {
                todo.push({temp->right,{x+1,y+1}});//when going to right vectical increases by 1 and 
                                                 // level increases by 
            }
        }
        
        vector<vector<int>> ans;
        for(auto p:nodes)  // p points to nodes map
        {
            vector<int> col;
            for(auto q:p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};