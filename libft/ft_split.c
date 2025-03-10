/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:23:12 by alaualik          #+#    #+#             */
/*   Updated: 2024/11/09 06:16:40 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && !word)
		{
			word = 1;
			count++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;	

	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	free_all(char **tab, int i)
{
	while (i--)
		free(tab[i]);
	free(tab);
}

static char	**tabl(char const *s, char c, char **tab)
{
	int		i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			tab[i] = ft_strndup(s, len);
			if (!tab[i])
			{
				free_all(tab, i);
				return (NULL);
			}
			i++;
			s += len;
		}
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab = tabl(s, c, tab);
	return (tab);
}
