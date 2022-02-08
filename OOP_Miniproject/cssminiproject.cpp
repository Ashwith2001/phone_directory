#include<iostream>
#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <iomanip>
using namespace std;

void SetColor(int ForgC);
void ClearConsoleToColors(int ForgC, int BackC);
void Navigationbar();
void seprator();


void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void ClearConsoleToColors(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SetConsoleTextAttribute(hStdOut, wColor);
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
        SetConsoleCursorPosition(hStdOut, coord);
    }
    return;
}

void Navigationbar()
{
    int i;
    ClearConsoleToColors(0,14);
    cout<<"\n\n";
    SetColor(1);
    for(i=0; i<211; i++)
        printf("*");
    SetColor(1);
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t-:- Telephone Directory -:-\t\t\t\t\t\t\t\t\t\t\t\n\n";
    for(i=0; i<211; i++)
        cout<<"*";
    cout<<"\n\n\n\n";
}

void seprator()
{
    int i;
    SetColor(13);
    cout<<"\t\t\t\t\t\t\t\t";
    for(i=0; i<80; i++)
        cout<<"#";
}
void timer()
{
    int seconds = 30,hours = 0, minutes = 0;
    while (true)
    {
        system("cls");
        SetColor(4);
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t  Try Again In 30s\n\n";
        SetColor(13);
        cout <<"\t\t\t\t\t\t\t\t\t\t\t\t\t   TIMER		 \n";
        SetColor(10);
        cout <<"\t\t\t\t\t\t\t\t\t\t\t\t        ----------\n";
        cout << setfill(' ') << setw(29);
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t| ";
        SetColor(0);
        cout << setfill('0') << setw(2) << seconds << " sec " ;
        SetColor(10);
        cout <<"|\n\t\t\t\t\t\t\t\t\t\t\t\t        ----------\n";
        Sleep(1000);
        --seconds;
        if (seconds == 0)
        {
            break;
        }
    }
}


