// Given a string, find the first non-repeating character in it and return it 's index. If it doesn' t exist, return -1.

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int firstUniqChar(string s)
{
	unordered_map<char, int> lMap;

	//emplace the map with char to the time its in the s
	for(auto letter : s) {
		if(lMap.count(letter) == 0){
			lMap.emplace(letter, 1);
		} else {
			lMap.at(letter)++;
		}
	}

	for(int i = 0 ; i < s.size(); i++) {
		if (lMap.at(s.at(i)) == 1)
		{
			return i;
		}
		
	}

	return -1;
}

//this solution times out in leetcode
// int firstUniqChar(string s)
// {
// 	unordered_multiset<char> letterSet(s.begin(), s.end());

// 	for (int i = 0; i < s.size(); i++)
// 	{
// 		if (letterSet.count(s.at(i)) == 1)
// 		{
// 			return i;
// 		}
// 	}

// 	return -1;
// }

int main(int argc, char const *argv[])
{
	string s = "loveleetcode";

	cout << firstUniqChar(s) << endl;
	return 0;
}
