#ifndef AA_H_INCLUDED
#define AA_H_INCLUDED
#define LOW(c) ((c)>='A' && (c)<='Z')?(((c)-'A')+'a'):(c)
extern void banner();
extern void welcome();
extern void login();
extern int len();
extern void convert();
extern void database();

typedef struct data
{
    char user[50];
    char pw[50];
    struct data *next;
}DATA;

#endif // AA_H_INCLUDED
