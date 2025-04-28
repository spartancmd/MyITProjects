#pragma once
#include <string>

class ConsoleDecorations {
public:
    static std::string clearConsole() {
        return "\033[2J\033[1;1H";
    }

    static std::string resetColor() {
        return "\033[0m";
    }

    static std::string setBackgroundColor(const char color) {
        switch (color) { 
                case 'B': // Black
                    return "\033[40m";
                case 'r': // Red
                    return "\033[41m";
                case 'g': // Green
                    return "\033[42m";
                case 'y': // Yellow
                    return "\033[43m";
                case 'b': // Blue
                    return "\033[44m";
                case 'w': // White
                    return "\033[47m";
                case 'D': // Default
                    return "\033[49m";
                case 0: // Reset
                    return "\033[0m";
        }

        return "";
    }

    static std::string setFontColor(const char color) {
        switch (color) { 
            case 'B': // Black
                return "\033[30m";
            case 'r': // Red
                return "\033[31m";
            case 'g': // Green
                return "\033[32m";
            case 'y': // Yellow
                return "\033[33m";
            case 'b': // Blue
                return "\033[34m";
            case 'w': // White
                return "\033[37m";
            case 'D': // Default
                return "\033[39m";
            case 0: // Reset
                return "\033[0m";
        }

        return "";
    }
};