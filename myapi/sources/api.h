# ifndef API_H
# define API_H

#include "mongoose.h"
#include <time.h>
#include <fcntl.h>
#include "mongoose.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

typedef struct		s_api
{
	struct	mg_mgr mgr;
	int		fd;
	int		conn_bool;
}					t_api;

extern t_api	my_api;

enum method {
	GET,
	POST,
	ERROR,
};

void	log_message(struct mg_http_message *request, int status);
int		get_method(struct mg_connection *coon, struct mg_http_message *request);
int		response_bd();
int		response_client(struct mg_connection *conn);


size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

# endif
