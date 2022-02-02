/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:54:14 by jatan             #+#    #+#             */
/*   Updated: 2022/02/01 16:37:35 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_input(char c, va_list args);
static char	*hex_case(char c, char *s);
static void	transform(unsigned int i, char *s);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		input;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		input = -1;
		if (*format == '%' && *(format + 1))
		{
			input = handle_input(*(format + 1), args);
			if (input != -1)
				format += 2;
		}
		if (*format && input == -1)
			input = ft_putchar_fd(*format++, 1);
		count += input;
	}
	va_end(args);
	return (count);
}

static int	handle_input(char c, va_list args)
{
	int		count;
	char	*s;

	count = 0;
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == 's')
		s = ft_strdup(va_arg(args, char *));
	else if (c == 'p')
		s = ft_itoa_addr(va_arg(args, size_t));
	else if (c == 'd' || c == 'i')
		s = ft_itoa(va_arg(args, int));
	else if (c == 'u')
		s = ft_itoa_uint(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		s = hex_case(c, ft_itoa_hex(va_arg(args, int)));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	else
		return (-1);
	count = ft_putstr_fd(s, 1);
	free(s);
	return (count);
}

static char	*hex_case(char c, char *s)
{
	if (c == 'X')
		ft_striteri(s, &transform);
	return (s);
}

static void	transform(unsigned int i, char *s)
{
	if (ft_isalpha(s[i]))
		s[i] = ft_toupper(s[i]);
}
