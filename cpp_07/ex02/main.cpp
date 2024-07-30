#include "Array.hpp"

#define MAX 10

template <typename T>
void displayArray(const std::string& title, const Array<T>& array, const std::string& color) {
	std::cout << color << title << RES << std::endl;
	for (unsigned int i = 0; i < array.size(); i++) {
		std::cout << color << array[i];
		if (i != array.size() - 1)
			std::cout << ", ";
	}
	std::cout << RES << std::endl << std::endl;
}

void fillCharArray(Array<char>& array) {
	for (int i = 0; i < MAX; i++) {
		array[i] = 'a' + i;
	}
}

void fillStringArray(Array<std::string>& array) {
	for (int i = 0; i < MAX; i++) {
		array[i] = "string";
	}
}

void fillArrayWithRandomValues(Array<int>& array, int* mirror) {
	srand(static_cast<unsigned>(time(NULL)));
	for (int i = 0; i < MAX; i++) {
		int value = rand() % 1000;
		array[i] = value;
		mirror[i] = value;
	}
}

void compareArrays(const Array<int>& numbers, int* mirror) {
	std::cout << PURPLE"\t\tCOMPARING VALUES OF [NUMBERS] AND [MIRROR]" RES << std::endl;
	for (int i = 0; i < MAX; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << RED"didn't save the same value!!" RES<< std::endl;
			return;
		} else
			std::cout << PURPLE"Same value at index " << i << " !" RES << std::endl;
	}
	std::cout << std::endl;
}

void testOutOfBounds(Array<int>& array) {
	std::cout << RED"\t\tTESTING TOO LOW INDEX VALUE" RES << std::endl;
	try {
		array[-2] = 0;
	} catch(const std::exception& e) {
		std::cerr << e.what() << "\n" RES;
	}

	std::cout << std::endl << RED"\t\tTESTING TOO HIGH INDEX VALUE" RES << std::endl;
	try {
		array[MAX] = 0;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n' << RES;
	}
	std::cout << std::endl;
}

void modifyArrayValues(Array<int>& array) {
	for (int i = 0; i < MAX; i++)
		array[i] = rand() % 1000;
}

int main() {
	Array<char> chars(MAX);
	fillCharArray(chars);
	displayArray("Displaying array of chars", chars, GREEN);

	Array<std::string> strings(MAX);
	fillStringArray(strings);
	displayArray("Displaying array of strings", strings, YELLOW);

	Array<int> emptyArray;
	displayArray("Displaying empty array of int", emptyArray, PURPLE);

	Array<int> numbers(MAX);
	int* mirror = new int[MAX];
	fillArrayWithRandomValues(numbers, mirror);
	displayArray("Displaying array of int [NUMBERS]", numbers, ORANGE);
	std::cout << BLUE"Displaying array of int [MIRROR]" RES << std::endl;
	for (int i = 0; i < MAX; i++) {
		std::cout << BLUE << mirror[i];
		if (i != MAX - 1)
			std::cout << ", ";
	}
	std::cout << RES << std::endl << std::endl;

	Array<int> tmp = numbers;
	displayArray("Displaying copy of [NUMBERS] by assignment operator", tmp, GREEN);

	Array<int> test(tmp);
	displayArray("Displaying copy of [NUMBERS] by copy constructor", test, YELLOW);

	compareArrays(numbers, mirror);

	testOutOfBounds(numbers);

	modifyArrayValues(numbers);
	displayArray("Modified values of [NUMBERS]", numbers, CYAN);

	delete[] mirror;
	return 0;
}