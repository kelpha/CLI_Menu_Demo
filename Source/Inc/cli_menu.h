/**
 * @file cli_menu.h
 * @brief Defines the CLI menu and item types.
 *
 * Items can invoke an action callback or open a submenu.
 */
#ifndef CLI_MENU_H
#define CLI_MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <variant>

namespace CLI {
    class Menu;
    using Action = void(*)(Menu*);
    using ItemAction = std::variant<Action, Menu*>;

    struct Item {
        const char* cmd;
        const char* desc;
        ItemAction action;

        Item(const char* _cmd, const char* _desc, ItemAction _action) 
            : cmd(_cmd), desc(_desc), action(_action) {}
    };
    
    class Menu {
    public:
        const char* title;
        Menu* parent;
        std::vector<Item> items;

        Menu(const char* _title, Menu* _parent = nullptr) : title(_title), parent(_parent) {}

        void add(const Item& item) {
            if (std::holds_alternative<Menu*>(item.action)) {
                Menu* submenu = std::get<Menu*>(item.action);
                submenu->parent = this; // Set the parent of the submenu
            }
            items.push_back(item);
        }

        void display() {
            std::cout << "=== " << title << " ===" << std::endl;
            for (const auto& item : items) {
                std::cout << item.cmd << ": " << item.desc << std::endl;
            }
            if (parent) {
                std::cout << "b: Back" << std::endl;
            }
            std::cout << "q: Quit" << std::endl;
        }

        void run() {
            while (true) {
                display();
                std::string input;
                std::cout << "Enter command: ";
                std::cin >> input;

                if (input == "q") {
                    break;
                } else if (input == "b" && parent) {
                    parent->run();
                    break;
                } else {
                    bool found = false;
                    for (const auto& item : items) {
                        if (input == item.cmd) {
                            if (auto action = std::get_if<Action>(&item.action)) {
                                (*action)(this);
                            } else if (auto submenu = std::get_if<Menu*>(&item.action)) {
                                (*submenu)->run();
                            }
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        std::cout << "Invalid command. Please try again." << std::endl;
                    }
                }
            }
        }
    };
};



#endif // CLI_MENU_H