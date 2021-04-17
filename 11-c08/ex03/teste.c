/* Test for evaluation
-------------------------
cd ~/basecamp/11-c08/ex03
rm a.out
norminette ft_point.h
gcc -Wall -Wextra -Werror ft_point.h teste.c
./a.out
-------------------------
*/

#include "ft_point.h"
#include <stdio.h>

void set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int main(void)
{
	t_point point;
	set_point(&point);
	printf("%d %d\n", point.x, point.y);
	return (0);
}