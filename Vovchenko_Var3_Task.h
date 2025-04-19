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

#endif