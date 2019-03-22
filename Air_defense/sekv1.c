#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include <time.h>
#include "AA.h"

static void cas(char **s)
{
    time_t seconds;
    time(&seconds);
    (*s)=ctime(&seconds);
}
void welcome()
{
    char *s1="###############################################################################\n";
    char *s2="WELCOME USER\n";
    char *s3=NULL;
    int rows, cols;

    cas(&s3);//casovy string
    initscr();
    getmaxyx(stdscr, rows, cols);//makro na ziskanie rows and cols
    mvprintw(1,(cols-strlen(s1))/2, "%s", s1);
    addch('\n');
    mvprintw(3, (cols-strlen(s2))/2, "%s", s2);
    addch('\n');
    mvprintw(5, (cols-strlen(s3))/2, "%s", s3);
    addch('\n');
    mvprintw(7, (cols-strlen(s1))/2, "%s", s1);
    printw("Press any key>\n");
    getch();
    clear();//vycisti text
    refresh();
}
void banner()
{
    char *s1="Anti air defense program ver ALPHA.\n";
    char *s2="Program develobed by Patrik Florians and Cyber_Legion.\n";
    char *s3="This program contains military simulations.\n";
    int rws,cls;
    initscr();
    clear();
    getmaxyx(stdscr, rws, cls);
    mvprintw(1, (cls-strlen(s1))/2, "%s", s1);
    addch('\n');
    mvprintw(3, (cls-strlen(s2))/2, "%s", s2);
    addch('\n');
    mvprintw(5, (cls-strlen(s3))/2, "%s", s3);
    printw("\nPress any key to continue>\n");
    getch();
    clear();
    refresh();
    endwin();
}

void convert(char *a)
{
    int i;
    for(i=0;i<strlen(a);i++)
    {
        a[i]=LOW(a[i]);
    }

}


