/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:40:49 by mquero            #+#    #+#             */
/*   Updated: 2025/02/24 17:17:48 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void    get_point_from_ray(t_vec3 *point ,t_ray ray, double t)
{
    double  x;
    double  y;
    double  z;

    point->x = ray.orig.x + (t * ray.direc.x);
    point->y = ray.orig.y + (t * ray.direc.y);
    point->z = ray.orig.z + (t * ray.direc.z);
}

t_vec3    multiply_colors(t_vec3 startcolor , t_vec3 endcolor)
{
    t_vec3 new_color;
    
    new_color.x = startcolor.x * endcolor.x * 0.5;
    new_color.y = startcolor.y * endcolor.y * 0.5;
    new_color.z = startcolor.z * endcolor.z * 0.5;
    return (new_color);
}