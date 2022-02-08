#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#define NULL 0
#include "cpyinlist-new.cpp"

using namespace std;

class node
{
public:
    char fname[20];
    char lname[20];
    char number[10];
    node* next;
};
class detail
{
public:
    detail()
    {
        head=NULL;
    }
    void adddetail();
    void display();
private:
    node* head;
};
void detail::adddetail()
{
    int h,k=0,i=0;
    node *value=new node();
    char cf[20],cl[20],cn[20],str[20],strf[20],strl[20];

Start:
    int f=1;
    cout<<"\n\n\n\n";
    seprator();
Fname:
    SetColor(10);
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tEnter First-Name :   ";
    SetColor(0);
    cin>>value->fname;
    strcpy(strf,value->fname);
    for(i=0; strf[i]; i++)
    {
        if(!(isalpha(strf[i])))
        {
            SetColor(4);
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t!! Invalid First Name !!\n\n";
            goto Fname;
            break;

        }
    }
    strlwr(strf);
    strcpy(value->fname,strf);
Lname:
    SetColor(10);
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tEnter Last-Name :    ";
    SetColor(0);
    cin>>value->lname;
    strcpy(strl,value->lname);

    for(i=0; strl[i]; i++)
    {
        if(!(isalpha(strl[i])))
        {
            SetColor(4);
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t!! Invalid Last Name !!\n\n";
            goto Lname;
            break;
        }
    }
    strlwr(strl);
    strcpy(value->lname,strl);
Phone:
    SetColor(10);
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tEnter Phone Number : ";
    SetColor(0);
    cin>>value->number;
    cout<<"\n\n";
    seprator();
    strcpy(str,value->number);
    if(strlen(str)!=10||str[0]=='0')
    {
        SetColor(4);
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t!! Invalid Phone-number !!\n\n";
        goto Phone;
    }

    k=check(str);
    if(k==1)
    {
        Sleep(1000);
        system("cls");
        Navigationbar();
        cout<<"\n\n\n";
        SetColor(4);
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t!! Phone-Number Already Exits !!\n\n";
        Sleep(2000);
        system("cls");
        Navigationbar();
        cout<<"\n\n\n";
        goto Phone;
    }
    Sleep(2000);
    system("cls");
    Navigationbar();
    SetColor(10);
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\tTo Confirm Please Enter Details again \n\n\n\n";
Enter:
    seprator();
    SetColor(10);
    h=0;
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tEnter First-Name :   ";
    SetColor(0);
    cin>>cf;
    SetColor(10);
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tEnter Last-Name :    ";
    SetColor(0);
    cin>>cl;
    strlwr(cf);
    strlwr(cl);
    SetColor(10);
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tEnter Phone Number : ";
    SetColor(0);
    cin>>cn;
    cout<<"\n\n";
    seprator();

    if(strcmp(cf,value->fname))
    {
        system("cls");
        Navigationbar();
        cout<<"\n";
        SetColor(4);
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t!! Entered Wrong First Name !!";
        cout<<"\n\t\t\t";
        cout<<"\n\n";
        seprator();
        h=1;
    }
    if(strcmp(value->lname,cl))
    {
        cout<<"\n";
        SetColor(4);
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t!! Entered Wrong Last Name !!";
        cout<<"\n\t\t\t";
        cout<<"\n\n";
        seprator();
        h=1;
    }
    if(strcmp(cn,value->number))
    {
        cout<<"\n";
        SetColor(4);
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t!! Entered Wrong Phone Number !!";
        cout<<"\n\t\t\t";
        cout<<"\n\n";
        seprator();
        h=1;
    }
    if(f<3 && h==1)
    {
        cout<<"\n";
        SetColor(4);
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t!! Try again !!";
        cout<<"\n\t\t\t";
        cout<<"\n\n";
        f++;
        Sleep(2000);
        system("cls");
        Navigationbar();
        goto Enter;
    }
    if(f==3)
    {
        Sleep(2000);
        system("cls");
        Navigationbar();
        cout<<"\n";
        SetColor(4);
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t!! Detecting Theft for System !! ";
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t!! Try again from starting !!";
        cout<<"\n\n";
        Sleep(2000);
        timer();
        system("cls");
        Navigationbar();
        SetColor(10);
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Enter Details Again";
        goto Start;
    }

    int choice;
    fstream p,q;
    fstream p1,q1;
    cout<<"\n\n";
    Navigationbar();
    seprator();
    SetColor(10);
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWhere To Add ?\n\n\t\t\t\t\t\t\t\t\t\t\t\t1) Add to Student Details\n\t\t\t\t\t\t\t\t\t\t\t\t2) Add to Faculty Details\n\n\t\t\t\t\t\t\t\t\t\t\t\tEnter your Choice : ";
    SetColor(0);
    cin>>choice;
    cout<<"\n\n";
    seprator();
    switch(choice)
    {
    case 1:

        p.open("pbl1.txt",ios::out|ios::app);
        if(!p)
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tfile not created";
        else
        {
            p<<cf<<"\t\t\t\t\t";
            p<<cl<<"\t\t\t\t\t";
            p<<cn<<"\n";

            value->next=NULL;
            if(head==NULL)
            {
                head=value;
            }
            else
            {
                node *temp;
                temp=head;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=value;
            }
        }
        p.close();
        Sort(1);
        break;
    case 2:
        p1.open("pbl2.txt",ios::out|ios::app);
        if(!p1)
            cout<<"file not created";
        else
        {
            p1<<cf<<"\t\t\t\t\t";
            p1<<cl<<"\t\t\t\t\t";
            p1<<cn<<"\n";

            value->next=NULL;
            if(head==NULL)
            {
                head=value;
            }
            else
            {
                node *temp;
                temp=head;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=value;
            }
        }
        p1.close();
        Sort(2);
        break;
    default:
        break;
    }
}

void detail::display()
{
    int choice;
    system("cls");
    Navigationbar();
    seprator();
    SetColor(10);
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t:Choices:\n\n\t\t\t\t\t\t\t\t\t\t\t\t   1) Student Contact\n\t\t\t\t\t\t\t\t\t\t\t\t   2) Faculty Contact\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Enter your Choice : ";
    SetColor(0);
    cin>>choice;
    cout<<"\n\n";
    seprator();

    fstream p,q;

    char ch[10000],ch1[10000];

    system("cls");
    Navigationbar();
    SetColor(10);
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t: Directory :\n\n\n\n";
    seprator();
    cout<<"\n\n\n";
    char line[200];
    SetColor(10);
    cout<<"\t\t\t\t\t\t\t\tFIRSTNAME\t\t\tLASTNAME\t\t\tPhone-Number\n\n\n";

    switch(choice)
    {
    case 1:
        p.open("pbl1.txt",ios::in);
        while(p)
        {

            printf("\t\t\t\t\t\t\t\t");
            p.getline(ch,10000);
            cout<<strupr(ch)<<endl;
        }
        cout<<"\n\n";
        seprator();
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t";
        system("pause");
        system("cls");
        break;
    case 2:
        q.open("pbl2.txt",ios::in);
        while(q)
        {
            printf("\t\t\t\t\t\t\t\t");
            q.getline(ch1,10000);
            cout<<strupr(ch1)<<endl;
        }
        cout<<"\n\n";
        seprator();
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t";
        system("pause");
        system("cls");
        break;
    default:
        cout<<"\n\n";
        seprator();
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t";
        system("pause");
        system("cls");
        cout<<"\n\nWrong Choice ";
        break;

    }
}
