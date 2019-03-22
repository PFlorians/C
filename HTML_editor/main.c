#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <dirent.h>
#include <unistd.h>
#define _WIN32_WINNT 0x0502
#include <windows.h>

/*
*treba doriesit davanie do suboru atd
*treba vyriesit scroll v okne mn
*       =>alternativa: vytvorenie druheho programu, ktory by sa spustal na zaciatku tohoto a monitoroval by zmeny suboru
*/
/*
*tu je vyvoj editoru
*/
typedef struct border
{
    char lh, ld, ph, pd, hr, dl, ls, ps;
}BORDER;

void borders(BORDER **m)
{
    (*m)->lh='+';
    (*m)->ld='+';
    (*m)->ph='+';;
    (*m)->pd='+';
    (*m)->hr='-';
    (*m)->dl='-';
    (*m)->ls='|';
    (*m)->ps='|';
}
void draw(WINDOW *wi, BORDER *m, int h, int w)
{

    //kresli okraje
    mvwprintw(wi, 0, 0, "%c", m->lh);
    mvwprintw(wi, 0, w-1, "%c", m->ph);
    mvwprintw(wi, h-1, 0, "%c", m->ld);
    mvwprintw(wi, h-1, w-1, "%c", m->pd);
    //linie
    mvwhline(wi, 0, 1, m->hr, w-2);
    mvwhline(wi, h-1, 1, m->dl, w-2);
    mvwvline(wi, 1, 0, m->ls, h-2);
    mvwvline(wi, 1, w-1, m->ps, h-2);
    wrefresh(wi);
}
void MaximizeOutputWindow(void)
{
    HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window
    ShowWindow(consoleWindow, SW_MAXIMIZE); // this mimics clicking on its' maximize button
}

void RestoreOutputWindow(void)
{
    HWND consoleWindow = GetConsoleWindow(); // Same as above
    ShowWindow(consoleWindow, SW_RESTORE); // this mimics clicking on its' maximize for a second time, which puts it back to normal
}

void show(int rx, int ry, char cmd[][100], int i, WINDOW *mn)
{
    int py=ry, px=rx;
    //for(j=0;j<i;j++)
    //{
        mvwprintw(mn, py, px, "%s", cmd[i-1]);
      //  py++;
    //}
}

