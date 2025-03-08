/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:07:24 by alaualik          #+#    #+#             */
/*   Updated: 2024/10/22 17:14:59 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*temp_src;
	char		*temp_dest;

	if (!dest && !src)
		return (NULL);
	temp_src = src;
	temp_dest = dest;
	while (n--)
		*temp_dest++ = *temp_src++;
	return (dest);
}
