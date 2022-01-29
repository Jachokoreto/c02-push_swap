#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**input;
	t_list	*stack;

	if (argc < 2)
		exit_error("Run ./push_swap 5 2 3 1");
	
	printf("number of input: %d\n", argc);
	printf("input: %s\n", argv[1]);

	input = ft_split(argv[1],' ');
	stack = init_stack(input);
	display_stack(stack);

	ft_lstclear(&stack, &free);
	return (0);
}

