/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:59:14 by akaraban          #+#    #+#             */
/*   Updated: 2023/01/22 22:28:43 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_arg(const char *string, int i, va_list args)
{
	if (string[i + 1] == '%')
		return (ft_putchar(string[i + 1]));
	else if (string[i + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (string[i + 1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (string[i + 1] == 'p')
		return (ft_putstr("0x") + ft_print_pointer(va_arg(args, void *), \
			"0123456789abcdef"));
	else if (string[i + 1] == 'd')
		return (ft_print_nbr(va_arg(args, int)));
	else if (string[i + 1] == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (string[i + 1] == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (string[i + 1] == 'X' || string[i + 1] == 'x')
	{
		if (string[i + 1] == 'X')
			return (ft_print_hex(va_arg(args, unsigned int), \
			"0123456789ABCDEF"));
		else
			return (ft_print_hex(va_arg(args, unsigned int), \
			"0123456789abcdef"));
	}
	else
		return (0); 
}

int	ft_printf(const char *str, ... )
{
    va_list args;
    int i;
    int result;

    i = 0;
    result = 0;
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%' && ft_strchr("cspdiuxX", str[i + 1]))
        {
            result += ft_printf_arg(str, i, args);
            i++;
        }
        else if (str[i] == '%' && str[i + 1] == '%')
        {
            result += ft_printf_arg(str, i, args);
            i++;
        }
        else
            result += ft_putchar(str[i]);
            i++;
    }
    va_end(args);
    return (result);
}