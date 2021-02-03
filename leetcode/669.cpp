/**
 * 669. Trim a Binary Search Tree
 */
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
    
    TreeNode* helper(TreeNode* root, const int& low, const int& high) {
        if (root == nullptr) {
            return nullptr;
        }
        
        if (root->val < low) {
            TreeNode* right = root->right;
            delete(root);
            return helper(right, low, high);
        }
    
        if (root->val > high) {
            TreeNode* left = root->left;
            delete(root);
            return helper(left, low, high);
        }
    
        root->left = helper(root->left, low, high);
        root->right = helper(root->right, low, high);
    
        return root;
    
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {

        return helper(root, low, high);
    }
};