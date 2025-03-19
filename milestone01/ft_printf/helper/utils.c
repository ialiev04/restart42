/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:09:35 by ilaliev           #+#    #+#             */
/*   Updated: 2025/03/18 20:09:35 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_num_len(unsigned int n)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	size_t			len;
	unsigned int	num;
	char			*ret;

	len = ft_num_len(n);
	num = n;
	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	while (len > 0)
	{
		ret[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (ret);
}

int	hex_len(uintptr_t p)
{
	int	len;

	len = 0;
	while (x != 0)
	{
		x = x / 16;
		len++;
	}
	return (len);
}

int	put_hex()
{
	char	c;

	if (x > 15)
	{
		if (put_hex(x / 16, format) < 0)
			return (-1);
		if (put_hex(x % 16, format) < 0)
			return (-1);
	}
	else
	{
		if (x <= 9)
			c = x + '0';
		else if (format == 'x')
			c = x - 10 + 'a';
		else if (format == 'X')
			c = x - 10 + 'A';
		if (write(1, &c, 1) < 0)
			return (-1);
	}
	return (0);
}
