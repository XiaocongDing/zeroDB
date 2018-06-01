#include<stdio.h>
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
//#define YYPRINTF fprintf
int main()
{
    ofstream fps;
    string temp;
    temp="parser.txt";
    fps.open(temp.c_str());
    fps <<temp;
    return 0;
}