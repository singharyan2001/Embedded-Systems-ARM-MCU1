#include <stdio.h>

int main() {
    char str[100];

    // Read characters until a newline is encountered
    printf("Enter a string: ");
    scanf("%[^\n]", str);

    // Print the string
    printf("You entered: %s\n", str);

    return 0;
}