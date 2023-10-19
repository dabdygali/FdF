/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:26:31 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/19 14:07:30 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putpixel_img(t_img *img, int x, int y)
{
	int	i;

	i = (y * img->size_line) + (x * (img->bitperpix / sizeof(char)));
	return ;
}

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}
