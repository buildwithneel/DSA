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
        int idx=0;
        return build(preorder,inorder,0,inorder.size()-1,idx);
    
    }
        TreeNode* build(vector<int>& preorder,vector<int>& inorder,int l,int r,int& idx){
        if(l>r) return NULL;
        TreeNode* root=new TreeNode(preorder[idx++]);
        int i=l;
        while(inorder[i]!=root->val) i++;
        root->left=build(preorder,inorder,l,i-1,idx);
        root->right=build(preorder,inorder,i+1,r,idx);
        return root;
    }
};