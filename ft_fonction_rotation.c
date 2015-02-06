/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:36:44 by mmole             #+#    #+#             */
/*   Updated: 2015/02/06 16:37:01 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_list(t_dlist **list)
{
	*list = (*list)->next;
}

void	ft_multi_rotate_list(t_dlist **list_a, t_dlist **list_b)
{
	*list_a = (*list_a)->next;
	*list_b = (*list_b)->next;
}

void	ft_inverse_rotate_list(t_dlist **list)
{
	*list = (*list)->prev;
}

void	ft_inverse_multi_rotate_list(t_dlist **list_a, t_dlist **list_b)
{
	*list_a = (*list_a)->prev;
	*list_b = (*list_b)->prev;
}
