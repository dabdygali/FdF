/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:01:32 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/02 11:37:59 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MIN_ARGC 2
# define MAX_ARGC 2
# define X_ADD 100
# define Y_ADD 100
# define MLX_ESC_KEYCODE 53
# define DESTR_CODE 17
# define SCALE_UNIT 10
# include "libft.h"

typedef struct mlx_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		size_x;
	int		size_y;
}	t_mlx_window;

typedef struct model_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct row_node
{
	t_point			*pts;
	struct row_node	*next;
}	t_rownode;

typedef struct map_model
{
	t_rownode	*head;
	int			col_count;
	int			row_count;
	float		x_min;
	float		y_min;
	float		x_max;
	float		y_max;
}	t_model;

typedef struct mlx_img
{
	int		width;
	int		height;
	void	*img_ptr;
	char	*data;
	int		bitperpix;
	int		size_line;
	int		endian;
}	t_img;

int		checkwarn_mlx_init(void *mlx_ptr);
int		checkwarn_mlx_new_window(void *win_ptr);
int		handle_key(int keycode, void *window);
int		handle_destroy(void *title);
int		init_window(char *name, t_mlx_window *window);
int		init_model(int argc, char *filepath, t_model *model);
int		parse_line(t_model *model, char *line);
void	set_extremes(t_model *model);

#endif
