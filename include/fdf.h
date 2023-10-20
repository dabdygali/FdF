/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:01:32 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/20 19:35:46 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MIN_ARGC 2
# define MAX_ARGC 2
# define X_ADD 200
# define Y_ADD 200
# define MLX_ESC_KEYCODE 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define DESTR_CODE 17
# define SCALE_UNIT 10
# define DISP_X_MAX 5120
# define DISP_Y_MAX 2880
# define INIT_X_ANGLE 0.61548
# define INIT_Z_ANGLE 0.785398
# define ANGLE_STEP 0.174533
# include "libft.h"

typedef struct s_mlx_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		size_x;
	int		size_y;
}	t_mlx_window;

typedef struct s_model_point
{
	float	x;
	float	y;
	float	z;
	int		rx;
	int		ry;
}	t_point;

typedef struct s_row_node
{
	t_point				*pts;
	struct s_row_node	*next;
}	t_rownode;

typedef struct s_map_model
{
	t_rownode	*head;
	int			col_count;
	int			row_count;
	float		x_min;
	float		y_min;
	float		x_max;
	float		y_max;
	float		z_min;
	float		angle_x;
	float		angle_y;
	float		angle_z;
}	t_model;

typedef struct s_mlx_img
{
	int				width;
	int				height;
	void			*img_ptr;
	char			*data;
	int				bitperpix;
	int				size_line;
	int				endian;
	unsigned int	color;
}	t_img;

typedef struct s_all_mlx
{
	t_mlx_window	*w;
	t_model			*m;
	t_img			*img;
}	t_all;

int		handle_destroy(void *title);
int		init_window(char *name, t_mlx_window *window, t_all *all);
int		init_model(int argc, char *filepath, t_model *model);
int		parse_line(t_model *model, char *line);
void	set_extremes(t_model *model);
int		model_to_img(t_model *model, t_img *img, void *mlx_ptr);
void	rasterize_model(t_model *model);
void	putpixel_img(t_img *img, int x, int y);
int		ft_abs(int i);
void	rotate_model_z(t_model *model, float angle);
void	rotate_model_y(t_model *model, float angle);
void	rotate_model_x(t_model *model, float angle);
void	clear_img(t_img *img);
void	build_img(t_model *model, t_img *img);
void	move_model_postive(t_model *model);

#endif
