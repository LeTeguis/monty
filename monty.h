#ifndef H_MONTY_H
#define H_MONTY_H

#define  _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

#define OPCODE_SIZE 2

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct Argument - argument
 * @argc: number of argument
 * @argv: list of argument
 * @passed: erreur
 */
typedef struct Argument
{
	size_t passed;
	int argc;
	char **argv;
} Argument;

extern instruction_t instructions[OPCODE_SIZE];
extern stack_t *stack_;
extern int value;
extern Argument _argument;

int printferr(int erreur, char *message, char *sup);
int _strcmp(char *s1, char *s2);

int isMontyFile(char *filename);

int _free(char **arg);
char **_getline_arg(FILE *file, int *arc);

void defineInstruction(void);
void setInstruction(int index, char *opcode,
		void (*f)(stack_t **stack, unsigned int line_number));
int argumentCorrect(char *nom, int nbr_param);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif
