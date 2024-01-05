/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:22:37 by mbartos           #+#    #+#             */
/*   Updated: 2023/10/27 12:49:30 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char			*new_str;
	int				length_of_str;
	unsigned int	i;

	length_of_str = ft_strlen(str);
	new_str = (char *) malloc(sizeof (char) * (length_of_str + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != 0)
	{
		new_str[i] = (char) str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
