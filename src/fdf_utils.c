/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:06:00 by dabdygal          #+#    #+#             */
/*   Updated: 2023/09/28 13:01:09 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include "mlx.h"
#include "fdf.h"

int	handle_key(int keycode, void *window)
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (keycode == MLX_ESC_KEYCODE)
	{
		mlx_ptr = ((t_mlx_window *) window)->mlx_ptr;
		win_ptr = ((t_mlx_window *) window)->win_ptr;
		mlx_destroy_window(mlx_ptr, win_ptr);
		exit(0);
	}
	return (0);
}

int	handle_destroy(void *title)
{
	ft_printf("Window \"%s\" was closed\n", title);
	exit(0);
	return (0);
}

int	init_window(char *name, t_mlx_window *win)
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
	mlx_key_hook(win->win_ptr, handle_key, (void *) win);
	mlx_hook(win->win_ptr, DESTR_CODE, 0, handle_destroy, (void *) name);
	return (0);
}
