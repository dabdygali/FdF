/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:23:54 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/18 11:13:40 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

void	bressenham_lda(t_img *img, t_point a, t_point b)
{
	a.rx = round(a.x);
	a.ry = round(a.y);
	b.rx = round(b.x);
	b.ry = round(b.y);
}

int	draw_lines(t_model *model, t_img *img)
{
	t_rownode	*tmp;
	int			i;

	tmp = model->head;
	while (tmp)
	{
		i = 0;
		while (i < model->col_count)
		{
			if (i < model->col_count - 1)
				bressenham_lda(img, tmp->pts[i], tmp->pts[i + 1]);
			if (tmp->next)
				bressenham_lda(img, tmp->pts[i], tmp->next->pts[i]);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
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
	if (!img->data)
		return (-1);
	if (*bpp % 2)
		return (-1);
	if (draw_lines(model, img) < 0)
		return (-1);
	return (0);
}
