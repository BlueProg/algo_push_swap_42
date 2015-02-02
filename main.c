/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:26:20 by mmole             #+#    #+#             */
/*   Updated: 2015/02/02 16:26:52 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "push_swap.h"
#include "stdlib.h"


#include <stdio.h>

t_dlist	*ft_create_list(int val)
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

void	ft_add_elem(t_dlist **list, int val)
{
	t_dlist	*new_elem;

	new_elem = (t_dlist *)malloc(sizeof(t_dlist));
	if (new_elem)
	{
		new_elem->val = val;
		(*list)->prev->next = new_elem;
		new_elem->prev = (*list)->prev;
		new_elem->next = *list;
		(*list)->prev = new_elem;	
	}
}

void	ft_delete_elem(t_dlist **elem)
{
	if ((*elem)->next == *elem && (*elem)->prev == (*elem))
	{
		free(*elem);
		return ;
	}		
		printf("cas1\n");
	(*elem)->prev->next = (*elem)->next;
	(*elem)->next->prev = (*elem)->prev;
	free(*elem);
}

int	main()
{
	t_dlist	*test;
	t_dlist	*tmp;

	test = ft_create_list(42);
	tmp = test;
	ft_delete_elem(&tmp);
	//tmp = test;
	printf("delete du dernier elements\n\n");

	//test = tmp->prev;
	printf("test: %d\n", tmp->val);

	// ft_add_elem(&test, 10);
	// printf("verif en sortie : list: %d, l-next: %d, l-prev: %d\n", test->val, test->next->val, test->prev->val);		
	// // printf("elem1: %d\n", test->val);
	// // printf("elem1: %d\n", test->next->val);
	// // test = test->next;
	// // printf("elem1: %d\n", test->val);
	// // printf("elem1: %d\n", test->next->val);
	// ft_add_elem(&test, 22);
	// printf("verif en sortie : list: %d, l-next: %d, l-prev: %d\n", test->val, test->next->val, test->prev->val);		
	// ft_add_elem(&test, 82);
	// printf("verif en sortie : list: %d, l-next: %d, l-prev: %d\n", test->val, test->next->val, test->prev->val);		
	// ft_add_elem(&test, 7);
	// printf("verif en sortie : list: %d, l-next: %d, l-prev: %d\n", test->val, test->next->val, test->prev->val);		
	// ft_add_elem(&test, 36);
	// printf("verif en sortie : list: %d, l-next: %d, l-prev: %d\n", test->val, test->next->val, test->prev->val);		
	// ft_add_elem(&test, 1);
	// printf("verif en sortie : list: %d, l-next: %d, l-prev: %d\n", test->val, test->next->val, test->prev->val);		
	// t_dlist	*tmp;
	// tmp = test->prev;

	// while (tmp != test)
	// {
	// 	printf("elem: %d\n", tmp->val);
	// 	tmp = tmp->prev;
	// }
	// printf("elem: %d\n", tmp->val);


	// ft_delete_elem(tmp);
	// printf("delete du dernier elements\n\n");

	// test = tmp->prev;
	// printf("test: %d\n", test->val);
	// tmp = test->prev;
	// printf("elem: %d, prev: %d, next: %d, test: %d\n", tmp->val, tmp->prev->val, tmp->next->val, test->val);
	// while (tmp != test)
	// {
	// 	printf("elem: %d\n", tmp->next->val);
	// 	tmp = tmp->prev;
	// }
	// printf("elem: %d\n", tmp->next->val);


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

