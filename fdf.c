/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:15:12 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/20 19:41:35 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <math.h>
#include "libft.h"
#include "mlx.h"
#include "fdf.h"

void	min_z_model(t_model *model)
{
	int			i;
	t_rownode	*tmp;

	model->z_min = 0;
	tmp = model->head;
	while (tmp)
	{
		i = 0;
		while (i < model->col_count)
		{
			if (model->z_min > tmp->pts[i].z)
				model->z_min = tmp->pts[i].z;
			i++;
		}
		tmp = tmp->next;
	}
	return ;
}

void	move_model_postive(t_model *model)
{
	t_rownode	*tmp;
	int			i;

	min_z_model(model);
	tmp = model->head;
	while (tmp)
	{
		i = 0;
		while (i < model->col_count)
		{
			if (model->x_min != 0)
				tmp->pts[i].x -= model->x_min;
			if (model->y_min != 0)
				tmp->pts[i].y -= model->y_min;
			if (model->z_min != 0)
				tmp->pts[i].z -= model->z_min;
			i++;
		}
		tmp = tmp->next;
	}
	set_extremes(model);
	min_z_model(model);
}

void	prepare_win(t_all all)
{
	rotate_model_z(all.m, INIT_Z_ANGLE);
	rotate_model_x(all.m, INIT_X_ANGLE);
	move_model_postive(all.m);
	all.img->width = round(all.m->x_max) - round(all.m->x_min) + 1 + X_ADD;
	all.img->height = round(all.m->y_max) - round(all.m->y_min) + 1 + Y_ADD;
	all.w->size_x = all.img->width + X_ADD;
	if (all.w->size_x >= DISP_X_MAX)
		all.w->size_x = 2500;
	all.w->size_y = all.img->height + Y_ADD;
	if (all.w->size_y >= DISP_Y_MAX)
		all.w->size_y = 1000;
	all.img->color = mlx_get_color_value(all.w->mlx_ptr, 0xFFFFFF);
}

int	main(int argc, char *argv[])
{
	t_mlx_window	window;
	t_model			model;
	t_img			img;
	int				(*disp_img)(void*, void*, void*, int, int);
	t_all			all;

	if (init_model(argc, argv[1], &model) < 0)
		return (EXIT_FAILURE);
	all.img = &img;
	all.m = &model;
	all.w = &window;
	prepare_win(all);
	if (init_window(argv[1], &window, &all) < 0)
		return (EXIT_FAILURE);
	if (model_to_img(&model, &img, window.mlx_ptr) < 0)
		return (EXIT_FAILURE);
	disp_img = &mlx_put_image_to_window;
	disp_img(window.mlx_ptr, window.win_ptr, img.img_ptr, 0, 0);
	mlx_loop(window.mlx_ptr);
	return (EXIT_SUCCESS);
}
