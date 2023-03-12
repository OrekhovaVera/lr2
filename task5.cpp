//
// Created by Вера Орехова on 12.03.2023.
//
#include "header.h"

//Входные данные
//В единственной строке записано выражение в постфиксной записи, содержащее цифры и операции +, -, *.
// Цифры и операции разделяются пробелами. В конце строки может быть произвольное количество пробелов.
//
//Выходные данные
//Необходимо вывести значение записанного выражения.

double strToNumber(std::string s) //преобразовываем строку в числа
{
    double number = 0;
    for (int i = 0; i<s.size(); i++) number = number * 10 + s[i] - '0';
    return number;
}

double calc(const std::string &str)  //функция, благодря которой вычисляем арифметическое выражение
{
    std::stack <double> stk; //задаем элементы и переменные
    std::string a;
    double value,a1,a2;
    std::string tmp =""; //для ананлиза строки
    char c;
    std::vector <std::string> lex;

    for (int i = 0; i < str.size(); i++) //смотрим знаки и числа в строке и добавляем их в tmp
    {
        c = str[i];
        if (c == ' ')
        {
            if (tmp.size() > 0) lex.push_back(tmp);
            tmp = "";
        }
        else
            tmp = tmp + c;
    }

    if (tmp.size()>0) lex.push_back(tmp); //проверяем ввод на "нормальность"
    for (int i = 0; i < lex.size(); i++) //поэлементно перебираем строку
    {
        a = lex[i];
        if (a[0] >= '0' && a[0] <= '9') //проверка на число (число или не число)
        {
            value = strToNumber(a);
            stk.push(value); //после превращения строки в число добавляем ее в стек
        }
        else
        {
            a2 = stk.top(); //берем верхнее значение стека
            stk.pop(); //удаляем это значение
            a1 = stk.top(); //берем нижнее значение стека
            stk.pop(); //удаляем его

            switch (a[0]) //функция переключения операций в зависимости от знака
            {
                case '+':
                    value = a1+a2;
                    break;
                case '-':
                    value = a1-a2;
                    break;
                case '*':
                    value = a1*a2;
                    break;
            }

            stk.push(value); //добавляем значения в верх стека

        }
    }

    return stk.top();
}

 void taskE()
{
    std::string expr;
    std::cout << " ";
    getline(std::cin,expr);
    try
    {
       std::cout << calc(expr) << std::endl;
    }
    catch (char const *msg)
    {
        std::cout << msg << std::endl;
    }
}
