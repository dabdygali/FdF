/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:32:05 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/20 17:07:09 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_img *img)
{
	int	max;
	int	i;

	max = img->width * img->height * (img->bitperpix / (sizeof(char) * 8));
	i = 0;
	while (i < max)
	{
		img->data[i] = 0;
		i++;
	}
}
