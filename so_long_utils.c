/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:18:31 by maddou            #+#    #+#             */
/*   Updated: 2023/03/07 15:50:09 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_player(t_long *l)
{
	l->i = 0;
	while (l->matrix[l->z] != NULL)
	{
		l->w = 0;
		while (l->matrix[l->z][l->w] != '\0')
		{
			if (l->matrix[l->z][l->w] == 'P')
				break ;
			l->w++;
		}
		if (l->matrix[l->z][l->w] == 'P')
			break ;
		l->z++;
	}
}

void	quit(t_long *l, t_mlx *mlx)
{
	l->cont_move++;
	put_nbr(l->cont_move);
	write(1, "\n", 1);
	free_image(l);
	exit(0);
}

void	exit_play(int keycode, t_long *l)
{
	t_mlx	mlx;

	if (keycode == 13 && l->matrix[l->z - 1][l->w] != '1')
	{
		l->cont_move++;
		if (l->matrix[l->z - 1][l->w] == 'E')
			check_exit(l);
	}
	else if (keycode == 2 && l->matrix[l->z][l->w + 1] != '1')
	{
		l->cont_move++;
		if (l->matrix[l->z][l->w + 1] == 'E')
			check_exit(l);
	}
	check_exit_player(keycode, l);
}

int	key_hok(int keycode, t_long *l)
{
	t_mlx	mlx;

	l->z = 0;
	l->w = 0;
	search_player(l);
	if (keycode == 13 && l->matrix[l->z - 1][l->w] != '1' && l->matrix[l->z
		- 1][l->w] != 'E')
		move_top(l, &mlx);
	else if (keycode == 2 && l->matrix[l->z][l->w + 1] != '1'
			&& l->matrix[l->z][l->w + 1] != 'E')
		move_right(l, &mlx);
	else if (keycode == 1 && l->matrix[l->z + 1][l->w] != '1' && l->matrix[l->z
			+ 1][l->w] != 'E')
		move_bottom(l, &mlx);
	else if (keycode == 0 && l->matrix[l->z][l->w - 1] != '1'
			&& l->matrix[l->z][l->w - 1] != 'E')
		move_left(l, &mlx);
	else if (keycode == 53)
		quit(l, &mlx);
	if (check_coins(l) == 1)
		exit_play(keycode, l);
	return (0);
}

void	put_image(t_long *l, t_mlx *mlx)
{
	mlx_function(l, mlx);
	while (l->matrix[l->i] != NULL)
	{
		l->j = 0;
		while (l->matrix[l->i][l->j] != '\0')
		{
			if (l->matrix[l->i][l->j] == '1')
				mlx_put_image_to_window(l->mx_init, l->mx_window,
					l->xpm_image[0], l->j * 63, l->i * 63);
			else if (l->matrix[l->i][l->j] == 'P')
				mlx_put_image_to_window(l->mx_init, l->mx_window,
					l->xpm_image[1], l->j * 63, l->i * 63);
			else if (l->matrix[l->i][l->j] == 'C')
				mlx_put_image_to_window(l->mx_init, l->mx_window,
					l->xpm_image[2], l->j * 63, l->i * 63);
			else if (l->matrix[l->i][l->j] == 'E')
				mlx_put_image_to_window(l->mx_init, l->mx_window,
					l->xpm_image[3], l->j * 63, l->i * 63);
			l->j++;
		}
		l->i++;
	}
}
