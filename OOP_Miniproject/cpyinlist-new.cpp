#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<stack>
#include "cssminiproject.cpp"
#define NULL 0

using namespace std;

void cpyinlist(int);
void cpyinfile(int);
void Delete();
void Sort(int);
void search();
void update(int);
int check(char a[]);
void Clear();
stack <string> s1;
stack <string> s2;
stack <string> s3;
stack <int> mem;

class node1
{
public:
    char fname[10];
    char lname[10];
    char number[10];
    node1* next;
};

node1* head=NULL;
void cpyinlist(int ch)
{

    char fname[100],lname[100],number[100];
    fstream p;
    if(ch==1)
    {
        p.open("pbl1.txt",ios::in);
    }
    else
    {
        p.open("pbl2.txt",ios::in);
    }

    while(p.good())
    {
        p>>fname>>lname>>number;
        if(p.fail())
        {
            break;
        }

        node1* nextnode=new node1();
        strcpy(nextnode->fname,fname);
        strcpy(nextnode->lname,lname);
        strcpy(nextnode->number,number);
        if(head==NULL)
        {
            head=nextnode;
        }
        else
        {
            node1* temp;
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nextnode;
        }
    }
}


void cpyinfile(int ch)
{
    fstream p,q,p1,q1;
    if(ch==1)
    {
        p.open("pbl1.txt",ios::out);
        q.open("pbl1.csv",ios::out);
        node1 *temp;
        temp=head;
        while(temp!=NULL)
        {
            p<<temp->fname<<"\t\t\t\t"<<temp->lname<<"\t\t\t\t"<<temp->number<<"\n";
            q<<temp->fname<<","<<temp->lname<<","<<temp->number<<"\n";
            temp=temp->next;
        }
    }
    else
    {
        p1.open("pbl2.txt",ios::out);
        q1.open("pbl2.csv",ios::out);
        node1 *temp;
        temp=head;
        while(temp!=NULL)
        {
            p1<<temp->fname<<"\t\t\t\t"<<temp->lname<<"\t\t\t\t"<<temp->number<<"\n";
            q1<<temp->fname<<","<<temp->lname<<","<<temp->number<<"\n";
            temp=temp->next;
        }
    }


}

void Delete()
{
    int ch=0,kl=0;
D:
    system("cls");
    Navigationbar();
    seprator();
    SetColor(10);
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t:Choices:\n\n\t\t\t\t\t\t\t\t\t\t\t\t1) Delete Student Details\n\t\t\t\t\t\t\t\t\t\t\t\t2) Delete Faculty Details\n\n\t\t\t\t\t\t\t\t\t\t\t\tEnter Choice : ";
    SetColor(0);
    cin>>ch;
    mem.push(ch);
    if(ch>2||ch<1)
    {
        cout<<"Entered wrong choice\n\n";
        goto D;
    }
    else
        cpyinlist(ch);
    node1 *temp,*ptr=head,*q,*m;
    char strn[20],num[20],ash[20];
    int count=0,len,i=1,k=0;
Dlp:
    system("cls");
    Navigationbar();
    SetColor(10);
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t: Welcome To Deletion Panel :\n\n\n\n";
    seprator();
    SetColor(10);
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter the Mobile Number to Delete : ";
    SetColor(0);
    cin>>strn;
    cout<<"\n\n";
    seprator();
    temp=head;
    while(temp!=NULL)
    {
        count++;
        if(!strcmp(strn,temp->number))
        {
            s1.push(temp->fname);
            s2.push(temp->lname);
            s3.push(temp->number);
            if(count==1)
            {
                node1 *p;
                p=head;
                head=p->next;
                p->next=NULL;
                k=1;
                m=temp;

                delete(p);
            }
            else
            {
                while(i<count-1)
                {
                    ptr=ptr->next;
                    i++;
                }
                q=ptr->next;
                ptr->next=q->next;
                q->next=NULL;
                delete(q);
                k=1;
                m=temp;
            }
        }
        temp=temp->next;
    }
    if(k!=1)
    {
        system("cls");
        Navigationbar();
        SetColor(4);
        cout<<"\n\t\t\t\t\t\t\t\t\t\t!! Number you want to Delete does not exists !!\n\n";
        Sleep(2000);
        goto Dlp;
    }
    else
    {
        system("cls");
        cpyinfile(ch);
        Navigationbar();
        cout<<"\n\n\n";
        SetColor(10);
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t!! Number Successfully Deleted !!\n\n\n\n";
        Sleep(2000);
        system("cls");
        Navigationbar();
        cout<<"\n\n\n";
        seprator();
        cout<<"\n\n";
        SetColor(10);
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t: Deleted Contact : \n\n\n\t\t\t\t\t\t\t\t\t\t\t\tPhone-Number : ";
        SetColor(0);
        cout<<strn;
        cout<<"\n\n";
        seprator();
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t";
        system("pause");
    }
    Clear();
}


