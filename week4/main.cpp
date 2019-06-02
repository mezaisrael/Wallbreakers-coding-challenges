#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr) {}
    
};

ListNode *reverseListHelper(ListNode *pre, ListNode *curr)
{
    ListNode *newHead;
    if (curr->next != nullptr)
    {
        newHead = reverseListHelper(curr, curr->next);
    }

    curr->next = pre;
    return newHead;
}

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
    {
        return head;
    }
    

    return reverseListHelper(head, head->next);
}

void append(ListNode* head, int val) {
    if(head == nullptr) {
        head = new ListNode(val);
        return;
    }

    ListNode *oldHead = head;
    head = new ListNode(val);
    head->next = oldHead;
}

void displayNode (ListNode* head) {
    ListNode *curr = head;
    while (head != nullptr)
    {
        std::cout << curr->val << std::endl;   
    }
    
}


int main(int argc, const char** argv) {
    ListNode* head = new ListNode(3);
    append(head,2);
    append(head,1);
    
    displayNode(head);
    return 0;
}