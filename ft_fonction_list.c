/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:58:24 by mmole             #+#    #+#             */
/*   Updated: 2015/02/06 15:58:55 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <string.h>

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
	if (*list == NULL)
		*list = new_elem;
	else
	{
		(*list)->prev->next = new_elem;
		new_elem->prev = (*list)->prev;
		new_elem->next = *list;
		(*list)->prev = new_elem;
	}
}

void	ft_add_head_elem(t_dlist **list, t_dlist *new_elem)
{
	if (*list == NULL)
		*list = new_elem;
	else
	{
		(*list)->prev->next = new_elem;
		new_elem->prev = (*list)->prev;
		new_elem->next = *list;
		(*list)->prev = new_elem;
		(*list) = new_elem;
	}
}

t_dlist	*ft_pop_first(t_dlist **list)
{
	t_dlist	*tmp;
	t_dlist	*new_elem;

	tmp = (*list);
	new_elem = ft_create_elem(tmp->val);
	(*list) = (*list)->next;
	(*list)->prev = tmp->prev;
	(*list)->prev->next = (*list);
	if ((*list) == tmp)
		(*list) = NULL;
	free(tmp);
	tmp = NULL;
	return (new_elem);
}
