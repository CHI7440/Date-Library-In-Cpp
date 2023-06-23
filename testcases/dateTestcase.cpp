#include<iostream>
#include<date>
using namespace std;
using namespace myDate;

int main()
{
try
{
Date date();
cout<<date<<endl;
}catch(DateException dateException)
{
cout<<dateException.what()<<endl;
}
return 0;
}