/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:08:38 by ilaliev           #+#    #+#             */
/*   Updated: 2025/03/26 18:43:19 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_sint(int num)
{
	char	*num_ascii;
	int		i;

	num_ascii = ft_itoa(num);
	if (!num_ascii)
		return (-1);
	i = 0;
	while (num_ascii[i])
	{
		if (write(1, &num_ascii[i], 1) < 1)
		{
			free(num_ascii);
			return (-1);
		}
		i++;
	}
	free(num_ascii);
	return (i);
}

int	print_uint(int num)
{
	char	*num_ascii;
	int		i;

	num_ascii = ft_uitoa(num);
	if (!num_ascii)
		return (-1);
	i = 0;
	while (num_ascii[i])
	{
		if (write(1, &num_ascii[i++], 1) < 1)
		{
			free(num_ascii);
			return (-1);
		}
	}
	free(num_ascii);
	return (i);
}
