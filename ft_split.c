/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrirod <patrirod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:48:01 by marvin            #+#    #+#             */
/*   Updated: 2026/09/29 10:49:49 by patrirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	*ft_free_matrix(char **words, size_t len)
{
	int	i;

	i = len;
	while (i > 0)
	{
		i--;
		free(words[i]);
	}
	free(words);
	return (NULL);
}

static char	**ft_allocate_words(char **words, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		j = i;
		while (s[j] != c && s[j] != '\0')
			j++;
		words[k] = ft_substr(s, i, j - i);
		if (!words[k])
			return ((char **)ft_free_matrix(words, k));
		i = j;
		k++;
	}
	words[k] = NULL;
	return (words);
}

//Allocates memory and returns an array of strings 
//obtained by splitting the string
//‘s’ into substrings using the character ‘c’ as the delimiter.
char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	return (ft_allocate_words(words, s, c));
}
