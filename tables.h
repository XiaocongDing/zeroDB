#include<iostream>
#include<string>
#include<map>
#include<stdio.h>
#include<stdlib.h>

// VARCHAR 1 INT 2 DOUBLE 3 TIME 4

// NOTNULL 1 DEFAULT 2 UNIQUE 3 CHECK 4 PRIMARYKEY 5


using namespace std;
class table{
    public:
    int val_num;//行
    int col_num;//属性
    string name;
    int valp;
    int colp;
    int dataattr[50];
    int datatype[50];
    int showval[1000];
    int showcol[50];
    int showcol_p;
    int showval_p;
    int maxcollen[50];
    int collen;
    int showval_c;
    int showcol_c;
    int delete_v;
    int update_c;
    string tables[1000][50];
    std::map<char,int> first;
    table(){};
    int create_table();
    void init_table(){
        valp=-1;
        colp=-1;
        collen=0;
        showcol_p=0;
        showval_p=0;
        delete_v=1000;
        update_c=50;
        for(int i=0;i<50;i++)
        {
            maxcollen[i]=0;
        }
    }
    int updata_val(string val,int valnum,int loc)
    {
        tables[valnum][loc]=val;
        return 0;
    }
    int updata_val_table(string ser){
        for(int i=1;i<showval_c;i++)
        {
            updata_val(ser,showval[i],update_c);
        }
        return 0;
    }
    int insert_val(string val,int valnum,int loc)
    {
        if(loc<=colp)
        {
            tables[valnum][loc]=val;
            valp=valnum;
        }
        else{
            cout<<"Internal error:the number of val exceed"<<endl;
        }
    }
    int delete_val(int valnum){
        if(valnum<=valp)
        {
            if(valnum==valp)
            {
                valp--;
                showval_c--;
            }
            else{
                for(int i=valnum;i<valp;i++)
                {
                    for(int j=0;j<colp+1;j++)
                    {
                        tables[i][j]=tables[i+1][j];
                    }
                }
                valp--;
                showval_c--;
            }
            return 1;
        }
        else{
            return 0;
        }
    }
    int delete_val_table()
    {
        //cout<<showval[1]<<endl;
        for(int i=1;i<showval_c;i++)
        {
            delete_val(showval[i]);
        }
    }
    int insert_col(string val,int datatypes,int dataattrs,int loc)
    {
        tables[0][loc]=val;
        dataattr[loc]=dataattrs;
        datatype[loc]=datatypes;
        valp=0;
        colp++;
        //cout<<val<<endl; 
    }
    void printblock(int n)
    {
        for(int i=0;i<n;i++)
            printf(" ");
    }
    void printline(int n)
    {
        for(int i=0;i<n;i++)
            printf("=");
    }
    void select_table(int flag,int flagval)
    {
        if(flag==1)
        {
            showcol_c=colp+1;
            for(int i=0;i<showcol_c;i++)
            {
                showcol[i]=i;
            }
        }
        if(flagval==1)
        {
            showval_c=valp+1;
            for(int i=0;i<showval_c;i++)
            {
                showval[i]=i;
            }
        }
    }
    int disp_table(){
        int t_block;
        int t1;
        int t2;
        //cout<<showcol_c<<" "<<showval_c<<endl;
        for(int j=0;j<showcol_c;j++)
        {
            for(int i=0;i<showval_c;i++)
            {
                t1=showval[i];
                t2=showcol[j];
                if(maxcollen[j]<tables[t1][t2].length())
                {
                    maxcollen[j]=tables[t1][t2].length();
                }
            }
            collen=collen+maxcollen[j];
        }
        collen=collen+showcol_c+1;
        printline(collen);
        printf("\n");
        for(int j=0;j<showval_c;j++)
        {
            printf("|");
            for(int i=0;i<showcol_c;i++)
            {
                t1=showval[j];
                t2=showcol[i];
                t_block=(maxcollen[i]-tables[t1][t2].length())/2;
                printblock(t_block);
                cout<<tables[t1][t2];
                printblock(t_block);
                if((maxcollen[i]-tables[t1][t2].length())%2==1)
                    printf(" ");
                printf("|");
            }
            printf("\n");
            printline(collen);
            printf("\n");
        }
        //cout<<endl;
        collen=0;
    }
    void select_col(string ser){
        for(int i=0;i<colp+1;i++)
        {
            //cout<<tables[0][i]<<" "<<ser<<endl;
            if(!tables[0][i].compare(ser))
            {
                showcol[showcol_p]=i;
                break;
            }
        }
        showcol_p++;
        showcol_c=showcol_p;
    }
    void select_val(string ser,int col,int attr,int flag)
    {//搜索值，搜索列,搜索值属性,比较符号:=<>
        int t;
        int tt;
        double b;
        double bb;
        showval[showval_p]=0;//显示属性
        showval_p++;
        if(attr==datatype[col])
        {
            if(attr==1)//搜索值为字符型
            {
                if(flag==1)
                {
                    for(int i=1;i<valp+1;i++)
                    {
                        if(!tables[i][col].compare(ser))
                        {
                            showval[showval_p]=i;
                            showval_p++;
                        }
                    }
                    showval_c=showval_p;
                }
                else{
                    cout<<"comparison error"<<endl;
                }
            }
            else{//搜索值为数字型
                if(attr==2) //整形
                {
                    t=atoi(ser.c_str());
                    if(flag==1)
                    {
                        for(int i=1;i<valp+1;i++)
                        {
                            tt=atoi(tables[i][col].c_str());
                            if(t==tt)
                            {
                                showval[showval_p]=i;
                                showval_p++;
                            }
                        }
                        showval_c=showval_p;
                        //cout<<showval[0]<<" "<<showval[1]<<endl;
                    }
                    else if(flag=4)
                    {
                        for(int i=1;i<valp+1;i++)
                        {
                            tt=atoi(tables[i][col].c_str());
                            if(t>tt)
                            {
                                showval[showval_p]=i;
                                showval_p++;
                            }
                        }
                        showval_c=showval_p;
                    }
                    else if(flag==6)
                    {
                        for(int i=1;i<valp+1;i++)
                        {
                            tt=atoi(tables[i][col].c_str());
                            if(t<tt)
                            {
                                showval[showval_p]=i;
                                showval_p++;
                            }
                        }
                        showval_c=showval_p;
                    }
                    else if(flag==3)
                    {
                        for(int i=1;i<valp+1;i++)
                        {
                            tt=atoi(tables[i][col].c_str());
                            if(t>=tt)
                            {
                                showval[showval_p]=i;
                                showval_p++;
                            }
                        }
                        showval_c=showval_p;
                    }
                    else if(flag==5)
                    {
                        for(int i=1;i<valp+1;i++)
                        {
                            tt=atoi(tables[i][col].c_str());
                            if(t<=tt)
                            {
                                showval[showval_p]=i;
                                showval_p++;
                            }
                        }
                        showval_c=showval_p;
                    }
                }
                else if(attr==3) //浮点型
                {
                    b=atof(ser.c_str());
                    if(flag==1)
                    {
                        for(int i=1;i<valp+1;i++)
                        {
                            bb=atof(tables[i][col].c_str());
                            if(b==bb)
                            {
                                showval[showval_p]=i;
                                showval_p++;
                            }
                        }
                        showval_c=showval_p;
                    }
                    else if(flag==3)
                    {
                        for(int i=1;i<valp+1;i++)
                        {
                            bb=atof(tables[i][col].c_str());
                            if(b>=bb)
                            {
                                showval[showval_p]=i;
                                showval_p++;
                            }
                        }
                        showval_c=showval_p;
                    }
                    else if(flag==4)
                    {
                        for(int i=1;i<valp+1;i++)
                        {
                            bb=atof(tables[i][col].c_str());
                            if(b>bb)
                            {
                                showval[showval_p]=i;
                                showval_p++;
                            }
                        }
                        showval_c=showval_p;
                    }
                    else if(flag==5)
                    {
                        for(int i=1;i<valp+1;i++)
                        {
                            bb=atof(tables[i][col].c_str());
                            if(b<=bb)
                            {
                                showval[showval_p]=i;
                                showval_p++;
                            }
                        }
                        showval_c=showval_p;
                    }
                    else if(flag==6)
                    {
                        for(int i=1;i<valp+1;i++)
                        {
                            bb=atof(tables[i][col].c_str());
                            if(b<bb)
                            {
                                showval[showval_p]=i;
                                showval_p++;
                            }
                        }
                        showval_c=showval_p;
                    }
                }
            }
        }
        else
        {
            cout<<"Attribute error"<<endl;
        }
    }
    void init_select_col()
    {
        showcol_p=0;
        for(int i=0;i<showcol_c;i++)
        {
            showcol[i]=0;
        }
    }
    void init_select_val(){
        showval_p=0;
        for(int i=0;i<showval_p;i++){
            showval[i]=0;
        }
    }
    int ifexist_col(string t)
    {
        int f=0;
        for(int i=0;i<colp+1;i++)
        {
            if(tables[0][i]==t)
            {
                f=i+1;
            }
        }
        return f;
    }
};