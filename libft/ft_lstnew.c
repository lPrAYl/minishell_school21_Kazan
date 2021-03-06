/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtyene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:43:47 by yfu               #+#    #+#             */
/*   Updated: 2021/10/24 13:05:25 by gtyene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(t_env *content)
{
	t_list	*nw;

	nw = (t_list *)malloc(sizeof(t_list));
	if (!nw)
	{
		ft_putstr_fd("ERROR_IN_FT_LSTNEW\n", 1);
		return (NULL);
	}
	nw->data = content;
	nw->next = NULL;
	return (nw);
}