void Sort(int ch)
{
    cpyinlist(ch);
    node1 *p,*q;
    char str1[20],str2[20];
    int i;
    p=head;
    node1 *temp;
    while(p->next!=NULL)
    {
        strcpy(str1,p->fname);
        q=p->next;
        while(q!=NULL)
        {
            int v=strcmp(p->fname,q->fname);
            if(v==1)
            {
                char temp[20];
                strcpy(temp,p->fname);
                strcpy(p->fname,q->fname);
                strcpy(q->fname,temp);

                strcpy(temp,p->lname);
                strcpy(p->lname,q->lname);
                strcpy(q->lname,temp);

                strcpy(temp,p->number);
                strcpy(p->number,q->number);
                strcpy(q->number,temp);
            }
            if(v==0)
            {
                int v1=strcmp(p->lname,q->lname);
                if(v1==1)
                {
                    char temp[20];
                    strcpy(temp,p->fname);
                    strcpy(p->fname,q->fname);
                    strcpy(q->fname,temp);

                    strcpy(temp,p->lname);
                    strcpy(p->lname,q->lname);
                    strcpy(q->lname,temp);

                    strcpy(temp,p->number);
                    strcpy(p->number,q->number);
                    strcpy(q->number,temp);
                }
            }
            q=q->next;
        }
        p=p->next;
    }
    cpyinfile(ch);
    Clear();
}

void search()
{
    int ch;
    Navigationbar();
    seprator();
    SetColor(10);
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWhere to search?\n\n\t\t\t\t\t\t\t\t\t\t\t\t1) Student Details\n\t\t\t\t\t\t\t\t\t\t\t\t2) Faculty Details\n\n\t\t\t\t\t\t\t\t\t\t\t\tEnter Choice : ";
    SetColor(0);
    cin>>ch;
    cout<<"\n\n";
    seprator();
    cpyinlist(ch);
    node1 *temp;
    char str[20];
    int k=0;
    system("cls");
    Navigationbar();
    SetColor(10);
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t: Welcome To Search Panel :\n\n\n\n";
    seprator();
    SetColor(10);
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tEnter Name to Search : ";
    SetColor(0);
    cin>>str;
    strcpy(str,strlwr(str));
    temp=head;
    while(temp!=NULL)
    {
        if(!strcmp(str,temp->fname))
        {
            SetColor(10);
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\tName         : ";
            SetColor(0);
            cout<<strupr(temp->fname)<<"\t"<<strupr(temp->lname);
            SetColor(10);
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tPhone-Number : ";
            SetColor(0);
            cout<<temp->number;
            k=1;
            cout<<"\n\n";
            seprator();
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t";
            system("pause");
        }
        temp=temp->next;
    }
    cout<<"\n\n\n\n";
    if(k!=1)
    {

        system("cls");
        Navigationbar();
        SetColor(4);
        cout<<"\t\t\t\t\t\t\t\t\t\t\t   !! Not Found !!\n\n\n\n\n\n";
        Sleep(2000);
    }
    Clear();
}


