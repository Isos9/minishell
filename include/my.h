/*
** my.h for minishell1 in /home/isos/Workspace/Epitech/PSU_2016_minishell1
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun Dec  4 02:38:45 2016 Sébastien Jacobin
** Last update Tue Dec 20 15:58:32 2016 Sébastien Jacobin
*/

#ifndef MY_H
# define MY_H

typedef	void (*builtin_fct)();

typedef	struct builtin_s
{
  char	*name;
  builtin_fct	builtin;
} builtin_t;

char	*my_strcat(char *dest, char *src);
int	count_line(char *buff);
char	*get_line(char	*buff, int  pos);
char	*get_next_line(int fd);
int	exec_cmd(char *str, char ***envp);
int	my_putstr(char *str);
void	my_putchar(char c);
char	**my_str_to_wordtab(char *str);
int	nb_words(char *str);
int	check(char *str, int e);
int	my_strcmp(char *s1, char *s2);
int	my_strlen(char *str);
char	*get_var_env(char **envp, char *env_var);
void	exec_child(char **args, char **envp, int *result);
int	count_pipe(char **cmd);
char	*get_path(char *cmd, char **envp, int *result);
char	*exec_file(char	*name, int *result);
void	make_pipes(int *fd, int nb);
void	forks_waits(int	nb);
void	close_all(int *fd, int nb);
void	my_fork(int *fd, int i, int e, int nb_pipe);
void	params_value(int *i, int *e, int nb_pipe, int state);
builtin_t	new_built(char *name, builtin_fct builtin);
char	**get_cmd(char ***cmd);
int	my_ptrlen(char	**cmd);
void	my_env(char **envp);
void	my_setenv(char *arg, char ***env);
void	my_unsetenv(char *arg, char ***env);
int	check_builtin(char *cmd);
void	exec_builtin(char *cmd, char *arg, char ***envp);
void	signal_cc();
builtin_t	*init_builtins();

#endif /*MY_H*/
