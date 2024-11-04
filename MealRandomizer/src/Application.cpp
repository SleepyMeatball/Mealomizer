#include "pch.h"
#include "Application.h"

Application& Application::GetInstance() {
	static Application instance_;
	return instance_;
}

void Application::Init(int argc, char* argv[]) {

}

bool Application::CreateUI(UIOptions opt) {
	if (opt == UIOptions::Console) {
		this->ui = std::make_unique<ConsoleUI>();
		return true;
	} else if (opt == UIOptions::Graphic) {
		this->ui = std::make_unique<GraphicsUI>();
		return true;
	} else return false;
}