/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtyene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:49:45 by gtyene            #+#    #+#             */
/*   Updated: 2021/11/26 00:48:17 by gtyene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cmd_env(char **argv, t_list **env_ms)
{
	t_list	*tmp;

	if (argv[1])
	{
		ft_putstr_fd("env: '", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putendl_fd("': No such file or directory", 2);
		return (127);
	}
	tmp = *env_ms;
	while (tmp)
	{
		if (tmp->data->value)
			printf("%s=%s\n", tmp->data->key, tmp->data->value);
		tmp = tmp->next;
	}
	return (1);
}
