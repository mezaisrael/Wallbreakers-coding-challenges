#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int> &A)
{
	deque<int> resultQueue;

	for(auto num : A) {
		if (num % 2 == 0) {
			//if it is eve put it in the front
			resultQueue.push_front(num);
		} else {
			resultQueue.push_back(num);
		}
		
	}

	std::vector<int> result(A.size());
	
	int index = 0;
	for(auto num : resultQueue) {
		result.at(index) = num;
		index++;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	std::vector<int> sample{3,1,2,4};

	sortArrayByParity(sample);
	return 0;
}
