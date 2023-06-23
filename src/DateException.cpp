#include<iostream>
#include<DateException>

using namespace std;
using namespace myDate;

DateException::DateException()
{
this->message = "";
}
DateException::DateException(string message)
{
this->message = message;
}
DateException::DateException(const DateException &other)
{
this->message = other.message;
}
DateException::~DateException() throw()
{
//do nothing
}
DateException& DateException::operator = (const DateException& other)
{
this->message = other.message;
return *this;
}
const char* DateException::what() const throw()
{
return this->message.c_str();
}
