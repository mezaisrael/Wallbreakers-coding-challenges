/*
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Vertex
{
	int val;
	std::vector<int> neighbors;	
};

typedef unordered_map<int, std::vector<int>> umap;

bool isCycle(umap& whiteSet, umap& graySet, umap& blackSet, int current) {
	cout << "current " << current << endl;
	//move current white to grey
	graySet.emplace(current, whiteSet.at(current));
	whiteSet.erase(current);
	//visit all neighbors of current
	for (auto neighbor : graySet.at(current)) {
		//if already explored neighbor do nothing
		if (blackSet.count(neighbor) > 0)
		{
			continue;
		}
		//if gray has its neighbor than it is a cycle
		if (graySet.count(neighbor) > 0)
		{
			return true;
		}
		if (isCycle(whiteSet, graySet, blackSet, neighbor))
		{
			return true;
		}
	}
	//if we made it to the end than no cycle was found
	blackSet.emplace(current, graySet.at(current));
	graySet.erase(current);
	return false;

}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	//map node to an array of its neighbors
	umap whiteSet;
	umap graySet;
	umap blackSet;
	//make an adjecency graph
	for(int i = 0; i < numCourses; i++) {
		whiteSet.emplace(i, std::vector<int>(0));
	}

	for (auto pair : prerequisites) {
		std::vector<int> & neighbors = whiteSet.at(pair.at(1));
		neighbors.push_back(pair.at(0));
	}

	for (auto node : whiteSet) {
		cout << node.first << ": ";
		for (auto n : node.second) {
			cout << n << " "; 
		}
		cout << endl;
	}

	while(!whiteSet.empty()) {
		if (isCycle(whiteSet, graySet, blackSet, whiteSet.begin()->first))
		{
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[])
{
	std::vector<std::vector<int>> courses {{0,1},{1,0}};

	cout << canFinish(2, courses) << endl;

	return 0;
}