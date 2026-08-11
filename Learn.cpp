// Copyright (c) 2026 Omid Teimory. All Rights Reserved


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

Here is the ultimate cheat sheet for exactly when and why you will actually type the * and & symbols in C++.I have tied these directly to things like physics simulations, hardware control, and data processing so you can see how they work in the wild.1. Avoiding the "Massive Copy" (Performance)When you have a gigantic object, you don't want to copy it. You just hand over the piece of paper with the address.C++struct ArmorPlate {
    int stressPoints[100000]; // Massive amount of data
}
;

// We pass by pointer (*) so we don't copy 100,000 integers.
void calculateImpact(ArmorPlate* target) {
	// We walk over to the address (-> is a shortcut for pointers to structs/classes)
	target->stressPoints[50] -= 10;
}
2. Spawning on the Fly(Heap Allocation) When you fire a virtual weapon,
	you don't know exactly how many shrapnel pieces will spawn. You have to ask the OS for memory right in that millisecond.C++// "Hey OS, give me a new mailbox for a Projectile right now!" Projectile
		*shrapnel = new Projectile();

// ... physics happen ...

// "Okay, it hit the ground. Give the mailbox back."
delete shrapnel;
3. Arrays of Unknown Size(Dynamic Sizing) If you are building a data refinery to process text,
	you might not know if a file has 10 lines or 1, 000,
	000 lines until you open it.C++ int totalLines = countLinesInFile(); // Could be anything

// Ask for a massive block of memory exactly the size we need
std::string* textData = new std::string[totalLines];

// Cleanup when done processing
delete[] textData;
4. The "I Might Not Exist" State(Nullptr)
	References(&) MUST point to something real.Pointers(*) have a superpower
    : they can point to nullptr(Address 0),
	meaning "nothing is here." C
	++ Entity* lockedTarget = nullptr; // Right now, we aren't aiming at anything

if (lockedTarget != nullptr) {
	shoot(lockedTarget); // Only shoot if the piece of paper actually has an address
}
5. Hardware& GPU Control(CUDA)
Your CPU cannot touch your graphics
	card 's memory directly. It can only hold pointers that represent addresses over in the GPU' s
		VRAM.C++ float* d_GraphicsData; // The 'd_' reminds us this is on the Device (GPU)
cudaMalloc(&d_GraphicsData, 1024);		// Reserve 1024 bytes on the GPU
6. The Shape - Shifter(Polymorphism) This is a massive concept in C
	       ++ gaming.A pointer can point to a generic "Base" class,
	but actually hold a specialized "Child" class.C++ // PhysicsObject is the generic base class
	// But the pointer is secretly holding a specific Missile object
	PhysicsObject *currentObject = new Missile();

// The pointer is smart enough to use the Missile's specific explosion code
currentObject->explode();
7. Linking Data Together(Data Structures) If you are moving chunks of refined data around,
	you can chain them together.Each chunk holds a pointer(an address) to the next chunk.C
	++ struct DataChunk {
	std::string text;
	DataChunk* nextChunk; // A piece of paper pointing to the next link in the chain
};
8. Returning New Creations from FunctionsIf a function creates something large,
	it shouldn't return the whole object (which triggers a massive copy). It should just return the address of the newly created object.C++int* generatePhysicsMatrix() { int
		*matrix = new int[500]; // Create it on the heap
// ... fill matrix with math ...
return matrix; // Just return the tiny piece of paper
}
9. The Self - Awareness Pointer(this) Inside every C++ class,
	there is a hidden pointer called
	this.It is literally a piece of paper that holds the address of the specific object running
	the code.C++ class Simulator {
	int speed;
	void setSpeed(int speed) {
		// "this->speed" means the variable owned by the class.
		// "speed" means the parameter passed into the function.
		this->speed = speed;
	}
};
10. Swapping Behaviors(Function Pointers) Variables
	aren't the only things with memory addresses! Functions live in memory too. You can create a pointer to a function and swap out how your program behaves on the fly.C++// A pointer that can hold the address of ANY function that takes two ints int (
		*mathOperation)(int, int);

// We can make the pointer point to our sum function
mathOperation = &sum;
