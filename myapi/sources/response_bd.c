#include <mysql/mysql.h>
#include "api.h"

static void finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

int response_bd()
{
	MYSQL	*con = mysql_init(NULL);
	FILE	*fd = fopen("mysql.txt", "a+");

	if (con == NULL)
	{
		fprintf(stderr, "mysql_init() failed\n");
		exit(1);
	}

	if (mysql_real_connect(con, getenv("DBHOST"), getenv("DBUSER"), getenv("DBPASS"), getenv("DBNAME"), (unsigned int)3306, NULL, 0) == NULL)
	{
		finish_with_error(con);
	}

	if (mysql_query(con, "SELECT * FROM MyGames"))
	{
		finish_with_error(con);
	}

	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error(con);
	}

	int num_fields = mysql_num_fields(result);

	MYSQL_ROW row;

	int j;

	j = 0;
	while ((row = mysql_fetch_row(result)))
	{
		fprintf(fd, "%s ", row[0] ? row[0] : "NULL");
		if (j++ < 9)
			fprintf(fd, ",");
	}

	mysql_free_result(result);
	mysql_library_end();
	mysql_close(con);
	fclose(fd);
	return (0);
}
