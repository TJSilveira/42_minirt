/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:16:39 by tsilveir          #+#    #+#             */
/*   Updated: 2025/08/18 18:16:40 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "../libft/libft.h"
# include <math.h>
# include "../minilibx-linux/mlx.h"
# define X 0
# define Y 1
# define Z 2
# define R 0
# define G 1
# define B 2
# define IMAGE_WIDTH 1200

#include <stdio.h>

typedef struct s_vec3 
{
	double e[3];
} t_vec3, t_color3, t_point3;

typedef struct ray
{
	struct s_vec3 *dir;
	t_point3 *orig;
} ray;

typedef struct s_sphere
{
	t_point3 center;
	double ray;
}t_sphere;

typedef struct s_image
{
	void			*img;
	char			*addr;
	int				pix_bits;
	int				line_len;
	int				endian;
	int				iter;
	// int				fractal_type;
	// unsigned int	main_color;
	// unsigned int	secundary_color;
}	t_image;

typedef struct s_camera
{
	double	focal_length;
    double	vp_height;
    double	vp_width;
	t_vec3	vec_right;
    t_vec3	vec_down;
    t_vec3	vec_focal;
	t_vec3	pixel_delta_right;
	t_vec3	pixel_delta_down;
	t_point3	camera_center;
	t_point3	vp_upper_left;
	t_point3	pixel00_loc;
}t_camera;

typedef struct s_engine
{
	void			*mlx;
	void			*window;
	unsigned int	win_w;
	unsigned int	win_h;
	double			aspect_ratio;
	t_image			img;
	t_camera		cam;
}	t_engine;


typedef struct s_pixel
{
	int	x;
	int	y;
	t_point3		center;
	unsigned int	clr;
}	t_pixel;

// utils.c function prototypes
void print_vec3(t_vec3 *v);
t_vec3 init_vec3(double x, double y, double z);
t_vec3 unit_vec3(t_vec3 *v);
double vec3_dot(t_vec3 *v1, t_vec3 *v2);

double		length_squared(t_vec3 *v);
double		length(t_vec3 *v);

t_vec3		vec3_mul_const_copy(t_vec3 v, double t);
void		vec3_mul_const(t_vec3 *v, double t);

t_vec3		vec3_div_const_copy(t_vec3 v, double t);
void		vec3_div_const(t_vec3 *v, double t);

t_vec3		vec3_add_2inst_copy(t_vec3 v1, t_vec3 v2);
void		vec3_add_2inst(t_vec3 *v1, t_vec3 *v2);

t_vec3		vec3_sub_2inst_copy(t_vec3 v1, t_vec3 v2);
void		vec3_sub_2inst(t_vec3 *v1, t_vec3 *v2);

// colors.c
void write_color(t_color3 *c);

// t_camera.c
void init_camera_upper_left(t_camera *c);
void init_pixel00(t_camera *c);
void init_camera(t_engine *e);
t_point3 calculate_pixel_center(t_camera *c, int row, int col);

// ray.c
unsigned int ray_color(ray *r);
t_point3 point_at_ray(ray *r, double t);
int	hit_sphere(t_sphere *s, ray *r);

// mlx_utils.c
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	update_pixel(t_engine *e);
void	init_img(t_engine *e);
void	init_engine(t_engine *e);

#endif