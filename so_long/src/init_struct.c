/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:28:59 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/29 12:16:00 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	init_params(t_struct *st)
{
	st->map = NULL;
	st->window = NULL;
	st->width = 0;
	st->height = 0;
	st->collec_cnt = 0;
	st->step_cnt = 0;
	st->walls = 0;
	st->ways = 0;
	st->exits = 0;
	st->cols = 0;
	st->enms = 0;
	st->frame_enemy = 0;
	st->frame_wall = 0;
	st->frame_bg = 0;
	st->frame_col = 0;
	st->flag = 0;
}

void	init_mlx(t_struct *st)
{
	st->wall = NULL;
	st->wall1 = NULL;
	st->wall2 = NULL;
	st->wall3 = NULL;
	st->way = NULL;
	st->way1 = NULL;
	st->way2 = NULL;
	st->exit_o = NULL;
	st->exit_c = NULL;
	st->player_u = NULL;
	st->player_d = NULL;
	st->player_l = NULL;
	st->player_r = NULL;
	st->enemy_u = NULL;
	st->enemy_d = NULL;
	st->enemy_l = NULL;
	st->enemy_r = NULL;
	st->col1 = NULL;
	st->col2 = NULL;
	st->col3 = NULL;
	st->col4 = NULL;
	st->col5 = NULL;
	st->col6 = NULL;
}

void	init_struct(t_struct *st)
{
	init_params(st);
	init_mlx(st);
}
