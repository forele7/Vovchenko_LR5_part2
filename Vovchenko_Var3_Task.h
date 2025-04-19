#ifndef _VOVCHENKO_VAR3TASK_H_
#define _VOVCHENKO_VAR3TASK_H_

#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>
#include <numeric>
#include <functional>
#include <string>

using namespace std;

bool Input (string input) 
{
    if (input.empty()) 
    {
        return false;
    }
    
    for (char c : input) 
    {
        if (!isdigit(c)) 
        {
            return false;
        }
    }
    
    try 
    {
        int number = stoi(input);
        if (number < 0) 
        {
            return false;
        }
    } 
    catch (...) 
    {
        return false;
    }
    return true;
}


function<void()> Enter_Number(double& varLink, string label)
{
    return [&varLink, label]()
    {
        string get_input;
        cout << label << "= ";
        getline(cin, get_input);
        while (!Input(get_input))
        {
            cout << label << "= ";
            getline(cin, get_input);
        }
        varLink = stod(get_input);
    };
}

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

#endif