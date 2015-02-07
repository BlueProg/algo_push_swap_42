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
	// int i;
	// // t_dlist	*tmp;
	// // t_dlist *tmp2;

	// i = 0;
	while (1)
	{
		// if (i > 20)
		// 	return ;
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
		// printf("\nlist en resolve:\n");
		// tmp = (*a)->next;
		// while (tmp != (*a))
		// {
		// 	printf("elem: %d\n", tmp->prev->val);
		// 	tmp = tmp->next;
		// }
		// printf("elem: %d\n\n", tmp->prev->val);
		// if (*b)
		// {
		// 	tmp2 = (*b)->next;
		// 	while (tmp2 != (*b))
		// 	{
		// 		printf("elem2: %d\n", tmp2->prev->val);
		// 		tmp2 = tmp2->next;
		// 	}
		// 	printf("elem2: %d\n", tmp2->prev->val);
		// }
		// i++;
	}
}

int	main()
{
	t_dlist	*list;
	t_dlist	*tmp;
	t_dlist	*list2;

	list2 = NULL;
	list = ft_create_elem(42);
	// ft_add_elem(&list, ft_create_elem(10));
	// ft_add_elem(&list, ft_create_elem(32));
	// ft_add_elem(&list, ft_create_elem(7));
	// ft_add_elem(&list, ft_create_elem(32));
	// ft_add_elem(&list, ft_create_elem(2));
	// ft_add_elem(&list, ft_create_elem(64));
	// ft_add_elem(&list, ft_create_elem(8));
	
	list = ft_create_elem(2);
	ft_add_elem(&list, ft_create_elem(1));
	ft_add_elem(&list, ft_create_elem(3));
	ft_add_elem(&list, ft_create_elem(6));
	ft_add_elem(&list, ft_create_elem(5));
	ft_add_elem(&list, ft_create_elem(8));


	printf("list avant resolve:\n");
	tmp = list->next;
	while (tmp != list)
	{
		printf("elem: %d\n", tmp->prev->val);
		tmp = tmp->next;
	}
	printf("elem: %d\n", tmp->prev->val);

	ft_resolve(&list, &list2);
	ft_putchar('\n');
	return (0);
}
