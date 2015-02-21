/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:36:44 by mmole             #+#    #+#             */
/*   Updated: 2015/02/21 18:25:26 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

void	ft_rotate_list(t_dlist **list, int number)
{
	*list = (*list)->next;
	if (number == 1)
		ft_putstr("ra");
	else
		ft_putstr("rb");
}
