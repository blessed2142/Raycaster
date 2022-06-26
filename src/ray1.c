/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:22:57 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/03 16:22:59 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	israyfacingdown(float angle)
{
	return (angle > 0 && angle < PI);
}

int	israyfacingup(float angle)
{
	return (!israyfacingdown(angle));
}

int	israyfacingright(float angle)
{
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}

int	israyfacingleft(float angle)
{
	return (!israyfacingright(angle));
}
