/* Test for evaluation
-------------------------
cd ~/basecamp/11-c08/ex02
rm a.out
norminette -R CheckDefine ft_abs.h
gcc -Wall -Wextra -Werror ft_abs.h teste.c
./a.out
-------------------------
*/

#include "ft_abs.h"
#include <stdio.h>

int main()
{
	printf("%d\n", ABS(0));
	return (0);
}