#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;

	TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}

	void printNode() {
		//if this node is null return
		if (left) left->printNode();

		std::cout << val << std::endl;

		if (right) right->printNode();
	}

	void addNode(int val) {
		if (this->val > val)
		{
			std::cout << "going left" << std::endl;
			//go left
			if (left)
			{
				std::cout << "left is not null" << std::endl;
				this->left->addNode(val);
			} else {
				std::cout << "left is null" << std::endl;
				left = new TreeNode(val);
			}
		} else {
			//go right
			std::cout << "going right" << std::endl;
			if(right) {
				this->right->addNode(val);
			} else {
				right = new TreeNode(val);
			}
		}
	}
};
class Tree
{
public:
	Tree(int val) {
		root = new TreeNode(val);
	}

	void addNode(int val) {
		TreeNode* currNode = root;
		
		while(true){
			if (val < currNode->val)
			{
				if (currNode->left)
				{
					currNode = currNode->left;
				} else {
					currNode->left = new TreeNode(val);
					return;
				}
			} else {
				if (currNode->right)
				{
					currNode = currNode->right;
				} else {
					currNode->right = new TreeNode(val);
					return;
				}
			}
		}

	}


	TreeNode* getRoot() {
		return root;
	}

	void display() {

	}

private:
	TreeNode * root;
};

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == nullptr && q == nullptr)
	{
		return true;
	} else if (p == nullptr && q != nullptr)
	{
		return false;
	} else if (q == nullptr && p != nullptr)
	{
		return false;
	}

	if (p->val != q->val)
	{
		return false;
	}

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, char const *argv[])
{
	Tree mtree(5);
	mtree.addNode(2);
	mtree.addNode(8);
	mtree.addNode(6);

	Tree othertree(5);
	othertree.addNode(6);
	othertree.addNode(8);
	othertree.addNode(2);

	TreeNode root(7);
	root.addNode(3);
	root.addNode(9);
	root.addNode(8);

	root.printNode();

	return 0;
}