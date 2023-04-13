/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:04:03 by maddou            #+#    #+#             */
/*   Updated: 2023/04/13 05:26:30 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_mlx
{
	int		width;
	int		height;
}			t_mlx;

typedef struct s_long
{
	int		i;
	int		x;
	int		y;
	int		j;
	int		r;
	int		maps;
	void	*xpm_image[5];
	char	**matrix;
	char	buffer[1000000];
	int		u;
	int		v;
	int		a;
	void	*mx_init;
	void	*mx_window;
	int		z;
	int		w;
	int		cont_move;
	int		cont_coins;
	int		c;
	int		e;
	int		p;
	int		co_c;
	int		co_e;
}			t_long;

typedef struct s_cont
{
	int		c;
	int		e;
	int		p;
	int		co_c;
	int		co_e;
}			t_cont;

size_t		ft_strlen(char *str);

void		check_element(char *str, t_long *cont);
void		check_length(char **matrix);
void		check_wall(char **matrix);
int			checkfila_wal(char **matrix, int j);
void		check_valid_map(char **matrix, t_long *l);
void		valid(t_cont *cont, t_long *l);
void		check_resolution(char *str);

void		free_split(char **matrix);

char		**ft_split(char *str, char c);

void		validpath(t_long *l);

int			key_hok(int keycode, t_long *l);
void		put_image(t_long *l, t_mlx *mlx);

void		move_top(t_long *l, t_mlx *mlx);
void		move_right(t_long *l, t_mlx *mlx);
void		move_bottom(t_long *l, t_mlx *mlx);
void		move_left(t_long *l, t_mlx *mlx);
void		put_nbr(int nb);

int			game_over(t_long *l);
int			check_coins(t_long *l);

void		mlx_function(t_long *l, t_mlx *mlx);

void		aplique_element(t_long *l);
void		check_exit_player(int keycode, t_long *l);

void		free_image(t_long *l);
#endif