/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwarn_argc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:53:56 by dabdygal          #+#    #+#             */
/*   Updated: 2023/09/25 11:15:37 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "libft.h"

int	ft_checkwarn_argc(int argc, int min_argc, int max_argc)
{
	if (min_argc > max_argc || min_argc < 0 || max_argc < 0)
	{
		errno = ENOSYS;
		ft_putstr_fd("'min_argc','max_argc' are setup wrong\n", STDERR_FD);
		return (-1);
	}
	if (argc < min_argc)
	{
		errno = EINVAL;
		ft_putstr_fd("Not enough arguments\n", STDERR_FD);
		return (-1);
	}
	if (argc > max_argc)
	{
		errno = EINVAL;
		ft_putstr_fd("Too much arguments\n", STDERR_FD);
		return (-1);
	}
	return (0);
}
