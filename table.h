#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define VARCHAR 1
#define INT 2
#define DOUBLE 3
#define TIME 4

#define NOTNULL 1
#define DEFAULT 2
#define UNIQUE 3
#define CHECK 4
#define PRIMARYKEY 5

typedef struct Table{
    char *tt[100][50];
    int valp;
    int colp;
}table;
void table_init(table &h)
{
    h.valp=-1;
    h.colp=-1;
}
void insert_col(table &h,const char* p)
{
    h.colp++;
    h.tt[0][h.colp]=(char*)malloc(16*sizeof(char));
    strcpy((h.tt[0][h.colp]),p);
    //printf("%s",h.tt[0][h.colp]);
}