/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_link, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr= q.front();
            q.pop();
            if(curr->left!= NULL){
                parent_link[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right!= NULL){
                parent_link[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_link;
        markparents(root, parent_link, target);
        
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int distance=0;
        
        while(!q.empty()){
            if(distance++==k){
                break;
            }
            int size=q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* curr= q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(parent_link[curr] && !visited[parent_link[curr]]){
                    q.push(parent_link[curr]);
                    visited[parent_link[curr]]=true;
                }
            } 
        }
        
        vector<int> res;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            res.push_back(curr->val);
        }
        
        return res;
    }
};