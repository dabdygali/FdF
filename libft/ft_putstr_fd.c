/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:25:39 by dabdygal          #+#    #+#             */
/*   Updated: 2023/07/18 15:50:25 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr_fd(const char *const s, int fd)
{
	int	done;
	int	i;

	i = 0;
	done = 0;
	if (!s)
	{
		write (fd, "(null)", 6);
		done = 6;
		return (done);
	}
	while (s[i])
	{
		write(fd, &s[i], sizeof(char));
		done++;
		i++;
	}
	return (done);
}
