//#include <curses.h>

#if defined _WIN32
    #include "pswin32_64.h"
#elif defined _linux_ || defined _unix_
    #include "psunix.h"
#endif


int main()
{
    DIR *t=NULL;
    char location[MAX_STRING];
    char cmd[20];
    int n=0;
    int j;

    ddir("C:/", NULL);//default
    while(strcmp(cmd, "exit")!=0)
    {
        printf("> ");
        scanf("%s", cmd);
        if(strcmp(cmd, "help")==0 || strcmp(cmd, "h")==0)
        {
            printf("help, h; - This help\n");
            printf("cd - Change directory + show elements\n");
            printf("dir -show current path\n");
            printf("ls - list all files in directory\n");
            printf("enc -encrypt using vigenere cipher\n");
        }
        else if(strcmp(cmd, "cd")==0)
        {
            scanf("%s", location);
            sdir(location, t);
        }
        else if(strcmp(cmd, "ls")==0)
        {
            printf("%s\n",path);
            for(j=0;j<i;j++)
            {
                puts(files[j]);
            }
        }
        else if(strcmp(cmd, "enc")==0)
        {
            printf("choose one: \n");
            for(j=0;j<i;j++)
            {
                printf("%d %s\n", j+1, files[j]);
            }
            scanf("%d", &n);
            n=n-1;
            if(n>=0 && n<=i)
            {
                vigenere(files[n], "sifra.dat");
            }
            else
            {
                printf("error choose a number between 0-%d\n", i);
            }
        }
        else if(strcmp(cmd, "dir")==0)
        {
            puts(path);
        }
        else if(strcmp(cmd, "mkd")==0)
        {
            //TODO
        }
        else if(strcmp(cmd, "exit")==0)
        {
            break;
        }
            /*for(j=0;j<strlen(cmd);j++)
            {
                cmd[j]=0;
            }*/


    }
    return 0;
}
