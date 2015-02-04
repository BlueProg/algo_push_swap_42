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

t_dlist	*ft_create_elem(int val)
{
	t_dlist	*newlist;

	newlist = (t_dlist *)malloc(sizeof(t_dlist));
	if (newlist)
	{
		newlist->val = val;
		newlist->prev = newlist;
		newlist->next = newlist;
	}
	return (newlist);
}

void	ft_add_elem(t_dlist **list, t_dlist *new_elem)
{
	(*list)->prev->next = new_elem;
	new_elem->prev = (*list)->prev;
	new_elem->next = *list;
	(*list)->prev = new_elem;
}

void	ft_delete_elem(t_dlist **elem)
{
	t_dlist	*tmp;

	tmp = *elem;
	(*elem)->prev->next = (*elem)->next;
	(*elem)->next->prev = (*elem)->prev;
	free(tmp);
	tmp = NULL;
}

t_dlist	*ft_pop_last(t_dlist **list)
{
	t_dlist	*tmp;
	t_dlist	*new_elem;

	tmp = (*list)->prev;
	new_elem = ft_create_elem(tmp->val);
	(*list)->prev = tmp->prev;
	(*list)->prev->next = (*list);
	free(tmp);
	tmp = NULL;
	return (new_elem);
}

int	main()
{
	t_dlist	*list;
	t_dlist	*tmp;
	t_dlist	*list2;
	t_dlist	*tmp2;

	list = ft_create_elem(42);
	list2 = NULL;
	ft_add_elem(&list, ft_create_elem(10));
	ft_add_elem(&list, ft_create_elem(23));

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
		printf("tmp2: %d, list2: %d\n", tmp2->val, list2->val);
		while (tmp2 != list2)
		{
			printf("elem: %d\n", tmp2->prev->val);
			tmp2 = tmp2->next;
		}
		printf("elem: %d\n", tmp2->prev->val);		
	}
	return (0);
}
/*
	stocker les elements dans le bon ordre.
	pour inverser facilement le 1er et le dernier element, les listes rotatives sont plus adaptées.

*/

// 2 1 3 6 5 8
// 1 2 3 6 5 8

// 6 5 8
// 3 2 1

// 5 6 8
// 3 2 1

// 1 2 3 5 6 8

