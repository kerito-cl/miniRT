#ifndef MINI_RT_H
# define MINI_RT_H
# define WIDTH 1980
# define HEIGHT 1080
# define INFINITY 1080

# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_arena
{
    char *arena_start;
    char *current;
    size_t total_size;
    size_t used_size;
} t_arena;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}       t_vec3;

typedef struct s_ray
{
	t_vec3 orig;
	t_vec3 direc;
}       t_ray;

typedef struct s_cam
{
	t_vec3 point;
	t_vec3 orient;
	unsigned int	fov;
}       t_cam;

typedef struct s_alight
{
	t_vec3 rgb;
	double	ratio;
}       t_alight;

typedef struct s_light
{
	t_vec3 point;
	t_vec3 rgb;
	double	br_ratio;
}       t_light;

typedef struct s_pl
{
	t_vec3 point;
	t_vec3 rgb;
	t_vec3 norm;
}       t_pl;

typedef struct s_sp
{
	t_vec3 center;
	t_vec3 rgb;
	double radius;
}       t_sp;

typedef struct s_cy
{
	t_vec3 center;
	t_vec3 rgb;
	t_vec3 norm;
	double radius;
	double height;
}       t_cy;

typedef struct s_info
{
	t_arena *arena;
	mlx_t *mlx;
	mlx_image_t		*img;
	t_cam c;
	t_alight a;
	t_light	l;
	t_pl	pl;
	t_sp	sp;
	t_cy	cy;
	t_ray	ray;
}       t_info;


void	print_vec3(t_vec3 vec3);


t_arena *arena_init(size_t size);
void arena_free(t_arena *arena);
void	throw_error(int flag);
int     check_if_rt(char *str);
void    parse(char *file, t_info *info);
void	freesplit(char **strs);
void    new_vec3(t_vec3 *vec3, char **cvec);
void	assign_plane_info(t_info *info, char **split);
void assign_sphere_info(t_info *info, char **split);
void assign_cylinder_info(t_info *info, char **split);
void	free_all(t_info *info);

/*        OPERATIONS                       */

double    dot_calculation(t_vec3 vec1, t_vec3 vec2);
double    vec_length(t_vec3 vec1);
void    vec_normalize(t_vec3 *vec1);
void    vec_substract(t_vec3 *vec1, t_vec3 vec2);
double intersect_plane(t_ray ray, t_pl pl);
double intersect_sphere(t_ray ray, t_sp sp);
void    get_point_from_ray(t_vec3 *point ,t_ray ray, double t);
t_vec3    multiply_colors(t_vec3 startcolor , t_vec3 endcolor);


#endif