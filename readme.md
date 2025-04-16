# Simple Compiler Project

A basic compiler implementation built with Flex and Bison, demonstrating fundamental compiler concepts.

## Overview

This project implements a simple compiler that supports:
- Variable declarations
- Basic arithmetic operations
- Value assignment
- Display statements

The compiler uses a symbol table to track variables and their values during execution.

## Project Structure

- `parser.y` - Bison grammar file defining the language syntax
- `lexer.l` - Flex lexical analyzer (tokenizer)
- `main.c` - Main program entry point

## Language Features

### Data Types
- Basic integer type (`mytype`)

### Statements
- Variable declaration: `mytype variable_name;`
- Assignment: `variable_name = expression;`
- Display: `show(variable_name);`
- Expression evaluation: `expression;`

### Expressions
- Arithmetic operations: `+`, `-`, `*`, `/`
- Parenthesized expressions
- Variables and numeric literals

## Building the Project

### Prerequisites
- Flex (Fast Lexical Analyzer)
- Bison (Parser Generator)
- C compiler (GCC recommended)

### Compilation Steps
```bash
flex lexer.l
bison -d parser.y
gcc lex.yy.c parser.tab.c main.c -o compiler