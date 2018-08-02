#ifndef Linked_list_h
#define Linked_list_h

#include "Node.hpp"

template <class T>
class Linked_list
{
protected:
	Node<T>* headPtr;
	Node<T>* rearPtr;
	int count;

public:
	Linked_list();
	Linked_list(const Linked_list<T>& list);
	virtual ~Linked_list();
	int getSize() const;
	bool isEmpty() const;
	void add(const T& input);
	void remove(const T& input);
	void clear();
	bool holds(const T& input) const;

	bool insertTop(const T& input);
	bool removeTop();

	bool insertRear(const T& input);


};

/*
Function: Creates a linked list
Description: Creates a linked list by initializing headPtr and rearPtr to nullptr
Parameters: None
Pre: Linked list does not exist.
Post: Linked list exists
Return: A linked list type T
*/
template <class T>
Linked_list<T>::Linked_list() : headPtr(nullptr), rearPtr(nullptr), count(0)
{

}

/*
Function: Copies a Linked List
Description: Creates a new linked list by copying another
Parameters: Linked List
Pre: One linked list
Post: Another copy of the same linked list
Return: A linked list type T
*/
template <class T>
Linked_list<T>::Linked_list(const Linked_list<T>& list)
{
	count = list.count;

	headPtr = list.headPtr;
	rearPtr = list.rearPtr;
}

/*
Function: Linked list destructor
Description: Destorys the linked list by calling clear
Parameters: None
Pre: Linked list exists
Post: Linked list is destoryed
Return: None
*/
template <class T>
Linked_list<T>::~Linked_list()
{
	clear();
}

/*
Function: Get size of Linked list
Description: Returns the size of the linked list by count
Parameters: None
Pre: None
Post: None
Return: Integer
*/
template <class T>
int Linked_list<T>::getSize() const
{
	return count;
}

/*
Function: Is linked list empty
Description: Checks if the linked list is empty by checking if the count is zero
Parameters: None
Pre: None
Post: None
Return: Boolean true or false
*/
template <class T>
bool Linked_list<T>::isEmpty() const
{
	return (count == 0);
}

/*
Function: Adds node
Description: Inserts a node in sorted order.
Parameters: User input of type T
Pre: None
Post: A new node is added
Return: None
*/
template <class T>
void Linked_list<T>::add(const T& input)
{
	Node<T>* pPre = nullptr;
	Node<T>* pCurr = headPtr;
	Node<T>* newNode = new Node(input);

	if (isEmpty() == true)	//if linked list is empty, set headPtr and rearPtr to newNode
	{
		headPtr = newNode;
		rearPtr = newNode;
	}
	else
	{
		while ((input > pCurr->getData()) && (pCurr->getNext() != nullptr))		//traverses through list 
		{
			pPre = pCurr;
			pCurr = pCurr->getNext();
		}

		//if (pPre == nullptr)	
		//{
		//	headPtr = newNode;
		//	newNode->setNext(pCurr);
		//}
		if (pCurr->getNext() != nullptr)	// if the node is somewhere in the middle of the list 
		{
			pPre->setNext(newNode);
			newNode->setNext(pCurr);
		}
		else // if it is the last node 
		{
			pCurr->setNext(newNode);
			rearPtr = newNode;
		}
	}

	count++;
}

/*
Function: Removes a node
Description: Removes a node given by user input.
Parameters: User input of type T
Pre: None
Post: A node is removed from the linked list
Return: None
*/
template <class T>
void Linked_list<T>::remove(const T& input)
{
	Node<T>* pPre = headPtr;
	Node<T>* pCurr = headPtr;

	if (isEmpty())	//if list is empty, return 
	{
		return;
	}

	if (headPtr->getData() == input)	//if the first node is the target, remove it
	{
		if (headPtr->getNext() == nullptr)
		{
			rearPtr = nullptr;
		}

		pCurr = headPtr->getNext();
		delete headPtr;
		headPtr = pCurr;
		count--;
	}
	else
	{
		while (pCurr != nullptr && pCurr->getData() != input)	//traverses the list 
		{
			pPre = pCurr;
			pCurr = pCurr->getNext();
		}

		if (pCurr)	//if found, remove the node 
		{
			if (pCurr->getNext() == nullptr)
			{
				rearPtr = pPre;
			}
			pPre->setNext(pCurr->getNext());
			delete pCurr;

			count--;
		}
	}
}

/*
Function: Clears the linked list
Description: Clears the linked list by deleting all the nodes
Parameters: None
Pre: Linked list has nodes
Post: Nodes are destoryed
Return: None
*/
template <class T>
void Linked_list<T>::clear()
{
	Node<T>* nodeDeletePtr = headPtr;
	while (headPtr != nullptr)
	{
		headPtr = headPtr->getNext();

		nodeDeletePtr->setNext(nullptr);
		delete nodeDeletePtr;
		nodeDeletePtr = headPtr;
	}
	count = 0;
}

/*
Function: Returns true or false
Description: Returns true if the data is in the list
Parameters: User input of type T
Pre: None
Post: None
Return: Boolean true or false
*/
template <class T>
bool Linked_list<T>::holds(const T& input) const
{
	return (getPtrTo(input) != nullptr);
}

/*
Function: Inserts top
Description: Inserts node in the beginning of the list
Parameters: User input of type T
Pre: None
Post: A node is added in front of the linked list
Return: Boolean true or false
*/
template <class T>
bool Linked_list<T>::insertTop(const T& input)
{
	Node<T>* newNode = new Node<T>(input);
	bool success = false;

	if (isEmpty() == true)
	{
		headPtr = newNode;
		rearPtr = newNode;
		count++;

		std::cout << newNode->getData() << " pushed on stack." << endl;

		success = true;
	}
	else
	{
		newNode->setNext(headPtr);
		headPtr = newNode;
		count++;

		std::cout << newNode->getData() << " pushed on stack." << endl;

		success = true;
	}

	return success;
}

/*
Function: Removes top
Description: Removes the first node of the linked list
Parameters: None
Pre: None
Post: The first node is removed from the linked list
Return: Boolean true or false
*/
template <class T>
bool Linked_list<T>::removeTop()
{
	bool success;
	Node<T>* pCurr = headPtr;

	if (isEmpty() == false) //if the list is not empty, remove the first node 
	{
		headPtr = headPtr->getNext();
		std::cout << pCurr->getData() << " popped off stack." << endl;
		delete pCurr;

		count--;
		success = true;

		if (isEmpty() == true)
		{
			rearPtr = nullptr;
		}
	}
	else{
		success = false;
	}

	return success;
}

/*
Function: Inserts rear
Description: Inserts node in the end of the list
Parameters: User input of type T
Pre: None
Post: A node is added at the end of the linked list
Return: Boolean true or false
*/
template<class T>
bool  Linked_list<T>::insertRear(const T& input)
{
	Node<T>* newNode = new Node<T>(input);
	bool success = false;

	if (isEmpty())
	{
		headPtr = newNode;
		rearPtr = newNode;

		cout << newNode->getData() << " enqueued." << endl;

		success = true;
		count++;
	}
	else
	{
		rearPtr->setNext(newNode);
		rearPtr = newNode;

		cout << newNode->getData() << " enqueued." << endl;

		success = true;
		count++;
	}

	return success;
}

#endif 