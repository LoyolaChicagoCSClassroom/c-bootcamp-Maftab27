#include "token.h"
#include <stdlib.h>
#include <string.h>

// create a token
token_t *create_token(token_type_t type, const char *text) {
    token_t *token = (token_t *)malloc(sizeof(token_t));
    if (token == NULL) {
        return NULL; // Memory allocation failed
    }

    token->type = type;
    token->text = strdup(text);
    if (token->text == NULL) {
        free(token);
        return NULL; // Memory allocation failed
    }

    return token;
}

// destroy a token
void destroy_token(token_t *token) {
    if (token != NULL) {
        free(token->text);
        free(token);
    }
}
