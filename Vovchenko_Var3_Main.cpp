#include "Vovchenko_Var3_Task.h"

using namespace std;

int main()
{
    map<int, Menu1> menu =
    {
        {1, {"Вывести A", ShowAnum}},
        {2, {"Вывести B", ShowBnum}},
        {3, {"Выполнить операцию “*”", Operation1}},
        {4, {"Выполнить операцию “/”", Operation2}},
    };

    double choice = 0;

    cout << "Menu: " << endl;
    for (const auto& item : menu)
    {
        cout << "Task: " <<item.first << ". " << item.second.title << endl;
    }

    cout << "0. Quit." << endl;

    while (true)
    {
    Enter_Number(choice, "Enter Number of task: ")();
    if (choice == 0)
    {
        cout << endl;
        break;
    }

    cout << endl;

    if (menu.find(choice) != menu.end())
    {
        menu[choice].action();
    }
    else
    {
        cout << "Invalid input.";
    }

    cout << endl << endl;
    }
    return 0;
}