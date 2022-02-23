/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:42:03 by lloko             #+#    #+#             */
/*   Updated: 2022/02/23 19:47:14 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	g_tosh;
int	g_shir;
int	g_res;

static void	ft_putchar(char b)
{
	write(1, &b, 1);
	g_res += 1;
}

static int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	ft_putstr(char *str, int len)
{
	while (*str != '\0' && len > 0)
	{
		ft_putchar(*str);
		str++;
		len--;
	}
}

static void	ft_printf_s(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (g_tosh == -1 && g_tosh < len)
		len = g_tosh;
	while (g_shir > len)
	{
		ft_putchar(' ');
		g_shir--;
	}
	ft_putstr(str, len);
}

static void	ft_printf_d(long nb, int base)
{
	
}

static void	ft_printf_x(unsigned long nb, int base)
{
	
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	g_tosh = -1;
	g_shir = 0;
	g_res = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			while (str[i] >= '0' && str[i] <= '9')
			{
				g_shir = g_shir * 10 + (str[i] - '0');
				i++;
			}
			if (str[i] == '.')
			{
				i++;
				g_tosh = 0;
				while (str[i] >= '0' && str[i] <= '9')
				{
					g_tosh = g_tosh * 10 + (str[i] - '0');
					i++;
				}
			}
			if (str[i] == 's')
				ft_printf_s(va_arg(ap, char *));
			else if (str[i] == 'd')
				ft_printf_d(va_arg(ap, int));
			else if (str[i] == 'x')
				ft_printf_x(va_arg(ap, unsigned int));
			else
				ft_putchar(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (g_res);
}
