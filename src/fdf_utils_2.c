/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:23:54 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/02 11:41:13 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

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

int	model_to_img(t_model *model, t_img *img, void *mlx_ptr)
{
	int	*bpp;
	int	*size_line;

	bpp = &img->bitperpix;
	size_line = &img->size_line;
	img->img_ptr = mlx_new_image (mlx_ptr, img->width, img->height);
	if (!img->img_ptr)
		return (-1);
	img->data = mlx_get_data_addr(img->img_ptr, bpp, size_line, &img->endian);
	return (0);
}
