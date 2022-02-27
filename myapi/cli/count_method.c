/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_method.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:49:16 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/02/27 12:46:09 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

void	count_methods(t_data *data)
{
	data->count.get_root = 0;
	data->count.get_secret = 0;

	while(fgets(data->buffer, 100, data->log_file))
	{
		if (strstr(data->buffer, "GET / "))
			data->count.get_root++;
		if (strstr(data->buffer, "GET /all"))
			data->count.get_secret++;
	}
	printf("%d - %d\n", data->count.get_root, data->count.get_secret);
}
