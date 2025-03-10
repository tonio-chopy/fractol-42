/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:06:50 by alaualik          #+#    #+#             */
/*   Updated: 2024/10/22 17:18:52 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	if ((!s2 || !s1) && len == 0)
		return (NULL);
	while (s1[i] && i < len)
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s2[j] && s1[i + j] && i + j < len && s1[i + j] == s2[j])
				j++;
			if (!s2[j])
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
