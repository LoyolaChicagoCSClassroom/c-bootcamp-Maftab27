#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

#define MAX_LINE_LENGTH 1024

// Classify token based on text
token_type_t classify_token(const char *text) {
    // Basic checks to classify token type
    if (text == NULL || *text == '\0') {
        return WORD;
    }

    // Check for numbers
    char *endptr;
    strtod(text, &endptr);
    if (*endptr == '\0') {
        return NUMBER;
    }

    // Check for operators
    if (strlen(text) == 1 && strchr("+-*/", *text) != NULL) {
        return OPERATOR;
    }

    // Check for symbols
    if (strlen(text) == 1 && strchr(":", ';') != NULL) {
        return SYMBOL;
    }

    // Default to word
    return WORD;
}

int main() {
    char input[MAX_LINE_LENGTH];

    // Read line by line
    while (fgets(input, sizeof(input), stdin) != NULL) {
        // Tokenize the input
        char *token_text = strtok(input, " \t\n");
        while (token_text != NULL) {
            // Classify token type
            token_type_t token_type = classify_token(token_text);

            // Create and output token
            token_t *token = create_token(token_type, token_text);
            if (token != NULL) {
                printf("Type: %d, Text: %s\n", token->type, token->text);
                destroy_token(token);
            }

            // Get next token
            token_text = strtok(NULL, " \t\n");
        }
    }

    return 0;
}
