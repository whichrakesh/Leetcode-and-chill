/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function(root) {
    if(root == null) return 0;
    return diameterAndMaxHeightOfBinaryTree(root).diameter - 1;
};

var diameterAndMaxHeightOfBinaryTree = function(root) {
    if(root == null){
        return {
        height: 0, 
        diameter: 0
    };
    }
    let dlh = diameterAndMaxHeightOfBinaryTree(root.left);
    let drh = diameterAndMaxHeightOfBinaryTree(root.right);
    return {
        height: Math.max(dlh.height, drh.height)+1, 
        diameter: Math.max(dlh.diameter, drh.diameter, dlh.height + drh.height + 1)
    };
};