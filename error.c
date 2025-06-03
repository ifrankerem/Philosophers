/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:31:25 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/02 23:22:12 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


//! t_table felan da koycaz parametre olarak bu fonklara cünkü
//! clean bastırıyoruz ona dikkat et
const char	*ft_error_str(char *msg)
{
	printf("%s", msg);
	//clean();
	return (NULL);
}
void	*ft_error_ptr(char *msg)
{
	printf("%s", msg);
	//clean();
	return (NULL);
}

long	ft_error_long(char *msg)
{
	printf("%s", msg);
	//clean();
	return (-1);
}
int	ft_error_int(char *msg)
{
	printf("%s", msg);
	//clean();
	return (-1);
}