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

    pair<int, int> solve(TreeNode* root){
        if(root == NULL)
            return {0,-1};

        auto left = solve(root -> left);
        auto right = solve(root -> right);

        int leftDia = left.first;
        int rightDia = right.first;

        int leftHeight = left.second;
        int rightHeight = right.second;

        int currDia = leftHeight + rightHeight + 2;
        
        int finalDia = max({leftDia, rightDia, currDia});
        int finalHeight = max(leftHeight, rightHeight) + 1;

        return {finalDia, finalHeight};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
    }
};