/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:32:41 by mmole             #+#    #+#             */
/*   Updated: 2015/02/06 16:34:41 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s_inverse_list(t_dlist **list)
{
	t_dlist	*tmp;
	int		val;

	tmp = *list;
	val = tmp->next->val;
	tmp->next->val = tmp->val;
	tmp->val = val;
}

void	ft_ss_list(t_dlist **list_a, t_dlist **list_b)
{
	ft_s_inverse_list(list_a);
	ft_s_inverse_list(list_b);
}

void	ft_pa_list(t_dlist **list_a, t_dlist **list_b)
{
	ft_add_elem(list_a, ft_pop_first(list_b));
}

void	ft_pb_list(t_dlist **list_a, t_dlist **list_b)
{
	ft_add_elem(list_b, ft_pop_last(list_a));
}