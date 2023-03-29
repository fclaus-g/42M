/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:01:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/29 22:57:35 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*libft.h*/
# include "./libft42/libft.h"

/*structs*/
typedef struct s_struct
{
	char	**paths;
	char	*match_path;
	char	*cmd;
}	t_struct;

/*main.c*/
void		get_paths(t_struct *tools, char **env);
int			find_path_index(t_struct *st);

/*utils.c*/
void		ft_print_dstr(char **dstr);
int			is_path(char *str);
void		ft_leaks(void);

#endif
