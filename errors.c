/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 03:44:43 by marina            #+#    #+#             */
/*   Updated: 2020/11/30 13:13:53 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_error(char *message, char *place, t_cub3d *cub3d)
{
	ft_printf("Error\n%s (in %s)\n", message, place);
	my_exit(cub3d);
}
