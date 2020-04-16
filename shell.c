#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
/**
 * myhandler - handles signl Ctl+c
 * @mysignal: atribute not used
 * Return: void
 */
void myhandler(int mysignal)
{
	(void)mysignal;

	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * main - Shell command line interpreter
 * @ac: argument counter for user input
 * @av: arguments input by user
 * Return: 0 on success
 */
int main(int ac, __attribute__((unused))char **av)
{
	char *line = NULL;
	size_t len = 0;
	char charcount = NULL;

	if (ac != 1)
	{
		exit(127);
	}
	signal(SIGINT, myhandler);
	do {
		printf("$ ");
		charcount = getline(&line, &len, stdin);
		printf("%s", line);
	} while (charcount != -1);
	free(line);
	return (0);
}
