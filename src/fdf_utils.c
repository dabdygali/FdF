/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:06:00 by dabdygal          #+#    #+#             */
/*   Updated: 2023/09/26 10:59:20 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include "mlx.h"
#include "libft.h"
#include "fdf.h"

int	init_window(int argc, char **argv, int *fd, t_mlx_window *window)
{
	if (ft_checkwarn_argc(argc, MIN_ARGC, MAX_ARGC) < 0)
		return (-1);
	*fd = open(argv[1], O_RDONLY);
	if (ft_checkwarn_open_fd(*fd) < 0)
		return (-1);
	window->mlx_ptr = mlx_init();
	if (checkwarn_mlx_init(window->mlx_ptr) < 0)
		return (-1);
	window->win_ptr = mlx_new_window(window->mlx_ptr, SIZE_X, SIZE_Y, argv[1]);
	if (checkwarn_mlx_new_window(window->win_ptr) < 0)
		return (-1);
	mlx_key_hook(window->win_ptr, handle_key, (void *) window);
	mlx_hook(window->win_ptr, DESTR_CODE, 0, handle_destroy, (void *) argv[1]);
	return (0);
}

int	checkwarn_mlx_init(void *mlx_ptr)
{
	if (mlx_ptr == NULL)
	{
		errno = ECONNREFUSED;
		perror("Failed to connect to a graphics server");
		return (-1);
	}
	return (0);
}

int	checkwarn_mlx_new_window(void *win_ptr)
{
	if (win_ptr == NULL)
	{
		errno = ENOSYS;
		perror("Failed to create a window");
		return (-1);
	}
	return (0);
}

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
