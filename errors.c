/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 03:44:43 by marina            #+#    #+#             */
/*   Updated: 2020/12/03 20:19:30 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	free_fp_map(t_fp_map **b)
{
	t_fp_map	*bin;
	t_fp_map	*tmp;

	bin = *b;
	while (bin)
	{
		tmp = bin;
		free((bin)->line);
		bin = bin->next;
		free(tmp);
	}
}

void	ft_error(char *message, char *place, t_cub3d *cub3d)
{
	ft_printf("Error\n%s (in %s)\n", message, place);
	my_exit(cub3d);
}

void	ft_errorfp(char *m, char *p, t_cub3d *cub3d, t_fp_map **b)
{
	ft_printf("Error\n%s (in %s)\n", m, p);
	free_fp_map(b);
	my_exit(cub3d);
}