int main(int argc, int **argv)
{
    FILE *f=NULL, *buff=NULL;
    int h=0, w=0, h1, w1, h2, w2;
    int hn, wn;
    int startx1, starty1;
    int startx2, starty2;
    int cykly=0;
    char command[100][100], type=0;
    char fname[]="win.txt";
    char *screen_buff=NULL;
    int rx=3, ry=2;//y zacina druhym riadkom a klesa po osi y
    int i=0;
    //pre windows terminal
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int cols, rows, cols2=0, rows2=0;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    //windows screen
    //system("mode CON: COLS=150");
   // MaximizeOutputWindow();

    BORDER *m=NULL;
    m=(BORDER*)malloc(sizeof(BORDER));

    borders(&m);
    command[0][0]=0;
    initscr();
    //noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);

    WINDOW *mn=NULL, *line=NULL;

    while(1)
    {
        cykly++;
        getmaxyx(stdscr, h, w);//curses unix

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);//windows
        cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        if((h!=hn || w!=wn) || (h!=hn && w!=wn))//inicializacia noveho okna pre linux
        {
            delwin(mn);
            delwin(line);
            startx1=0;
            starty1=0;
            h1=h-10;
            w1=w;
            mn=newwin(h1, w1, starty1, startx1);

            h2=10;
            w2=w1;

            starty2=h1;
            startx2=0;
            line=newwin(h2, w2, starty2, startx2);

            draw(mn, m, h1, w1);
            if(command[0][0]!=0)
            {
                //scrollok(mn, TRUE);
                mvwprintw(mn, 1, 3,"Hlavne okno cur %d", cykly);
                show(rx, ry, command, i, mn);
            }
            else
            {
                mvwprintw(mn, 1, 3,"Hlavne okno cur %d", cykly);
            }
            draw(line, m, h2, w2);
            mvwprintw(line, 1, 3, "Command Line: ");

            wrefresh(mn);
            wrefresh(line);
            hn=h;
            wn=w;
        }
        else if(cols!=cols2 || rows!=rows2 || (cols!=cols2 && rows!=rows2))//nove okno pre windows
        {
            delwin(mn);
            delwin(line);
            startx1=0;
            starty1=0;
            h1=rows-10;
            w1=cols;
            mn=newwin(h1, w1, starty1, startx1);

            h2=10;
            w2=w1;
            starty2=h1;
            startx2=0;
            line=newwin(h2, w2, starty2, startx2);

            draw(mn, m, h1, w1);
            if(command[0][0]!=0)
            {
                //scrollok(mn, TRUE);
                mvwprintw(mn, 1, 3,"Hlavne okno win %d", cykly);
                show(rx, ry, command, i, mn);
            }
            else
            {
                mvwprintw(mn, 1, 3,"Hlavne okno win %d", cykly);
            }

            draw(line, m, h2, w2);
            mvwprintw(line, 1, 3, "Command Line: ");

            wrefresh(mn);
            wrefresh(line);

            cols2=cols;
            rows2=rows;
        }
        else
        {
            draw(mn, m, h1, w1);

            if(command[0][0]!=0)
            {
                //scrollok(mn, TRUE);
                mvwprintw(mn, 1, 3,"Hlavne okno neit %d", cykly);
                show(rx, ry, command, i, mn);
            }
            else
            {
                mvwprintw(mn, 1, 3,"Hlavne okno neit %d", cykly);
            }
            draw(line, m, h2, w2);

            mvwprintw(line, 1, 3, "Command Line: ");
            nodelay(line, TRUE);

            if((type=wgetch(line))==ERR)
            {
                ;
            }
            else
            {
                if(f!=NULL)//ak uz je otvoreny a existuje
                {
                    fclose(f);
                    remove(fname);
                    f=NULL;
                    if((f=fopen(fname, "w+"))==NULL)
                    {
                        wprintw(line, "Error creating file sub-procedure\n");
                    }
                }
                else
                {
                    if((f=fopen(fname, "w+"))==NULL)
                    {
                        wprintw(line, "Error creating file\n");
                    }
                }
                putwin(line, f);
                wgetstr(line, command[i]);
                getwin(f);

                /*def_prog_mode();
                endwin();//vystupenie z curses

                gets(command);

                reset_prog_mode();//navrat
                wrefresh(mn);
                wrefresh(line);*/

                type=0;
                if(command[i][0]=='e' || (strcmp("exit", command[i])==0))
                {
                    screen_buff=(char*)malloc(10000*sizeof(char));
                    mvwinstr(mn,2,3, screen_buff);
                    if((buff=fopen("file.txt", "w"))==NULL)
                    {
                        wprintw(line, "error opening file\n");
                    }
                    //fprintf(buff, "%s", screen_buff);
                    fclose(buff);
                    //free(screen_buff);
                    //screen_buff=NULL;
                    clear();
                    break;
                }
                else
                {
                    wclear(line);
                    wprintw(line, command[i]);
                    //show(rx, ry, command, i, mn);
                    i++;
                    ry++;
                    wrefresh(line);
                }
            }
            wrefresh(mn);
            wrefresh(line);
        }
    }

    wgetch(line);//getch() robi automaticky wgetch(stdscr) takze hned aktualizuje stdscr
    delwin(mn);
    delwin(line);
    endwin();
    printf("%s", screen_buff);
    free(screen_buff);
    screen_buff=NULL;
    //RestoreOutputWindow();//vykomentovat windwo resize

  return 0;
}
