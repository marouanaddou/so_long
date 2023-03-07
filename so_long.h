/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:04:03 by maddou            #+#    #+#             */
/*   Updated: 2023/03/07 15:42:51 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
#include <stdlib.h>
#include "mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_long
{
    int i;
    int j;
    int r;
    int maps;
    void *xpm_image[4];
    //char **read;
    //char *line;
    char **matrix;
    char buffer[1000000];
    int mat[5800][2];
    //int *x;
    int u;
    int v;
    int a;
    void *mx_init;
    void *mx_window;
    int z;
    int w;
    //int m;
    //int n;
    int cont_move;
    int cont_coins;
    int c;
    int e;
    int p;
    int co_c;
    int co_e;
} t_long;

typedef struct s_cont
{
    int c;
    int e;
    int p;
    int co_c;
    int co_e;
} t_cont;

typedef struct s_mlx
{   
    // void *mx_image_player;
    // void *xpm_player_to_image;
    // void *xpm_wall_to_image;
    // void *xpm_coins_to_image;
    // void *xpm_exit_to_image;
    int width;
    int height;
} t_mlx;

int	ft_strlen(char *str);

void check_element(char *str, t_long *cont);
void check_length(char **matrix);
void check_wall(char **matrix);
int checkfila_wal(char **matrix, int j);
void check_valid_map(char **matrix, t_long *l);
void valid(t_cont *cont, t_long *l);
void check_resolution(char *str);

void free_split(char **matrix);

char	**ft_split(char *str, char c);

void validpath(t_long *l);

int key_hok(int keycode , t_long *l);
void put_image(t_long *l, t_mlx *mlx);

void move_top(t_long *l, t_mlx *mlx);
void move_right(t_long *l, t_mlx *mlx);
void move_bottom(t_long *l, t_mlx *mlx);
void move_left(t_long *l, t_mlx *mlx);
void put_nbr(int nb);

int check_exit(t_long *l);
int check_coins(t_long *l);

void mlx_function(t_long *l, t_mlx *mlx);

void aplique_element(t_long *l);
void check_exit_player(int keycode, t_long *l); 

void free_image(t_long *l);
#endif