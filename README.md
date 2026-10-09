# CLI Menu Demo

## Overivew
This project is created for CLI menu infrastructure as CLI menu is the most common way of creating small Utilit

## How to add new menu
1. Create a class from CLI::Menu
2. Add Static methods as your menu actions
3. Create Item for each menu item with inline object creation with arguments as command, description and function pointer of action
4. In the constructor of Menu add all the object to menu
5. In case if perticular Item is a submenu repeat the above steps to create that menu
6. Add the menu into action For that Item
