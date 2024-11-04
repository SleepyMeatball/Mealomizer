#pragma once
#include "OConsole.h"

class UserInterface {
protected:
	// Start
	virtual void Start_Help(std::vector<std::string>) {}
	virtual void Start_GUI(std::vector<std::string>) {}
	// Start END --------

	// List
	virtual void List_Help(std::vector<std::string>) {}
	// List END --------

	// Tag
	virtual void Tag_Help(std::vector<std::string>) {}
	// Tag END --------

	// Random
	virtual void Random_Help(std::vector<std::string>) {}
	// Random END --------

	// Help
	virtual void Help(std::vector<std::string>) {}
	// Help END --------
};

class ConsoleUI : public UserInterface {
public:
	void HandleArguments(int argc, char* argv[]);

private:
	OConsole cn_out;

	struct Command {
		std::string name;
		void (ConsoleUI::*Handler)(std::vector<std::string>);
		std::vector<Command> subcommands;
		std::map<std::string, bool> flags;
		std::vector<std::string> values;
	};

	std::vector<Command> commands = {
		{"start", &ConsoleUI::Start_Help, {
			{"gui", &ConsoleUI::Start_GUI}
		}},
		{"list", &ConsoleUI::List_Help},
		{"tag", &ConsoleUI::Tag_Help},
		{"random", &ConsoleUI::Random_Help},
		{"help", &ConsoleUI::Help},
	}; 

	void ParseCommand(std::vector<std::string>, Command&);
	
	// Start
	void Start_Help(std::vector<std::string>) override;
	void Start_GUI(std::vector<std::string>) override;
	// Start END --------

	// List
	void List_Help(std::vector<std::string>) override;
	// List END -------- 
	
	// Tag
	void Tag_Help(std::vector<std::string>) override;
	// Tag END --------

	// Random
	void Random_Help(std::vector<std::string>) override;
	// Random END --------

	// Help
	void Help(std::vector<std::string>) override;
	// Help END --------
};

class GraphicsUI : public UserInterface {

};