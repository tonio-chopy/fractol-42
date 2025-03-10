/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:03:41 by alaualik          #+#    #+#             */
/*   Updated: 2024/10/24 19:05:49 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	cpy = ft_calloc(len + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s + start, len + 1);
	return (cpy);
}
