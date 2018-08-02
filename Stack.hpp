#ifndef STACK_H
#define STACK_H

#include "Linked_list.hpp"
#include <iostream>

template<class T>
class Stack : protected Linked_list<T>
{
private:
	//using Linked_list<T>::headPtr;
	//using Linked_list<T>::rearPtr;
	//using Linked_list<T>::count;

public:
	Stack();
	~Stack();
	bool push(const T& newInput);
	bool pop();
	bool isEmpty();
	bool clearStack();
	T peek();
};

/*
Function: Creates a stack
Description: Sets the head pointer and rear pointer to null pointer
Parameters: None
Pre: No stack
Post: Stack is created and points to nullptr
Return: A stack type T
*/
template<class T>
Stack<T>::Stack()
{
	this->headPtr = nullptr;
	this->rearPtr = nullptr;
	this->count = 0;
}

/*
Function: Destroys a stack
Description: Calls clearStack to destory all nodes in the linked list.
Parameters: None
Pre: Stack exist
Post: Stack is destoryed
Return: None
*/
template<class T>
Stack<T>::~Stack()
{
	clearStack();
}

/*
Function: Pushes top of stack
Description: Inserts a data onto the top of the stack which is the beginning of the linked list
Parameters: User input of data to push
Pre: Stack exists
Post: A new node is added to the front of the linked list
Return: Boolean true or false
*/
template<class T>
bool Stack<T>::push(const T& newInput)
{
	return this->insertTop(newInput);
}

/*
Function: Pop top of stack
Description: Removes the data of the top of the stack which is the beginning of the linked list.
Parameters: None
Pre: Stack exists
Post: First node is deleted
Return: Boolean true or false
*/
template<class T>
bool Stack<T>::pop()
{
	return this->removeTop();
}

/*
Function: Is the stack empty
Description: Determines whether the stack is empty by checking count
Parameters: None
Pre: None
Post: None
Return: Boolean True or false
*/
template<class T>
bool Stack<T>::isEmpty()
{
	return (this->count == 0);
}

/*
Function: Peeks the top of stack
Description: Peeks at the first data of the linked list.
Parameters: None
Pre: None
Post: None
Return: Data type of the node
*/
template<class T>
T Stack<T>::peek()
{
	if (isEmpty())
	{
		throw StackIsEmpty("Error: Stack is empty");
	}
	else
		return this->headPtr->getData();
}

/*
Function: Clears stack
Description: Calls pop to destory all the nodes until there is none left.
Parameters: None
Pre: Stack exists
Post: Stack's nodes are destoryed.
Return: Boolean true or false
*/
template<class T>
bool Stack<T>::clearStack()
{
	bool success = false;

	while (isEmpty() == false)
	{
		pop();
		success = true;
	}

	return success;
}

#endif