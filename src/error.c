/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:37:19 by mquero            #+#    #+#             */
/*   Updated: 2025/02/19 13:49:23 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	check_error(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	return (1);
}

void	free_all(t_mlx *c)
{
	mlx_delete_image(c->mlx, c->img);
	mlx_terminate(c->mlx);
	exit(1);
}

void	throw_error(int flag)
{
	if (flag == 0)
	{
		printf("Not passing correct arguments\n");
		exit(1);
	}
	if (flag == 1)
	{
		printf("Your scene doesn't exist\n");
		exit(1);
	}
}

int	check_if_rt(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == 'r' && str[i + 2] == 't'
			&& str[i + 3] == '\0')
			return (1);
		i++;
	}
	return (0);
}
