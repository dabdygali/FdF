/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:15:12 by dabdygal          #+#    #+#             */
/*   Updated: 2023/09/20 13:40:04 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	argv++;
	if (ft_check_argc(argc, 2, 2) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
