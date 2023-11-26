#include <stdio.h>
#include <time.h>
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
	clock_t begin, end;
	double time_spent;
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	long int number;
	long int p, q, n;
	int flag;

	begin = clock();
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
			while (q <= (number / 2))
			{
				n = p * q;
				if (n == number)
				{
					printf("%ld=%ld*%ld\n", n, p, q);
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

	end = clock();
	time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
	printf("time spent: %f\n", time_spent);
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
