#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
		exit_error("Run ./push_swap 5 2 3 1")
	
	printf("number of input: %d\n", argc);
	printf("input: %s\n", argv[1]);
	return (0);
}