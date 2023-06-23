#include<iostream>
#include<date>
using namespace std;
using namespace myDate;

int main()
{
try
{
Date date("1/1/1901");
cout<<date.dayNumber<<endl;
}catch(DateException dateException)
{
cout<<dateException.what()<<endl;
}
return 0;
}