#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // For defining buffer sizes if needed

// Define a reasonable maximum size for our buffers
#define BUFFER_SIZE 128

/**
 * @brief Safely copies a source string to a destination buffer.
 * 
 * Uses snprintf for bounds checking instead of strcpy().
 * 
 * @param dest The destination buffer.
 * @param src The source string.
* @param size The maximum size of the destination buffer.
 */
void safe_strcpy(char *dest, const char *src, size_t size) {
    // snprintf returns the number of characters that WOULD have been written, 
    // including null terminator for strings.
    int result = snprintf(dest, size, "%s", src);

    if (result < 0 || (size_t)result >= size) {
        fprintf(stderr, "Error: Source string too long or buffer operations failed.\n");
        // Ensure destination is null-terminated even on failure
        dest[size - 1] = '\0'; 
    } else {
        printf("Successfully copied \"%s\" to the buffer.\n", src);
    }
}

/**
 * @brief Safely concatenates source strings into a provided destination buffer.
 * 
 * Uses snprintf() multiple times or careful length checks. Building piece-by-piece 
 * is safer than direct concatenation with unconstrained functions.
 * 
 * @param dest The destination buffer (must be large enough!).
 * @param max_size The maximum size of the destination buffer.
 * @param part1 First string segment.
 * @param part2 Second string segment.
 */
void safe_strcat(char *dest, size_t max_size, const char *part1, const char *part2) {
    if (max_size < 2 || !dest || !part1 || !part2) {
        fprintf(stderr, "Error: Invalid arguments or buffer too small.\n");
        return;
    }

    // 1. Start by resetting the destination to an empty string if we are repurposing it
    strncpy(dest, "", max_size-1); 
    
    // 2. Append part1 safely
    if (snprintf(dest, max_size, "%s", part1) >= max_size) {
        fprintf(stderr, "Error: Could not fit Part 1.\n");
        return;
    }

    // Calculate remaining space for Part 2 (minus null terminator safety margin)
    int remaining_space = snprintf(NULL, 0, "%s", part2) + 1; // Get length of part2 including '\0' if it were the only thing
    
    if (strlen(dest) + strlen(part2) + 1 > max_size) {
        fprintf(stderr, "Error: Concatenation would overflow buffer size %zu.\n", max_size);
        return;
    }

    // Append part2 safely
    snprintf(dest + strlen(dest), max_size - strlen(dest), "%s", part2);
    printf("Successfully appended \"%s\" and \"%s\" to the buffer.\n", part1, part2);
}


/**
 * @brief Safely builds a formatted string using snprintf.
 * 
 * This is the primary replacement for sprintf().
 * 
 * @param output Buffer where the result will be written.
 * @param size Size of the output buffer.
 * @param format The formatting string (e.g., "Value: %s, Count: %d").
 * @param ... Arguments to substitute into the format string.
 */
void safe_sprintf(char *output, size_t size, const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Use vsnprintf for variable arguments and bounds checking
    int chars_written = vsnprintf(output, size, format, args);

    if (chars_written < 0) {
        perror("vsnprintf failed");
        return;
    } else if ((size_t)chars_written >= size) {
        fprintf(stderr, "Warning: Buffer overflow risk! Output truncated to %zu bytes.\n", size - 1);
    } else {
        // Print the actual result for confirmation
        printf("Successfully formatted string: %s\n", output);
    }

    va_end(args);
}


int main() {
    char destination[BUFFER_SIZE];
    const char *user = "Alice";
    const char *subject = "development";
    int year = 2024;

    printf("========================================\n");
    printf("Demonstrating Safe C String Handling (snprintf)\n");
    printf("========================================\n");


    /* --- Test 1: Safe Copying --- */
    printf("\n--- Testing safe_strcpy ---\n");
    safe_strcpy(destination, user, BUFFER_SIZE);

    /* --- Test 2: Safe Concatenation --- */
    printf("\n--- Testing safe_strcat ---\n");
    // The buffer must be large enough to hold the combined content + null terminator
    safe_strcat(destination, BUFFER_SIZE, "My Profile:", " ");


    /* --- Test 3: Safe Formatting (Replacement for sprintf) --- */
    printf("\n--- Testing safe_sprintf ---\n");
    // Construct a full report string safely
    safe_sprintf(destination, BUFFER_SIZE, 
                  "User %s started work on the %s project in %d.", 
                  user, subject, year);

    /* --- Test 4: Intentional Overflow Check (Demonstrates Safety) --- */
    printf("\n--- Testing Buffer Overflow Prevention ---\n");
    char tiny_buffer[10];
    const char *long_string = "This string is deliberately much too long to fit.";
    // This call will print an error message and NOT write garbage/overflow.
    safe_strcpy(tiny_buffer, long_string, sizeof(tiny_buffer));

    return 0;
}

/*
To Compile and Run on Linux:
1. Save the code as SafeStrings.c
2. Compile using gcc (linking math or other libraries if used, but not here):
   $ gcc -std=c99 -Wall -Wextra SafeStrings.c -o safe_strings
3. Run:
   $ ./safe_strings
*/
