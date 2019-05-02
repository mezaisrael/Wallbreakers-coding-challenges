#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>> &A)
{
	std::vector<vector<int>> results;

	for(int i = 0; i < A.at(0).size(); i++)
	{
		std::vector<int> newRow(A.size());
		for(int j = 0; j < A.size(); j++)
		{
			newRow.at(j) = A.at(j).at(i);
		}
		
		results.push_back(newRow);
	}

	return results;
}

int main(int argc, char const *argv[])
{
	std::vector<vector<int>> input {
		{1,2,3},
		{4,5,6},
	};

	transpose(input);

	return 0;
}
