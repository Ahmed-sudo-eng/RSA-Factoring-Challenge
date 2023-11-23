#include <stdio.h>
#include <stdlib.h>

/**
 * main - a programe that factorizes numbers from a file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Success (0), Failure (1)
 */
int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	int number;
	int p, q;
	int n;
	int flag;

	if (argc != 2)
		exit(EXIT_FAILURE);
	
	stream = fopen(argv[1], "r");
	if (stream == NULL)
		exit(EXIT_FAILURE);

	while ((getline(&line, &len, stream)) != -1)
	{
		number = atoi(line);

		flag = 1;
		p = 1;
		while (p < number)
		{
			q = 1;
			while (q < number)
			{
				n = p * q;
				if (n == number)
				{
					printf("%d=%d*%d\n", n, p, q);
					flag = 0;
					break;
				}
				else
					q++;
			}
			if (flag == 0)
				break;
			p++;
		}
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
