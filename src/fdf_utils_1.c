/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:50:38 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/20 14:22:19 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	append_row_node(t_model *model, t_point *points)
{
	t_rownode	*tmp;
	t_rownode	*node;

	node = (t_rownode *) malloc(sizeof(t_rownode));
	if (!node)
		return (-1);
	node->pts = points;
	node->next = NULL;
	if (!model->head)
		model->head = node;
	else
	{
		tmp = model->head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (0);
}

int	append_row(t_model *model, char **str)
{
	t_point		*points;
	int			i;

	points = (t_point *) malloc(sizeof(t_point) * model->col_count);
	if (!points)
		return (-1);
	i = 0;
	while (str[i])
	{
		points[i].x = (float)(i * SCALE_UNIT);
		points[i].y = (float)((model->row_count - 1) * SCALE_UNIT);
		points[i].z = (float) ft_atoi(str[i]) * SCALE_UNIT;
		i++;
	}
	if (i < model->col_count)
	{
		free (points);
		return (-1);
	}
	if (append_row_node(model, points) < 0)
	{
		free(points);
		return (-1);
	}
	return (0);
}

int	parse_line(t_model *model, char *line)
{
	char		**str;

	if (ft_strchr(line, '\n'))
		*(ft_strchr(line, '\n')) = '\0';
	str = ft_split(line, ' ');
	if (model->col_count == 0)
	{
		while (str[model->col_count])
			model->col_count++;
		if (model->col_count == 0)
		{
			ft_putstr_fd("No data found\n", STDERR_FILENO);
			free(str);
			return (-1);
		}
	}
	if (append_row(model, str) < 0)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}

static void	init_zeros(t_model *model)
{
	model->col_count = 0;
	model->row_count = 0;
	model->head = NULL;
	model->angle_x = 0;
	model->angle_y = 0;
	model->angle_x = 0;
	return ;
}

int	init_model(int argc, char *filepath, t_model *model)
{
	char	*line;
	int		fd;

	if (ft_checkwarn_argc(argc, MIN_ARGC, MAX_ARGC) < 0)
		return (-1);
	fd = open(filepath, O_RDONLY);
	if (ft_checkwarn_open_fd(fd) < 0)
		return (-1);
	init_zeros(model);
	line = get_next_line(fd);
	while (line)
	{
		model->row_count++;
		if (parse_line(model, line) < 0)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	set_extremes(model);
	return (0);
}
