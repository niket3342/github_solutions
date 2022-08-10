if(nums.size() == 0) return NULL;
return createTree(nums, 0, nums.size()-1);
}
TreeNode* createTree(vector<int>&nums, int start, int end){
if(start>end) return NULL;
int mid = (start+end)/2;
TreeNode* node = new TreeNode(nums[mid]);
node->left = createTree(nums,start, mid-1);
node->right = createTree(nums, mid+1, end);
return node;