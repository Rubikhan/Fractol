/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:26:31 by smaddux           #+#    #+#             */
/*   Updated: 2018/01/27 16:25:08 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_mousem(int x, int y, t_oya *view)
{
	int cr;
	int ci;
	if(x >= 0 && x <= 800 && y >= 0 && y <= 800)
	{
		cr = -3.2 + ((x * 3.4) / 800);
		ci = -3.2 + ((y * 3.4) / 800);
		julia1(view, cr, ci);
	}
	return (1);
}

int julia1(t_oya *view, double cr, double ci)
{

	double minx;
	double miny;
	double x;
	double y;
	double tmp;
	int i;
	double pr;
	double pi;
	double iter;
	int acolor;
	acolor = 0x000035;
	
	x = 0;
	y = 0;
	while (x < 800)
	{
		while (y < 800)
		{
			i = -1;
			pr =  -3.2 + (x * (3.4 + 3.2) / 800);
			pi = -3.2 + (y * (3.4 + 3.2)/ 800);
//			cr = -1.1380;
//			ci = 0.2403;
			while(++i < 16 && (pr * pr + pi * pi) < 4) 
			{
				tmp = pr;
				pr = pr * pr - pi * pi + cr;
				pi = 2 * pi * tmp + ci;
			}
			mlx_pixel_put(view->hajimari, view->win, y, x, acolor * i);
			y++;
		}
		y = 0;
		x++;
	}



	return (26);
}

int julia2(t_oya *view, float creal, float cimg)
{

	float y;
	float x;
	float cx;
	float cy;
	float xt;
	int i;
	int color = 0x000022;
	int acolor = 0;

	x = 0;
	y = 0;

	while (y < 800)
	{

		while (x < 800)
		{
			cx = -2 + x / 200;
			cy = -2 + y / 200;
			i = 0;
			while ((cx * cx + cy * cy < 4) && i < 255)
			{
				xt = cx * cx - cy * cy + creal;
				cy = 2 * cx * cx + cimg;
				cx = xt;
				i++;
			}
			acolor = color * i;
			mlx_pixel_put(view->hajimari, view->win, y, x, acolor);
			x++;
		}
		x = 0;
		y++;
	}

	ft_putstr("hi this is from julia2\n");
	return (1);
}