/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:15:12 by dabdygal          #+#    #+#             */
/*   Updated: 2023/09/28 13:48:33 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <math.h>
#include "libft.h"
#include "mlx.h"
#include "fdf.h"

/*
void	print_model(t_model *model)
{
	int			i;
	int			j;
	t_rownode	*tmp;

	i = 0;
	tmp = model->head;
	while (i < model->row_count)
	{
		j = 0;
		while (j < model->col_count)
		{
			printf("%.1f ", tmp->pts[j].z);
			j++;
		}
		printf("\n");
		tmp = tmp->next;
		i++;
	}
}*/

int	calc_win_size(t_model *model, int *x, int *y)
{
	int			j;
	t_rownode	*tmp;
	int			x_max;
	int			y_max;

	tmp = model->head;
	x_max = 0;
	y_max = 0;
	while (tmp)
	{
		j = 0;
		while (j < model->col_count)
		{
			if (x_max < fabs((double) tmp->pts[j].x))
				x_max = (int) ceil((double) tmp->pts[j].x);
			if (y_max < fabs((double) tmp->pts[j].y))
				y_max = (int) ceil((double) tmp->pts[j].y);
			j++;
		}
		tmp = tmp->next;
	}
	*x = x_max + X_ADD;
	*y = y_max + Y_ADD;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx_window	window;
	t_model			model;
	t_img			img;

	if (init_model(argc, argv[1], &model) < 0)
		return (EXIT_FAILURE);
	if (calc_win_size(&model, &window.size_x, &window.size_y) < 0)
		return (EXIT_FAILURE);
	if (init_window(argv[1], &window) < 0)
		return (EXIT_FAILURE);
	if (model_to_img(&model, &img, window.mlx_ptr) < 0)
		return (EXIT_FAILURE);
	mlx_loop(window.mlx_ptr);
	return (EXIT_SUCCESS);
}
