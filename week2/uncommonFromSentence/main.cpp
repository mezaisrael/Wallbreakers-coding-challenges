
/* We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words. 

You may return the list in any order.
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> uncommonFromSentences(string A, string B)
{
	std::vector<string> unique;
	//map word to the number of occurences
	unordered_map<string, int> wordCount;

	string word;
	for(auto c : A) {
		if (c == ' ')
		{
			if (wordCount.count(word) == 0)
			{
				wordCount.emplace(word, 1);
			}
			else
			{
				wordCount.at(word)++;
			}
			word = "";
		} else {
			word += c;
		}
	}

	if (wordCount.count(word) == 0)
	{
		wordCount.emplace(word, 1);
	}
	else
	{
		wordCount.at(word)++;
	}

	word = "";
	for (auto c : B)
	{
		if (c == ' ')
		{
			if (wordCount.count(word) == 0)
			{
				wordCount.emplace(word, 1);
			}
			else
			{
				wordCount.at(word)++;
			}
			word = "";
		}
		else
		{
			word += c;
		}
	}
	if (wordCount.count(word) == 0)
	{
		wordCount.emplace(word, 1);
	}
	else
	{
		wordCount.at(word)++;
	}

	//add to unique only the words that appeared once
	for(auto word : wordCount) {
		if (word.second == 1)
		{
			unique.push_back(word.first);			
		}
		
	}

	for(auto word : unique) {
		std::cout << word << '\n';
	}

	return unique;
}

int main(int argc, char const *argv[])
{
	string a = "apple apple";
	string b = "sour";


	uncommonFromSentences(a, b);

	return 0;
}
