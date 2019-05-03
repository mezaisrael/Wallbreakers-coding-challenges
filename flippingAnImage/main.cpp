#include <iostream>
#include <vector>
using namespace std;

//version 2
vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
{
	for(auto &vec : A)
	{
		auto front = vec.begin();
		auto back = vec.end()-1;
		for(; front <= back; front++, back--) {
			//flip their values only if they are equal
			if (*front == *back) {
				*front = !*front;
				*back = !*back;
			}
			
		}

		//if A size is odd then we need to flip the middle
		if (front == back)
		{
			*front = !*front;
		}
		
	}

	return A;
}

int main(int argc, char const *argv[])
{

	std::vector<vector<int>> input{
		{1, 0, 1},
		{1, 1, 1},
		{0, 1, 0},
	};

 	flipAndInvertImage(input);
	return 0;
}
