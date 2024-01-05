/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:35:30 by mbartos           #+#    #+#             */
/*   Updated: 2023/10/24 10:48:16 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	char	*source;

	source = (char *) src;
	i = 0;
	while (source[i] && ((i + 1) < size))
	{
		dest[i] = source[i];
		i++;
	}
	if (size)
		dest[i] = 0;
	return (ft_strlen(src));
}
