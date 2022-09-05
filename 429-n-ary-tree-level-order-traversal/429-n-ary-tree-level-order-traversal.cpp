/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        dfs(root, 0);
        return ans;        
    }
    void dfs(Node* root, int level)
    {
        if(root == NULL) return ;
        if(level == ans.size())  ans.emplace_back();//need more level-> add new level;
        ans[level].push_back(root->val);
        for(Node* child: root->children )
            dfs(child, level+1);
    }
    
    
};