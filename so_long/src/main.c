/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:36:09 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/27 09:31:55 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	swap_z(mlx_image_t *img2, mlx_image_t *img1, size_t total, int on, int under)
{
	size_t	i;

	i = 0;
	while (i < total)
	{
		mlx_set_instance_depth(&img2->instances[i], on);
		mlx_set_instance_depth(&img1->instances[i], under);
		i++;
	}
}

//Si le paso la struct a swap_z puedo hacer que deje el frame a 0 cada vez que se ejecute
//también podría probar a usar +- para todos los valores, comprobar si no da fallo, asi paso
//solo un valor y le puedo pasar el frame como quinto parámetro

void	col_animation(t_struct *st)
{
	if (st->frame_col == 25 && st->col1->instances[0].z > 0)
	{	
		swap_z(st->col2, st->col1, st->cols, 110, -110);
		st->frame_col = -1;
	}
	else if (st->frame_col == 25 && st->col2->instances[0].z > 0)
	{	
		swap_z(st->col3, st->col2, st->cols, 110, -120);
		st->frame_col = -1;
	}
	else if (st->frame_col == 25 && st->col3->instances[0].z > 0)
	{	
		swap_z(st->col4, st->col3, st->cols, 110, -130);
		st->frame_col = -1;

	}
	else if (st->frame_col == 25 && st->col4->instances[0].z > 0)
	{	
		swap_z(st->col5, st->col4, st->cols, 110, -140);
		st->frame_col = -1;
	}
	else if (st->frame_col == 25 && st->col5->instances[0].z > 0)
	{	
		swap_z(st->col6, st->col5, st->cols, 110, -150);
		st->frame_col = -1;
	}
	else if (st->frame_col == 25 && st->col6->instances[0].z > 0)
	{	
		swap_z(st->col1, st->col6, st->cols, 110, -160);
		st->frame_col = -1;
	}
	st->frame_col++;
}

void	background_animation(void *param)
{
	t_struct	*st;
	size_t		i;

	st = (t_struct *)param;
	i = 0;
	if (st->frame_bg == 100 && st->way->instances[i].z > 0)
	{	
		while (i < st->ways)
		{
			mlx_set_instance_depth(&st->way1->instances[i], 10);
			mlx_set_instance_depth(&st->way->instances[i], -10);
			i++;
		}
		st->frame_bg = -1;
	}
	else if (st->frame_bg == 100 && st->way1->instances[i].z > 0)
	{	
		while (i < st->ways)
		{
			mlx_set_instance_depth(&st->way2->instances[i], 10);
			mlx_set_instance_depth(&st->way1->instances[i], -20);
			i++;
		}
		st->frame_bg = -1;
	}
	else if (st->frame_bg == 100 && st->way2->instances[i].z > 0)
	{	
		while (i < st->ways)
		{
			mlx_set_instance_depth(&st->way->instances[i], 10);
			mlx_set_instance_depth(&st->way2->instances[i], -30);
			i++;
		}
		st->frame_bg = -1;
	}
	st->frame_bg++;
}

void	wall_animation(void *param)
{
	t_struct	*st;
	size_t		i;

	st = (t_struct *)param;
	i = 0;
	if (st->frame_delay == 40 && st->wall->instances[i].z > 0)
	{	
		while (i < st->walls)
		{
			mlx_set_instance_depth(&st->wall1->instances[i], 110);
			mlx_set_instance_depth(&st->wall->instances[i], -110);
			i++;
		}
		st->frame_delay = -1;
	}
	else if (st->frame_delay == 40 && st->wall1->instances[i].z > 0)
	{	
		while (i < st->walls)
		{
			mlx_set_instance_depth(&st->wall2->instances[i], 110);
			mlx_set_instance_depth(&st->wall1->instances[i], -120);
			i++;
		}
		st->frame_delay = -1;
	}
	else if (st->frame_delay == 40 && st->wall2->instances[i].z > 0)
	{	
		while (i < st->walls)
		{
			mlx_set_instance_depth(&st->wall3->instances[i], 110);
			mlx_set_instance_depth(&st->wall2->instances[i], -130);
			i++;
		}
		st->frame_delay = -1;
	}
	else if (st->frame_delay == 40 && st->wall3->instances[i].z > 0)
	{	
		while (i < st->walls)
		{
			mlx_set_instance_depth(&st->wall->instances[i], 110);
			mlx_set_instance_depth(&st->wall3->instances[i], -140);
			i++;
		}
		st->frame_delay = -1;
	}
	st->frame_delay++;
}

