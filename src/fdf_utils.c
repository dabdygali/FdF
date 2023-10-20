/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:06:00 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/20 19:15:57 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "mlx.h"
#include "fdf.h"

void	rasterize_model(t_model *model)
{
	int			i;
	t_rownode	*tmp;

	tmp = model->head;
	while (tmp)
	{
		i = 0;
		while (i < model->col_count)
		{
			tmp->pts[i].rx = round(tmp->pts[i].x);
			tmp->pts[i].ry = round(tmp->pts[i].y);
			i++;
		}
		tmp = tmp->next;
	}
	return ;
}

void	set_extremes(t_model *model)
{
	int			i;
	t_rownode	*tmp;

	tmp = model->head;
	model->x_max = 0;
	model->y_max = 0;
	model->x_min = 0;
	model->y_min = 0;
	while (tmp)
	{
		i = -1;
		while (++i < model->col_count)
		{
			if (model->x_max < tmp->pts[i].x)
				model->x_max = tmp->pts[i].x;
			if (model->y_max < tmp->pts[i].y)
				model->y_max = tmp->pts[i].y;
			if (model->x_min > tmp->pts[i].x)
				model->x_min = tmp->pts[i].x;
			if (model->y_min > tmp->pts[i].y)
				model->y_min = tmp->pts[i].y;
		}
		tmp = tmp->next;
	}
	return ;
}

int	handle_key(int keycode, void *all)
{
	t_all	*a;
	void	*ptr;

	a = (t_all *) all;
	ptr = a->w->mlx_ptr;
	if (keycode == MLX_ESC_KEYCODE)
	{
		mlx_destroy_window(a->w->mlx_ptr, a->w->win_ptr);
		exit(0);
	}
	if (keycode == KEY_LEFT)
		rotate_model_y(a->m, -ANGLE_STEP);
	if (keycode == KEY_RIGHT)
		rotate_model_y(a->m, ANGLE_STEP);
	if (keycode == KEY_UP)
		rotate_model_x(a->m, ANGLE_STEP);
	if (keycode == KEY_DOWN)
		rotate_model_x(a->m, -ANGLE_STEP);
	move_model_postive(a->m);
	rasterize_model(a->m);
	build_img(a->m, a->img);
	mlx_put_image_to_window(ptr, a->w->win_ptr, a->img->img_ptr, 0, 0);
	return (0);
}

int	handle_destroy(void *title)
{
	ft_printf("Window \"%s\" was closed\n", title);
	exit(0);
	return (0);
}

int	init_window(char *name, t_mlx_window *win, t_all *all)
{
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == NULL)
	{
		errno = ECONNREFUSED;
		perror("Failed to connect to a graphics server");
		return (EXIT_FAILURE);
	}
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->size_x, win->size_y, name);
	if (win->win_ptr == NULL)
	{
		errno = ENOSYS;
		perror("Failed to create a window");
		return (-1);
	}
	mlx_key_hook(win->win_ptr, handle_key, (void *) all);
	mlx_hook(win->win_ptr, DESTR_CODE, 0, handle_destroy, (void *) name);
	return (0);
}
