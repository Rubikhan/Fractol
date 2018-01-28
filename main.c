/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:33:34 by smaddux           #+#    #+#             */
/*   Updated: 2018/01/27 16:13:29 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

float ft_shrink(float input, float max)
{
	float n;

	n = max / 4;
	input = input / n;
	input = input - 2; // why?
	return (input);
	
}


 void newmandel1(t_oya *view) 
 { 
 	int x; 
 	int y; 
 	float sx; 
 	float sy; 
 	float i; 
 	float z; 
 	float xx; 
 	float yy; 
 	float xtx; 
 	float cy; 
 	x = 0; 
 	y = 0; 
 	z = 0; 
 	xx = 0; 
 	yy = 0; 
 	xtx = 0; 

 	while(x < 800) 
 	{ 

 		while (y < 800) 
 		{ 
 			i = 0; 
 			sx = ft_shrink((float)x, 800);// 
 			sy = ft_shrink((float)y, 800); 
 			xx = 0; 
 			yy = 0; 
 			while(i < 100) 
 			{ 
 				xtx = xx * yy; 
 				xx = xx * xx - yy * yy + sx; 
 				yy = 2 * xtx + sy; 
 				if (((xx * xx + yy * yy) > 4)) 
 					break; 
 				i++; 
 			} 
 			xx = 0; 
 			yy = 0; 
 			mlx_pixel_put(view->hajimari, view->win, x, y, 0x000015 * i); 
 			y++; 
 		} 
 		y = 0; 
 		x++; 
 	} 

 } 

int tdavis(t_oya *view)
{
	int x = 0;
	int y = 800;

	while (x <= 800)
	{
		draw_line(0, y, x, 0, view);
		y = y - 20;
		x = x + 20;
	}
	return (3);
}

int	z_mandel(t_oya *view)
{
	static float xmin = -2;
	static float ymin = -2;
	static float scale = 200;

	xmin = xmin + 50 / scale;
	ymin = -50 / (scale + 200) / (scale + ymin);
	scale = scale * 2;
	printf("frozen to the face of the earth");
	mlx_clear_window(view->hajimari, view->win);
	mandel1(view, xmin, ymin, scale);
	return (9);

}

int z_julia(t_oya *view)
{
	static float dreal;
	static float dimg;
	static float count = 1;
	
	count++;

	dreal = -.8 + .6 * sin(count/(3.14/20));
	dimg = .156 + .4 * cos(count/(3.14/20));
	mlx_clear_window(view->hajimari, view->win);
	julia2(view, dreal, dimg);
	return (11);
	
	
}

int             key_down_hook(int kcode, t_oya *view)
{
	void *a;

	a = view;
	printf("%d\n", kcode);
	if (kcode == 53)
		exit(0);
	if (kcode == 6 && view->selection == 1)
		z_mandel(view);
	else if (kcode == 6 && view->selection == 2)
		z_julia(view);
	else if(kcode == 0 && view->selection == 4)
	{
		mlx_clear_window(view->hajimari, view->win);
		mlx_hook(view->win, MOTION_NOTIFY, PTR_MOTION_MASK, ft_mousem, view);
	}
	return (0);
}

void argv_frac(t_oya *view, char argv[])
{
	if (ft_strcmp((const char*)argv, "OldMandelbrot") == 0)
		view->selection = 1;
	else if (ft_strcmp((const char*)argv, "OldJulia") == 0)
		view->selection = 2;
	else if (ft_strcmp((const char*)argv, "NewMandelbrot") == 0)
		view->selection = 3;
	else if (ft_strcmp((const char*)argv, "NewJulia") == 0)
		view->selection = 4;
	else 
		view->selection = 0;
		
}

int main (int argc, char *argv[])
{
	t_oya	*first;

	if (argc <= 1 || argc > 2)
	{
		ft_putstr("usage: ./fractol <fractol name>\n");
		exit (0);
	}
	
	first = malloc (sizeof(t_oya));
	first->hajimari = mlx_init();

	argv_frac(first, argv[1]);

	if(first->selection == 1)
	{
		first->win = mlx_new_window(first->hajimari, 800, 800, argv[1]);
		mandel1(first, -2, -2, 200);
	}
	else if (first->selection == 2)
	{
		first->win = mlx_new_window(first->hajimari, 800, 800, argv[1]);
		julia2(first, -.8, .156);
	}
	else if (first->selection == 3)
	{
		first->win = mlx_new_window(first->hajimari, 800, 800, argv[1]);
		newmandel1(first);
	}
	else if (first->selection == 4)
	{
		first->win = mlx_new_window(first->hajimari, 800, 800, argv[1]);
		julia1(first, -1.1380, 0.2403);
	}
	else
	{
		ft_putstr("valid fractols: Mandelbrot\n");
		exit (0);
	}
	mlx_key_hook(first->win, key_down_hook, first);
	mlx_loop(first->hajimari);
}