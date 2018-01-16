/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:33:34 by smaddux           #+#    #+#             */
/*   Updated: 2018/01/15 18:32:10 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

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

int             key_down_hook(int kcode, t_oya *view)
{
	void *a;

	a = view;
	printf("%d\n", kcode);
	if (kcode == 53)
		exit(0);
	if (kcode == 6)
		z_mandel(view);
	return (0);
}



int main (int argc, char *argv[])
{
	t_oya	*first;

	
	first = malloc (sizeof(t_oya));

	first->hajimari = mlx_init();

	first->win = mlx_new_window(first->hajimari, 800, 800, argv[1]);

	mandel1(first, -2, -2, 200);
	printf("one");
	mlx_key_hook(first->win, key_down_hook, first);
	printf("two");
	mlx_loop(first->hajimari);
	printf("three");
}