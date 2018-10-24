#include <iostream>
#include <valarray>
using namespace std ;
int add ( int a , int b ) ;
int add2 ( int &a , int &b ) ;
int main ( )
{
    int a=1;
    int b=2;
    return 0 ;
}
int  add ( int a , int b)
{
    return a ;
}
int add2 ( int &a , int &b)
{
    a=a+b ;
    return a ;

    DIKKE YOLO
}