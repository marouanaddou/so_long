/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:04:03 by maddou            #+#    #+#             */
/*   Updated: 2023/02/27 17:17:30 by maddou           ###   ########.fr       */
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
    char **read;
    char *line;
    char **matrix;
    char buffer[1000000];
    int mat[5800][2];
    int *x;
    int u;
    int v;
    int a;
} t_long;

typedef struct s_cont
{
    int c;
    int e;
    int p;
    int co_c;
    int co_e;
} t_cont;

int	ft_strlen(char *str);

void check_element(char *str, t_cont *cont);
void check_length(char **matrix);
void check_wall(char **matrix);
int checkfila_wal(char **matrix, int j);
void check_valid_map(char **matrix, t_cont *cont, t_long *l);
void valid(t_cont *cont, t_long *l);
void check_resolution(char *str);

void free_split(char **matrix);

char	**ft_split(char *str, char c);

void validpath(t_long *l, t_cont *cont);
#endif