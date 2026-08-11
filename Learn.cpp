
// 2 or 4 bytes!
// has a an address in memory!
int num = 100;

// health nickname of num
// we've basically created a read only version of num that's not a copy but a reference, reflection of you in the mirror is not a copy of you it's literally you that can be used to shave as data paramiter
int& health = num;

// the address that num is stored at in memory!
// i think you can's say an int = ptr that's why use & not sure of course
int* numsAddress = &num;

// structure
// type mansegment and clean architect
struct Axis {
	// why assign a value 0
	// IMPORTAMT for garbage control and safety
	int x = 0;
	int y = 0;
};

// Standard class
class Calculate {

private:
public:
	void sum(const Axis& numbers);
};

// Axis &numbers --> in memory(RAM) go in the address that Axis(x and y) is stored at get what is inside with the nickname od numbers
// no copy -- it's ;literally x and y but has nickname
void sum(const Axis& numbers) {
	int total = numbers.x + numbers.y;
};

// the other shit that i have no still fully understood

//1th
int* a = new int;
*a = 35;
std::cout << a;
delete a;

//2th
int something = 100;
int* ptr = &something

		   // you wanna cout the ptr instead of cout &something
		   std::cout
	   << ptr;
