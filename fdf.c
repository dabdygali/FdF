/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:15:12 by dabdygal          #+#    #+#             */
/*   Updated: 2023/09/26 13:57:01 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>
#include <errno.h>
#include "mlx.h"
#include "fdf.h"

static int	append_row(t_model *model, char *line)
{
	return (0);
}

static int	init_model(t_model *model, int fd)
{
	char	*line;

	model->col_count = 0;
	model->row_count = 0;
	model->row.pts = NULL;
	model->row.next = NULL;
	line = get_next_line(fd);
	while (line)
	{
		model->row_count++;
		if (append_row(model, line) < 0)
		{
			ft_putstr_fd("Found wrong line length\n", STDERR_FILENO);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!model->row.pts)
	{
		ft_putstr_fd("No data found\n", STDERR_FILENO);
		return (-1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int				map_fd;
	t_mlx_window	window;
	t_model			model;

	if (init_window(argc, argv, &map_fd, &window, &model) < 0)
		return (EXIT_FAILURE);
	if (init_model(&model, map_fd) < 0)
		return (EXIT_FAILURE);
	close(map_fd);
	mlx_loop(window.mlx_ptr);
	return (EXIT_SUCCESS);
}
