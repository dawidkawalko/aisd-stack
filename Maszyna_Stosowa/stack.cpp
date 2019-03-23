#include "stack.hpp"
#include <iostream>

Stack::Stack() : m_top(nullptr), m_size(0) {}

Stack::~Stack()
{
	while (m_size > 0)
	{
		pop();
	}
}

void Stack::push(const int value)
{
	Node* newNode = new Node(value);

	newNode->next = m_top;
	m_top = newNode;

	++m_size;
}

void Stack::pop()
{
	if (m_size < 1)
	{
		return;
	}

	Node* tmp = m_top;
	m_top = m_top->next;
	tmp->next = nullptr;

	delete tmp;

	--m_size;
}

void Stack::swap()
{
	if (m_size < 2)
	{
		return;
	}

	Node* tmp = m_top->next;

	m_top->next = tmp->next;
	tmp->next = m_top;
	m_top = tmp;
}

void Stack::sum()
{
	if (m_size < 2)
	{
		return;
	}

	int sum = m_top->value + m_top->next->value;

	pop();
	pop();
	push(sum);
}

void Stack::move()
{
	if (m_size < 1)
	{
		return;
	}

	int n = m_top->value;
	pop();

	if (n < 2 || n > m_size)
	{
		return;
	}

	if (n == 2)
	{
		swap();
		return;
	}

	Node* previous = nullptr;
	Node* current = m_top;
	while (n-- > 1) // count from 1
	{	
		previous = current;
		current = current->next;
	} 
	
	Node* second = m_top->next;
	m_top->next = current->next;
	current->next = m_top;
	m_top = second;
}

void Stack::print() const
{
	Node* tmp = m_top;
	while (tmp)
	{
		std::cout << tmp->value << " ";
		tmp = tmp->next;
	}
}