/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:24:33 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/21 19:24:23 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const t_function_type func_tab[] = {
	{'%', pourcent_spec},
	{'s', s_spec},
	{'S', ss_spec},
	{'d', d_spec},
	{'i', d_spec},
	{'D', dd_spec},
	{'p', p_spec},
	{'u', u_spec},
	{'U', u_spec},
	{'o', o_spec},
	{'x', x_spec},
};

size_t	new_format(va_list ap, const char **format)
{
	int i;
	size_t	count;
	t_mark mk;

	i = 0;
	count = 0;
	(*format)++;
	format_parsing(format, &mk);
	while (i < 11)
	{
		if (*format[0] == func_tab[i].type)
			count = func_tab[i].t_function_type(ap, *format, mk);
		i++;
	}
	return (count);
}
