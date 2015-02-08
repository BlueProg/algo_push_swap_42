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
#include "libft/includes/libft.h"

void	ft_s_inverse_list(t_dlist **list, int number)
{
	t_dlist	*tmp;
	int		val;

	tmp = *list;
	val = tmp->next->val;
	tmp->next->val = tmp->val;
	tmp->val = val;
	if (number == 1)
		ft_putstr("sa");
	else
		ft_putstr("sb");
}

void	ft_push_list(t_dlist **list_a, t_dlist **list_b, int number)
{
	ft_add_head_elem(list_a, ft_pop_first(list_b));
	if (number == 1)
		ft_putstr("pa");
	else
		ft_putstr("pb");
}
