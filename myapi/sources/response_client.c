#include "api.h"

int	response_client(struct mg_connection *conn)
{
	char	buffer[50000];
	char	*s;
	char	*temp;
	FILE	*fd;

	fd = fopen("mysql.txt", "a+");
	s = strdup("");
	fgets(buffer, 50000, fd);
	mg_http_reply(conn, 200, "Content-Type: application/json\r\n", "{\nGames:[\n %s]\n}", buffer);
	fclose(fd);
	return (0);
}
