#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>

using namespace std;

char* Change(char* str)
{
    char* tmp = new char[strlen(str)];
    char* p;
    int pos1 = 0,
        pos2 = 0;
    *tmp = 0;

    while (p = strchr(str + pos1, 'S'))
    {
        pos1 = pos2;
        if (str[p - str + 1] == 'Q' || str[p - str - 1] == 'Q')
        {
            if (str[p - str + 1] == 'Q')
            {
                pos2 = p - str + 2;
                strncat(tmp, str + pos1, pos2 - pos1 - 2);
                strcat(tmp, "**");
                pos1 = pos2;
            }
            if (str[p - str - 1] == 'Q')
            {
                pos2 = p - str + 1;
                strncat(tmp, str + pos1, pos2 - pos1 - 2);
                strcat(tmp, "**");
                pos1 = pos2;
            }
        }
        else
        {
            pos2 = p - str + 1;
            strncat(tmp, str + pos1, pos2 - pos1);
            pos1 = pos2;
        }
    }
    pos2 = p - str + 2;
    strncat(tmp, str + pos1, pos2 - pos1 - 2);

    strcat(tmp, str + pos1);

    strcpy(str, tmp);

    return tmp;
}

int main()
{
    char str[50] = "hjgjgabcgjhjhSSQQabcSjjSQ";
    cout << "Done string: " << endl << endl << str << endl << endl;
    char q[] = "abc";
    char q1[] = "abc";

    bool b = false;
    if (strstr(str, q))
        b = true;
    if (strstr(str, q1))
        b = true;
    if (b)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    char* second = new char[121];
    second = Change(str);

    cout << "Modified string: " << second;

    return 0;
}
