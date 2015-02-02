/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 16:52:38 by mmole             #+#    #+#             */
/*   Updated: 2015/01/31 01:11:16 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_char(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (i);
		i++;
	}
	if (s1[i] == c)
		return (i);
	return (-1);
}