#ifndef PARSER_H
#define PARSER_H

#include "..\tokenizer\tokenizer.h"



// AST node types
typedef enum {
    AST_NUMBER,
    AST_BINARY_OP,
    AST_UNARY_OP,
    AST_COMPARISON,
    AST_LOGICAL_OP,
    AST_IDENTIFIER,
    AST_ASSIGNMENT,
} ASTNodeType;

// AST node structure
typedef struct ASTNode {
    ASTNodeType type;
    union {
        int number;
        struct {
            struct ASTNode* left;
            TokenType op;
            struct ASTNode* right;
        } binary_op;
        struct {
            TokenType op;
            struct ASTNode* operand;
        } unary_op;
        
        //identifier
        char* identifier;
        // assignment, variable, function call, etc.
        
        struct {
            struct ASTNode* left;
            TokenType op;
            struct ASTNode* right;
        } assignment_op;
     
    } data;
} ASTNode;

// Function to parse an expression and create an AST
ASTNode* parse_expression(Token** tokens);

// Function to free memory allocated for an AST
void free_ast(ASTNode* node);

#endif /* PARSER_H */