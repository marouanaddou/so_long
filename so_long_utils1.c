/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:22:22 by maddou            #+#    #+#             */
/*   Updated: 2023/03/07 16:05:25 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit(t_long *l)
{
	free_image(l);
	exit(0);
}

int	check_coins(t_long *l)
{
	int	i;
	int	j;

	i = 0;
	while (l->matrix[i] != NULL)
	{
		j = 0;
		while (l->matrix[i][j] != '\0')
		{
			if (l->matrix[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	mlx_function(t_long *l, t_mlx *mlx)
{
	l->xpm_image[0] = mlx_xpm_file_to_image(l->mx_init, "textures/wall.xpm",
			&mlx->width, &mlx->height);
	l->xpm_image[1] = mlx_xpm_file_to_image(l->mx_init, "textures/player.xpm",
			&mlx->width, &mlx->height);
	l->xpm_image[2] = mlx_xpm_file_to_image(l->mx_init, "textures/coins1.xpm",
			&mlx->width, &mlx->height);
	l->xpm_image[3] = mlx_xpm_file_to_image(l->mx_init, "textures/exit-3.xpm",
			&mlx->width, &mlx->height);
	if (l->xpm_image[0] == NULL || l->xpm_image[1] == NULL
		|| l->xpm_image[2] == NULL || l->xpm_image[3] == NULL)
	{
		free_image(l);
		exit(1);
	}
}

void	aplique_element(t_long *l)
{
	if (l->matrix[l->u][l->v] == 'P')
	{
		if (l->matrix[l->u][l->v] == 'P' && (l->matrix[l->u - 1][l->v] == 'E'
				|| l->matrix[l->u][l->v + 1] == 'E' || l->matrix[l->u
				+ 1][l->v] == 'E' || l->matrix[l->u][l->v - 1] == 'E')
			&& l->co_e < 1)
			l->co_e++;
		if (l->matrix[l->u - 1][l->v] != '1' && l->matrix[l->u
			- 1][l->v] != 'E')
			l->matrix[l->u - 1][l->v] = 'P';
		if (l->matrix[l->u][l->v + 1] != '1' && l->matrix[l->u][l->v
			+ 1] != 'E')
			l->matrix[l->u][l->v + 1] = 'P';
		if (l->matrix[l->u + 1][l->v] != '1' && l->matrix[l->u
			+ 1][l->v] != 'E')
			l->matrix[l->u + 1][l->v] = 'P';
		if (l->matrix[l->u][l->v - 1] != '1' && l->matrix[l->u][l->v
			- 1] != 'E')
			l->matrix[l->u][l->v - 1] = 'P';
	}
}

void	check_exit_player(int keycode, t_long *l)
{
	if (keycode == 1 && l->matrix[l->z + 1][l->w] != '1')
	{
		l->cont_move++;
		if (l->matrix[l->z + 1][l->w] == 'E')
			check_exit(l);
	}
	else if (keycode == 0 && l->matrix[l->z][l->w - 1] != '1')
	{
		l->cont_move++;
		if (l->matrix[l->z][l->w - 1] == 'E')
			check_exit(l);
	}
}
