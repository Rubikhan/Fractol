/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:15:37 by smaddux           #+#    #+#             */
/*   Updated: 2018/01/15 17:18:53 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandel1(t_oya *view , float xmin, float ymin, float scale)
{
	float x = 0;
	float y = 0;
	float i;
	float xt;
	float cx;
	float cy;
	float zx;
	float zy;
	int color = 0x000022;
	int acolor = 0;

	while(x < 800)
	{
		while (y < 800)
		{
			i = 0;
			cx = xmin + x / scale;
			cy = ymin + y / scale;
			zx = 0;
			zy = 0;
			while (i < 255 && ((zx * zx + zy * zy) < 4)) 
			{
				xt = zx * zy;
				zx = zx * zx - zy * zy + cx;
				zy = 2 * xt + cy;
				i++;
			}
			acolor = color * i; 
			zx = 0;
			zy = 0;
			y++;
			mlx_pixel_put(view->hajimari, view->win, x, y, acolor);
		}
		y = 0;
		x++;
	}
	return (1);

}