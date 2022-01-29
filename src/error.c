#include "push_swap.h"

void exit_error(char *msg)
{
	ft_putendl_fd("Error\n", 1);
	ft_putendl_fd(msg, 1);
	exit (1);	
}