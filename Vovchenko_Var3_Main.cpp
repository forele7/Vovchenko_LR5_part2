#include "Vovchenko_Var3_Task.h"

using namespace cute;
using namespace std;

int main()
{
    suite s;

    s.push_back(CUTE(ShowNumA1));
    s.push_back(CUTE(ShowNumA2));
    s.push_back(CUTE(ShowNumA3));

    s.push_back(CUTE(ShowNumB1));
    s.push_back(CUTE(ShowNumB2));
    s.push_back(CUTE(ShowNumB3));

    s.push_back(CUTE(test1Operation1));
    s.push_back(CUTE(test2Operation1));

    s.push_back(CUTE(test1Operation2));
    s.push_back(CUTE(test2Operation2));

    ide_listener<> listener;
    makeRunner(listener)(s, "Test");
}

// struct Menu1
// {
//     string title;
//     function<void()> action;
// };

// int main()
// {
//     suite s;
//     // s.push_back(CUTE(ShowNumA1));

//     map<int, Menu1> menu =
//     {
//         // {1, {"Тест 1: Вывести A", [&s]() { s.push_back(CUTE(ShowNumA1)); }}},
//         // {2, {"Тест 2: Вывести A", ShowNumA2}},
//         // {3, {"Тест 3: Вывести A", ShowNumA3}},
//         // {4, {"Тест 4: Вывести A", ShowNumA4}},

//         // {5, {"Тест 1: Вывести B", ShowNumB1}},
//         // {6, {"Тест 2: Вывести B", ShowNumB2}},
//         // {7, {"Тест 3: Вывести B", ShowNumB3}},
//         // {8, {"Тест 4: Вывести B", ShowNumB4}},

//         {9, {"Тест 1: Выполнить операцию “*”", CUTE(test1Operation1)}},
//         //{10, {"Тест 2: Выполнить операцию “*”", Operation1Test2}},

//         {11, {"Выполнить операцию “/”", test1Operation2}},
//         // {12, {"Выполнить операцию “/”", Operation2Test2}},

//     };
//     ide_listener<> listener;
//     makeRunner(listener)(s, "Test");

//     double choice = 0;

//     cout << "Menu: " << endl;
//     for (const auto& item : menu)
//     {
//         cout << "Task: " <<item.first << ". " << item.second.title << endl;
//     }

//     cout << "0. Quit." << endl;

//     while (true)
//     {
//     Enter_Number(choice, "Enter Number of task: ")();
//     if (choice == 0)
//     {
//         cout << endl;
//         break;
//     }

//     cout << endl;

//     if (menu.find(choice) != menu.end())
//     {
//         menu[choice].action();
//     }
//     else
//     {
//         cout << "Invalid input.";
//     }

//     cout << endl << endl;
//     }
//     return 0;
// }
