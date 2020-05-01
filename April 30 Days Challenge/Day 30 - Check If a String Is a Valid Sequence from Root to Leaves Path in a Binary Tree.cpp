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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return isValidSequence(root, arr, 0);
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr, int pos) {
        if(root == NULL || pos >= arr.size()){
            return false;
        }
        if(pos == arr.size()-1 && arr[pos] == root->val && root->left == NULL && root->right == NULL){
            return true;
        }
        if(arr[pos] == root->val){
            return isValidSequence(root->left, arr, pos+1)
                || isValidSequence(root->right, arr, pos+1);
        }
        return false;
    }
};