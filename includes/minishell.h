#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <dirent.h>
# include "../libft/libft.h"

int		g_status;

typedef struct s_token
{
	char	**cmd;
	int		redOrPipe;
	int		fd0;
	int		fd1;
	int		fd[2];
	char	*stopheredoc;
	char	*error;
	pid_t	pid;
	struct s_token	*next;
}				t_token;

typedef struct s_parser
{
	char	*line;
	char	**env;
	int		i;
	int		k;
	int		j;
}			t_parser;

/*
*	The names of functions that actually do the manipulation.
*/
typedef struct s_command
{
	char	*name;
	int		(*func)(char **, t_list **);
}			t_command;

/*	builtins	*/

int		cmd_echo(char **argv, t_list **env_ms);
int		cmd_pwd(char **argv, t_list **env_ms);
int		cmd_exit(char **argv, t_list **env_ms);
int		cmd_env(char **argv, t_list **env_ms);
int		cmd_export(char **argv, t_list **env_ms);
int		cmd_unset(char **argv, t_list **env_ms);
int		cmd_cd(char **argv, t_list **env_ms);

/*	utils	*/

int		print_errno(void);
void	free_array(char **argv);
void	free_list(t_list **list);
void	*malloc_x(size_t size);
void	get_current_pwd(char **pwd, t_list *env_ms);
char	*search_value_by_key(t_list *env_ms, char *key);
char	**list_to_array(t_list *env_ms);
void	heredoc(t_token *point);

/*	parsing	*/
char	*preparser(char *line);
char	*ft_dollar(char *str, int *i, char **env);
char	*ft_slesh(char *str, int *i);
char	*ft_gap(char *str, int *i);
char	*ft_gap2(char *str, int *i, char **env);
char	*ft_insert_space_after_red(char *str, int *i);
int		ifkey(char c);
char	*deleteSpace(char *line);
int		searchRed(char *line, int i);
int		searchPipe(char *line, int i);
int		searchNext(char *line, int i, char letter);
char	*parser_str(char *line, char **env);
char	*outputError(char *str, char *line, int exit_status);
int		parserToken(t_token **token, t_parser *pr, int pp);
void	createToken(t_token **token, t_parser *pr, char *str, int redOrPipe);
void	*free_token(t_token **t);
void	ft_token(t_token **token, char *str, t_parser *pr, int pp);
char	*changeLetter(char *str, char in, char out);
void	ft_parser_red(t_token *new, t_parser *pr);
int		ft_append_red(t_token *new, int *i);
void	ft_close_fd(t_token *new, int fd);
void	ft_free_str_in_token(t_token *new, int i);
void	ft_clear_empty_line(t_token *new, int max_i);
char	**parser_split(char *s, char c);
void	print_token(t_token *token);
char	*break_on_error(char *str1, char *str2, int exit_status);
char	**ft_free_array(char **arr);
void	ft_heredoc_stops(t_token *new);

void	parser(t_token **token, t_parser *pr);
void	clear_token(t_token **token);

void	signals_interactive_shell(void);
void	signals_non_interactive_shell(void);
void	signals_ctrl_D(int sig);

#endif
