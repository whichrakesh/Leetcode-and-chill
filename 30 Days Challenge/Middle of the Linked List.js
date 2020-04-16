/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var middleNode = function(head) {
    let p1 = head, p2 = head;
    let i = 0;
    while(p2.next != null){
        p2 = p2.next;
        if(i%2 == 0){
            p1 = p1.next;
        }
        i++;
    }
    return p1;
};