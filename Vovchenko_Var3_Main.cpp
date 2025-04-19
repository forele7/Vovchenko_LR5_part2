
#include "Vovchenko_Var3_Task.h"

using namespace std;

//число А
double a;
void setA(double a);
double getA() {return a;};

//число В
double b;
void setB(double b);
double getB() {return b;};

struct Menu1
{
    string title;
    function<void()> action;
};

//задание 1
void ShowAnum()
{
    Enter_Number(a, "Enter number A: ")();
    cout << a << endl;
}

//задание 2
void ShowBnum()
{
    Enter_Number(b, "Enter number B: ")();
    cout << b << endl;
}

// //задание 3
void Operation1()
{
    Enter_Number(a, "Enter number A: ")();
    Enter_Number(b, "Enter number B: ")();
    cout << "A*B = " << a*b << endl;
}

// // задание 4
void Operation2()
{
    Enter_Number(a, "Enter number A: ")();
    Enter_Number(b, "Enter number B: ")();
    if (b == 0){cout << "На ноль делить нельзя!";}
    else {cout << "A/B = " << a/b << endl;}
}

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