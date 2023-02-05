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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr= root;
        while(curr!=NULL){
            if(curr->left==NULL){
                preorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev= curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    preorder.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return preorder;
    }
};



// // Iterative
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         if(root==NULL){
//             return ans;
//         }
//         stack <TreeNode*>s;
//         s.push(root);   
//         while(!s.empty()){
//             TreeNode* temp= s.top();
//             s.pop();
//             ans.push_back(temp->val);
//             if(temp->right) s.push(temp->right);
//             if(temp->left) s.push(temp->left);
//         }
//         return ans;
//     }
// };



// Recursive


//class Solution {
// public:
//     void pre(TreeNode* root, vector<int>& ans){
//         if(root==NULL){
//             return;
//         }
//         ans.push_back(root->val);
//         pre(root->left,ans);
//         pre(root->right,ans);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         pre(root,ans);
//         return ans;
//     }
// };