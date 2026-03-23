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
    stack<TreeNode*> s1, s2;
    TreeNode* getNextLeaf(stack<TreeNode*> &s){
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();

            if(node->left) s.push(node->left);
            if(node->right) s.push(node->right);

            if(!node->left && !node -> right)
                return node;
        }
        return NULL;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        s1.push(root1);
        s2.push(root2);

        while(!s1.empty() && !s2.empty()){
            TreeNode* leaf1 = getNextLeaf(s1);
            TreeNode* leaf2 = getNextLeaf(s2);

            if(!leaf1 || !leaf2 || leaf1->val != leaf2->val)
                return false;
        }
        return s1.empty() && s2.empty();
         
    }
};