#include"DataBase.h"
void DB::print_prompt() //打印提示符
{
	std::cout << "db > ";
}

bool DB::parse_meta_command(std::string command)//判断输入语句
{
	if (command == ".exit") //exit
	{
		std::cout << "Bye!" << std::endl;
		exit(EXIT_SUCCESS);
	}
	else //other
	{
		std::cout << "Unrecognized command: " << command << std::endl;
		return true;
	}
	return false;
}
void DB::start() //Eazy_Repl
{
	while (true)
	{
		print_prompt();
		
		std::string input_line;
		std::getline(std::cin, input_line);//以换行符做分割，通过回车键来区分新语句
		
		if (parse_meta_command(input_line))
		{
			continue;
		}
	}
}

