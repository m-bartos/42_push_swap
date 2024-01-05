/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:39:33 by mbartos           #+#    #+#             */
/*   Updated: 2023/10/24 15:41:14 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	str_itoa_len(long long number)
{
	int	length;

	length = 0;
	if (number < 0)
		length++;
	else if (number == 0)
		return (1);
	while (number)
	{
		number = number / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char		*str;
	long long	number;
	int			length;

	number = n;
	length = str_itoa_len(number);
	str = (char *) malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	if (number < 0)
	{
		number = -number;
		str[0] = '-';
	}
	else if (number == 0)
		str[0] = '0';
	str[length] = '\0';
	while (number)
	{
		str[--length] = number % 10 + '0';
		number = number / 10;
	}
	return (str);
}
