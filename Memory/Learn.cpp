// Copyright (c) 2026 Omid Teimory. All Rights Reserved

#include <iostream>
#include <string>

// ============================================================================
// PART 1: Core Fundamentals (Pointers & References)
// ============================================================================

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

// ============================================================================
// PART 2: Ultimate Cheat Sheet — When & Why to Use '*' and '&' in C++
// ============================================================================

// 1. Avoiding the "Massive Copy" (Performance)
// When you have a gigantic object, you don't want to copy it.
// You hand over the piece of paper with the address (ArmorPlate*).
struct ArmorPlate {
	int stressPoints[100000]; // Massive amount of data
};

// We pass by pointer (*) so we don't copy 100,000 integers.
void calculateImpact(ArmorPlate* target) {
	if (target != nullptr) {
		// -> is a shortcut for (*target).stressPoints (pointers to structs/classes)
		target->stressPoints[50] -= 10;
	}
}

// 2. Spawning on the Fly (Heap Allocation)
// When you fire a virtual weapon, you don't know how many shrapnel pieces will spawn.
// You ask the OS for memory right at runtime using `new`.
struct Projectile {
	float velocity = 100.0f;
};

void spawnExample() {
	// "Hey OS, give me memory for a Projectile right now!"
	Projectile* shrapnel = new Projectile();

	// ... physics calculations ...

	// "Okay, it hit the ground. Free the memory back to the OS."
	delete shrapnel;
}

// 3. Arrays of Unknown Size (Dynamic Sizing)
// If you are building a data processor, you might not know total lines until runtime.
void dynamicSizingExample(int totalLines) {
	// Ask for a block of memory exactly the size needed
	std::string* textData = new std::string[totalLines];

	// ... process textData ...

	// Cleanup dynamically allocated array when done
	delete[] textData;
}

// 4. The "I Might Not Exist" State (Nullptr)
// References (&) MUST point to something real.
// Pointers (*) can point to `nullptr` (Address 0), meaning "nothing is currently targeted".
struct Entity {
	std::string name;
};

void shoot(Entity* target) {
	if (target != nullptr) {
		std::cout << "Shooting target: " << target->name << std::endl;
	}
}

void nullptrExample() {
	Entity* lockedTarget = nullptr; // Right now, we aren't aiming at anything

	if (lockedTarget != nullptr) {
		shoot(lockedTarget); // Only shoot if pointer actually holds an address
	}
}

// 5. Hardware & GPU Control (CUDA / VRAM Pointers)
// Your CPU cannot touch graphics card VRAM directly.
// It holds pointers representing addresses over in GPU memory.
void hardwareControlExample() {
	float* d_GraphicsData = nullptr; // 'd_' convention denotes Device (GPU) memory pointer
	// cudaMalloc(&d_GraphicsData, 1024); // Reserve 1024 bytes on the GPU
	(void)d_GraphicsData;
}

// 6. The Shape-Shifter (Polymorphism)
// A base class pointer can point to a generic base class, but actually hold a child class.
class PhysicsObject {
public:
	virtual ~PhysicsObject() = default;
	virtual void explode() {
		std::cout << "Generic physics explosion!" << std::endl;
	}
};

class Missile : public PhysicsObject {
public:
	void explode() override {
		std::cout << "Missile BOOM!" << std::endl;
	}
};

void polymorphismExample() {
	// PhysicsObject pointer holding a specific Missile object on the heap
	PhysicsObject* currentObject = new Missile();

	// Calls Missile's specific explosion code via virtual function resolution
	currentObject->explode();

	delete currentObject;
}

// 7. Linking Data Together (Data Structures)
// Chaining data chunks together where each chunk holds a pointer to the next chunk.
struct DataChunk {
	std::string text;
	DataChunk* nextChunk = nullptr; // Pointer to the next link in the chain
};

// 8. Returning New Creations from Functions
// If a function creates something large on the heap, return the address instead of copying.
int* generatePhysicsMatrix() {
	int* matrix = new int[500]; // Create array on heap
	// ... fill matrix with math ...
	return matrix; // Return the memory address pointer
}

// 9. The Self-Awareness Pointer (this)
// Inside every C++ class, `this` is a hidden pointer holding the address of the current object.
class Simulator {
private:
	int speed = 0;

public:
	void setSpeed(int speed) {
		// `this->speed` refers to the member variable owned by the class instance.
		// `speed` refers to the parameter passed into the function.
		this->speed = speed;
	}
};

// 10. Swapping Behaviors (Function Pointers)
// Functions live in memory too! A function pointer holds the address of a function.
int addNumbers(int a, int b) {
	return a + b;
}

void functionPointerExample() {
	// Pointer holding the address of any function taking (int, int) and returning int
	int (*mathOperation)(int, int) = &addNumbers;

	if (mathOperation != nullptr) {
		int result = mathOperation(5, 10);
		std::cout << "Function pointer result (5 + 10): " << result << std::endl;
	}
}

// ============================================================================
// PART 3: Main Execution Loop
// ============================================================================

int main() {
	std::cout << "=== C++ Fundamentals & Pointer Cheat Sheet ===" << std::endl;

	// Basic Pointer & Reference checks:
	std::cout << "Value of num: " << num << std::endl;
	std::cout << "Reference health (alias of num): " << health << std::endl;
	std::cout << "Pointer numsAddress: " << numsAddress << std::endl;

	Axis axisVal{10, 20};
	Calculate calc;
	calc.sum(axisVal);

	// 1st: Dynamic memory allocation on the heap
	int* a = new int;
	*a = 35;
	std::cout << "Address stored in a: " << a << std::endl;
	std::cout << "Value pointed to by *a: " << *a << std::endl;
	delete a; // Free memory allocated on heap

	// 2nd: Storing address of a local stack variable
	int something = 100;
	int* ptr = &something;
	std::cout << "Pointer address (ptr): " << ptr << std::endl;
	std::cout << "Value stored at ptr (*ptr): " << *ptr << std::endl;

	// Cheat Sheet Demos:
	spawnExample();
	nullptrExample();
	polymorphismExample();
	functionPointerExample();

	int* matrix = generatePhysicsMatrix();
	delete[] matrix; // Clean up returned array

	return 0;
}