void update(int ch)
{
    cpyinlist(ch);
    node1 *temp,*p;
    char str[20],strf[20],strl[20],strn[20];
    int k=0,count=1,loc,i,n,m;
Startu:
    system("cls");
    Navigationbar();
    SetColor(10);
    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Phone-Number to Update : ";
    SetColor(0);
    cin>>str;
    temp=head;
    while(temp!=NULL)
    {
        if(!strcmp(str,temp->number))
        {

            p=temp;
            k=1;
        }
        temp=temp->next;
    }
    if(k==1)
    {
Upd:
        system("cls");
        Navigationbar();
        SetColor(10);
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t: Welcome To Update Panel :\n\n\n\n";
        seprator();
        SetColor(10);
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tWhat do you want to Update ?\n\n\t\t\t\t\t\t\t\t\t\t\t\t1) First-Name\n\t\t\t\t\t\t\t\t\t\t\t\t2) Last-Name\n\t\t\t\t\t\t\t\t\t\t\t\t3) Phone-Number\n\t\t\t\t\t\t\t\t\t\t\t\t4) Both First-Name and Last-Name\n\t\t\t\t\t\t\t\t\t\t\t\t5) Update all\n\n\t\t\t\t\t\t\t\t\t\t\t\tEnter your choice : ";
        SetColor(0);
        cin>>n;
        cout<<"\n\n";
        seprator();
        cout<<"\n\n\n\n";
        switch(n)
        {
        case 1:
            goto Fnameu;
            break;
        case 2:
            goto Lnameu;
            break;
        case 3:
            goto Phoneu;
            break;
        case 4:
            goto Fnameu;
            break;
        case 5:
            goto Fnameu;
            break;
        default :
            system("cls");
            Navigationbar();
            SetColor(4);
            cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t!! Entered Wrong Choice !!\n\n\n\n";
            Sleep(2000);
            system("cls");
            goto Upd;
            break;
        }
        if(n==5||n==4||n==1)
        {
Fnameu:
            system("cls");
            Navigationbar();
            cout<<"\n\n\n";
            seprator();
            SetColor(10);
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\tEnter New First-Name   : ";
            SetColor(0);
            cin>>p->fname;
            if(n==1)
            {
                cout<<"\n\n";
                seprator();
            }
            strcpy(strf,p->fname);
            for(i=0; strf[i]; i++)
            {
                if(!(isalpha(strf[i])))
                {
                    SetColor(4);
                    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t!! Invalid First-Name !!\n\n";
                    Sleep(2000);
                    system("cls");
                    goto Fnameu;
                    break;
                }
            }
            strlwr(strf);
            strcpy(p->fname,strf);
        }
        if(n==2||n==4||n==5)
        {
Lnameu:
            if(n==2)
            {
                Navigationbar();
                cout<<"\n\n\n";
                seprator();
                cout<<"\n\n";
            }
            SetColor(10);
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEnter New Last-Name    : ";
            SetColor(0);
            cin>>p->lname;
            if(n==2 || n==4)
            {
                cout<<"\n\n";
                seprator();
            }
            strcpy(strl,p->lname);
            for(i=0; strl[i]; i++)
            {
                if(!(isalpha(strl[i])))
                {
                    SetColor(4);
                    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t!! Invalid Last-Name !!\n\n";
                    Sleep(2000);
                    system("cls");
                    goto Lnameu;
                    break;
                }
            }
            strlwr(strl);
            strcpy(p->lname,strl);
        }
        if(n==3||n==5)
        {
Phoneu:
            if(n==3)
            {
                Navigationbar();
                cout<<"\n\n\n";
                seprator();
                cout<<"\n\n";
            }
            SetColor(10);
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEnter New Phone-Number : ";
            SetColor(0);
            cin>>strn;
            cout<<"\n\n";
            seprator();
            cout<<"\n\n";
            node1 *temp;
            temp=head;
            while(temp!=NULL)
            {
                if(!strcmp(strn,temp->number))
                {
                    SetColor(4);
                    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t!! Phone-Number Already Exists !!";
                    Sleep(2000);
                    system("cls");
                    goto Phoneu;
                }
                temp=temp->next;
            }


            if(strlen(strn)!=10||strn[0]=='0')
            {
                SetColor(4);
                cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t!! Invalid Phone Number !!\n\n";
                Sleep(2000);
                system("cls");
                goto Phoneu;
            }

            strcpy(p->number,strn);
        }
        cpyinfile(ch);
        system("cls");
        Navigationbar();
        SetColor(10);
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t!!Data Successfully Updated !!\n\n";
        seprator();
        cout<<"\n\n\n";
        SetColor(10);
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tUpdated Data :\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tName : ";
        SetColor(0);
        cout<<strupr(p->fname)<<"\t"<<strupr(p->lname);
        SetColor(10);
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tPhone-Number : ";
        SetColor(0);
        cout<<p->number;
        cout<<"\n\n\n";
        seprator();
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t";
        system("pause");


    }
    else
    {
        SetColor(4);
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t!! Phone-Number Not Found !!";
        Sleep(2000);
        system("cls");
        goto Startu;
    }

    Clear();
}

int check(char a[])
{
    int k;
    cpyinlist(1);
    node1 *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(!strcmp(a,temp->number))
        {
            k=1;
            return 1;
        }

        temp=temp->next;
    }
    Clear();
    if(k!=1)
    {
        cpyinlist(2);
        temp=head;
        while(temp!=NULL)
        {
            if(!strcmp(a,temp->number))
            {
                return 1;
            }

            temp=temp->next;
        }
        Clear();
    }

}

void Clear()
{
    node1* temp;
    temp=head;
    while(temp!=NULL)
    {
        delete(temp);
        temp=temp->next;
    }
    head=NULL;
}

void retrieve()
{
    fstream p;
    if(s1.empty())
    {
        Navigationbar();
        cout<<"\n\n\n";
        seprator();
        SetColor(4);
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tNo any Detail Recently Deleted\n\n";
        seprator();
        Sleep(2000);

    }
    else
    {
        if(mem.top()==1)
        {
            p.open("pbl1.txt",ios::out|ios::app);
            p<<"\n"<<s1.top()<<"\t\t\t\t\t";
            p<<s2.top()<<"\t\t\t\t\t";
            p<<s3.top()<<"\n";
            s1.pop();
            s2.pop();
            s3.pop();
            mem.pop();
            p.close();
            Sort(1);
            Navigationbar();
            cout<<"\n\n\n";
            seprator();
            SetColor(10);
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\tContact Successfully Retrieved To Student Database\n\n";
            seprator();
            Sleep(3000);
        }
        else if(mem.top()==2)
        {
            p.open("pbl2.txt",ios::out|ios::app);
            p<<"\n"<<s1.top()<<"\t\t\t\t\t";
            p<<s2.top()<<"\t\t\t\t\t";
            p<<s3.top()<<"\n";
            s1.pop();
            s2.pop();
            s3.pop();
            mem.pop();
            p.close();
            Sort(2);
            Navigationbar();
            cout<<"\n\n\n";
            seprator();
            SetColor(10);
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\tContact Successfully Retrieved To Faculty Database\n\n";
            seprator();
            Sleep(3000);
        }
    }
}
