#include "pch.h"
#include "Application.h"

int main(int argc, char* argv[]) {

	Application& app = Application::GetInstance();
	app.Init(argc, argv);

	int a = 1;
	std::cout << a;

	std::cin.get();

	return 0;
} 