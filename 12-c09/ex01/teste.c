/* Test for evaluation
-------------------------
cd ~/basecamp/12-c09/ex01
rm a.out
gcc -Wall -Wextra -Werror teste.c -L. -lft
./a.out
-------------------------
*/

void	ft_putstr(char *str);

int main(void)
{
	ft_putstr("oi\n");
	return (0);
}