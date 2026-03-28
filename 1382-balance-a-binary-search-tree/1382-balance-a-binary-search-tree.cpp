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
    void inorder(TreeNode* root, vector<int> &in){
        if(root == NULL) return ;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    TreeNode* inorderToBST(int left, int right, vector<int> in){
        if(left > right)
            return NULL;
        
        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(in[mid]);

        root->left = inorderToBST(left, mid-1, in);
        root->right = inorderToBST(mid+1, right, in);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderVal;
        inorder(root, inorderVal);

        return inorderToBST(0, inorderVal.size()-1, inorderVal);
    }
};