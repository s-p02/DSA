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
    void help(TreeNode* node, string str, vector<string> &ans){
        if(node==NULL){
            return;
        }
        if(node->left==NULL && node->right==NULL){
            str+=(to_string(node->val));
            ans.push_back(str);
        }
        
        else{
            str+= (to_string(node->val)+"->");
        }
        help(node->left,str,ans);
        help(node->right,str,ans);
        
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        string curr="";
        help(root,curr,answer);
        return answer;
    }
};