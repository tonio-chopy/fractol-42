/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:06:50 by alaualik          #+#    #+#             */
/*   Updated: 2024/10/22 17:13:19 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*i;
	t_list	*stock_ad;

	if (!lst || !del)
		return ;
	i = *lst;
	if (i == 0)
		*lst = NULL;
	else
	{
		while (i != NULL)
		{
			stock_ad = i->next;
			del(i->content);
			free(i);
			i = stock_ad;
		}
	}
	*lst = NULL;
}
