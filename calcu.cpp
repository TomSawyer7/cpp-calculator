#include <iostream>
using namespace std;

int main()
{
    double firstNum, secondNum;
    char oper;
    cout<<"Enter first num: ";
    cin>>firstNum;
    cout<<"Enter second num: ";
    cin>>secondNum;
    cout<<"What operation: + - / *: ";
    cin>>oper;
     switch (oper){
         case '+':
         cout<<firstNum+secondNum;
         break;
         
         case '-':
         cout<<firstNum-secondNum;
         break;
         
         case '/':
         cout<<firstNum/secondNum;
         break;
         
         case '*':
         cout<<firstNum*secondNum;
         break;
         
         default:
         cout<<"Dun sa apat ka lang pipili!";
     }


    return 0;
}