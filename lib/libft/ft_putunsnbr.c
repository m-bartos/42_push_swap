/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:05:19 by mbartos           #+#    #+#             */
/*   Updated: 2023/11/01 09:29:32 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsnbr(unsigned int n, int *ptr_sum)
{
	unsigned long int	n_long;

	n_long = n;
	if (n_long > 9)
	{
		ft_putunsnbr(n_long / 10, ptr_sum);
		ft_putunsnbr(n_long % 10, ptr_sum);
	}
	else
		ft_putchar_c(n_long + '0', ptr_sum);
}
