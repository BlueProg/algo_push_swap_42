/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:26:20 by mmole             #+#    #+#             */
/*   Updated: 2015/02/04 17:16:30 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
	
#include "libft/includes/libft.h"
#include "push_swap.h"
#include "stdlib.h"

// !!!

// Voir correction et gestion derror !

// !!!
#include <stdio.h>

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

void	ft_resolve(t_dlist **a, t_dlist **b)
{
	while (1)
	{
		if ((*a) && (*b) == NULL && ft_is_sort(a))
			return ;
		if ((*a) && (*a)->prev->val < (*a)->val)
		{
			ft_rotate_list(a);
			ft_putstr("ra");
		}
		else if ((*a) && (*a)->next->val < (*a)->val)
		{
			ft_s_inverse_list(a);
			ft_putstr("sa");
		}
		else if ((*b) && (*b)->prev->val > (*b)->val)
		{
			ft_rotate_list(b);
			ft_putstr("rb");
		}
		else if ((*b) && (*b)->next->val > (*b)->val)
		{
			ft_s_inverse_list(b);
			ft_putstr("sb");
		}
		else if (!ft_is_sort(a) || (*a)->val < (*b)->val)
		{
			ft_push_list(b, a);
			ft_putstr("pb");
		}
		else
		{
			ft_push_list(a, b);
			ft_putstr("pa");	
		}
		if (!((*a) && (*b) == NULL && ft_is_sort(a)))
			ft_putstr(" ");
	}
}

int	main(int argc, char **argv)
{
	t_dlist	*list;
	t_dlist	*tmp;
	t_dlist	*list2;

	list = NULL;
	list2 = NULL;
	if (argc > 1)
	{
		while (*++argv)
		{
			if (ft_atoi(*argv) != 0 || (*argv)[0] == '0')
				ft_add_elem(&list, ft_create_elem(ft_atoi(*argv)));
		}
		if (list == NULL)
			ft_putendl_fd("Give list integer format \"x x x\", thank you", 2);
	}
	else
		ft_putendl_fd("Give list integer format \"x x x\", thank you", 2);

	if (list)
	{
		ft_resolve(&list, &list2);
		// tmp = list->next;
		// while (tmp != list)
		// {
		// 	printf("elem: %d\n", tmp->prev->val);
		// 	tmp = tmp->next;
		// }
		// printf("elem: %d\n", tmp->prev->val);
	}

	
	// ft_putchar('\n');
	return (0);
}
