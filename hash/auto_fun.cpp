#include<stdlib.h>
#include<iostream>
using namespace std;

int main(void){

    int i = 0, &ri = i;

    auto a = i; //a为int型变量
    auto a1 = ri; //a1为int型变量

    auto p = &i;// &i 是一个普通int指针，p是一个整型指针int *
    auto p1 = &ri; //同上
    cout<<"p: "<<*p<<endl;

    // return;
}