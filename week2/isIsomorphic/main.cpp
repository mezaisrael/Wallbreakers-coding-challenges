/* Given two strings s and t, determine if they are isomorphic.
 Two strings are isomorphic if the characters in s can be replaced to get t.
 All occurrences of a character must be replaced with another character while preserving the order of characters.No two characters may map to the same character but a character may map to itself. */

#include <iostream>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t)
{
	if(s.size() != t.size()) {
        //return early if they arent the same size
		return false;
	}

    //map the charactes fom s to t
    unordered_map<char, char> sToT;
    //map the chrs from t to s
    unordered_map<char, char> tToS;

    for(int i = 0; i < s.size(); i++) {
        char sChar = s[i];
        char tChar = t[i];

        //if char in s is not yet tranlated, tranlate it
        if(sToT.count(sChar) == 0) {
            sToT.emplace(sChar, tChar);
        } else {
            //if it s was translated should be equal to that tranlation
            if (sToT.at(sChar) != tChar)
            {
                //if previous tranlation is different
                //than return flase;
                return false;
            }
        }

        //do the same logic bit from t to s
        //if char in s is not yet tranlated, tranlate it
        if(tToS.count(tChar) == 0) {
            tToS.emplace(tChar, sChar);
        } else {
            //if it was prev translated tChar should be equal to that tranlation
            if (tToS.at(tChar) != sChar)
            {
                //if previous tranlation is different
                //than return flase;
                return false;
            }
        }
    }

	return true;	
}

int main(int argc, char const *argv[])
{
	/* code */
	string s1 = "baa";
	string s2 = "baa";

	std::cout << isIsomorphic(s1,s2) << '\n';
	return 0;
}
