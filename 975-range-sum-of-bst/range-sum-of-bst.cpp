class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        std::stack<TreeNode*> stack = std::stack<TreeNode*>();
        stack.push(root);
        
        while(!stack.empty()){
            TreeNode* node = stack.top();
            stack.pop();
            if(node->val >= L && node->val <= R){
                sum+=node->val;
            }
            if(node->left && node->val >= L){
                stack.push(node->left);
            }
            if(node->right && node->val <= R){
                stack.push(node->right);
            }
        }
        return sum;
    }
};