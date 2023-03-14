/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sena <sena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:18:26 by zdogan            #+#    #+#             */
/*   Updated: 2023/03/14 20:45:13 by sena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include "colors.h"

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_hex(unsigned long long arg, char c);
int	ft_putint(long arg, char *base);
int	ft_putunsigned(unsigned long arg, char *base);
int	ft_printf(const char *str, ...);

#endif