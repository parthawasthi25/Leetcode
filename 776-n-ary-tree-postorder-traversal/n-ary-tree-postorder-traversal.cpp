class Solution {
public:
    vector<int> ans;
    void _postorder(Node* node){
        if(node==NULL) return;
        
        for(Node* child : node->children){
            _postorder(child);
        }
        
        ans.push_back(node->val);
    }
    vector<int> postorder(Node* root) {
        _postorder(root);
        return ans;
    }
};