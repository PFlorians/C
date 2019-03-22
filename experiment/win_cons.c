#include "pswin32_64.h"
int i=0;


int isFile(char *str)
{
    int j;
    long len=(str!=NULL)?strlen(str):0;
    bool file=false;
    if(len!=0)
    {
        for(j=0;j<len;j++)
        {
            if(str[j]=='.' && CH(str[j-1])==1)
            {
                file=true;
                return file;
            }
        }
        if(file==false)
        {
            return file;
        }
    }
    else
    {
        return file;
    }
    return file;
}

char files[MAX_STRING][MAX_STRING];//bude obsahovat mena suborov

void sdir(char *location, DIR *t)
{
    DIR *target;
    struct dirent *ls;
    i=0;
    if(t==NULL && location!=NULL)
    {
        if((target=opendir(location))!=NULL)
        {
            while((ls=readdir(target))!=NULL)//readdir return null if end or error per errno
            {
                printf("%s\n", ls->d_name);
                if(isFile(ls->d_name))//files list
                {
                    strcpy(files[i], ls->d_name);
                    i++;
                }
            }
        }
        else
        {
            perror("Error");
        }
        strcpy(path, location);
        t=target;
        closedir(target);
    }
    else if(location==NULL && t==NULL)
    {
        if((target=opendir("C:/"))!=NULL)
        {
            while((ls=readdir(target))!=NULL)//readdir return null if end or error per errno
            {
                printf("%s\n", ls->d_name);
                if(isFile(ls->d_name))
                {
                    strcpy(files[i], ls->d_name);
                    i++;
                }
            }
        }
        else
        {
            perror("Error");
        }
        strcpy(path, "C:/");
        t=target;
        closedir(target);
    }
    else if(t!=NULL && location==NULL)
    {
        target=t;
        while((ls=readdir(target))!=NULL)//readdir return null if end or error per errno
        {
            printf("%s\n", ls->d_name);
            if(isFile(ls->d_name))
                {
                    strcpy(files[i], ls->d_name);
                    i++;
                }
        }
        strcpy(path, location);
        closedir(target);
    }

}

void ddir(char *location, DIR *t)
{
    DIR *target;

    if(t==NULL && location!=NULL)
    {
        if((target=opendir(location))!=NULL)
        {
            printf("%s\n", location);
        }
        else
        {
            perror("Error");
        }
        strcpy(path, location);
        t=target;
        closedir(target);
    }
    else if(location==NULL && t==NULL)
    {
        if((target=opendir("C:/"))!=NULL)
        {
            printf("%s\n", location);
        }
        else
        {
            perror("Error");
        }
        strcpy(path, "C:/");
        t=target;
        closedir(target);
    }
    else if(t!=NULL && location==NULL)
    {
        target=t;
        printf("%s\n", location);

        strcpy(path, location);
        closedir(target);
    }
}
