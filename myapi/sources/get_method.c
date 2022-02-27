#include "api.h"

void	log_message(struct mg_http_message *request, int status)
{
	time_t curtime;

	time(&curtime);
	dprintf(my_api.fd, "%.*s ", (int)request->method.len, request->method.ptr);
	dprintf(my_api.fd, "%.*s ", (int)request->uri.len, request->uri.ptr);
	dprintf(my_api.fd, "%d ", status);
	dprintf(my_api.fd, "%s", ctime(&curtime));
}

int	get_method(struct mg_connection *conn, struct mg_http_message *request)
{
	if (mg_http_match_uri(request, "/"))
	{
		mg_http_reply(conn, 200, "Content-Type: application/json\r\n", "{\"result\": %s}", "\"Welcome: Options uri: all\"");
		log_message(request, 200);
	}
	else if (mg_http_match_uri(request, "/all"))
	{
		response_bd();
		response_client(conn);
		log_message(request, 200);
	}
	else
	{
		mg_http_reply(conn, 404, "Content-Type: application/json\r\n", "{\"result\": %s}", "\"path not found\"");
		log_message(request, 400);
	}
	return (0);
}
