#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold variable information
typedef struct {
    char name[20];
    int value;
} Variable;

// Define an array to store variables
Variable variables[100];
int num_variables = 0;

// Function to define a variable
void define_variable(char *name, int value) {
    for (int i = 0; i < num_variables; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            variables[i].value = value;
            return;
        }
    }
    // Variable not found, add it
    strcpy(variables[num_variables].name, name);
    variables[num_variables].value = value;
    num_variables++;
}

// Function to get the value of a variable
int get_variable(char *name) {
    for (int i = 0; i < num_variables; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return variables[i].value;
        }
    }
    printf("Error: Variable '%s' not found.\n", name);
    exit(1);
}

// Function to define a constant (just a wrapper for define_variable)
void define_constant(char *name, int value) {
    define_variable(name, value);
}

// Example operations to evaluate boolean expressions
int is_true(int value) {
    return value != 0;
}

int is_false(int value) {
    return value == 0;
}

// Example logical operators
int logical_and(int a, int b) {
    return a && b;
}

int logical_or(int a, int b) {
    return a || b;
}

int logical_not(int value) {
    return !value;
}

// Example comparison operators
int equal(int a, int b) {
    return a == b;
}

int not_equal(int a, int b) {
    return a != b;
}

int greater_than(int a, int b) {
    return a > b;
}

int less_than(int a, int b) {
    return a < b;
}

// Example if-else statement
void conditional_example(int value) {
    if (value > 0) {
        printf("%d is positive\n", value);
    } else if (value < 0) {
        printf("%d is negative\n", value);
    } else {
        printf("%d is zero\n", value);
    }
}

// Example while loop
void while_loop_example(int n) {
    while (n > 0) {
        printf("%d ", n);
        n--;
    }
    printf("\n");
}

// Example function declaration and definition
int add(int a, int b) {
    return a + b;
}

// Example function with parameters and return value
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Example REPL (Read-Eval-Print Loop)
void repl() {
    char input[100];
    while (1) {
        printf(">> ");
        fgets(input, sizeof(input), stdin);
        // Tokenize input and interpret FORTH commands here
        printf("Command executed: %s\n", input);
    }
}

int main() {
    // Example usage
    define_variable("x", 5);
    printf("Value of x: %d\n", get_variable("x"));

    define_constant("PI", 3.14);
    printf("Value of PI: %f\n", get_variable("PI"));

    conditional_example(10);
    while_loop_example(5);

    printf("Addition result: %d\n", add(3, 4));
    printf("Maximum value: %d\n", max(8, 6));

    // Start the REPL
    repl();

    return 0;
}
