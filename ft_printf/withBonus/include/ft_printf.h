/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:26:35 by yback             #+#    #+#             */
/*   Updated: 2022/08/22 20:57:40 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct info_s
{
	int		zeropad;
	int		sign;
	int		plus;
	int		space;
	int		left;
	int		small;
	int		special;
	int		width;
	int		precision;
	char	str[1024];
	int		i_for_str;
	int		base;
}	info_t;

#endif