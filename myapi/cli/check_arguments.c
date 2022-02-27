/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:06:02 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/02/27 12:45:35 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

int	check_arguments(int argc, char *argv[], t_data *data)
{
	if (argc < 2 || argc > 3)
		ft_printf_help(data);
	else if (argc == 2)
	{
		if (!strncmp(argv[1], "all", 3) && \
			!strncmp(argv[1], "GET", 3))
			ft_printf_help(data);
	}
	else if (argc == 3)
	{
		if (!strncmp(argv[1], "all", 3) && \
			!strncmp(argv[1], "GET", 3) && \
			!strncmp(argv[2], "/", 1) && \
			!strncmp(argv[2], "/all", 7))
			ft_printf_help(data);
	}
	return (0);
}
