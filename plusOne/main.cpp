#include <iostream>
#include <vector>

using namespace std;

// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

// You may assume the integer does not contain any leading zero, except the number 0 itself.

// int sumElements(std::vector<unsigned int> digits) {
// 	int sum =0;

// 	long decimalPlace = 1;
// 	for (auto digit = digits.rbegin(); digit != digits.rend(); digit++) {
// 		*digit *= decimalPlace;
// 		sum += *digit;

// 		decimalPlace *= 10;
// 	}

// 	return sum;
// }

// void splitHelper(int num, std::vector<int> &results);

// //recursive version so that I can easily push back
// std::vector<int> splitNum(int num) {
// 	std::vector<int> results;
// 	if(num / 10 != 0) {
// 		splitHelper(num, results);
// 	}

// 	return results;
// }

// //helper for recursive
// void splitHelper(int num, std::vector<int> &results) {
// 	if (num / 10 != 0)
// 	{
// 		splitHelper(num / 10, results);
// 	}

// 	//pushback the remainder
// 	results.push_back(num % 10);

// }


// vector<int> plusOne(vector<int> &digits)
// {
// 	//exit early if you dont need to carry over
// 	if (*digits.rbegin() != 9) {
// 		*digits.rbegin() += 1;
// 		std::cout << "returning " << '\n';
// 		return digits;
// 	}
	
// 	//turn to number and add 1
// 	int plusOne = sumElements(digits) + 1;

// 	//turn back to array;
// 	return splitNum(plusOne);

// }

vector<int> plusOne(vector<int> &digits)
{
	auto digitIt = digits.rbegin();
	if (*digitIt < 9) {
		(*digitIt)++;
		return digits;
	}

	//carry over if needed
	while(*digitIt == 9) {
		*digitIt = 0;

		digitIt++;
	}


	//it the iterator made it to the end then we
	//need to insert 1 to the begining
	if (digitIt == digits.rend()) {
		digits.insert(digits.begin(), 1);
	} else {
		(*digitIt)++;
	}
	

	return digits;
}

int main(int argc, char const *argv[])
{
	std::vector<int> sample{9};

	std::vector<int> result = plusOne(sample);

	for(auto num : sample)
	{
		cout << num << endl;
	}
	return 0;
}
