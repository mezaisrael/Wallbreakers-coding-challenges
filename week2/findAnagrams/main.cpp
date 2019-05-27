

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

// 	unordered_map<char, int> pCount;

// 	for(auto c : p) {
// 		if (pCount.count(c) == 0)
// 		{
// 			pCount.emplace(c, 1);
// 		} else {
// 			pCount.at(c)++;
// 		}
// 	}

// 	int i =0;
// 	for (auto sIt = s.begin(); sIt <= s.end() - anagrSize; sIt++, i++)
// 	{
// 		unordered_multiset<char> sSet(sIt, (sIt + anagrSize));

// 		bool isAnagram = true;

// 		for (auto c : sSet)
// 		{
// 			if (pCount.count(c) == 0 || sSet.count(c) != pCount.at(c))
// 			{
// 				isAnagram = false;
// 				break;
// 			}
// 		}
// 		if (isAnagram)
// 		{
// 			positions.push_back(i);
// 		}
// 	}

// 	return positions;
// }

vector<int> findAnagrams(string s, string p)
{
	vector<int> res;
	if (p.length() > s.length())
		return res;

	vector<int> tmp(26, 0), ref(26, 0);
	int p_size = p.size(), s_size = s.size(), i;
	for (i = 0; i < p_size; i++)
	{
		tmp[p[i] - 'a']++;
		ref[s[i] - 'a']++;
	}

	if (tmp == ref)
		res.push_back(0);

	for (i = p_size; i < s_size; i++)
	{
		ref[s[i] - 'a']++;			//Increment the right side
		ref[s[i - p_size] - 'a']--; //Decrement from the left side

		if (tmp == ref)
			res.push_back(i - p_size + 1);
	}

	for (auto x : res)
	{
		std::cout << x << std::endl;
	}

	return res;
}

int main(int argc, char const *argv[])
{
	string s = "aaaa";
	string p = "aa";
	findAnagrams(s,p);
	
	return 0;
}
