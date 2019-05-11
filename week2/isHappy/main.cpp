/* Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers. */

#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>

using namespace std;

std::vector<int> split(int num) {
	std::vector<int> digits;
	while(num != 0) {
		digits.push_back(num%10);
		num /= 10;
	}
	return digits;
}

bool isHappyHelper(int num, unordered_set<int>& seen)
{
	std::vector<int> digits = split(num);
	int sum = 0;
	for (int i = 0; i < digits.size(); i++)
	{
		sum+= pow(digits.at(i),2);
	}
	
	//if we seen this sum then we are going to go in a loop
	if (seen.count(sum) > 0)
	{
		return false;
	} else if(sum == 1) {
		return true;
	}

	seen.emplace(num);
	return isHappyHelper(sum, seen);
}

// bool isHappy(int n)
// {
// 	unordered_set<int> seen;

// 	return isHappyHelper(n, seen);
// }

bool isHappy(int n) {
	unordered_set<int> seen;
	while (n != 1) {
		seen.emplace(n);
	
		int res = 0;
		while(n != 0) {

			res += (n%10) * (n%10);
			n /= 10;

		}
		n = res;
		if (seen.count(n)) {
			return false;
		}


	}
	return true;
}

int main(int argc, char const *argv[])
{

	if (isHappy(19))
	{
		std::cout << "True" << '\n';
	} else {
		std::cout << "false" << '\n';
	}
	
	return 0;
}
