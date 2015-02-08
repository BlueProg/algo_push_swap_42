/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 20:30:59 by mmole             #+#    #+#             */
/*   Updated: 2015/02/08 20:38:04 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

static int		ft_is_not_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int				ft_parse_data(char **tab, t_dlist **list, int *option)
{
	int	i;

	i = 1;
	while (*tab && tab[i])
	{
		if (ft_strcmp(tab[i], "-v") == 0)
			*option = 1;
		else
		{
			if (ft_is_not_number(tab[i]))
			{
				ft_putendl_fd("Error", 2);
				return (1);
			}
			ft_add_elem(list, ft_create_elem(ft_atoi(tab[i])));
		}
		i++;
	}
	return (0);
}

int				ft_check_double(t_dlist *list)
{
	int		save;
	t_dlist	*tmp;
	t_dlist	*tmp2;

	tmp = list->next;
	while (tmp != list)
	{
		tmp2 = tmp->next;
		save = tmp->val;
		while (tmp2 != tmp)
		{
			if (save == tmp2->val)
			{
				ft_putendl_fd("Error", 2);
				return (1);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
