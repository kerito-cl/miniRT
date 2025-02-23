/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:47:06 by mquero            #+#    #+#             */
/*   Updated: 2025/02/23 14:39:58 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double intersect_plane(t_ray ray, t_pl pl)
{
    t_vec3 plane_ray_vec;
    double dot_plane;
    double result;

   dot_plane = dot_calculation(ray.direc, pl.norm);
    if (dot_plane >= 0)
        return (INFINITY);
    ft_memcpy(&plane_ray_vec, &pl.point, sizeof(t_vec3));
    vec_substract(&plane_ray_vec, ray.orig);
    result = dot_calculation(plane_ray_vec, pl.norm);
    result = result / dot_plane;
    if (result > 0)
        return result;
    return (INFINITY);
}
static double quadratic(double a, double b, double c)
{
    double discriminant;
    double t0;
    double t1;

    discriminant = (b * b) - (4 * a * c);
    if (discriminant < 0)
        return (INFINITY);

    discriminant = sqrt(discriminant);
    t0 = (-b - discriminant) * (1 / (2 * a));
    t1 = (-b + discriminant) * (1 / (2 * a));
    if (t0 > 0)
        return (t0);
    if (t1 > 0)
        return (t1);
    return (INFINITY);
}

double intersect_sphere(t_ray ray, t_sp sp)
{
    t_vec3 l;
    double a;
    double b;
    double c;

    ft_memcpy(&l, &ray.orig, sizeof(t_vec3));
    vec_substract(&l, sp.center);
    a = dot_calculation(ray.direc, ray.direc);
    b = 2 * dot_calculation(l, ray.direc);
    c = dot_calculation(l, l) - (sp.radius * sp.radius);
    return (quadratic(a, b, c));
}