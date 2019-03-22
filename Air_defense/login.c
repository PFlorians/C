#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include "AA.h"

static int first=0;
void coding(char *a)
{
    int i;
    for (i=0;i<strlen(a);i++)
    {
        a[i]=a[i]+10;
    }
    a[i]='\0';
}
void decoding(char *a)
{
    int i;
    for(i=0;i<strlen(a);i++)
    {
        a[i]=a[i]-10;
    }
    a[i]='\0';
}
void acdata(DATA **fi, DATA **ac, DATA **pr)
{
    FILE *f;
    int kt=0, j=0, i;
    char c, st[50];
    if((f=fopen("database.AA", "r"))==NULL)
    {
        printw("ERROR OPENING FILE\n");
    }
    while((c=getc(f))!=EOF)
    {
        if(c!='\n' && c!='#')
        {
            st[j]=c;
            j++;
        }
        else if(c=='\n')
        {
            if(kt==0)
            {
                st[j]='\0';
                if((*fi)==NULL && first==0)
                {
                    (*fi)=(DATA*)malloc(sizeof(DATA));
                    strcpy((&(*fi)->user), st);
                }
                else
                {
                    (*ac)->next=(DATA*)malloc(sizeof(DATA));//tu je chyba
                    (*ac)=(*ac)->next;
                    strcpy((&(*ac)->user), st);
                }
                kt++;
                j=0;
                for(i=0;i<strlen(st);i++)
                {
                    st[i]=0;
                }
            }
            else if(kt==1)
            {
                st[j]='\0';
                if(first==0)
                {
                    strcpy((&(*fi)->pw), st);
                    (*fi)->next=NULL;
                    (*pr)=(*ac)=(*fi);
                    first=1;
                }
                else
                {
                    strcpy((&(*ac)->pw), st);
                    (*ac)->next=NULL;
                }
                kt++;
                j=0;
                for(i=0;i<strlen(st);i++)
                {
                    st[i]=0;
                }
            }
            else if(kt==2)
            {
                st[j]='\0';
                j=0;
                for(i=0;i<strlen(st);i++)
                {
                    st[i]=0;
                }
                kt=0;
            }

        }
    }
    getch();
    fclose(f);
}
void database()
{
    FILE *f;
    DATA *fi=NULL, *ac=NULL, *pr=NULL;
    char user[50];
    char pw[20];
    char *superu;
    char *superpw;
    char c;
    int checku=0, checkpw=0;//1 true, 0 false
    int sy, sx;             //stred konzoly
    char addu[50], addpw[50];

    initscr();
    getmaxyx(stdscr, sy, sx);

    superu="root";
    superpw="root";

    if((f=fopen("database.AA", "a"))==NULL)
    {
        printw("ERROR OPENING DATABASE EXITING NOW\n");
        endwin();
        exit(1);
    }
    if((c=getc(f))==EOF)
    {
        //printw("THERE IS NO USER NOR PASSWORD\n");
        l: printw("Please enter superuser id and password\n");
        printw("Username: ");
        echo();
        getstr(user);
        printw("Password: ");
        noecho();
        getstr(pw);
        addch('\n');
        if((strcmp(user, superu))==0)
        {
            checku=1;
        }
        else
        {
            checku=0;
        }
        if(strcmp(pw, superpw)==0)
        {
            checkpw=1;
        }
        else
        {
            checkpw=0;
        }
        if(checkpw==0 || checku==0 || (checkpw==0 && checku==0))
        {
            attron(A_STANDOUT);
            clear();
            mvprintw(3, (sx-30)/2, "INCORRECT USERNAME OR PASSWORD\n");
            attroff(A_STANDOUT);
            goto l;
        }
        else
        {
            printw("Thank you super user.\n");
            printw("Please enter the username and password for new user\n");
            echo();
            printw("Username: ");
            getstr(addu);
            printw("Password: ");
            noecho();
            getstr(addpw);
            clear();
            echo();
            coding(&addpw);
            //decoding(&addpw);

            fprintf(f, "%s\n", addu);
            fprintf(f, "%s\n", addpw);
            fprintf(f, "#################################################################\n");

            rewind(f);
        }
    }
    fclose(f);
     acdata(&fi, &ac, &pr);
    /*else
    {
        printw("else\n");
        while((c=getc(f))!=EOF)//az dokonca
        {
            ;
        }
        t: printw("Please enter superuser id and password\n");
        printw("Username: ");
        echo();
        getstr(user);
        printw("Password: ");
        noecho();
        getstr(pw);
        addch('\n');
        if((strcmp(user, superu))==0)
        {
            checku=1;
        }
        else
        {
            checku=0;
        }
        if(strcmp(pw, superpw)==0)
        {
            checkpw=1;
        }
        else
        {
            checkpw=0;
        }
        if(checkpw==0 || checku==0 || (checkpw==0 && checku==0))
        {
            attron(A_STANDOUT);
            clear();
            mvprintw(3, (sx-30)/2, "INCORRECT USERNAME OR PASSWORD\n");
            attroff(A_STANDOUT);
            goto t;
        }
        else
        {
            printw("Thank you super user.\n");
            printw("Please enter the username and password for new user\n");
            echo();
            printw("Username: ");
            getstr(addu);
            printw("Password: ");
            noecho();
            getstr(addpw);
            clear();
            echo();
            coding(&addpw);
            //decoding(&addpw);

            fprintf(f, "%s\n", addu);
            fprintf(f, "%s\n", addpw);
            fprintf(f, "#################################################################\n");

            rewind(f);
        }
    }*/
    fclose(f);
    refresh();
    endwin();
}
void login()
{
    char username[50];
    char password[20];
    //endwin();

    initscr();
    printw("Username: ");
    getstr(username);
    noecho();
    printw("\nPassword: ");
    getstr(password);
    //getch();
    clear();
    refresh();
    endwin();
}
