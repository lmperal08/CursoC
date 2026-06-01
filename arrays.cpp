#include <iostream>

void f(int array[])
{
	std::cout << sizeof(array) << std::endl;
}

int main()
{
	int array[]={1,2,3,4,5};
	std::cout << sizeof(array) << std::endl;
	f(array);

}