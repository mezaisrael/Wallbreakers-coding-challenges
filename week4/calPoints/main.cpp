#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int calPoints(vector<string>& ops) {
	stack<int> validPoints; 
	int sum = 0;
	for (unsigned int i = 0; i < ops.size(); ++i)
	{
		if (ops.at(i) == "+"){
			int x = validPoints.top();
			validPoints.pop();
			int y = validPoints.top();
			sum = sum+ x + y;

			//since we poped x put it back in stack
			validPoints.push(x);
			//add x+y to the top of the stack
			validPoints.push(x+y);
		}
		else if (ops.at(i) == "D"){
			int lastPointDoubled = validPoints.top() * 2;

			validPoints.push(lastPointDoubled);
			sum+= lastPointDoubled;
		}
		else if (ops.at(i) == "C"){
			//last valid were invalid
			int invalidP = validPoints.top();
			validPoints.pop();

			sum -= invalidP;
		} else {
			int point = stoi(ops.at(i));
			sum += point;
			validPoints.push(point);
		}
	}
    return sum;
}

int main(int argc, char const *argv[])
{
	stack<int> points;

	std::vector<string> v{"5","-2","4","C","D","9","+","+"};

	cout << calPoints(v) << endl;
	return 0;
}