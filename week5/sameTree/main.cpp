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

	TreeNode(int _val) : val(_val) {

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

	cout << isSameTree(mtree.getRoot(), othertree.getRoot()) << endl;

	return 0;
}