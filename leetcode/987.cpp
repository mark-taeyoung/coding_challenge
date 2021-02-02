/**
 * #987 Vertical Order Traversal of a Binary Tree
 * 
 * 
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> tb;
        helper(root, 0, 0, tb);
        
        vector<vector<int>> res;
        
        for (auto& col : tb) {
            vector<int> curr;
            sort(col.second.begin(), col.second.end());
            for (const auto& x : col.second) {
                curr.push_back(x % 10000);
            }
            res.push_back(curr);
        }
        return res;
        
    }

    void helper(TreeNode* root, int row, int col, map<int, vector<int>>& tb) {
        if (root == nullptr) {
            return;
        }
        
        helper(root->left, row + 1, col - 1, tb);
        tb[col].push_back(root->val + row * 10000);
        helper(root->right, row + 1, col + 1, tb);
        
    }
};