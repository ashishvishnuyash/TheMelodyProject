#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "..\parser\parser.h"

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_LIST,
} LiteralType;
// Define the Variable struct and use typedef for convenience

// Declare the head of the linked list
typedef struct Literal
{
    void *value;
    LiteralType type;
    struct{
        int count;
        struct Literal** elements;
    } List;

}Literal;

typedef struct Variable {
    char *name;
    Literal *value;
    struct Variable *next;  // Use 'struct Variable' here
} Variable;

typedef struct Function {
    char* name;
    ASTNode* body;
    char** parameters;
    int param_count;
    struct Function* next;
} Function;
typedef struct {
    Literal* value;
    int is_return;
} ReturnValue;

// Function to interpret an AST and return the result
Literal* interpret(ASTNode* node);

#endif /* INTERPRETER_H */