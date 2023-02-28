/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:41:28 by maddou            #+#    #+#             */
/*   Updated: 2023/02/27 12:53:05 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_resolution(char *str)
{
    int i;
    int j;
    int x;

    i = 0;
    j = 0;
    x = 0;
    while(str[i] != '\n')
        i++;
    while(str[j] != '\0')
    {
        if(str[j] == '\n')
            x++;
        j++;
    }
    if (str[j] == '\0')
        x++;
    if (i > 51 || x > 28)
    {
        write(1, "resolution not convenient ❌\n", 30);
        exit(1);
    }
}

void number_element(char *str, t_cont *cont)
{
    int i;

    cont->c = 0;
    cont->e = 0;
    cont->p = 0;
    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == 'C')
            cont->c += 1;
        else if(str[i] == 'E')
            cont->e += 1;
        else if(str[i] == 'P')
            cont->p += 1;
        i++;
    }
    if(cont->p > 1 || cont->p == 0 || cont->e > 1 || cont->e == 0 || cont->c == 0)
    {
        write(1, "not valid elment ❌\n", 22);
        exit(1);  
    }
}

void check_length(char **matrix)
{
    int i;
    int j;
    int x;

    i = 0;
    x = 0;
    j = 1;
    while(matrix[0][i] != '\0')
        i++;
    while(matrix[j] != NULL)
    {
        while(matrix[j][x] != '\0')
            x++;
        if(x != i)
        {
            write(1, "length not valid ❌\n", 21);
            free_split(matrix);
            exit(1);
        }
        x = 0;
        j++;
    }
    write(1, "valid length ✅\n", 17);
}

void check_element(char *str, t_cont *cont)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] != 'E' && str[i] != 'P')
        {
            if(str[i] == '\n' && str[i - 1] != '1' && str[i - 1] != '0' && str[i - 1] != 'C' && str[i - 1] != 'E' && str[i - 1] != 'P')
            {
                write(1, "not valid elment ❌\n", 22);
                exit(1);
            }
            else if (str[i] != '\n')
            {
                write(1, "not valid elment ❌\n", 22);
                exit(1);
            }
        }       
        i++;
    }
    number_element(str, cont);
    write(1, "good element ✅\n", 17);
}

void check_wall(char **matrix)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(matrix[j] != NULL)
        j++;
    j--;
    i = checkfila_wal(matrix, j);
    while(j > 0)
    {
        if(matrix[j][0] != '1' || matrix[j][i - 1] != '1')
        {
            write(1, "not valid wall ❌\n", 20);
            free_split(matrix);
            exit(1);
        }
        j--;
    }   
    write(1, "valid wall ✅\n", 15);
}
