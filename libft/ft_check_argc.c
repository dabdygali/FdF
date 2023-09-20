/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:53:56 by dabdygal          #+#    #+#             */
/*   Updated: 2023/09/20 14:04:56 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>

int	ft_check_argc(int argc, int min_argc, int max_argc)
{
	if (argc < min_argc || argc > max_argc)
	{
		errno = EINVAL;
		perror("Invalid number of arguments");
		return (-1);
	}
	return (0);
}
