#pragma once
#include "pch.h"

class OConsole {
public:
    OConsole() { ClearConsole(); }
	~OConsole() {}

    void ClearConsole() {
#ifdef PLATFORM_WIN64
        // Windows specific clear command
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(hConsole, &mode);
        SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
        std::cout << "\033[2J\033[H"; // Clear screen using ANSI escape codes
#else
        // POSIX compliant systems (Linux, macOS)
        std::cout << "\033[2J\033[H"; // Clear screen using ANSI escape codes
#endif
        std::cout.flush(); // Ensure the output is sent to the console immediately
    }

    void OutputLine(std::vector<std::string> line) {
        int i = 1;
        for (std::string& word : line) {
            std::cout << word << (i < line.size() ? " " : "");
            i++;
        }
        std::cout << std::endl;
    }
};