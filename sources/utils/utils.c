/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtyene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:50:26 by gtyene            #+#    #+#             */
/*   Updated: 2021/11/27 18:17:05 by gtyene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pr_err(char *str1, char *str2, char *str3, int exit_status)
{
	if (str1)
		ft_putstr_fd(str1, 2);
	if (str2)
		ft_putstr_fd(str2, 2);
	if (str3)
		ft_putstr_fd(str3, 2);
	g_status = exit_status;
}

int	print_errno(void)
{
	ft_putendl_fd(strerror(errno), 2);
	return (1);
}

void	*malloc_x(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		print_errno();
	return (ptr);
}

void	free_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
}

void	fill_in_env(t_list **env_ms)
{	
	char	pwd[4096];
	char	*env[4];

	getcwd(pwd, 4096);
	env[0] = ft_strjoin("PWD=", pwd);
	env[1] = "SHLVL=0";
	env[2] = "_=/usr/bin/env";
	env[3] = NULL;
	init_start_struct(env_ms, env);
}
