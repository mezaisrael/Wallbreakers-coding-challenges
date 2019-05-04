#include <iostream>
#include <deque>
#include <vector>
#include <list>

using namespace std;

bool isSelfDividing(int num)
{
	int quotient = num;

	while (quotient != 0)
	{
		int r = quotient % 10;
		if (r == 0 || num % r != 0)
		{
			return false;
		}

		quotient /= 10;
	}
	return true;
}

vector<int> selfDividingNumbers(int left, int right)
{
	std::vector<int> results;

	for(int i = left; i <= right; i++)
	{
		if(i < 10) {
			results.push_back(i);
		}
		else if (isSelfDividing(i)) {
			results.push_back(i);
		}
		
	}
	
	for(auto num : results) {
		std::cout << num << '\n';
	}

	return results;
}

int main(int argc, char const *argv[])
{

	selfDividingNumbers(1,22);

	/* code */
	return 0;
}
