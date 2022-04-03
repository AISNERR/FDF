/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 00:35:06 by aisner            #+#    #+#             */
/*   Updated: 2022/04/03 03:04:46 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

char	*ft_get_word(char *word, char c)
{
	char	*start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

void	ft_free_words(char **words, size_t i)
{
	while (i--)
		ft_strdel(&(words[i]));
	free(*words);
}

char	**ft_get_words(char *s, char c, size_t words_count)
{
	char	**words;
	char	*word;
	size_t	i;

	i = 0;
	words = (char **)ft_memalloc(sizeof(char *) * (words_count + 1));
	if ((words))
	{
		while (i < words_count)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				word = ft_get_word(s, c);
				runner(word, i, words);
				if (!(word))
					return (NULL);
				words[i++] = word;
				s += (ft_strlen(word) + 1);
			}
		}
		words[i] = NULL;
	}
	return (words);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*line;

	line = ft_strdup((char *)s);
	if (!s || !(line))
		return (NULL);
	words = ft_get_words(line, c, ft_count_words(line, c));
	free(line);
	return (words);
}
