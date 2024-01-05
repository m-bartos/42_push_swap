/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:15:33 by mbartos           #+#    #+#             */
/*   Updated: 2023/11/01 12:45:28 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_c(char *s, int *ptr_sum)
{
	if (s == NULL)
	{
		ft_putstr_c("(null)", ptr_sum);
		return ;
	}
	while (*s)
	{
		write(1, s++, 1);
		*ptr_sum += 1;
	}
}
