/*
 * Program Demonstrating Differences Between K&R C and ANSI C
 * -------------------------------------------------------------
 * This conceptual program illustrates key differences in language features
 * between the original K&R C and later standards (ANSI/ISO C).
 */

#include <stdio.h>
#include <stdlib.h>

// Assume we are simulating compiler behavior for demonstration purposes

/*
 * 1. Variable Declaration Scope:
 *    - In K&R C, variables could be declared anywhere before use, potentially leading
 *      to ambiguous scope rules.
 *    - ANSI/ISO C (and modern C) require all variables to be declared at the start of
 *      a block or function scope before they are used.
 */

void k_and_r_style_example() {
    // K&R allowed this structure: declaration after use
    /* int x; // If we were truly compiling with old rules, local declarations were tricky */
    int a = 10;

    printf("--- K&R Style Concept (Modern C interpretation assumed) ---\\n");
    printf("Variable 'a' declared and used correctly.\\n");
}

/*
 * 2. Function Prototypes:
 *    - Early K&R often omitted explicit return types in prototypes, relying on convention or context.
 *    - ANSI C standardized and strongly recommends function prototypes for all functions to enforce correct linkage and usage.
 */
int add(int b); // Explicit prototype (Best practice since ANSI C)

void k_and_r_vs_ansi() {
    printf("\\n--- Function Prototype Example ---\\n");
    // In modern C, the function signature must match the prototype defined above.
    int result = add(5);
    printf("Result of addition (using standard prototypes): %d\\n", result);
}

/*
 * 3. Variable Length Arrays (VLAs):
 *    - VLAs were an extension that became common but are not part of the core C99 standard,
 *      though many compilers support them by default. Their formal status changed over time.
 */
void vla_example() {
    printf("\\n--- Variable Length Arrays Example ---\\n");
    int size = 5;
    // This is conceptually valid in C99 and later, but was not guaranteed in early standards.
    int array[size];

    for (int i = 0; i < size; ++i) {
        array[i] = i * 2;
    }
    printf("Successfully created an array of size %d.\\n", size);
}


// Function implementation adhering to modern standards
int add(int b) {
    // Here we demonstrate using a variable declared at the start of the function scope. (ANSI/ISO standard)
    int initial_value = 5;
    return initial_value + b;
}

int main() {
    printf("==============================================\\n");
    printf("   C Standard Evolution Demo Start          \\n");
    printf("==============================================\\n");

    k_and_r_style_example();
    k_and_r_vs_ansi();
    vla_example();

    printf("\\n==============================================\\n");
    printf("   Demo Complete. Note: Modern compilers enforce the stricter ANSI standard.\\n");
    printf("==============================================\\n");

    return 0;
}
