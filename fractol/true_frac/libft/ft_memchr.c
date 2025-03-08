/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:47:24 by alaualik          #+#    #+#             */
/*   Updated: 2024/10/22 17:14:33 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp_s;
	unsigned char		temp_c;
	unsigned int		i;

	temp_s = s;
	temp_c = c;
	i = 0;
	while (i < n)
	{
		if (temp_s[i] == temp_c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
