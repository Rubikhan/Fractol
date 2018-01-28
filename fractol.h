/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:08:41 by smaddux           #+#    #+#             */
/*   Updated: 2018/01/27 16:25:34 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"

# define MOTION_NOTIFY 6 //
# define PTR_MOTION_MASK (1L << 6) //

typedef struct      s_dl
{
    int steepbool;
    int xstart;
    int ystart;
    int xfin;
    int yfin;
    int tempstart;
    int tempfin;
    int tempx;
    int tempy;
    int dx;
    int dy;
    int derror;
    int error;
    int jy;
    int jx;
}                   t_dl;

typedef struct		s_oya
{
	void	*hajimari;
	void	*win;
	int		selection;
}					t_oya;

int     			draw_line(int x0, int y0, int x1, int y1, t_oya *view);
int					key_down_hook(int kcode, t_oya *view);
int					mandel1(t_oya *view, float xmin, float ymin, float scale);
int					julia1(t_oya *view, double cr, double ci);
int					julia2(t_oya *view,  float creal, float cimg);
int					ft_mousem(int x, int y, t_oya *view);

#endif