#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Added this include for string functions
#include "parser.tab.h"

// External declarations
extern FILE* yyin;
extern int yyparse(void);

// Token list structure from lexer
typedef struct TokenNode {
    char* token;
    char* type;
    struct TokenNode* next;
} TokenNode;

extern TokenNode* token_list;

// Function to print tokens by category
void print_token_list() {
    printf("\n==Token List==\n");
    
    // Create arrays for each category
    char* preprocessor[100] = {0};
    char* keywords[100] = {0};
    char* identifiers[100] = {0};
    char* operators[100] = {0};
    char* literals[100] = {0};
    char* punctuation[100] = {0};
    
    int p_count = 0, k_count = 0, i_count = 0, o_count = 0, l_count = 0, punct_count = 0;
    
    // Categorize tokens
    TokenNode* current = token_list;
    while (current) {
        if (strcmp(current->type, "Preprocessor Directive") == 0) {
            preprocessor[p_count++] = current->token;
        } else if (strcmp(current->type, "Header File") == 0) {
            preprocessor[p_count++] = current->token;
        } else if (strcmp(current->type, "Keyword") == 0) {
            // Check if keyword already exists
            int exists = 0;
            for (int j = 0; j < k_count; j++) {
                if (strcmp(keywords[j], current->token) == 0) {
                    exists = 1;
                    break;
                }
            }
            if (!exists) {
                keywords[k_count++] = current->token;
            }
        } else if (strcmp(current->type, "Identifier") == 0) {
            // Check if identifier already exists
            int exists = 0;
            for (int j = 0; j < i_count; j++) {
                if (strcmp(identifiers[j], current->token) == 0) {
                    exists = 1;
                    break;
                }
            }
            if (!exists) {
                identifiers[i_count++] = current->token;
            }
        } else if (strstr(current->type, "Operator") != NULL) {
            // Check if operator already exists
            int exists = 0;
            for (int j = 0; j < o_count; j++) {
                if (strcmp(operators[j], current->token) == 0) {
                    exists = 1;
                    break;
                }
            }
            if (!exists) {
                char description[100];
                if (strcmp(current->token, "=") == 0) {
                    operators[o_count++] = "= (assignment)";
                } else if (strcmp(current->token, "+") == 0) {
                    operators[o_count++] = "+ (addition)";
                } else if (strcmp(current->token, ",") == 0) {
                    operators[o_count++] = ", (comma, separator)";
                } else {
                    operators[o_count++] = current->token;
                }
            }
        } else if (strstr(current->type, "Literal") != NULL) {
            // Check if literal already exists
            int exists = 0;
            for (int j = 0; j < l_count; j++) {
                if (strcmp(literals[j], current->token) == 0) {
                    exists = 1;
                    break;
                }
            }
            if (!exists) {
                if (strstr(current->type, "String") != NULL) {
                    char description[100];
                    sprintf(description, "%s (string)", current->token);
                    literals[l_count++] = strdup(description);
                } else if (strstr(current->type, "Integer") != NULL) {
                    char description[100];
                    sprintf(description, "%s (integer)", current->token);
                    literals[l_count++] = strdup(description);
                } else {
                    literals[l_count++] = current->token;
                }
            }
        } else if (strcmp(current->type, "Punctuation") == 0) {
            // Check if punctuation already exists
            int exists = 0;
            for (int j = 0; j < punct_count; j++) {
                if (strcmp(punctuation[j], current->token) == 0) {
                    exists = 1;
                    break;
                }
            }
            if (!exists) {
                if (strcmp(current->token, "(") == 0 || strcmp(current->token, ")") == 0) {
                    punctuation[punct_count++] = "() (parentheses)";
                } else if (strcmp(current->token, "{") == 0 || strcmp(current->token, "}") == 0) {
                    punctuation[punct_count++] = "{} (curly braces)";
                } else if (strcmp(current->token, ";") == 0) {
                    punctuation[punct_count++] = "; (semicolon)";
                } else if (strcmp(current->token, ",") == 0) {
                    punctuation[punct_count++] = ", (comma, in variable declarations)";
                } else {
                    punctuation[punct_count++] = current->token;
                }
            }
        }
        
        current = current->next;
    }
    
    // Print tokens by category
    if (p_count > 0) {
        printf("=Preprocessor Directive:=\n");
        for (int i = p_count - 1; i >= 0; i--) {
            printf("%s\n", preprocessor[i]);
        }
    }
    
    if (k_count > 0) {
        printf("=Keywords:=\n");
        for (int i = 0; i < k_count; i++) {
            printf("%s\n", keywords[i]);
        }
    }
    
    if (i_count > 0) {
        printf("=Identifiers:=\n");
        for (int i = 0; i < i_count; i++) {
            printf("%s\n", identifiers[i]);
        }
    }
    
    if (o_count > 0) {
        printf("=Operators:=\n");
        for (int i = 0; i < o_count; i++) {
            printf("%s\n", operators[i]);
        }
    }
    
    if (l_count > 0) {
        printf("=Literals:=\n");
        for (int i = 0; i < l_count; i++) {
            printf("%s\n", literals[i]);
        }
    }
    
    if (punct_count > 0) {
        printf("=Punctuation/Symbols:=\n");
        for (int i = 0; i < punct_count; i++) {
            printf("%s\n", punctuation[i]);
        }
    }
}

int main(int argc, char **argv) {
    // Check if a file was provided
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Cannot open file %s\n", argv[1]);
            return 1;
        }
        // Set flex to read from file
        yyin = file;
    }
    
    // Parse the input
    yyparse();
    
    // Print token list
    print_token_list();
    
    // Clean up
    if (argc > 1) {
        fclose(yyin);
    }
    
    return 0;
}