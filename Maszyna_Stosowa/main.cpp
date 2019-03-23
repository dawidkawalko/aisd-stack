#include "stack.hpp"
#include <iostream>

int pow(const int base, const int exp)
{
	if (exp <= 0)
	{
		return 1;
	}
	
	return base * pow(base, exp - 1);
}

int charArrayToInt(char* array, const int size)
{
	int result = 0;
	if (size > 0)
	{
		bool isNegative = array[0] == '-';
		int startIndex = isNegative ? 1 : 0;

		for (int i = startIndex; i < size; ++i)
		{
			int value = array[i] - '0';
			result += value * pow(10, size - i - 1);
		}

		if (isNegative)
		{
			result *= -1;
		}
	}

	return result;
}

int main()
{
	Stack stack;
	
	int value = 0;
	char input[16] = { 0 };

	while (strcmp(input, "q") != 0)
	{
		std::cin >> input;

		int inputSize = strlen(input);
		if (inputSize <= 0)
		{
			continue;
		}

		switch (input[0])
		{
		case 'p':
			stack.print();
			std::cout << "\n";
			break;

		case 's':
			stack.swap();
			break;

		case 'x':
			stack.pop();
			break;

		case '+':
			stack.sum();
			break;

		case 'r':
			stack.move();
			break;

		default:
			value = charArrayToInt(input, inputSize);
			stack.push(value);
			break;
		}
	}

	return 0;
}