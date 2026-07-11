#include <stdio.h>

constexpr int max_items = 1'000'000;      // constexpr + digit separators
constexpr int flags = 0b1010'1100;        // binary literals (also new in C23)

enum Color : int { RED, GREEN, BLUE };    // enum with a fixed underlying type

[[nodiscard]] int add(int a, int b) {
    return a + b;
}

int main(void) {
    auto x = 42;                          // auto type inference
    auto name = "Sam";                     // auto deduces char[4] here
    bool ready = true;                     // bool/true/false now keywords, no stdbool.h needed

    int *ptr = nullptr;                    // nullptr keyword

    enum Color c = GREEN;

    [[maybe_unused]] int scratch = 7;      // silences unused-variable warnings

    printf("max_items = %d, flags = %d\n", max_items, flags);
    printf("x = %d, name = %s, ready = %d\n", x, name, ready);
    printf("ptr is %s\n", ptr == nullptr ? "null" : "not null");
    printf("color = %d\n", c);

    int sum = add(3, 4);
    printf("sum = %d\n", sum);

    add(1, 2);                             // discarding a [[nodiscard]] result: should warn

    return 0;
}
