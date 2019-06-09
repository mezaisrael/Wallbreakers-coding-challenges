/*jshint esversion: 6 */

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 
/***/
function TreeNode(val) {
	this.val = val;
	this.left = this.right = null;
}

/*
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
var leafSimilar = function(root1, root2) {
	let leaves1 = [];
	let leaves2 = [];

	getLeaves(root1, leaves1);
	getLeaves(root2, leaves2);

	//check if the array sequence is the same
	for (var i = 0; i < leaves1.length; i++) {
		if (leaves1[i].val !== leaves2[i].val) {
			return false;
		}
	}

	return true;
};

function getLeaves(node, leaves) {

	if (isLeaf(node)) {
		leaves.push(node);
		return;
	}

	if (node.left) {
		getLeaves(node.left, leaves);

	}

	if (node.right) {
		getLeaves(node.right, leaves);
	}
}

function isLeaf(node) {
	if (!node.left && !node.right) {
		return true;
	} else {
		return false;
	}
}

function addNode (node, val) {
	// console.log("val ", node.val);
	if(!node) {
		node = new TreeNode(val);
		return;
	}
		
	if (val < node.val) {
		//go left if there is a left child
		if (node.left) {
			addNode(node.left, val);
		} else {
			node.left = new TreeNode(val); 
		}

	} else if (val > node.val) {
		//go right if there is a right node
		if (node.right) {
			addNode(node.right, val);
		} else {
			node.right = new TreeNode(val);
		}

	}
}

function printNode (node) {
	if(node.left){
		printNode(node.left);
	}

	console.log(node.val);

	if (node.right) {
		printNode(node.right);
	}
}
let root = new TreeNode(5);
addNode(root, 2);
addNode(root, 8);
addNode(root, 6);

let root2 = new TreeNode(5);
addNode(root2, 9);
addNode(root2, 2);
addNode(root2, 6);
addNode(root2, 1);

console.log(leafSimilar(root,root2));