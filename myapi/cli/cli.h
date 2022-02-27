/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:01:44 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/02/27 14:50:33 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>


#define PATH_LOG "../sources/logs/logs.log"

typedef struct s_count
{
    int    get_root;
    int    get_secret;
}    t_count;

typedef struct s_data
{
    FILE    *log_file;
	FILE	*log_error;
    char    buffer[50];
    int        fd_log;
    int        fd_log_result;
    t_count    count;
}    t_data;

void	count_methods(t_data *data);
void    print_all(t_data *data);
void	ft_printf_help(t_data *data);
int		check_arguments(int argc, char *argv[], t_data *data);
void	print_get_root(t_data *data);
void	print_get_secret(t_data *data);
void	ft_chose_printf(int argc, char *argv[], t_data *data);

#endif
