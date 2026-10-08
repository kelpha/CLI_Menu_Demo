#ifndef SIMPLE_H
#define SIMPLE_H
#include <iostream>
#include "cli_menu.h"

namespace Calculator {
    class Standard : public CLI::Menu {
    public:
        Standard(const char* title = "Standard Menu");

        static void add(CLI::Menu* menu) {
            std::cout << "Performing addition..." << std::endl;
        }
        static void subtract(CLI::Menu* menu) {
            std::cout << "Performing subtraction..." << std::endl;
        }
        static void multiply(CLI::Menu* menu) {
            std::cout << "Performing multiplication..." << std::endl;
        }
        static void divide(CLI::Menu* menu) {
            std::cout << "Performing division..." << std::endl;
        }
    };

    static inline CLI::Item addItem("1", "Add", Standard::add);
    static inline CLI::Item subtractItem("2", "Subtract", Standard::subtract);
    static inline CLI::Item multiplyItem("3", "Multiply", Standard::multiply);
    static inline CLI::Item divideItem("4", "Divide", Standard::divide);
    static inline Standard standardMenu("Standard Menu");
    
}

#endif // SIMPLE_H