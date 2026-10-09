# CLI Menu

A small C++17 library for building command-line menus. An item can either call
an action or open another menu.

## Project layout

```text
Source/
  Inc/cli_menu.h              Menu and item definitions
Example/
  Calculator/
    Calculator.cpp            Calculator example entry point
    standard.h                Standard calculator submenu and actions
```

## Requirements

- A C++17 compiler. The example VS Code configuration uses GCC from MSYS2
  UCRT64.
- VS Code's Microsoft C/C++ extension if you want to use the supplied
  IntelliSense and debugger configuration.

## Build the calculator example

From the project root, build with:

```sh
g++ -std=c++17 -ISource/Inc Example/Calculator/Calculator.cpp -o Calculator.exe
```

Run the executable from the project root:

```sh
./Calculator.exe
```

On Windows PowerShell, use `.\Calculator.exe` to run it.

The checked-in calculator example currently needs a small source fix before
this command will compile: `Standard`'s constructor in
`Example/Calculator/standard.h` refers to `addItem`, `subtractItem`,
`multiplyItem`, and `divideItem` before those names are declared. Move those
item declarations before the class, or define the constructor after the item
declarations.

## Menu API

`CLI::Item` stores a command, a description, and an action. An action is a
`std::variant` that holds either:

- `CLI::Action`, a function pointer with the signature `void(CLI::Menu*)`; or
- `CLI::Menu*`, a pointer to a submenu.

Add items to a menu with `Menu::add`, then call `Menu::run` to display the
menu and process commands. For example:

```cpp
void showMessage(CLI::Menu*) {
    std::cout << "Action selected\n";
}

CLI::Menu menu("Main Menu");
CLI::Item actionItem("1", "Run action", &showMessage);
menu.add(actionItem);
menu.run();
```

When an item contains a submenu pointer, `Menu::add` sets that submenu's
`parent` to the menu it was added to. The menu displays `q` to quit and `b`
to go back when a parent menu is set.

## VS Code

The `.vscode` folder contains GCC build, launch/debug, and IntelliSense
settings. Open the project root as the VS Code workspace to use
`${workspaceFolder}` paths. The default build task currently references
`Source/Src/cli_menu.cpp`, which is not present in this checkout; remove that
argument from `.vscode/tasks.json` or add the source file before using the task.
