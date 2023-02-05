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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        
        TreeNode* curr= root;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev= curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};


// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
        
//         stack<pair<TreeNode*,int>>s;
//         vector<int> ans;
//         if(root==NULL){
//             return ans;
//         }

//         s.push({root,1});

//         while(!s.empty()){
//             auto temp= s.top();
//             s.pop();
//             if(temp.second==1){
//                 temp.second ++;
//                 s.push(temp);
//                 if(temp.first->left){
//                     s.push({temp.first->left,1});
//                 }
//             }
//             else if(temp.second==2){
//                 ans.push_back(temp.first->val);
//                 temp.second ++;
//                 s.push(temp);
//                 if(temp.first->right){
//                     s.push({temp.first->right,1});
//                 }
//             }
//             else{
//                 continue;
//             }
//         }
//         return ans;
//     }
// };



// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int>& ans){
//         if(root== NULL){
//             return;
//         }
        
//         inorder(root->left,ans);
//         ans.push_back(root->val);
//         inorder(root->right, ans);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         inorder(root,ans);
//         return ans;
//     }
// };