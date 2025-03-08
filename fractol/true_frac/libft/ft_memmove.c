/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:06:50 by alaualik          #+#    #+#             */
/*   Updated: 2024/10/22 20:13:15 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	*cpy(unsigned char *dest,
							const unsigned char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;
	size_t				i;

	temp_dest = dest;
	temp_src = src;
	if (temp_dest == temp_src)
		return (dest);
	if (temp_dest > temp_src && temp_dest < temp_src + n)
	{
		i = n;
		while (i > 0)
		{
			temp_dest[i - 1] = temp_src[i - 1];
			i--;
		}
	}
	else
		cpy(temp_dest, temp_src, n);
	return (dest);
}
