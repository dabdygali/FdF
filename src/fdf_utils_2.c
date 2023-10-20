/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:23:54 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/20 17:46:56 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>

void	bressenham_y(t_img *img, t_point a, t_point b)
{
	int	x;
	int	y;
	int	p;
	int	dx;
	int	xi;

	dx = ft_abs(b.rx - a.rx);
	p = (2 * dx) - (b.ry - a.ry);
	x = a.rx;
	y = a.ry;
	xi = 1;
	if (b.rx < a.rx)
		xi = -1;
	while (y <= b.ry)
	{
		putpixel_img(img, x, y++);
		if (p < 0)
			p = p + (2 * dx);
		else
		{
			p = p + (2 * (dx - (b.ry - a.ry)));
			x += xi;
		}
	}
	return ;
}

void	bressenham_x(t_img *img, t_point a, t_point b)
{
	int	x;
	int	y;
	int	p;
	int	dy;
	int	yi;

	dy = ft_abs(b.ry - a.ry);
	p = (2 * dy) - (b.rx - a.rx);
	x = a.rx;
	y = a.ry;
	yi = 1;
	if (b.ry < a.ry)
		yi = -1;
	while (x <= b.rx)
	{
		putpixel_img(img, x++, y);
		if (p < 0)
			p = p + (2 * dy);
		else
		{
			p = p + (2 * (dy - (b.rx - a.rx)));
			y += yi;
		}
	}
	return ;
}

void	draw_line(t_img *img, t_point a, t_point b)
{
	if (a.rx < 0 || a.ry < 0 || b.rx < 0 || b.ry < 0)
		return ;
	if (ft_abs(b.ry - a.ry) <= ft_abs(b.rx - a.rx))
	{
		if (b.rx >= a.rx)
			bressenham_x(img, a, b);
		else
			bressenham_x(img, b, a);
	}
	else
	{
		if (b.ry >= a.ry)
			bressenham_y(img, a, b);
		else
			bressenham_y(img, b, a);
	}
	return ;
}

void	build_img(t_model *model, t_img *img)
{
	t_rownode	*tmp;
	int			i;

	clear_img(img);
	tmp = model->head;
	while (tmp)
	{
		i = 0;
		while (i < model->col_count)
		{
			if (i < model->col_count - 1)
				draw_line(img, tmp->pts[i], tmp->pts[i + 1]);
			if (tmp->next)
				draw_line(img, tmp->pts[i], tmp->next->pts[i]);
			i++;
		}
		tmp = tmp->next;
	}
	return ;
}

int	model_to_img(t_model *model, t_img *img, void *mlx_ptr)
{
	int	*bpp;
	int	*size_line;

	img->data = NULL;
	img->img_ptr = NULL;
	bpp = &img->bitperpix;
	size_line = &img->size_line;
	img->img_ptr = mlx_new_image (mlx_ptr, img->width, img->height);
	if (!img->img_ptr)
		return (-1);
	img->data = mlx_get_data_addr(img->img_ptr, bpp, size_line, &img->endian);
	if (!img->data)
		return (-1);
	if (*bpp % 2)
		return (-1);
	rasterize_model(model);
	build_img(model, img);
	return (0);
}
