/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:09:00 by emiro-co          #+#    #+#             */
/*   Updated: 2023/07/12 19:03:38 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_search(va_list args, char s)
{
	int		ret;

	ret = 0;
	if (s == 'c')
		ret = ft_putchar(va_arg(args, int));
	if (s == 's')
		ret = ft_printstr(va_arg(args, char *));
	else if (s == 'p')
		ret = ft_ptr(va_arg(args, unsigned long long));
	else if (s == 'd' || s == 'i')
		ret = ft_print_int(va_arg(args, int));
	else if (s == 'u')
		ret = ft_ui(va_arg(args, unsigned int));
	else if (s == 'x' || s == 'X')
		ret = ft_hexnum(va_arg(args, unsigned int), s);
	else if (s == '%')
		ret = ft_putchar('%');
	if (ret < 0)
		return (-1);
	return (ret);
}

int	ft_parse(va_list args, const char *s)
{
	int	ret;
	int	cnt;

	ret = 0;
	cnt = 0;
	while (*s)
	{
		if (*s == '%')
		{
			ret = ft_search(args, *(++s));
			if (ret < 0)
				return (-1);
			cnt += ret;
			s++;
		}
		else
		{
			ret = ft_putchar(*(s++));
			if (ret < 0)
				return (-1);
			cnt += ret;
		}
	}
	return (cnt);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		ret;

	va_start(args, s);
	ret = ft_parse(args, s);
	if (ret < 0)
		return (-1);
	va_end(args);
	return (ret);
}
