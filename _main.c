#include "monty.h"


char **op_toks = NULL;

/**
 * main - Monty Interp entry point
 *
 * @argc: z cont o arguments passed to the program
 * @argv: pointer 2 arr o char pointers to arguments
 *
 * Return: (EXIT_SUCCESS) f success, (EXIT_FAILURE) f error
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_error(argv[1]));
	exit_code = run_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
