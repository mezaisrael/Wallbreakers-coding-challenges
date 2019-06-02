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
// var reverseList = function (head) {
//     if (!head) {
//         return head;
//     }
    
//     let pre = null;
//     let curr = head;
//     while (curr) {
//         let next = curr.next;
//         curr.next = pre;
//         pre = curr;
//         curr = next;
//     }

//     return pre;
// };

var reverseList = function (head) {
    if (!head) {
        return head;
    }

    next = head.next;
    curr = head;
    head.next = null;
    return reverseListHelper(curr, next);
};

var reverseListHelper = function (pre, curr) {
    let head = curr;

    if(!curr) {
        return pre;
    }
    //keep going to the end, which will be the new head
    if(curr.next){
        head = reverseList(curr, curr.next);
    }
    curr.next = pre;
    return head;
}

//node contructor function
function ListNode(val) {
    this.val = val;
    this.next = null;

}

ListNode.prototype.displayNode = function () {
    let curr = this;
    while(curr) {
        console.log(curr.val)
        curr = curr.next;
    }
}

ListNode.prototype.append = function (val) {
    let newNode = new ListNode(val);
    newNode.next = this;
    return newNode;
}

let head = new ListNode(1);

// head = head.append(2);
// head = head.append(3);

head = reverseList(head);
console.log(head);
