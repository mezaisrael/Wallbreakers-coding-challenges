/* You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

	The letters in J are guaranteed distinct,
	and all characters in J and S are letters.Letters are case sensitive, so "a" is considered a different type of stone from "A"
 */

#include <iostream>
#include <unordered_set>

using namespace std;

int numJewelsInStones(string J, string S)
{
	unordered_set<char> jewels;

	// put all the jewels in a hash set
	for(auto c : J) {
		jewels.emplace(c);
	}

	int jewelCount = 0;
	for (auto c : S) {
		if (jewels.count(c) > 0) {
			jewelCount++;
		}
		
	}

	return jewelCount;
}

int main(int argc, char const *argv[])
{
	string jewels = "z";
	string stones = "ZZ";

	cout << numJewelsInStones(jewels, stones) << endl;

	return 0;
}
