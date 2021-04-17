/* Test for evaluation
-------------------------
cd ~/basecamp/11-c08/ex01
rm a.out
norminette -R CheckDefine ft_boolean.h
gcc -Wall -Wextra -Werror ft_boolean.h teste.c
./a.out
-------------------------
*/

#include "ft_boolean.h"

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

t_bool ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

int main(int argc, char **argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
	return (SUCCESS);
}