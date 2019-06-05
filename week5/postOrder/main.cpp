#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// Given an n-ary tree, return the postorder traversal of its nodes' values.

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void postorderHelper(Node* nodePtr, std::vector<int>& results) {
    if (nodePtr == nullptr)
    {
        return;
    }

    //for each child visit  their children
    for (auto childPtr : nodePtr->children) {
        postorderHelper(childPtr, results);
    }

    results.push_back(nodePtr->val);
}

//recursive solution
// vector<int> postorder(Node* root) {
//     std::vector<int> results;

//     postorderHelper(root, results);

//     return results;
// }

vector<int> postorder(Node* root) {

    if (!root)
    {
        return {};
    }

    std::vector<int> results;

    stack<pair<bool,Node*>> visited;
    visited.push(make_pair(false, root));

    while(!visited.empty()) {
        const auto [addedChildren, node] = visited.top();

        if (addedChildren)
        {
            visited.pop();
            results.push_back(node->val);
        } else {
            visited.top().first = true;

            for(auto it = node->children.rbegin(); it < node->children.rend(); it++) {
                visited.push(make_pair(false, *it));
            }
        }
    }

    return results;
}


int main(int argc, char const *argv[])
{
	std::vector<Node*> children(3);

	for(unsigned int i = 2; i < children.size()+2; i++) {
        std::vector<Node*> grandchidren(2, new Node());

		children.at(i-2) = new Node(i, grandchidren);
	}
	Node* head = new Node(1, children);

    std::vector<int> results = postorder(head);

    for(auto num : results) {
        std::cout << num << std::endl;
    }


	return 0;
}