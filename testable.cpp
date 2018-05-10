#include"tables.h"
#include<stdlib.h>
int main(){
    // table a;
    // table_init(a);
    // insert_col(a,"abc");
    table a;
    a.init_table();
    a.insert_col("aa",2,2,0);
    a.insert_col("bb",2,2,1);
    a.insert_val("11",1,0);
    a.insert_val("22",1,1);
    a.select_table(1,1);
    a.disp_table();
    string f="123";
    int b=0;
    b=atoi(f.c_str());
    printf("%d",b);
    return 0;
}