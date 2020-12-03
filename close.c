/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:52:29 by marina            #+#    #+#             */
/*   Updated: 2020/12/03 19:30:56 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		click(t_cub3d *cub3d)
{
	cub3d->fov = 0;
	my_exit(cub3d);
	return (0);
}

void	my_exit(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map && cub3d->map[i])
	{
		free(cub3d->map[i]);
		i++;
	}
	free(cub3d->map);
	free_sprite(cub3d->sprite);
	free(cub3d->distances);
	exit(0);
}
