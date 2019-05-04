#include <iostream>
#include <vector>

using namespace std;

vector<string> fizzBuzz(int n)
{
	std::vector<string> results(n);
	for(int i = 1; i <= n; i++)
	{
		string fizzBuzz = "";
		if (i % 3 == 0) {
			fizzBuzz += "Fizz";
		}
		
		if (i % 5 == 0)
		{
			fizzBuzz += "Buzz";	
		}
		
		if(i % 3 != 0 && i % 5 != 0) {
			fizzBuzz += to_string(i);
		}
		results.at(i-1) = fizzBuzz;
	}
	return results;
}

int main(int argc, char const *argv[])
{
	fizzBuzz(1);

	return 0;
}
