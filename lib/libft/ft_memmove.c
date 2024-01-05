/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:19:22 by mbartos           #+#    #+#             */
/*   Updated: 2023/10/31 08:30:39 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*new_src;
	char		*new_dest;

	new_src = src;
	new_dest = dest;
	if (!dest && !src)
		return (dest);
	if (new_dest < new_src)
	{
		while (n--)
			*new_dest++ = *new_src++;
	}
	else
	{
		while (n--)
			*(new_dest + n) = *(new_src + n);
	}
	return (dest);
}
