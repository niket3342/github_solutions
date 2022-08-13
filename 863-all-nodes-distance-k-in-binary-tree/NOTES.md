}
}
}
vector<int> result;
while(!queue.empty()) {
TreeNode* current = queue.front(); queue.pop();
result.push_back(current->val);
}
return result;
void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target) {
queue<TreeNode*> queue;
queue.push(root);
while(!queue.empty()) {
TreeNode* current = queue.front();
queue.pop();
if(current->left) {
parent_track[current->left] = current;
queue.push(current->left);
}
if(current->right) {
parent_track[current->right] = current;
queue.push(current->right);
}
}
}