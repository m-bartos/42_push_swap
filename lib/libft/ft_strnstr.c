/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:19:43 by mbartos           #+#    #+#             */
/*   Updated: 2023/10/27 12:29:33 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_str_in_str(const char *str, const char *to_find)
{
	size_t	i;

	i = 0;
	while (to_find[i])
	{
		if (str[i] == to_find [i])
			i++;
		else
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	len_to_find;

	len_to_find = ft_strlen(to_find);
	if (to_find[0] == 0)
		return ((char *) str);
	i = 0;
	while (str[i] != 0 && len > 0)
	{
		if (str[i] == to_find[0])
		{
			if (len_to_find > len)
				return (NULL);
			if (ft_is_str_in_str(&str[i], to_find))
				return ((char *) &str[i]);
		}
		i++;
		len--;
	}
	return (NULL);
}
