/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} preorder
 * @return {TreeNode}
 */
var bstFromPreorder = function(preorder) {
    if(preorder.length == 0){
        return null;
    }
    let node  = new TreeNode(preorder[0]);
    node.left = bstFromPreorder(preorder.filter(r => r < preorder[0]));
    node.right = bstFromPreorder(preorder.filter(r => r > preorder[0]));
    return node;
};