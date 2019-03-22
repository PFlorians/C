#include "pswin32_64.h"

int vigenere(char *file1, char *file2)
{
    FILE *f;
    FILE *cf;
    char c;
    char word[26];
    char square[27][27];
    int i, j, z=0;
    char v;
    square[0][0]=' ';

    for(i=0;i<27;i++)
    {
        for(j=1;j<27;j++)
        {
            if(i>0)
            {
                v=('A'+i)+j-1;
                if(v>90 || v<65)
                {
                    v='A'+z;
                    square[i][j]=v;
                    z++;
                }
                else
                {
                    square[i][j]=v;
                }
            }
            else
            {
                square[i][j]='A'+j-1;
            }

        }
        if(i>0)
        {
            square[i][0]='A'+i-1;
        }
        z=0;
    }
    for(i=0;i<27;i++)
    {
        printf("%d) ", i);
        for(j=0;j<27;j++)
        {
            printf("%c ", square[i][j]);
        }
        putchar('\n');
    }

    printf("\nchoose the cipher word:>\n");
    scanf("%s", word);
    for(i=0;i<strlen(word);i++)
    {
        word[i]=toupper(word[i]);
    }
    printf("%s\n", word);
    if((f=fopen(file1, "r"))==NULL)
    {
        printf("vstupny subor bud neexistuje alebo je problem\n");
        return 1;
    }
    if((cf=fopen(file2, "w"))==NULL)
    {
        printf("vstupny subor bud neexistuje alebo je problem\n");
        return 1;
    }
    //printf("%c\n", square[0]);
    i=z=0;
    j=1;
    while((c=getc(f))!=EOF)
    {
        if(c!=' ' && c!='.' && c!='\n')
        {
            v=c;

            while(word[i]!=square[j][0] && j<27)
            {
                printf("sq:%c w:%c j:%d\n", square[j][0], word[i], j);
                if((word[i]==square[j+1][0]) && j+1<=26)
                {
                    while(v!=square[0][z])
                    {
                        if(v==square[0][z+1] && z<27)
                        {
                            putc(square[j+1][z+1], cf);
                            printf("%d %d %c %d\n", j+1, z+1, square[j+1][z+1], square[j+1][z+1]);
                            z=0;//z sa potom spusti znova
                            break;
                        }
                        z++;
                    }

                    i++;
                    if(i==strlen(word))
                    {
                        i=0;
                    }
                    j=1;
                    break;
                }
                /*if(i==strlen(word))
                {
                    i=0;
                }*/
                j++;
            }
        }
    }

    fclose(f);
    fclose(cf);
    return 0;
}
