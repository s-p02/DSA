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

// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         if(inorder.size()!=postorder.size()){
//             return NULL;
//         }
        
//         map<int,int> mpp;
//         for(int i=0;i<inorder.size();i++){
//             mpp[inorder[i]]=i;
//         }
        
//         TreeNode* root= build(postorder,0,postorder.size()-1,
//                              inorder,0,inorder.size()-1,
//                              mpp);
        
//         return root;
//     }
    
//     TreeNode* build(vector<int>& postorder, int ps,int pe,
//                    vector<int>& inorder, int is, int ie,
//                    map<int,int> & mpp){
//         if((ps>pe) || (is>ie)) {
//             return NULL;
//         }
//         TreeNode* root= new TreeNode(postorder[pe]);
//         int ele= mpp[postorder[pe]];
//         int n= ele-is;
//         root->left= build(postorder,ps,ps+n-1,
//                          inorder,is,ele-1,mpp);
//         root->right= build(postorder,ps+n,pe,
//                          inorder,ele+1,ie,mpp);
        
//         return root;
//     }
// };


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size())
            return NULL;
        map<int,int> mpp;
        
        for(int i = 0;i<inorder.size();i++)
        {
            mpp[inorder[i]] = i;
        }
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
    }
    TreeNode* build(vector<int> &inorder,int is,int ie,vector<int> &postorder,int ps,int pe,map<int,int>& mpp)
    {
        if(ps>pe || is>ie)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[pe]);
        int inroot = mpp[postorder[pe]];
        int numleft = inroot-is;
        root->left = build(inorder,is,inroot-1,postorder,ps,ps+numleft-1,mpp);
        root->right = build(inorder,inroot+1,ie,postorder,ps+numleft,pe-1,mpp);
        return root;
    }
};


