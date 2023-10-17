/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:15:12 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/16 11:14:18 by dabdygal         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_mlx_window	window;
	t_model			model;
	t_img			img;

	if (init_model(argc, argv[1], &model) < 0)
		return (EXIT_FAILURE);
	img.width = (int) round(model.x_max - model.x_min);
	img.height = (int) round(model.y_max - model.y_min);
	window.size_x = img.width + X_ADD;
	window.size_y = img.height + Y_ADD;
	if (init_window(argv[1], &window) < 0)
		return (EXIT_FAILURE);
	if (model_to_img(&model, &img, window.mlx_ptr) < 0)
		return (EXIT_FAILURE);
	mlx_loop(window.mlx_ptr);
	return (EXIT_SUCCESS);
}
