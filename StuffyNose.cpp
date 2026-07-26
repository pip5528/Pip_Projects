#include <iostream>
// Learning C++ classes


class stuff {
    public:
        std::string stuffy;
        void nose() {
            printf("Stuffy nose\n");
        }
};

int main(void) {


// Class, object
stuff stuffy;
// object, member
stuffy.nose();

return 0;
}

