#include <iostream>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v) : val(v), next(nullptr){}
};


ListNode* oddEvenList(ListNode *head)
{
	if(head == nullptr) {
		return head;
	} else if(head->next == nullptr) {
		return head;
	}

	ListNode* firstEven = head->next;

	ListNode* curr = head;
	ListNode* next = curr->next;

	//keep track if curr is an even or odd node
	bool currIsOdd = true;
	while(next->next != nullptr) {
		curr->next = next->next;
		curr = next;
		next = next->next;
		currIsOdd = !currIsOdd;
	}

	if (currIsOdd)
	{
		curr->next = firstEven;
	} else {
		std::cout << "current ended an even" << std::endl;
		std::cout << curr->val << " " << next->val << std::endl;
		next->next = firstEven;
		//curr is now the tail
		curr->next = nullptr;
	}
	

	return head;
}

void append(ListNode* &head, int val)
{
	if (head == nullptr)
	{
		head = new ListNode(val);
		return;
	}

	ListNode *oldHead = head;
	head = new ListNode(val);
	head->next = oldHead;
}

void displayNode(ListNode *head)
{
	ListNode *curr = head;
	while (curr != nullptr)
	{
		std::cout << curr->val << std::endl;
		curr = curr->next;
	}
}

int main(int argc, char const *argv[])
{
	ListNode* head = new ListNode(1);

	append(head, 2);
	append(head, 3);
	append(head, 4);
	append(head, 5);
	append(head, 6);

	oddEvenList(head);
	
	displayNode(head);

	return 0;
}
