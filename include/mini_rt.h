#ifndef MINI_RT_H
# define MINI_RT_H

# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_mlx
{
	mlx_t			*mlx;
	mlx_image_t		*img;
}       t_mlx;


void	throw_error(int flag);
int     check_if_rt(char *str);

#endif