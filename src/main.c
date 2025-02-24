/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:45:28 by mquero            #+#    #+#             */
/*   Updated: 2025/02/24 17:45:23 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "mini_rt.h"
void	print_vec3(t_vec3 vec3)
{
	printf("x : %f\n", vec3.x);
	printf("y : %f\n", vec3.y);
	printf("z : %f\n", vec3.z);

}
unsigned int get_color(t_vec3 vec1, t_vec3 vec2, double t)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	if (t > 1)
		t = 1;
	if (t < 0)
		t = 0;
	r = vec1.x + (vec2.x - vec1.x) * t;
	g = vec1.y + (vec2.y - vec1.y) * t;
	b = vec1.z + (vec2.z - vec1.z) * t;
	return ((r << 24) + (g << 16) + (b << 8) + 255);
}

void	draw(t_info *info)
{
	t_vec3	sky;
	t_vec3	fog;
	t_vec3	intersect_color;
	t_vec3	intersect_point;
	t_vec3	intersect_normal;
	t_vec3	final_color;
	t_vec3	to_light;
	unsigned int	color;
	unsigned int	col;
	unsigned int	row;
	double	t;
	double	x;
	double	y;
	double	nearest_t;
	double	aspect_ratio;
	double	intensity;

	t = 0;
	row = 0;
	vec_normalize(&info->pl.norm);
	ft_memcpy(&info->ray.orig, &info->c.point, sizeof(t_vec3));
	sky.x = 5;
	sky.y = 5;
	sky.z = 255;
	fog.x = 178;
	fog.y = 178;
	fog.z = 178;
	to_light.x = 1;
	to_light.y = 1;
	to_light.z = 1;
	vec_normalize(&to_light);
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			x = (double)col / (WIDTH - 1);
			y = (double)row / (HEIGHT - 1);
			y = 1 - y;
			x = (x * 2) - 1;
			y = (y * 2) - 1;
			aspect_ratio = (double)WIDTH / HEIGHT;
			x = x * aspect_ratio;
			info->ray.direc.x = x;
			info->ray.direc.y = y;
			info->ray.direc.z = -2;
			vec_normalize(&(info->ray).direc);

			ft_bzero(&intersect_color, sizeof(t_vec3));
			nearest_t = INFINITY;
			t = intersect_sphere(info->ray, info->sp);
			if (t < nearest_t)
			{
				nearest_t = t;
				get_point_from_ray(&intersect_point, info->ray, t);
				ft_memcpy(&intersect_normal, &intersect_point, sizeof(t_vec3));
				vec_substract(&intersect_point, info->sp.center);
				ft_memcpy(&intersect_color, &info->sp.rgb, sizeof(t_vec3));
				//color = get_color(info->sp.rgb, info->sp.rgb, 0);
			}
			t = intersect_plane(info->ray, info->pl);
			if (t < nearest_t)
			{
				nearest_t = t;
				ft_memcpy(&intersect_normal, &info->pl.norm, sizeof(t_vec3));
				ft_memcpy(&intersect_color, &info->pl.rgb, sizeof(t_vec3));
				//color = get_color(info->pl.rgb, fog, t * 0.008);
			}
			if (nearest_t < INFINITY)
			{
				vec_normalize(&intersect_normal);
				final_color = multiply_colors(intersect_color, info->l.rgb);
				intensity = dot_calculation(intersect_normal, to_light);
				if(intensity < 0)
					intensity = 0;
				intersect_color.x *= intensity;
				intersect_color.y *=  intensity;
				intersect_color.z *= intensity;
				color = get_color(intersect_color, fog, t);
				

			}
			if (nearest_t == INFINITY)
				color = get_color(fog ,sky, info->ray.direc.y * 1.5);
			mlx_put_pixel(info->img, col, row, color);
			col++;
		}
		row++;
	}
}
int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2 || check_if_rt(argv[1]) == 0)
			throw_error(0);
	ft_bzero(&info, sizeof(t_info));
	info.arena = arena_init(1024);
	parse(argv[1], &info);
	info.mlx =  mlx_init(WIDTH, HEIGHT, "KD MiniRT", true);
	info.img = mlx_new_image(info.mlx, WIDTH, HEIGHT);
 	if (!info.img || (mlx_image_to_window(info.mlx, info.img, 0, 0) < 0))
		return (0);
	draw(&info);
	mlx_loop(info.mlx);
	free_all(&info);
	return (0);	
}
