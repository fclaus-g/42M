/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:00:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/04/16 21:51:32 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	child_proc(t_struct	*st)
{
	dup2(st->fd_in, STDIN_FILENO);
	dup2(st->pipe[1], STDOUT_FILENO);
	close_pipe(st);
	find_path_index(st, st->cmd1[0]);
	if (execve(st->path_cmd, st->cmd1, st->env))
	{
		perror("Command not found");
		exit_pipex(st, 1);
	}
}

void	parent_proc(t_struct *st)
{
	dup2(st->pipe[0], STDIN_FILENO);
	dup2(st->fd_out, STDOUT_FILENO);
	close_pipe(st);
	find_path_index(st, st->cmd2[0]);
	if (execve(st->path_cmd, st->cmd2, st->env) == -1)
	{
		perror("Command not found");
		exit_pipex(st, 1);
	}
}

/**
 * Pipex tiene que crear un pipe y dos procesos hijos con fork, que el padre 
 * espere a que los dos hijos terminen su trabajo y devulve el exit_code del 
 * ultimo proceso en terminar
 */
void	ft_pipex(t_struct *st)
{
	pipe_gen(st);
	get_iofiles(st);
	st->pid_child = fork();
	if (st->pid_child == -1)
		exit_pipex(st, 1);
	else if (st->pid_child == 0)
		child_proc(st);
	else
	{
		st->pid_child = fork();
		if (st->pid_child == -1)
			exit_pipex(st, 1);
		else if (st->pid_child == 0)
			parent_proc(st);
		else
			close_pipe(st);
	}
	waitpid(st->pid_child, NULL, 0);
}

/**
 Un nuevo argumento para main -> @param env
	@param env = puntero a la variables de entorno del sistema
	almacena en un string cada línea de env
	//TODO gestion errores? return 1 +- imprimir mensaje
	//! protecciones de los argumentos y gestión de errores (mejorar)
*/
int	main(int ac, char **av, char **env)
{
	t_struct	st;

	atexit(ft_leaks);
	if (ac != 5)
		return (perror("Error"), 1);
	if (!env || !*env)
		return (perror("Error"), 1);
	st = init_struct(ac, av, env);
	ft_pipex(&st);
	exit_pipex(&st, 0);
	return (0);
}
