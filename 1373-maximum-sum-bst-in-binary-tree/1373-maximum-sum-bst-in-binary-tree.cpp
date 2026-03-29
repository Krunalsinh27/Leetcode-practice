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
    int maxSum = 0;
    struct Info {
        bool isBST;
        int sum;
        int maxVal;
        int minVal;
    };

    Info solve(TreeNode* root){
        if(!root)
            return {true, 0, INT_MIN, INT_MAX};

        Info left = solve(root->left);
        Info right = solve(root->right);

        Info curr;
        if(left.isBST && right.isBST && (root->val > left.maxVal && root->val < right.minVal)){
            curr.isBST = true;
            curr.sum = left.sum + right.sum + root->val;
            curr.maxVal = max(root->val, right.maxVal);
            curr.minVal = min(root->val, left.minVal);

            maxSum = max(maxSum, curr.sum);
        }else{
            curr.isBST = false;
            curr.sum = 0;
            curr.maxVal = INT_MAX;
            curr.minVal = INT_MIN;
        }
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};