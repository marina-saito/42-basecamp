/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 00:09:51 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/03 13:06:16 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_swap(int *a, int *b);
void quick_sort(int *tab, int left, int right);
int organize_around_pivot(int *tab, int left, int right);

void	ft_sort_int_tab(int *tab, int size)
{
	int left;
	int right;

	left = 0;
	right = size - 1;
	quick_sort(tab, left, right);
}

void	quick_sort(int *tab, int left, int right)
{
	int index_split;

	index_split = organize_around_pivot(tab, left, right);
	if (index_split > left)
	{
		quick_sort(tab, left, index_split - 1);
	}
	if (index_split < right)
	{
		quick_sort(tab, index_split, right);
	}
}

int		organize_around_pivot(int *tab, int left, int right)
{
	int pivot;
	int *ptr_left;
	int *ptr_right;

	pivot = (*(tab + left) + *(tab + right)) / 2;
	while (left < right)
	{
		ptr_left = tab + left;
		ptr_right = tab + right;
		while (*ptr_left < pivot)
		{
			ptr_left = tab + ++left;
		}
		while (*ptr_right > pivot)
		{
			ptr_right = tab + --right;
		}
		if (left <= right)
		{
			ft_swap(ptr_left, ptr_right);
			left++;
			right--;
		}
	}
	return (left);
}

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
