/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:31:25 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/11 12:06:14 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_error_ptr(char *msg)
{
	printf("%s", msg);
	return (NULL);
}

long	ft_error_long(char *msg)
{
	printf("%s", msg);
	return (-1);
}
int	ft_error_int(char *msg)
{
	printf("%s", msg);
	return (1);
}
void	ft_error_void(char *msg)
{
	printf("%s", msg);
	return ;
}
