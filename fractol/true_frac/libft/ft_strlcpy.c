/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:46:07 by alaualik          #+#    #+#             */
/*   Updated: 2024/10/22 17:18:06 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const char	*temp_src;
	size_t		i;

	i = 0;
	temp_src = src;
	if (size)
	{
		while (*temp_src && i++ < (size - 1))
			*dest++ = *temp_src++;
		*dest = 0;
	}
	while (src[i])
		i++;
	return (i);
}
