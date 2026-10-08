#include <iostream>

#include "cli_menu.h"
#include "standard.h"

using namespace std;
using namespace CLI;

int main(void)
{
    Menu TopLevelMenu("Top Level Menu");
    Item standardItem(  "1", "Standard", &Calculator::standardMenu);

    TopLevelMenu.add(standardItem);

    TopLevelMenu.run();
    
    return 0;
}
