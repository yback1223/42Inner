/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:26:35 by yback             #+#    #+#             */
/*   Updated: 2022/08/24 13:42:41 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct info_s
{
	int		zeropad;
	char	sign;
	int		plus;
	int		space;
	int		left;
	int		small;
	int		special;
	int		width;
	int		precision;
	char	*str;
	int		base;
	char	fmt;
}	info_t;

#endif