#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << CYAN"Printing the stack:" << std::endl;
	mstack.printStack();

	std::cout << std::endl << "Printing value that is on the top of the stack:" << std::endl;
	std::cout << mstack.top() << std::endl << std::endl;

	std::cout << "Removing value on the top and printing size of the stack:" << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl << std::endl;

	std::cout << "Adding 4 values and printing the stack:" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << std::endl;
	}

	std::cout << std::endl << "Copying stack with copy constructor and printing it:" << std::endl;
	MutantStack<int> copy(mstack);
	copy.printStack();

	std::cout << std::endl << "Copying stack with assignment operator and printing it:" << std::endl;
	MutantStack<int> other_copy;
	other_copy = copy;
	other_copy.printStack();

	std::cout << std::endl << RES GREEN"TESTING SAME CODE WITH A LIST:" RES << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);

	std::cout << PURPLE"Printing the list:" << std::endl;
	for (std::list<int>::iterator it_lst = lst.begin(); it_lst != lst.end(); ++it_lst) {
		std::cout << *it_lst << std::endl;
	}

	std::cout << std::endl << "Printing value that is on the top of the list:" << std::endl;
	std::cout << lst.back() << std::endl << std::endl;

	std::cout << "Removing value on the top and printing size of the list:" << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl << std::endl;

	std::cout << "Adding 4 values and printing the list:" << std::endl << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	for (std::list<int>::iterator it_lst = lst.begin(); it_lst != lst.end(); ++it_lst) {
		std::cout << *it_lst << std::endl;
	}
	std::cout << RES << std::endl;

	return 0;
}
