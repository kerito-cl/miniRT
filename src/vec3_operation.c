/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:56:14 by mquero            #+#    #+#             */
/*   Updated: 2025/02/22 23:38:34 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double    dot_calculation(t_vec3 vec1, t_vec3 vec2)
{
    double  x;
    double  y;
    double  z;

    x = vec1.x * vec2.x;
    y = vec1.y * vec2.y;
    z = vec1.z * vec2.z;
    return (x + y + z);
}

double    vec_length(t_vec3 vec1)
{
    double  x;
    double  y;
    double  z;

    x = vec1.x * vec1.x;
    y = vec1.y * vec1.y;
    z = vec1.z * vec1.z;
    return (sqrt(x + y + z));
}

void    vec_normalize(t_vec3 *vec1)
{
    double inverse;

    inverse = 1 / vec_length(*vec1);
    vec1->x = vec1->x * inverse;
    vec1->y = vec1->y * inverse;
    vec1->z = vec1->z * inverse;
}

void    vec_substract(t_vec3 *vec1, t_vec3 vec2)
{
    vec1->x -= vec2.x;
    vec1->y -= vec2.y;
    vec1->z -= vec2.z;
}