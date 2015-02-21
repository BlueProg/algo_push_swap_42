/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:26:20 by mmole             #+#    #+#             */
/*   Updated: 2015/02/21 18:24:12 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "push_swap.h"
#include "stdlib.h"
#include <unistd.h>

int		ft_is_sort(t_dlist **a)
{
	t_dlist	*tmp;

	tmp = (*a)->next;
	while (tmp != *a)
	{
		if (tmp->prev->val > tmp->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_print_list(t_dlist **a, t_dlist **b)
{
	t_dlist *l1;
	t_dlist *l2;

	l1 = (*a)->next;
	ft_putstr("List1 : ");
	while (l1 != *a)
	{
		ft_putstr(ft_itoa(l1->prev->val));
		write(1, " ", 1);
		l1 = l1->next;
	}
	ft_putendl(ft_itoa(l1->prev->val));
	if (b && *b)
	{
		l2 = (*b)->next;
		ft_putstr("List2 : ");
		while (l2 != *b)
		{
			ft_putstr(ft_itoa(l2->prev->val));
			write(1, " ", 1);
			l2 = l2->next;
		}
		ft_putendl(ft_itoa(l2->prev->val));
	}
}

void	ft_next_resolve(t_dlist **a, t_dlist **b)
{
	if ((*a) && (*a)->prev->val < (*a)->val)
		ft_rotate_list(a, 1);
	else if ((*a) && (*a)->next->val < (*a)->val)
		ft_s_inverse_list(a, 1);
	else if ((*b) && (*b)->prev->val > (*b)->val)
		ft_rotate_list(b, 2);
	else if ((*b) && (*b)->next->val > (*b)->val)
		ft_s_inverse_list(b, 2);
	else if (!ft_is_sort(a) || (*a)->val < (*b)->val)
		ft_push_list(b, a, 2);
	else
		ft_push_list(a, b, 1);
}

void	ft_resolve(t_dlist **a, t_dlist **b, int optionv)
{
	int		sort;

	sort = 0;
	while (1)
	{
		if ((*a) && (*b) == NULL && ft_is_sort(a))
			break ;
		sort = 1;
		ft_next_resolve(a, b);
		if (!((*a) && (*b) == NULL && ft_is_sort(a)))
		{
			if (optionv != 1)
				ft_putchar(' ');
			else
				ft_putchar('\n');
		}
		if (optionv == 1)
			ft_print_list(a, b);
	}
	if (sort == 1)
		ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	t_dlist	*list;
	t_dlist	*list2;
	int		optionv;

	list = NULL;
	list2 = NULL;
	optionv = 0;
	if (argc == 1)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	if (ft_parse_data(argv, &list, &optionv))
		return (0);
	if (argc > 1 && ft_check_double(list))
		return (0);
	if (list)
		ft_resolve(&list, &list2, optionv);
	return (0);
}
