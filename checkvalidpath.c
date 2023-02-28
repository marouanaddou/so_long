/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkvalidpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:40:33 by maddou            #+#    #+#             */
/*   Updated: 2023/02/27 13:19:40 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int checkfila_wal(char **matrix, int j)
{
    int i;

    i = 0;
    while(matrix[0][i] != '\0' && matrix[j][i] != '\0')
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

void apliquep(t_long *l, t_cont *cont)
{
    l->u = 0;
    while(l->matrix[l->u] != NULL)
    {
        l->v = 0;
        while(l->matrix[l->u][l->v] != '\0')
        {
            if(l->matrix[l->u][l->v] == 'P')
            {
                if (l->matrix[l->u - 1][l->v] != '1')
                   l->matrix[l->u - 1][l->v] = 'P';
                
                if (l->matrix[l->u][l->v + 1] != '1')
                    l->matrix[l->u][l->v + 1] = 'P';
                
                if (l->matrix[l->u + 1][l->v] != '1')
                    l->matrix[l->u + 1][l->v] = 'P';
                
                if (l->matrix[l->u][l->v - 1] != '1')
                    l->matrix[l->u][l->v - 1] = 'P';
            }
            l->v++;
        }
        l->u++;
    }
}

void validpath(t_long *l, t_cont *cont)
{
    l->a = 0;
    l->i = 0;
    while(l->a <= cont->p)
    {
        apliquep(l, cont);
        l->a++;
    }
    while(l->matrix[l->i] != NULL)
    {
        l->j = 0;
        while(l->matrix[l->i][l->j] != '\0')
        {
            if(l->matrix[l->i][l->j] == 'C' || l->matrix[l->i][l->j] == 'E')
            {
                write(1, "not valid path ❌\n", 19);
                free_split(l->matrix);
                exit(1);
            }
            l->j++;
        }
        l->i++;
    }
    write(1, "valid path ✅\n", 15);
}

void check_valid_map(char **matrix, t_cont *cont, t_long *l)
{
    l->i = 1;
    l->j = 0;
    l->r = 1;
    l->a = 1;
    cont->co_c = 0;
    cont->co_e = 0;
    while(matrix[l->i] != NULL)
    {
        l->j = 0;
        while(matrix[l->i][l->j] != '\0')
        {
            if(matrix[l->i][l->j] == 'P')
                break;
            l->j++;
        }
        if(matrix[l->i][l->j] == 'P')
            break;
        l->i++;
    }
    while(l->buffer[cont->p] != '\0')
        cont->p++;
    l->mat[0][0] = l->i;
    l->mat[0][1] = l->j;
    validpath(l, cont);
}
