/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:15:17 by maddou            #+#    #+#             */
/*   Updated: 2023/03/07 12:07:01 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_nbr(int nb)
{
	int		i;
	char	c;

	i = 0;
	if (nb > 9)
	{
		put_nbr(nb / 10);
		put_nbr(nb % 10);
	}
	if (nb >= 0 && nb <= 9)
	{
		c = nb + 48;
		write(1, &c, 1);
	}
}

void	move_top(t_long *l, t_mlx *mlx)
{
	l->cont_move++;
	put_nbr(l->cont_move);
	write(1, "\n", 1);
	mlx_clear_window(l->mx_init, l->mx_window);
	l->matrix[l->z][l->w] = '0';
	l->matrix[l->z - 1][l->w] = 'P';
	l->i = 0;
	l->j = 0;
	put_image(l, mlx);
}

void	move_right(t_long *l, t_mlx *mlx)
{
	l->cont_move++;
	put_nbr(l->cont_move);
	write(1, "\n", 1);
	mlx_clear_window(l->mx_init, l->mx_window);
	l->matrix[l->z][l->w] = '0';
	l->matrix[l->z][l->w + 1] = 'P';
	l->i = 0;
	l->j = 0;
	put_image(l, mlx);
}

void	move_bottom(t_long *l, t_mlx *mlx)
{
	l->cont_move++;
	put_nbr(l->cont_move);
	write(1, "\n", 1);
	mlx_clear_window(l->mx_init, l->mx_window);
	l->matrix[l->z][l->w] = '0';
	l->matrix[l->z + 1][l->w] = 'P';
	l->i = 0;
	l->j = 0;
	put_image(l, mlx);
}

void	move_left(t_long *l, t_mlx *mlx)
{
	l->cont_move++;
	put_nbr(l->cont_move);
	write(1, "\n", 1);
	mlx_clear_window(l->mx_init, l->mx_window);
	l->matrix[l->z][l->w] = '0';
	l->matrix[l->z][l->w - 1] = 'P';
	l->i = 0;
	l->j = 0;
	put_image(l, mlx);
}
