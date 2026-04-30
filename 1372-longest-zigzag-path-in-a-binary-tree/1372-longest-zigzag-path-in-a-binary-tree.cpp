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
    int maxLen = 0;
    void maxZigZag(TreeNode* node, int direction, int length){
        if(!node){
            return;
        }
        
        maxLen = max(maxLen, length);

        if(direction == 0){
            maxZigZag(node->right, 1, length+1);
            maxZigZag(node->left, 0, 1);
        }else{
            maxZigZag(node->left, 0, length+1);
            maxZigZag(node->right, 1, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        maxZigZag(root, 1, 0);
        maxZigZag(root, 0, 0);

        return maxLen;
    }
};