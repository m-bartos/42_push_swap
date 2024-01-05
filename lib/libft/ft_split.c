/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:47:11 by mbartos           #+#    #+#             */
/*   Updated: 2023/10/24 15:42:17 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_of_strings(char *str, char c)
{
	int	i;
	int	n_words;

	n_words = 0;
	i = 0;
	if (str[0] && str[0] != c)
		n_words++;
	while (str[i])
	{
		if (str[i] == c && (str[i + 1] != c && str[i + 1] != 0))
			n_words++;
		i++;
	}
	return (n_words);
}

char	*str_add(char *str, char c, int *index)
{
	int		i;
	int		length;
	char	*word;

	length = 0;
	while (str[length] && str[length] != c)
		length++;
	word = malloc(sizeof(char) * (length + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	*index = *index + length;
	while (i < length)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**array;
	int		i;
	int		j;

	str = (char *) s;
	array = (char **) malloc(sizeof(char *) * (num_of_strings(str, c) + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (str[i] && str[i] != c)
		array[j++] = str_add(&str[i], c, &i);
	while (str[i])
	{
		if (str[i] == c && (str[i + 1] != c && str[i + 1] != 0))
			array[j++] = str_add(&str[i + 1], c, &i);
		i++;
	}
	array[j] = NULL;
	return (array);
}
