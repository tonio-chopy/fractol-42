/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 22:45:51 by alaualik          #+#    #+#             */
/*   Updated: 2024/10/22 17:18:25 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*temp_s;

	i = 0;
	if (s)
	{
		temp_s = ft_calloc(ft_strlen(s) + 1, sizeof(char));
		if (!temp_s)
			return (NULL);
		while (s[i])
		{
			temp_s[i] = f(i, s[i]);
			i++;
		}
		return (temp_s);
	}
	return (NULL);
}
