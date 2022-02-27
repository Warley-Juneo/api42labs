/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:20:16 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/02/27 12:47:10 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

void	ft_printf_help(t_data *data)
{
	data->log_error = fopen("./text.txt", "r+");
	bzero(data->buffer, 50);
	while (fgets(data->buffer, 25, data->log_error))
	{
		printf("%s", data->buffer);
	}
}

void    ft_chose_printf(int argc, char *argv[], t_data *data)
{
    if (argc == 2)
    {
        if (!strncmp(argv[1], "all", 3))
            print_all(data);
        else if (!strncmp(argv[1], "GET", 3))
            print_all(data);
        else
            ft_printf_help(data);
    }
    else if (argc == 3)
    {
        if (!strcmp(argv[1], "GET") && \
            !strcmp(argv[2], "/"))
            print_get_root(data);
        else if (!strcmp(argv[1], "GET") && \
                !strcmp(argv[2], "/all"))
            print_get_secret(data);
        else
            ft_printf_help(data);
    }
}


void    print_all(t_data *data)
{
    printf("------------------------------------------------\n");
    printf("| TOTAL REQUESTS  | HTTP Method  |   Path      |\n");
    printf("|----------------------------------------------|\n");
    printf("|     %6d      |     GET      |     /       |\n", \
        data->count.get_root);
    printf("|----------------------------------------------|\n");
    printf("|     %6d      |     GET      |   /all      |\n", \
        data->count.get_secret);
    printf("|----------------------------------------------|\n");
}

void    print_get_root(t_data *data)
{
    printf("------------------------------------------------\n");
    printf("| TOTAL REQUESTS  | HTTP Method  |   Path      |\n");
    printf("|----------------------------------------------|\n");
    printf("|     %6d      |     GET      |      /      |\n", \
        data->count.get_root);
    printf("|----------------------------------------------|\n");
}

void    print_get_secret(t_data *data)
{
    printf("------------------------------------------------\n");
    printf("| TOTAL REQUESTS  | HTTP Method  |   Path      |\n");
    printf("|----------------------------------------------|\n");
    printf("|     %6d      |     GET      |    /all     |\n", \
        data->count.get_secret);
    printf("|----------------------------------------------|\n");
}
