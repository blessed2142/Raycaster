/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:46:37 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 01:46:39 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	error1(int error_code)
{
	if (error_code == 4)
	{
		printf("Error\nMap is invalid\n");
		exit(0);
	}
	if (error_code == 5)
	{
		printf("Error\nMemory allocation trouble\n");
		exit(0);
	}
	if (error_code == 6)
	{
		printf("Error\nNot enough elements in map file\n");
		exit(0);
	}
	if (error_code == 7)
	{
		printf("Error\nInvalid argument\n");
		exit(0);
	}
	if (error_code == 8)
	{
		printf("Error\nNot xpm!\n");
		exit(0);
	}
}

void	error(int error_code)
{
	if (error_code == 1)
	{
		printf("Error\nProblems with Resolution\n");
		exit(0);
	}
	if (error_code == 2)
	{
		printf("Error\nProblems with floor or ceiling color definition\n");
		exit(0);
	}
	if (error_code == 3)
	{
		printf("Error\nProblems with NO, SO, EA, WE or S texture definition\n");
		exit(0);
	}
	if (error_code == 4)
		error1(4);
	if (error_code == 5)
		error1(5);
	if (error_code == 6)
		error1(6);
	if (error_code == 7)
		error1(7);
	if (error_code == 8)
		error1(8);
}
