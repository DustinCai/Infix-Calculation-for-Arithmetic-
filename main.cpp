/*Program Filename : InfixCalculator
Authors : Jason Goble and Dustin Cai
Date : 5 / 12 / 2017
Description : Evaluates user input equations
Input : None
Output : None
Assumptions :
1. Operands of input expressions are single digit onnly
2. Operators used are only +, -, *, /, %, (, )
3. Parentheses are not used for multiplication
4. No use of unary operators
*/

#include "Node.hpp"
#include "Linked_list.hpp"
#include "Stack.hpp"
#include "Exceptions.h"
#include "InfixCalculator.hpp"

using namespace std;

int main()
{
	string input;
	int result;
	bool again = false;

	do 
	{
		cout << "Enter an equation to evaluate: " << endl;
		getline(cin, input);
		InfixCalculator alpha(input);
		result = alpha.evaluate();
		cout << result << endl;

		cout << "Would you like to evaulate another equation? (Y/N)" << endl;
		cin >> input;
		cin.ignore(1000, '\n');
		while ((input != "Y") && (input != "N") && (input != "y") && (input != "n"))
		{
			cout << "Would you like to evaulate another equation? (Y/N)" << endl;
			cin >> input;
			cin.ignore(1000, '\n');
		}
		if ((input == "Y") || (input == "y"))
			again = true;
		else if ((input == "N") || (input == "n"))
			again = false;
	} while (again == true);

	return 0;
}