/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:40:27 by mquero            #+#    #+#             */
/*   Updated: 2025/02/22 19:12:23 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static  void assign_camera_info(t_info *info, char **split)
{
    char  **vec;

    info->c.fov = strtod(split[3], NULL);
    vec = ft_split(split[1], ',');
    if (!vec)
    {
        arena_free(info->arena);
        exit(1);
    }
    new_vec3(&(info->c).point, vec);
    vec = ft_split(split[2], ',');
    if (!vec)
    {
        arena_free(info->arena);
        exit(1);
    }
    new_vec3(&(info->c).orient, vec);
}
static  void assign_ambient_info(t_info *info, char **split)
{
    char  **rgb;

    info->a.ratio = strtod(split[1], NULL);
    rgb = ft_split(split[2], ',');
    printf("%s\n",split[2]);
    if (!rgb)
    {
        arena_free(info->arena);
        exit(1);
    }
    new_vec3(&(info->a).rgb, rgb);
}

static  void assign_light_info(t_info *info, char **split)
{
    char  **vec;

    info->l.br_ratio = strtod(split[2], NULL);
    vec = ft_split(split[3], ',');
    if (!vec)
    {
        arena_free(info->arena);
        exit(1);
    }
    new_vec3(&(info->l).rgb, vec);
    vec = ft_split(split[1], ',');
    if (!vec)
    {
        arena_free(info->arena);
        exit(1);
    }
    new_vec3(&(info->l).point, vec);
}
void    parse(char *file, t_info *info)
{
    int fd;
    char *input;
    char **split;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        throw_error(1);
    input = get_next_line(fd);
    while (input != NULL)
    {
        split = ft_split(input, ' ');
        free(input);
        if (!split)
        {
            freesplit(split);
            arena_free(info->arena);
            exit(1);
        }
        if (ft_strncmp(split[0], "A", ft_strlen(split[0])) == 0)
            assign_ambient_info(info, split);
        else if (ft_strncmp(split[0], "C", ft_strlen(split[0])) == 0)
            assign_camera_info(info, split);
        else if (ft_strncmp(split[0], "L", ft_strlen(split[0])) == 0)
            assign_light_info(info, split);
        else if (ft_strncmp(split[0], "pl", ft_strlen(split[0])) == 0)
            assign_plane_info(info, split);
        else if (ft_strncmp(split[0], "sp", ft_strlen(split[0])) == 0)
            assign_sphere_info(info, split);
        else if (ft_strncmp(split[0], "cy", ft_strlen(split[0])) == 0)
            assign_cylinder_info(info, split);
        freesplit(split);
        input = get_next_line(fd);
    }
}
