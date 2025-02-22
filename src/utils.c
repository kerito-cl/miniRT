/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:35:21 by mquero            #+#    #+#             */
/*   Updated: 2025/02/22 18:40:08 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void    new_vec3(t_vec3 *vec3, char **cvec)
{
    vec3->x = strtod(cvec[0], NULL);
    vec3->y = strtod(cvec[1], NULL);
    vec3->z = strtod(cvec[2], NULL);
    if (cvec != NULL)
        freesplit(cvec);
}