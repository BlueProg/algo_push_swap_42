/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 17:39:27 by mmole             #+#    #+#             */
/*   Updated: 2015/02/21 18:25:04 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_dlist
{
	int				val;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

t_dlist				*ft_create_elem(int val);
void				ft_add_elem(t_dlist **list, t_dlist *new_elem);
void				ft_add_head_elem(t_dlist **list, t_dlist *new_elem);
t_dlist				*ft_pop_last(t_dlist **list);
t_dlist				*ft_pop_first(t_dlist **list);
void				ft_s_inverse_list(t_dlist **list, int number);
void				ft_push_list(t_dlist **list_a, t_dlist **list_b, int nb);
void				ft_rotate_list(t_dlist **list, int number);
int					ft_parse_data(char **data, t_dlist **list, int *option);
int					ft_check_double(t_dlist *list);

#endif
