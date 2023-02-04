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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int> mpp;
        
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        
        TreeNode* root= build(preorder, 0, preorder.size()-1,
                              inorder,0, inorder.size()-1,
                              mpp);
        return root;
    }
    
    TreeNode* build(vector<int> preorder,int preStart, int preEnd,
                   vector<int>inorder,int inStart, int inEnd,
                   map<int,int>&mpp){
        if(preStart>preEnd || inStart>inEnd ){
            return NULL;
        }
        
        TreeNode* root= new TreeNode(preorder[preStart]);
        
        int ele= mpp[root->val];
        
        int n=ele-inStart;
        
        root->left= build(preorder, preStart+1, preStart+n,
                         inorder, inStart, ele-1,
                         mpp);
        root->right= build(preorder, preStart+n+1, preEnd,
                         inorder, ele+1,inEnd,
                         mpp);
        return root;
    }
};