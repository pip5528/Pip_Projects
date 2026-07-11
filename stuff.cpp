#include <iostream>


int main(void) {

// Learning C++ and a bit of syntax threw me coming from C but I think I'm getting the hang of it! :D

struct baby {
  std::string name;
  int age;
};

baby b = {"Ben", 5};

std::cout << b.name << ", " << b.age << "\n";


return 0;
}
