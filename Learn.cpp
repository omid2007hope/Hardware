#include <iostream>

// 2 or 4 bytes (typically 4 bytes on 32/64-bit systems)!
// Has an address in memory!
int num = 100;

// health: nickname (alias) of num
// We've created a read-only reference (const int&)—not a copy.
// A reflection of you in the mirror is not a copy of you, it's literally you used as a parameter.
const int& health = num;

// The address where num is stored in memory!
// An int variable cannot directly hold a memory address, which is why we use `int*` and `&num`.
int* numsAddress = &num;

// Structure
// Type management and clean architecture
struct Axis {
	// Why assign a default value 0?
	// IMPORTANT for garbage value prevention and safety.
	int x = 0;
	int y = 0;
};

// Standard class
class Calculate {
private:
public:
	void sum(const Axis& numbers);
};

// Axis &numbers --> in memory (RAM), go to the address where Axis (x and y) is stored
// and access what is inside using the alias `numbers`.
// No copy -- it's literally x and y with a nickname.
void Calculate::sum(const Axis& numbers) {
	int total = numbers.x + numbers.y;
	std::cout << "Total sum: " << total << std::endl;
}

int main() {
	// Practice examples:

	// 1st: Dynamic memory allocation on the heap
	int* a = new int;
	*a = 35;
	std::cout << "Address stored in a: " << a << std::endl;
	std::cout << "Value pointed to by *a: " << *a << std::endl;
	delete a; // Free memory allocated on heap

	// 2nd: Storing address of a local stack variable
	int something = 100;
	int* ptr = &something;

	// Printing ptr outputs the memory address of 'something' instead of &something
	std::cout << "Pointer address (ptr): " << ptr << std::endl;
	std::cout << "Value stored at ptr (*ptr): " << *ptr << std::endl;

	return 0;
}

