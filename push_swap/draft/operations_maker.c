/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_maker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:27:01 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/02/12 10:00:14 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_rotate_top(t_index *index, int x, int y)
{
	if (x > y)
	{
		while ((x--) - y > 0)
			rotate_a(index);
		while ((y--) > 0)
			rotate_ab(index);
	}
	while ((y--) - x > 0)
		rotate_b(index);
	while ((x--) > 0)
		rotate_ab(index);
}

void	best_rotate_bot(t_index *index, int x, int y)
{
	if (x > y)
	{
		while ((x--) - y > 0)
			revrot_a(index);
		while ((y--) > 0)
			revrot_ab(index);
	}
	while ((y--) - x > 0)
		revrot_b(index);
	while ((x--) > 0)
		revrot_ab(index);
}

void	operation_maker(t_index *index)
{
	int	x;
	int	y;

	x = index->coords[0];
	y = index->coords[1];
	if (x >= 0 && y >= 0)
		best_rotate_top(index, x, y);
	if (x < 0 && y < 0)
		best_rotate_bot(index, -x, -y);
	if (x >= 0 && y < 0)
	{
		while (x-- > 0)
			rotate_a(index);
		while (y++ < 0)
			revrot_b(index);
	}
	if (x < 0 && y > 0)
	{
		while (x++ < 0)
			revrot_a(index);
		while (y-- > 0)
			rotate_b(index);
	}
}
