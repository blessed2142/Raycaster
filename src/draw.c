/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:40:54 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 01:40:56 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	drawpixel(t_game *game, int x, int y, unsigned int color)
{
	game->img.addr[(game->resolution.x_res * y) + x] = color;
}
