#ifndef __Stack__
#define __Stack__

class Stack
{
public:
	Stack();
	~Stack();

	/**
	* Pushes a new value onto the stack
	* @param value new value
	*/
	void push(const int value);

	/**
	* Removes the top most value from the stack
	*/
	void pop();

	/**
	* Gets the number of elements on the stack
	*/
	int size() const { return m_size; }

	/**
	* Checks if the stack contains eny elements
	*/
	bool isEmpty() const { return m_size == 0; }

	/**
	* Swaps the 2 top most values of the stack
	*/
	void swap();

	/**
	* Removes the 2 top most values and pushes their sum onto the stack
	*/
	void sum();

	/**
	* Moves the top most value of the stack to a
	* position given by the top most stack value
	*/
	void move();

	/**
	* Prints the stack to the standard output
	*/
	void print() const;

private:
	struct Node
	{
		explicit Node(const int _value) : value(_value) {}

		int value = 0;
		Node* next = nullptr;
	};

	Node* m_top;
	int m_size;
};

#endif // __Stack__
