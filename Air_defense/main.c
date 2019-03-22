#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <string.h>
#include "AA.h"

void prikazy()
{
    initscr();
    printw("/l/L/login - login\n");
    printw("/a/A/add - add user to database\n");
    printw("/h/H/help - commands\n");
    printw("/e/E/end - end program\n");
    getch();
    refresh();
    endwin();
}
int main()
{
    char command[50];
    int i;
    for(i=0;i<50;i++)
    {
        command[i]=0;
    }
    banner();
    prikazy();

    initscr();
    while(strcmp(command, "e")!=0)
    {
        scanw("%s", command);

        //endwin();
       // printf("%s", command);
        convert(&command);

        if(strcmp(command, "a")==0 || strcmp(command, "add")==0)
        {
            attron(A_STANDOUT);
            printw("add to database\n");
            attroff(A_STANDOUT);
            endwin();
            database();
            initscr();
        }
        else if(strcmp(command, "l")==0 || strcmp(command, "login")==0)
        {
            printw("login\n");
            endwin();
            login();
            initscr();
        }
        else if(strcmp(command, "h")==0 || strcmp(command, "help")==0)
        {
            endwin();
            prikazy();
            initscr();
        }
        else if(strcmp(command, "e")==0 || strcmp(command, "exit")==0)
        {
            //endwin();
            printw("koncim\n");
            endwin();
            exit(1);
        }
        refresh();
    }
    refresh();
    endwin();
    //welcome();
    return 0;
}
