#include<iostream>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include<conio.h>
#include "linkedlist-new.cpp"

using namespace std;

class admin
{
private:
    char username[6]="admin";
    char password[5]="pass";
public:
    int verify(char u[],char p[]);

};

int admin::verify(char user[],char pass[])
{
    if(!strcmp(user,username))
    {
        if(!strcmp(pass,password))
            return 1;
        else
            return 0;
    }
    else
        return 0;

}

int main()
{
    admin ad;
    int i,n,n1;
Start:
    Navigationbar();
    seprator();
    SetColor(10);
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tHow do you want to access the Directory ?\n\n\t\t\t\t\t\t\t\t\t\t\t1) Admin\n\t\t\t\t\t\t\t\t\t\t\t2) User\n\t\t\t\t\t\t\t\t\t\t\t3) Exit\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\tEnter your Choice : ";
    SetColor(0);
    cin>>n1;
    cout<<"\n\n";
    seprator();
    switch(n1)
    {
    case 1:
    {
        char u[5],p[10];
        int count=1;
        int verifycode;
User:
        Sleep(2000);
        system("cls");
        Navigationbar();
        cout<<"\t";
        seprator();
        SetColor(10);
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tEnter User-name : ";
        SetColor(0);
        scanf("%s",u);
        SetColor(10);
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tEnter Password  : ";
        SetColor(0);
        for(i=0;i<4;i++)
        {
            p[i]=_getch();
            printf("*");
        }
        Sleep(1500);
        cout<<"\n\n\t";
        seprator();
        verifycode=ad.verify(u,p);
        count++;
        if(verifycode)
        {
            Sleep(2000);
            system("cls");
            Navigationbar();
            SetColor(10);
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t: Welcome To Admin Panel :\n\n\n\n";
            while(1)
            {
Adminc:
                cout<<"\n\n";
                Navigationbar();
                cout<<"\n\n\n";
                seprator();
                SetColor(10);
                cout<<"\n";
                cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t:Choices:\n\n\t\t\t\t\t\t\t\t\t\t\t\t1) Add New Phone-Number\n\t\t\t\t\t\t\t\t\t\t\t\t2) Display Directory\n\t\t\t\t\t\t\t\t\t\t\t\t3) Search Details\n\t\t\t\t\t\t\t\t\t\t\t\t4) Update Phone-Number\n\t\t\t\t\t\t\t\t\t\t\t\t5) Delete any Contact\n\t\t\t\t\t\t\t\t\t\t\t\t6) Retrieve Deleted Detail\n\t\t\t\t\t\t\t\t\t\t\t\t7) Exit\n\t\t\t\t\t\t\t\t\t\t\t\t8) Logout\n";
                cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\tEnter your Choice : ";
                SetColor(0);
                cin>>n;
                cout<<"\n\n";
                seprator();
                detail* info=new detail();
                switch(n)
                {
                case 1:
                    Sleep(2000);
                    system("cls");
                    Navigationbar();
                    char l;
                    do
                    {

                        info->adddetail();
                        Sleep(2000);
                        system("cls");
                        Navigationbar();
                        SetColor(10);
                        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\tDo you Want to continue(y/n)? : ";
                        fflush(stdin);
                        SetColor(0);
                        cin>>l;
                        cout<<"\n\n\n";
                    }
                    while(l=='y' || l=='Y');
                    break;
                case 2:
                    Sleep(2000);
                    system("cls");
                    info->display();
                    break;
                case 3:
                    system("cls");
                    search();
                    break;
                case 4:
                    int ch;
                    system("cls");
                    Navigationbar();
                    seprator();
                    SetColor(10);
                    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\tWhere to update?\n\n\t\t\t\t\t\t\t\t\t\t\t\t1) Student Detail\n\t\t\t\t\t\t\t\t\t\t\t\t2) Faculty Detail\n\n\t\t\t\t\t\t\t\t\t\t\t\tEnter Choices : ";
                    fflush(stdin);
                    SetColor(0);
                    cin>>ch;
                    seprator();
                    update(ch);
                    Sort(ch);
                    break;
                case 5:
                    system("cls");
                    Delete();
                    break;
                case 6:
                    retrieve();
                    break;
                case 7:
                    return 0;
                    break;
                case 8:
                    system("cls");
                    SetColor(4);
                    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t!! Logout Successfully !!";
                    Sleep(2000);
                    goto Start;
                    break;
                default:
                {
                    system("cls");
                    Navigationbar();
                    SetColor(4);
                    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t!! Entered Wrong Choice !!\n\n\n\n";
                    Sleep(2000);
                    system("cls");
                    goto Adminc;
                    break;

                }
                break;
                }
            }
        }
        else
        {
            SetColor(4);
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t!! Wrong User-name or password !!\n\n";
            Sleep(2000);
            if(count<=3)
                goto User;
            else
            {
                system("cls");
                Navigationbar();
                seprator();
                cout<<"\n\n";
                SetColor(4);
                cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t!! Reached Login Limit !!\n\t\t\t\t\t\t\t\t\t\t\t\t    !! Try Again !!";
                cout<<"\n\n";
                seprator();
                Sleep(2000);
                timer();
                system("cls");
                goto Start;
            }
        }
    }
    break;
    case 2:
    {
        Sleep(2000);
        system("cls");
        Navigationbar();
        SetColor(10);
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t: Welcome To User Panel :\n\n\n\n";
        while(1)
        {
Userc:
            cout<<"\n\n";
            Navigationbar();
            cout<<"\n\n\n";
            seprator();
            SetColor(10);
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t:Choices:\n\n\t\t\t\t\t\t\t\t\t\t\t\t1) Add New Phone-Number\n\t\t\t\t\t\t\t\t\t\t\t\t2) Display Directory\n\t\t\t\t\t\t\t\t\t\t\t\t3) Search Details\n\t\t\t\t\t\t\t\t\t\t\t\t4) Exit\n\t\t\t\t\t\t\t\t\t\t\t\t5) Back to Main Menu\n";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\tEnter your Choice : ";
            SetColor(0);
            cin>>n;
            cout<<"\n\n";
            seprator();
            detail* info=new detail();
            switch(n)
            {
            case 1:
                Sleep(2000);
                system("cls");
                Navigationbar();
                char l;
                do
                {
                    info->adddetail();
                    Sleep(2000);
                    system("cls");
                    Navigationbar();
                    SetColor(10);
                    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tDo you Want to continue(y/n)? : ";
                    fflush(stdin);
                    SetColor(0);
                    cin>>l;
                    cout<<"\n\n\n";
                    system("cls");
                }
                while(l=='y' || l=='Y');
                break;
            case 2:
                system("cls");
                info->display();
                break;
            case 3:
                system("cls");
                search();
                break;
            case 4:
                return 0;
                break;
            case 5:
                goto Start;
                break;
            default:
                system("cls");
                Navigationbar();
                SetColor(4);
                cout<<"\n\t\t\t\t\t\t\t\t!! Entered Wrong Choice !!\n\n\n\n";
                Sleep(2000);
                system("cls");
                goto Userc;
                break;
            }
        }
    }
    case 3:
        return 0;
        break;
    default:
    {
        system("cls");
        Navigationbar();
        SetColor(4);
        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t!! Entered Wrong Choice !!\n\n\n\n";
        Sleep(2000);
        system("cls");
        goto Start;
    }
    break;
    }
}

