/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_geo_objects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:53:16 by mquero            #+#    #+#             */
/*   Updated: 2025/02/22 19:09:10 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void assign_plane_info(t_info *info, char **split)
{
    char  **vec;

    vec = ft_split(split[1], ',');
    if (!vec)
    {
        arena_free(info->arena);
        exit(1);
    }
    new_vec3(&(info->pl).point, vec);
    vec = ft_split(split[2], ',');
    if (!vec)
    {
        arena_free(info->arena);
        exit(1);
    }
    new_vec3(&(info->pl).norm, vec);
    vec = ft_split(split[3], ',');
    if (!vec)
    {
        arena_free(info->arena);
        exit(1);
    }
    new_vec3(&(info->pl).rgb, vec);
}

void assign_sphere_info(t_info *info, char **split)
{
    char  **vec;

    info->sp.radius = strtod(split[2], NULL) * 0.5;
    vec = ft_split(split[1], ',');
    if (!vec)
    {
        arena_free(info->arena);
        exit(1);
    }
    new_vec3(&(info->sp).center, vec);
    vec = ft_split(split[3], ',');
    if (!vec)
    {
        arena_free(info->arena);
        exit(1);
    }
    new_vec3(&(info->sp).rgb, vec);
}

void assign_cylinder_info(t_info *info, char **split)
{
    char  **vec;

    info->cy.radius = strtod(split[3], NULL) * 0.5;
    info->cy.height = strtod(split[4], NULL);
    vec = ft_split(split[1], ',');
    if (!vec)
    {
        arena_free(info->arena);
        exit(1);
    }
    new_vec3(&(info->cy).center, vec);
    vec = ft_split(split[2], ',');
    if (!vec)
    {
        arena_free(info->arena);
        exit(1);
    }
    new_vec3(&(info->cy).norm, vec);
    vec = ft_split(split[2], ',');
    if (!vec)
    {
        arena_free(info->arena);
        exit(1);
    }
    new_vec3(&(info->cy).rgb, vec);
}
