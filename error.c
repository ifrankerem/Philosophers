/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:31:25 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/12 13:31:52 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
