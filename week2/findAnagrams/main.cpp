

/* 
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter. */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>


using namespace std;

// vector<int> findAnagrams(string s, string p)
// {
// 	std::vector<int> positions;
// 	int anagrSize = p.size();

// 	unordered_multiset<char> pSet(p.begin(), p.end());

// 	for(auto sIt = s.begin(); sIt <= s.end()-anagrSize; sIt++) {
// 		unordered_multiset<char> sSet(sIt, (sIt+anagrSize));


// 		bool isAnagram = true;

// 		for(auto c : sSet) {
// 			if(sSet.count(c) != pSet.count(c)) {
// 				isAnagram = false;
// 				break;
// 			}
// 		}
// 		if(isAnagram) {
// 			positions.push_back(sIt-s.begin());
// 		}
// 	}
// 	return positions;	
// }

vector<int> findAnagrams(string s, string p)
{
	std::vector<int> positions;
	int anagrSize = p.size();

	unordered_map<char, int> pCount;

	for(auto c : p) {
		if (pCount.count(c) == 0)
		{
			pCount.emplace(c, 1);
		} else {
			pCount.at(c)++;
		}
	}

	int i =0;
	for (auto sIt = s.begin(); sIt <= s.end() - anagrSize; sIt++, i++)
	{
		unordered_multiset<char> sSet(sIt, (sIt + anagrSize));

		bool isAnagram = true;

		for (auto c : sSet)
		{
			if (pCount.count(c) == 0 || sSet.count(c) != pCount.at(c))
			{
				isAnagram = false;
				break;
			}
		}
		if (isAnagram)
		{
			positions.push_back(i);
		}
	}

	return positions;
}

int main(int argc, char const *argv[])
{
	string s = "cbaebabacd";
	string p = "abc";
	findAnagrams(s,p);
	
	return 0;
}
