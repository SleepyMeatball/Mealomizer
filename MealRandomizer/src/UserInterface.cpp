#include "pch.h"
#include "UserInterface.h"

void ConsoleUI::HandleArguments(int argc, char* argv[]) {
	std::vector<std::string> args(argv + 1, argv + argc);

	if (args.empty()) {
		Help({});
		return;
	} 

	for (Command& cmd : commands) {
		if (cmd.name == argv[0]) {
			args.erase(args.begin());
			ParseCommand(args, cmd);
			return;
		}
	}

	Help({});
}

void ConsoleUI::ParseCommand(std::vector<std::string> args, Command& cmd) {
	if (args.empty()) {
		(this->*(cmd.Handler))(args) ;
		return;
	}

	for (Command& subcmd : cmd.subcommands) {
		if (args[0] == subcmd.name) {
			args.erase(args.begin());
			ParseCommand(args, subcmd);
			return;
		}
	}

	for (std::pair<const std::string, bool>& flag : cmd.flags) {
		if (args.end() != std::find(args.begin(), args.end(), flag.first)) {
			flag.second = true;
		}
		std::erase_if(args, [&flag](std::string arg) {return flag.first == arg; });
	};

	(this->*(cmd.Handler))(args);
}

void ConsoleUI::Start_GUI(std::vector<std::string> args) {

}

void ConsoleUI::Start_Help(std::vector<std::string> args) {

}

void ConsoleUI::List_Help(std::vector<std::string> args) {

}

void ConsoleUI::Tag_Help(std::vector<std::string> args) {

}

void ConsoleUI::Random_Help(std::vector<std::string> args) {

}

void ConsoleUI::Help(std::vector<std::string> args) {


}