void	key_control(void *param)
{
	t_struct	*st;

	st = (t_struct *)param;
	if (mlx_is_key_down(st->window, MLX_KEY_ESCAPE))
		mlx_close_window(st->window);
	if (mlx_is_key_down(st->window, MLX_KEY_UP))
	{	
		mlx_set_instance_depth(&st->player_d->instances[0], -310);
		mlx_set_instance_depth(&st->player_u->instances[0], 310);
		mlx_set_instance_depth(&st->player_l->instances[0], -330);
		mlx_set_instance_depth(&st->player_r->instances[0], -340);
		if (st->map[((int)(st->player_d->instances[0].y + 4) - MOV) / PIX][(int)st->player_d->instances[0].x / PIX] != '1'
			&& st->map[((int)(st->player_d->instances[0].y + 4) - MOV) / PIX][((int)st->player_d->instances[0].x + 60) / PIX] != '1')
		{		
			st->player_d->instances[0].y -= MOV;
			st->player_u->instances[0].y -= MOV;
			st->player_l->instances[0].y -= MOV;
			st->player_r->instances[0].y -= MOV;
		}
	}
	if (mlx_is_key_down(st->window, MLX_KEY_DOWN))
	{	
		mlx_set_instance_depth(&st->player_d->instances[0], 310);
		mlx_set_instance_depth(&st->player_u->instances[0], -320);
		mlx_set_instance_depth(&st->player_l->instances[0], -330);
		mlx_set_instance_depth(&st->player_r->instances[0], -340);
		if (st->map[((int)(st->player_d->instances[0].y + 60) + MOV) / PIX][((int)st->player_d->instances[0].x + 60) / PIX] != '1' 
			&& st->map[((int)(st->player_d->instances[0].y + 60) + MOV) / PIX][((int)st->player_d->instances[0].x) / PIX] != '1')
		{		
			st->player_d->instances[0].y += MOV;
			st->player_u->instances[0].y += MOV;
			st->player_l->instances[0].y += MOV;
			st->player_r->instances[0].y += MOV;
		}
	}
	if (mlx_is_key_down(st->window, MLX_KEY_LEFT))
	{	
		mlx_set_instance_depth(&st->player_d->instances[0], -310);
		mlx_set_instance_depth(&st->player_u->instances[0], -320);
		mlx_set_instance_depth(&st->player_l->instances[0], 310);
		mlx_set_instance_depth(&st->player_r->instances[0], -340);
		if (st->map[((int)st->player_d->instances[0].y + 4) / PIX][((int)st->player_d->instances[0].x - MOV) / PIX] != '1'
			&& st->map[((int)st->player_d->instances[0].y + 60) / PIX][((int)st->player_d->instances[0].x - MOV) / PIX] != '1')
		{	
			st->player_d->instances[0].x -= MOV;
			st->player_u->instances[0].x -= MOV;
			st->player_l->instances[0].x -= MOV;
			st->player_r->instances[0].x -= MOV;
		}
	}
	if (mlx_is_key_down(st->window, MLX_KEY_RIGHT))
	{	
		mlx_set_instance_depth(&st->player_d->instances[0], -310);
		mlx_set_instance_depth(&st->player_u->instances[0], -320);
		mlx_set_instance_depth(&st->player_l->instances[0], -330);
		mlx_set_instance_depth(&st->player_r->instances[0], 310);
		if (st->map[((int)st->player_d->instances[0].y + 4) / PIX][(((int)st->player_d->instances[0].x + 60) + MOV) / PIX] != '1'
			&& st->map[((int)st->player_d->instances[0].y + 60) / PIX][(((int)st->player_d->instances[0].x + 60) + MOV) / PIX] != '1')
		{	
			st->player_d->instances[0].x += MOV;
			st->player_u->instances[0].x += MOV;
			st->player_l->instances[0].x += MOV;
			st->player_r->instances[0].x += MOV;
		}
	}
	background_animation(st);
	wall_animation(st);
	col_animation(st);
}

int	main(int ac, char **av)
{
	t_struct		st;

	(void)ac;
	init_struct(&st);
	read_map(&st, av[1]);
	st.window = mlx_init(st.width * PIX, st.height * PIX, NAME, false);
	load_images(&st);
	render_images(&st);
	mlx_loop_hook(st.window, key_control, &st);
	mlx_loop(st.window);
	mlx_terminate(st.window);
	ft_printf("Taluego! Ya te queda menos...=)");
	return (0);
}

/**
 * @brief Lista tareas TO_DO
 * - Esquema capas -> HECHO
 * - Carga de imagenes -> una función que llame a varias funciones, una por tipo de img -> HECHO
 * - Colocar + profundidad cada tipo de imagen -> una función + funcion por tipo(mlx_depth) -> HECHO
 * - FUNCION AUX QUE CAMBIE LA Z DE CUALQUIER INSTANCIA? (meter las capas de imgen en array?) -> X
 * - Ordenar init struct, cambiar de t_struct a void y pasarle la original, luego partirla en
 * 		funciones por grupos de elementos -> HECHO
 * - Quitarle formato hook a las funciones de animación, dejarlas como funciones normales
 * - Funcion universal para cambiar depth de dos imagenes del mismo elemento -> le tendria que
 * 		pasar los dos elementos y los dos valores a cambiar, y luego en la funcion llama 
 * 		a mlx_depth usando esos valores...
 * - Función universal + quitar param = st + contador i- / i++ en while puede funcionar
 */