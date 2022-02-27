#include "api.h"
#include "mongoose.h"
#include <stdbool.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

t_api	my_api;

int c_sig = 0;

static	void sigint(int sig)
{
	(void)sig;
	c_sig = 1;
}

static int	check_method(const char *method)
{
	if (!strncmp(method, "GET", 3))
		return (GET);
	else if (!strncmp(method, "POST", 4))
		return (POST);
	else
		return (ERROR);
}

static void fn(struct mg_connection *conn, int ev, void *ev_data, void *fn_data)
{
	struct mg_http_message *request;
	request = (struct mg_http_message *)ev_data;
	if (ev == MG_EV_HTTP_MSG)
	{
		int method = check_method(request->method.ptr);
		if (method == GET)
		{
			get_method(conn, request);
		}
		else
		{
			mg_http_reply(conn, 404, "Content-Type: application/json\r\n", "{\"result\": %s}", "\"Method Not Found\"");
			log_message(request, 404);
		}
	}
	(void)fn_data;
}

int	main(void)
{
	signal(SIGINT, sigint);
	my_api.fd = open("logs/logs.log", O_CREAT | O_WRONLY | O_APPEND, 0644);
	mg_mgr_init(&my_api.mgr);
	mg_http_listen(&my_api.mgr, "0.0.0.0:8080", fn, NULL);
	while (!c_sig)
		mg_mgr_poll(&my_api.mgr, 1000);
	mg_mgr_free(&my_api.mgr);
	close(my_api.fd);
	return (0);
}
