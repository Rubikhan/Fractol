/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:05:16 by smaddux           #+#    #+#             */
/*   Updated: 2018/01/04 17:00:02 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//x0 y0 x1 

//rename y2 = y1?

t_dl    *dl_helper1(int x0, int y0, int x1,  int y1)
{
    t_dl *a;

    a = malloc(sizeof(t_dl));
    a->steepbool = 0;
    a->xstart = x0;
    a->ystart = y0;
    a->xfin = x1;
    a->yfin = y1;
    return (a);
}

void    dl_helper2(t_dl *a)
{
    a->tempstart = a->xstart;
    a->tempfin = a->xfin;
    a->xstart = a->ystart;
    a->xfin = a->yfin;
    a->ystart = a->tempstart;
    a->yfin = a->tempfin;
    a->steepbool = 1;
}

void    dl_helper3(t_dl *a)
{
    a->tempx = a->xfin;
    a->tempy = a->yfin;
    a->xfin = a->xstart;
    a->yfin = a->ystart;
    a->xstart = a->tempx;
    a->ystart = a->tempy;
}

void    dl_helper4(t_dl *a)
{
    a->dx = a->xfin - a->xstart;
    a->dy = a->yfin - a->ystart;
    a->derror = ft_abs(a->dy) * 2;
    a->error = 0;
    a->jy = a->ystart;
    a->jx = a->xstart;
}

int     draw_line(int x0, int y0, int x1,  int y1, t_oya *view)
{
    t_dl *a;

    a = dl_helper1(x0, y0, x1, y1);
    if (ft_abs(a->xstart - a->xfin) < ft_abs(a->ystart - a->yfin))
        dl_helper2(a);
    if (a->xstart > a->xfin)
        dl_helper3(a);
    dl_helper4(a);
    while (a->jx <= a->xfin)
    {
        if (a->steepbool)
            mlx_pixel_put(view->hajimari, view->win, a->jy, a->jx, 0x33AC88);
        else
            mlx_pixel_put(view->hajimari, view->win, a->jx, a->jy, 0x33AC88);
        a->error += a->derror;
        if (a->error > a->dx)
        {
            a->jy += (a->yfin > a->ystart ? 1 : -1);
            a->error -= a->dx * 2;
        }
        a->jx++;
    }
    return (1);
}