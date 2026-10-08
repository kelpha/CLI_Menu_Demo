#include "standard.h"

using namespace Calculator;

Standard::Standard(const char* title) : CLI::Menu(title) {
    CLI::Menu::add(addItem);
    CLI::Menu::add(subtractItem);
    CLI::Menu::add(multiplyItem);
    CLI::Menu::add(divideItem);
}