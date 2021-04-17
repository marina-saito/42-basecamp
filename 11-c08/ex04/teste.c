/* Test for evaluation
-------------------------
cd ~/basecamp/11-c08/ex04
rm a.out
norminette ft_strs_to_tab.c ft_show_tab.c
gcc -Wall -Wextra -Werror teste.c ft_strs_to_tab.c ft_show_tab.c 
./a.out
-------------------------
*/

#include "ft_stock_str.h"
#include <stdio.h>

struct	s_stock_str *ft_strs_to_tab(int ac, char **av);
void	ft_show_tab(struct s_stock_str *par);

int main(void)
{
	char *strs[] = {"oi", "tudo", "bem", "?"};
	struct	s_stock_str *strs_to_tab = ft_strs_to_tab(4, strs);
	strs_to_tab[1].copy = "hehe";
	ft_show_tab(strs_to_tab);
	return (0);
}