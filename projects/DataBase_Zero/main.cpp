#include"DataBase.h"
#include"Statement.h"
enum MetaCommandResult
{
	META_COMMAND_SUCCESS,
	META_COMMAND_UNRECOGNIZED_COMMAND
};
enum PrepareResult
{
	PREPARE_SUCCESS,
	PREPARE_UNRECOGNIZED_STATEMENT
};
enum StatementType
{
	STATEMENT_INSERT,
	STATEMENT_SELECT
};

int main(int argc, char const *argv[])
{
	DB db;
	db.start();
	return 0;
}

