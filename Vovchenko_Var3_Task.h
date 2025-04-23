#ifndef _VOVCHENKO_VAR3TASK_H_
#define _VOVCHENKO_VAR3TASK_H_

#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"

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

//тест А1: отсев буквенных значений
void ShowNumA1()
{
    string A = "ww";
    bool expected = false;
    bool actual = Input(A);
    ASSERT_EQUAL(expected, actual);
}

// тест А2: отсев цифро-буквенных значений
void ShowNumA2()
{
    string A = "7e";
    bool expected = false;
    bool actual = Input(A);
    ASSERT_EQUAL(expected, actual);
}

// тест А3: отсев пустых значений
void ShowNumA3()
{
    string A = "";
    bool expected = false;
    bool actual = Input(A);
    ASSERT_EQUAL(expected, actual);
}

// тест В1: отсев пустых значений
void ShowNumB1()
{
    string B = "";
    bool expected = false;
    bool actual = Input(B);
    ASSERT_EQUAL(expected, actual);
}

// тест В2: отсев буквенных значений
void ShowNumB2()
{
    string B = "-3";
    bool expected = false;
    bool actual = Input(B);
    ASSERT_EQUAL(expected, actual);
}

// тест В3: отсев цифро-буквенных значений
void ShowNumB3()
{
    string B = "e9";
    bool expected = false;
    bool actual = Input(B);
    ASSERT_EQUAL(expected, actual);
}

// задание 3
int testCalc1(double A, double B)
{
    return A * B;
}

// тест 1: умножение
void test1Operation1()
{
    double A = 9;
    double B = 4;

    double expected = 36;
    double actual = testCalc1(A, B);
    ASSERT_EQUAL (expected, actual);
}

// тест 2: умножение
void test2Operation1()
{
    double A = 6;
    double B = 7;

    double expected = 50;
    double actual = testCalc1(A, B);
    ASSERT_EQUAL (expected, actual);
}

//задание 4
int testCalc2(double A, double B)
{
    return A / B;
}

// тест 1: деление
void test1Operation2()
{
    double A = 8;
    double B = 2;

    double expected = 4;
    double actual = testCalc2(A, B);
    ASSERT_EQUAL (expected, actual);
}

// тест 2: деление
void test2Operation2()
{
    double A = 40;
    double B = 10;

    double expected = 6;
    double actual = testCalc2(A, B);
    ASSERT_EQUAL (expected, actual);
}

#endif