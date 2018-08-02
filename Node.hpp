#ifndef Node_h
#define Node_h

template <class T>
class Node
{
private:
	T data;
	Node<T> *next;

public:
	Node();
	Node(const T& newData);
	Node(const T& newData, Node<T> *nextNodePtr);
	void setData(const T& newData);
	void setNext(Node<T>* nextNodePtr);
	T getData() const;
	Node<T>* getNext() const;
};

/*
Function: Default constructor
Description: Initializes node
Parameters: None
Pre: None
Post: Node is created
Return: A node of type T
*/
template<class T>
Node<T>::Node() : data(0), next(nullptr)
{
}

/*
Function: Overloaded constructor
Description: Initializes node with user input
Parameters: User input of type T
Pre: None
Post: Node is created
Return: A node of type T
*/
template <class T>
Node<T>::Node(const T& newData) : data(newData), next(nullptr)
{
}

/*
Function: Overloaded node constructor
Description: Initializes a node and points to another node
Parameters: User input of type T and nextNodePtr
Pre: None
Post: Node is created and points to another node
Return: Node of type T
*/
template <class T>
Node<T>::Node(const T& newData, Node<T> *nextNodePtr) : data(newData), next(nextNodePtr)
{
}

/*
Function: Sets Data
Description: Sets the data of the node
Parameters: User input of type T
Pre: None
Post: Data is set
Return: None
*/
template <class T>
void Node<T>::setData(const T& newData)
{
	data = newData;
}

/*
Function: Sets pointer
Description: Set pointer to point to the next node
Parameters: A pointer of type T
Pre: None
Post: Pointer points to a node
Return: None
*/
template <class T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
}

/*
Function: Gets data
Description: Returns the data of the node
Parameters: None
Pre: None
Post: None
Return: Node of type T
*/
template <class T>
T Node<T>::getData() const
{
	return data;
}

/*
Function: Gets next
Description: Returns the next node pointer
Parameters: None
Pre: None
Post: None
Return: Node of type T
*/
template <class T>
Node<T>* Node<T>::getNext() const
{
	return next;
}


#endif
