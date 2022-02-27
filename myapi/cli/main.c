/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:35:43 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/02/27 14:49:45 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.log_file = fopen(PATH_LOG, "r");
	if (!data.log_file)
	{
		perror("ERROR");
		exit(1);
	}
	count_methods(&data);
	if (check_arguments(argc, argv, &data) != 0)
		return (1);
	ft_chose_printf(argc, argv, &data);
	return (0);
}
