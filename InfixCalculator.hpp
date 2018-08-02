#ifndef INFIXCALCULATOR_H
#define INFIXCALCULATOR_H

#include "Stack.hpp"
#include <string>

class InfixCalculator
{
private:
	std::string m_equation;
	Stack<char>* opStack;
	Stack<int>* numStack;

public:
	InfixCalculator(std::string equation);
	~InfixCalculator();
	int evaluate();
	void execute();
	int precedence(char op);
};

/*
Function: Creates an object to be calculated
Description: Sets the equation to user input and creates two stacks
Parameters: None
Pre: None
Post: Object is created
Return: An object of two stacks and an equation
*/
InfixCalculator::InfixCalculator(std::string equation)
{
	m_equation = equation;
	opStack = new Stack<char>();
	numStack = new Stack<int>();
}

/*
Function: Destroys the object
Description: Destroys the object
Parameters: None
Pre: Objects exists
Post: Object is destoryed
Return: None
*/
InfixCalculator::~InfixCalculator()
{
}

/*
Function: Evaluate algebraic function
Description: Converts infix equation to postfix if necessary and evaluates the equation
Parameters: None
Pre: Equation to evaluate
Post: None
Return: Int value of evaluated equation
*/
int InfixCalculator::evaluate()
{
	int length = m_equation.length();
	int result = 0;
	int num;

	for (int i = 0; i < length; i++)
	{
		char x = m_equation[i];

		switch (x)
		{
		// Cases for all numbers
		case ('0'):
		case ('1'):
		case ('2'):
		case ('3'):
		case ('4'):
		case ('5'):
		case ('6'):
		case ('7'):
		case ('8'):
		case ('9'):
			num = x - '0';
			numStack->push(num);
			break;
		// Case for open parentheses
		case ('('):
			opStack->push(x);
			break;
		// Cases for all operators
		case ('+'):
		case ('-'):
		case ('*'):
		case ('/'):
		case ('%'):
		{
			if (opStack->isEmpty())
				opStack->push(x);
			// Pushes operator on stack if precedence is higher
			else if (precedence(x) > precedence(opStack->peek()))
				opStack->push(x);
			// Evaluates stack until operator stack is empty or precedence is lower
			else
			{
				while (!opStack->isEmpty() && (precedence(x) <= precedence(opStack->peek())))
					execute();
				opStack->push(x);
			}
			break;
		}
		// Case for closed parentheses
		case (')'):
		{
			// Evaluates expression inside parentheses
			while (opStack->peek() != '(')
				execute();
			opStack->pop();
			break;
		}
		default :
			break;
		}
	}
	// Evaluates what remains of the equation
	while (!opStack->isEmpty())
		execute();
	result = numStack->peek();

	return result;
}

/*
Function: Executes a single operation
Description: Executes a single operation of the equation
Parameters: None
Pre: Precedence dictates an operation
Post: Stacks are updated after operation execution
Return: None
*/
void InfixCalculator::execute()
{
	int operand1 = 0;
	int operand2 = 0;
	char oper;
	int result;

	operand2 = numStack->peek();
	numStack->pop();
	
	operand1 = numStack->peek();
	numStack->pop();
	
	oper = opStack->peek();
	opStack->pop();
	
	if (oper == '+')
		result = operand1 + operand2;
	else if (oper == '-')
		result = operand1 - operand2;
	else if (oper == '*')
		result = operand1 * operand2;
	else if (oper == '/')
		result = operand1 / operand2;
	else if (oper == '%')
		result = operand1 % operand2;
	
	numStack->push(result);
}

/*
Function: Precedence
Description: Determines precedence value of an operator
Parameters: Operator
Pre: None
Post: None
Return: Int value of precedence
*/
int InfixCalculator::precedence(char op)
{
	int precedence;

	if ((op == '*') || (op == '/') || (op == '%'))
		precedence = 2;
	else if ((op == '+') || (op == '-'))
		precedence = 1;
	else if (op == '(')
		precedence = 0;

	return precedence;
}

#endif
