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
     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx=postorder.size()-1;
        return build(inorder,postorder,0,inorder.size()-1,idx);
    
    }
    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int l,int r,int& idx){
        if(l>r) return NULL;
        TreeNode* root=new TreeNode(postorder[idx--]);
        int i=l;
        while(inorder[i]!=root->val) i++;
        root->right=build(inorder,postorder,i+1,r,idx);
        root->left=build(inorder,postorder,l,i-1,idx);
        return root;
    }
};