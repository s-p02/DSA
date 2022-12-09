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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int flag=0;
        while(!q.empty()){
            int len= q.size();
            vector<int>row;
            for(int i=0;i<len;i++){
                TreeNode* temp= q.front();
                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                row.push_back(temp->val);
            }
            if(flag==0){
                ans.push_back(row);
                flag=1;
            }
            else{
                reverse(row.begin(),row.end());
                ans.push_back(row);
                flag=0;
            }
        }
        return ans;
    }   
};