/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:13:06 by alaualik          #+#    #+#             */
/*   Updated: 2024/10/22 17:19:01 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	temp_c;
	unsigned char	*stock;
	unsigned char	*str;
	int				check;

	i = 0;
	temp_c = (unsigned char)c;
	str = (unsigned char *)s;
	check = 0;
	while (str[i])
	{
		if (s[i] == temp_c)
		{
			stock = &str[i];
			check = 1;
		}
		i++;
	}
	if (str[i] == '\0' && temp_c == '\0')
		return (&((char *)str)[i]);
	if (i == 0 || check == 0)
		return (NULL);
	return ((char *)stock);
}
