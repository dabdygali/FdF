/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:26:31 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/20 18:44:45 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rotate_model_y(t_model *model, float angle)
{
	t_rownode	*tmp;
	int			i;
	float		x;
	float		z;

	tmp = model->head;
	while (tmp)
	{
		i = 0;
		while (i < model->col_count)
		{
			x = tmp->pts[i].x;
			z = tmp->pts[i].z;
			tmp->pts[i].x = (x * cos(angle)) + (z * sin(angle));
			tmp->pts[i].z = -(x * sin(angle)) + (z * cos(angle));
			i++;
		}
		tmp = tmp->next;
	}
	model->angle_y += angle;
	if (model->angle_y >= 2 * M_PI || model->angle_y <= -(2 * M_PI))
		model->angle_y = fmod(model->angle_y, 2 * M_PI);
	set_extremes(model);
}

void	rotate_model_x(t_model *model, float angle)
{
	t_rownode	*tmp;
	int			i;
	float		y;
	float		z;

	tmp = model->head;
	while (tmp)
	{
		i = 0;
		while (i < model->col_count)
		{
			y = tmp->pts[i].y;
			z = tmp->pts[i].z;
			tmp->pts[i].y = (y * cos(angle)) - (z * sin(angle));
			tmp->pts[i].z = (y * sin(angle)) + (z * cos(angle));
			i++;
		}
		tmp = tmp->next;
	}
	model->angle_x = angle;
	if (model->angle_x >= 2 * M_PI || model->angle_x <= -(2 * M_PI))
		model->angle_x = fmod(model->angle_x, 2 * M_PI);
	set_extremes(model);
}

void	rotate_model_z(t_model *model, float angle)
{
	t_rownode	*tmp;
	int			i;
	float		x;
	float		y;

	tmp = model->head;
	while (tmp)
	{
		i = 0;
		while (i < model->col_count)
		{
			x = tmp->pts[i].x;
			y = tmp->pts[i].y;
			tmp->pts[i].x = (x * cos(angle)) - (y * sin(angle));
			tmp->pts[i].y = (x * sin(angle)) + (y * cos(angle));
			i++;
		}
		tmp = tmp->next;
	}
	model->angle_z = angle;
	if (model->angle_z >= 2 * M_PI || model->angle_z <= -(2 * M_PI))
		model->angle_z = fmod(model->angle_z, 2 * M_PI);
	set_extremes(model);
}

void	putpixel_img(t_img *img, int x, int y)
{
	int	pxi;
	int	i;
	int	shift;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	i = img->bitperpix / (sizeof(char) * 8);
	shift = img->bitperpix - (sizeof(char) * 8);
	pxi = (y * img->size_line) + (x * i);
	if (pxi + i > img->width * img->height * i)
		return ;
	while (--i >= 0)
	{
		if (img->endian == 1)
			img->data[pxi + i] = (img->color >> (shift - (i * 8))) & 0xFF;
		else if (img->endian == 0)
			img->data[pxi + i] = (img->color >> (i * 8)) & 0xFF;
	}
	return ;
}

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}
