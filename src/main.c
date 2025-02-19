/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:45:28 by mquero            #+#    #+#             */
/*   Updated: 2025/02/19 13:45:51 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "mini_rt.h"

int	main(int argc, char **argv)
{
	if (argc != 2 || check_if_rt(argv[1]) == 0)
			throw_error(0);
	//c.fd_folder = open(argv[1], O_DIRECTORY);
	return (0);	
}
