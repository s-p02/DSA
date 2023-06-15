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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int maxi=INT_MIN;
        int level=0;
        int curr=0;
        while(!q.empty()){
            curr++;
            int n= q.size();
            int sum=0;
            for(int i=0;i<n;i++){
                auto node= q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);
                sum+=node->val;
            }
            if(sum>maxi){
                maxi= sum;
                level=curr;
            }  
        }
        return level;
        
    }
};