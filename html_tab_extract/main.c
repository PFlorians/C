#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct td
{
    char string[1024];//retazec hodnota
}td;
typedef struct tr
{
    int numberOfNodes;
    td **nodes;//pole pre dcerske uzly
}tr;
//filename must be table.html
int getFileLength(FILE *f)
{
    int i=0;
    while(fscanf(f, "%c", stdout)!=EOF)
    {
        i++;
    }
    rewind(f);
    return i;
}
int length(int *array)
{
    int i=0;
    while(array[i]!=0)
    {
        i++;
    }
    return i;
}
char *getInformation(char *str)
{
    int i, len=strlen(str);
    char a[1024]="-";
    int j=0;
    str[len-1]='\0';

    for(i=0;i<len;i++)
    {
        if(str[i]=='>' && str[i+1]!='<' && str[i+1]!='\0')
        {
            i++;
            while(str[i]!='<')
            {
                a[j]=str[i];
                i++;
                j++;
            }
        }
    }

    a[j]='\0';
    return a;
}
int detectRows(FILE *f)
{
    int rows=0;
    char str[1024];

    while(fgets(str, 1024, f)!=NULL)
    {
        if((strstr(str, "<tr>")!=NULL) || (strstr(str, "<TR>")!=NULL))
        {
            rows++;
        }
    }
    rewind(f);
    return rows;
}
void initNodes(FILE *f, tr **trarray, int rows, int cols)
{
    char str[1024], str2[1024], *tmp="-";
    int i=0, j=0;
    for(i=0;i<rows;i++)
    {
        trarray[i]->nodes=malloc(cols*sizeof(td*));
        for(j=0;j<cols;j++)
        {
            trarray[i]->nodes[j]=malloc(sizeof(td));
        }
    }
    i=j=0;
    while(fgets(str, 1024, f)!=NULL)
    {
        if(((strstr(str, "<tr>")!=NULL) || (strstr(str, "<TR>")!=NULL)))
        {
            while((fgets(str2, 1024, f)!=NULL) && ((strstr(str2, "</tr>")==NULL) || (strstr(str2, "</TR>")==NULL)))
            {
                if((strstr(str2, "<td>")!=NULL) || (strstr(str2, "<TD>")!=NULL) || (strstr(str2, "<TD ")!=NULL) ||
                   (strstr(str2, "<td ")!=NULL))
                {
                    tmp=getInformation(str2);
                    //printf("inner: %s", tmp);
                    if((strstr(str2, "<td>")!=NULL || strstr(str2, "<td ")!=NULL))
                    {
                        strcpy(trarray[i]->nodes[j]->string, tmp);
                        //printf("%s", trarray[i]->nodes[j]->string);
                    }
                    else
                    {
                        strcpy(trarray[i]->nodes[j]->string, tmp);
                      //  printf("%s", trarray[i]->nodes[j]->string);
                    }
                    strcpy(tmp, "-");
                    j++;
                }
                if((strstr(str2, "</tr>")!=NULL) || (strstr(str2, "</TR>")!=NULL))
                {
                    break;
                }
            }
            j=0;
            i++;
           // printf("stav: %d\n", i);
        }
    }
    rewind(f);
}
//rows==size of arr
int detectCols(FILE *f, tr **trarray, int rows)
{
    int cols=0;
    char str[1024], str2[1024];

    while(fgets(str, 1024, f)!=NULL)
    {
        if(((strstr(str, "<tr>")!=NULL) || (strstr(str, "<TR>")!=NULL)))
        {
            while((fgets(str2, 1024, f)!=NULL) || (strstr(str2, "</tr>")!=NULL) || (strstr(str2, "</TR>")!=NULL))
            {
                if((strstr(str2, "<th>")!=NULL) || (strstr(str2, "<TH>")!=NULL))
                {
                    printf("%s\n", str2);
                    cols++;
                }
            }
        }
    }
    rewind(f);
    initNodes(f, trarray, rows, cols);
    return cols;
}

void fillZero(int *a, int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        a[i]=0;
    }
}
void writeFile(int *input, tr **trarray, int rows)
{
    FILE *f;
    int i, j, len=length(input);
    if((f=fopen("data.csv", "a+"))==NULL)
    {
        printf("error opening file \ninput file must be of name table.html\n");
        exit(1);
    }
    for(i=1;i<rows;i++)
    {
        for(j=0;j<len;j++)
        {
            if(j<len-1)
            {
                fprintf(f, "%s,", trarray[i]->nodes[input[j]-1]->string);
            }
            else if(j==len-1)
            {
                fprintf(f, "%s", trarray[i]->nodes[input[j]-1]->string);
            }

        }
        fprintf(f, "\n");
    }
}

int main()
{
    FILE *f;
    int *input;
    int size, i=0, c, rows, j;
    tr **trarray;//pole prvotnych uzlov
    if((f=fopen("table.html", "r"))==NULL)
    {
        printf("error opening file \ninput file must be of name table.html\n");
        return 0;
    }
    rows=detectRows(f);
    printf("rows %d\n", detectRows(f));
    trarray=(tr**)malloc(rows*sizeof(tr*));//problem s pointrami
    for(i=0;i<rows;i++)
    {
        trarray[i]=(tr*)malloc(sizeof(tr));
    }
    trarray[0]->numberOfNodes=11;
    size=detectCols(f, trarray, rows);
    printf("\nthere are %d columns\n", size);

    input=malloc(size*sizeof(int));
    fillZero(input, size);

    printf("enter which columns to extract>\n");
    i=0;
    while(i<size && (scanf("%d", &input[i])==1))
    {
        if((c=getc(stdin))==10)
        {
            writeFile(input, trarray, rows);
            break;
        }
        else if(input[i]>size || input[i]<0)
        {
            input[i]=0;
            printf("wrong input enter only numbers from<0-%d>\n", size);
            i--;
        }
        i++;
    }
    /*for(i=0;i<rows;i++)
    {
        for(j=0;j<size;j++)
        {
           printf("%s,", trarray[i]->nodes[j]->string);
        }
    }*/
    if(fclose(f)==EOF)
    {
        printf("chyba zatvarania\n");
    }
    return 0;
}
