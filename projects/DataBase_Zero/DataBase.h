#include <iostream>
#include <string>
class DB
{
public:
	void start();
	bool parse_meta_command(std::string &command);
	MetaCommandResult do_meta_command(std::string &command);
	
	PrepareResult prepare_statement(std::string &input_line, Statement &statement);
	bool parse_statement(std::string &input_line, Statement &statement);
	void execute_statement(Statement &statement);
	
	void print_prompt();//打印提示符
	
	bool parse_meta_command(std::string command);
};

