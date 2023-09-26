/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:01:32 by dabdygal          #+#    #+#             */
/*   Updated: 2023/09/26 13:13:35 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MIN_ARGC 2
# define MAX_ARGC 2
# define SIZE_X 500
# define SIZE_Y 500
# define MLX_ESC_KEYCODE 53
# define DESTR_CODE 17
# define SCALE_UNIT 20

typedef struct mlx_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_window;

typedef struct model_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct row_list
{
	t_point		*pts;
	t_rowlist	*next;
}	t_rowlist;

typedef struct map_model
{
	t_rowlist	row;
	int			col_count;
	int			row_count;
}	t_model;

int	checkwarn_mlx_init(void *mlx_ptr);
int	checkwarn_mlx_new_window(void *win_ptr);
int	handle_key(int keycode, void *window);
int	handle_destroy(void *title);
int	init_window(int argc, char **argv, int *fd, t_mlx_window *window);

#endif
