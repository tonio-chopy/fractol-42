/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:06:50 by alaualik          #+#    #+#             */
/*   Updated: 2024/10/22 17:19:17 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*new_s;

	start = 0;
	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while ((end > start) && ft_strchr(set, s1[end - 1]))
		end--;
	new_s = malloc(sizeof(char) * (end - start) + 1);
	if (!new_s)
		return (NULL);
	while (start < end)
		new_s[i++] = s1[start++];
	new_s[i] = '\0';
	return (new_s);
}
