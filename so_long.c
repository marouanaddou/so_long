/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:07:59 by maddou            #+#    #+#             */
/*   Updated: 2023/02/27 17:32:54 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
#include <stdio.h>
#include <unistd.h>

void chek_file(int maps)
{
    if(maps < 0)
    {
        write(1, "file unavaible ❌\n", 19);
        exit(1);
    }
    else 
        write(1, "valid file ✅\n", 16);
}

void print(int i)
{
    if (i == 0)
    {
        write(1, "error name ❌\n", 15);
        exit(1);
    }
    else
        write(1, "valid name ✅\n", 16);
}

int check_name(char *str)
{
    int i;
    int j;
    
    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '.')
            break;
        i++;
    }
    if(str[i + 1] != 'b')
        print (0);
    if(str[i + 2] != 'e')
        print (0);
    if(str[i + 3] != 'r')
        print (0);
    print(1);
    return (1);
}

void check_map(t_long *mp)
{
    mp->i = 0;
    mp->j = 2;
    mp->r = 1;
    t_cont cont;
    while(mp->j != 0)
    {
        mp->j = read(mp->maps, mp->buffer, 1000000); 
        if (mp->j == -1)
            return;
    }
    check_resolution(mp->buffer);
    check_element(mp->buffer, &cont);
    mp->matrix = ft_split(mp->buffer, '\n');
    check_length(mp->matrix);
    check_wall(mp->matrix);
    check_valid_map(mp->matrix, &cont, mp);
}

int main(int argc, char *argv[])
{
    t_long s;
    
    if (argc > 1)
    {
        check_name(argv[1]);
        s.maps = open(argv[1], O_RDONLY);
        chek_file(s.maps);
        check_map(&s);
    }
}