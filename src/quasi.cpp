#include <iostream>

int factorial(int n)
{
	if (n==1) return 1;
	return n*factorial(n-1);
}

int main()
{
	std::cout << "Hello World!" << std::endl;
	std::cout << "The factorial of 5 is: " << factorial(5) << std::endl;
	std::cin.get();
	return 0;
}
