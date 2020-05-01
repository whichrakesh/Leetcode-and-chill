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
    int maxPathSum(TreeNode* root) {
        return maxPathSum2(root).first;
    }
    
    // First: maxSum, maxInc
    pair<int, int> maxPathSum2(TreeNode* root) {
        if(root == NULL){
            return make_pair(INT_MIN/2, INT_MIN/2);
        }
        
        pair<int, int> left = maxPathSum2(root->left);
        pair<int, int> right = maxPathSum2(root->right);
        int pathSum = (left.second > 0 ? left.second : 0)  + (right.second > 0 ? right.second : 0) + root->val;
        return make_pair(max(pathSum, max(left.first, right.first)), max(root->val, max(root->val + left.second, root->val + right.second)));
    }
};