#ifndef __MONTY_H__
#define __MONTY_H__

/*Libraries*/
#include <stdio.h>    /*For any out in puts */

#include <unistd.h>  /*for display the function write */

#include <stdarg.h>   /*for argmnts */

#include <stdarg.h>   /*for argument after "..."*/

#include <limits.h>   /*for max byet no. */

#include <stdlib.h>

#include <string.h>     /* for startup */

#include <fcntl.h>      /* for functionality */

#include <sys/types.h>

#include <sys/stat.h>






/*all defs*/
#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"


/**************************************************************************/




/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;






/**************************************************************************/


/** .    _main.c  .  **/
int main(int argc, char **argv);


/* . _monty.c . */
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);







/* err_cal.c */
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);


/* err_emp */
int usage_error(void);
int malloc_error(void);


/* err_fun */
int no_int_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
int short_stack_error(unsigned int line_number, char *op);

/* err_op */
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
void set_op_tok_error(int error_code);










/* fn2_str.c */
char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);


/* fost.c */
char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);

int is_empty_line(char *line, char *delims);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);


/*l_free.c*/
void free_stack(stack_t **stack);

void free_tokens(void);


/*l_token.c*/

int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

unsigned int token_arr_len(void);







/* m_cal.c */
void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);


/* m_do */
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);


/* m_func.c */
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);


/* m_mon.c */
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);










#endif
