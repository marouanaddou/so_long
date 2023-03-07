/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkvalidpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:40:33 by maddou            #+#    #+#             */
/*   Updated: 2023/03/07 12:03:13 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkfila_wal(char **matrix, int j)
{
	int	i;

	i = 0;
	while (matrix[0][i] != '\0' && matrix[j][i] != '\0')
	{
		if (matrix[0][i] != '1' || matrix[j][i] != '1')
		{
			write(1, "not valid wall ❌\n", 20);
			free_split(matrix);
			exit(1);
		}
		i++;
	}
	return (i);
}

void	aplique(t_long *l)
{
	l->u = 0;
	while (l->matrix[l->u] != NULL)
	{
		l->v = 0;
		while (l->matrix[l->u][l->v] != '\0')
		{
			aplique_element(l);
			l->v++;
		}
		l->u++;
	}
}

void	c_map(t_long *l)
{
	l->i = 0;
	l->j = 0;
	l->a = 0;
	while (l->buffer[l->i] != '\0')
	{
		if (l->buffer[l->i] == '\n')
		{
			l->j++;
			l->i++;
			l->a = 0;
		}
		l->matrix[l->j][l->a] = l->buffer[l->i];
		l->a++;
		l->i++;
	}
	l->i = 0;
	l->j = 0;
}

void	validpath(t_long *l)
{
	l->a = 0;
	l->i = 0;
	while (l->a <= l->p)
	{
		aplique(l);
		l->a++;
	}
	while (l->matrix[l->i] != NULL)
	{
		l->j = 0;
		while (l->matrix[l->i][l->j] != '\0')
		{
			if (l->matrix[l->i][l->j] == 'C' || l->co_e != 1)
			{
				write(1, "not valid path ❌\n", 19);
				free_split(l->matrix);
				exit(1);
			}
			l->j++;
		}
		l->i++;
	}
	c_map(l);
	write(1, "valid path ✅\n", 15);
}

void	check_valid_map(char **matrix, t_long *l)
{
	l->i = 1;
	l->j = 0;
	l->r = 1;
	l->a = 1;
	l->co_c = 0;
	l->co_e = 0;
	while (matrix[l->i] != NULL)
	{
		l->j = 0;
		while (matrix[l->i][l->j] != '\0')
		{
			if (matrix[l->i][l->j] == 'P')
				break ;
			l->j++;
		}
		if (matrix[l->i][l->j] == 'P')
			break ;
		l->i++;
	}
	while (l->buffer[l->p] != '\0')
		l->p++;
	l->mat[0][0] = l->i;
	l->mat[0][1] = l->j;
	validpath(l);
}
