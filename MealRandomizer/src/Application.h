#pragma once
#include "UserInterface.h"

class Application {
public:
	Application(Application const&) = delete;
	void operator=(Application const&) = delete;
	static Application& GetInstance();

	void Init(int argc, char* argv[]);

protected:
	Application() {}
	~Application() {}

private:
	enum class UIOptions{
		Console,
		Graphic
	}; 
	std::unique_ptr<UserInterface> ui;
	
	bool CreateUI(UIOptions opt);
};