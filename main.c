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


#include <stdio.h>

int	main()
{
	t_dlist	*list;
	t_dlist	*tmp;
	t_dlist	*list2;
	t_dlist *tmp2;

	list2 = NULL;
	list = ft_create_elem(42);
	ft_add_elem(&list, ft_create_elem(10));
	ft_add_elem(&list, ft_create_elem(32));
	ft_add_elem(&list, ft_create_elem(7));
	ft_add_elem(&list, ft_create_elem(32));
	ft_add_elem(&list, ft_create_elem(2));
	ft_add_elem(&list, ft_create_elem(64));
	ft_add_elem(&list, ft_create_elem(8));

	printf("list1:\n");
	tmp = list->next;
	while (tmp != list)
	{
		printf("elem: %d\n", tmp->prev->val);
		tmp = tmp->next;
	}
	printf("elem: %d\n", tmp->prev->val);

	printf("list2:\n");
	if (list2)
	{
		tmp2 = list->next;

		while (tmp2 != list)
		{
			printf("elem: %d\n", tmp2->prev->val);
			tmp2 = tmp->next;
		}
		printf("elem: %d\n", tmp2->prev->val);		
	}

	list2 = ft_pop_last(&list);
	ft_add_elem(&list2, ft_pop_last(&list));
	ft_add_elem(&list2, ft_pop_last(&list));
	ft_add_elem(&list2, ft_pop_last(&list));
	printf("list1:\n");
	tmp = list->next;
	while (tmp != list)
	{
		printf("elem: %d\n", tmp->prev->val);
		tmp = tmp->next;
	}
	printf("elem: %d\n", tmp->prev->val);

	printf("list2:\n");
	if (list2)
	{
		tmp2 = list2->next;
		while (tmp2 != list2)
		{
			printf("elem: %d\n", tmp2->prev->val);
			tmp2 = tmp2->next;
		}
		printf("elem: %d\n", tmp2->prev->val);		
	}

	ft_multi_rotate_list(&list, &list2);
	printf("MULTIROTATE\nlist1:\n");
	tmp = list->next;
	while (tmp != list)
	{
		printf("elem: %d\n", tmp->prev->val);
		tmp = tmp->next;
	}
	printf("elem: %d\n", tmp->prev->val);

	printf("list2:\n");
	if (list2)
	{
		tmp2 = list2->next;
		while (tmp2 != list2)
		{
			printf("elem: %d\n", tmp2->prev->val);
			tmp2 = tmp2->next;
		}
		printf("elem: %d\n", tmp2->prev->val);		
	}
	return (0);
}
