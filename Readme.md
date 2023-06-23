## Date Library in C++

Here you will get to know about the Date `library`, which is built using `c++` programming language.

## Table of Contents

* [Overview](#overview)
* [Methods and Operators](#methods-and-operators)
    * [Constructors](#constructors)
    * [Print Date](#print-date)
    * [Get Methods](#get-methods)
    * [Assignment Operators](#assignment-operators)
    * [Arithmetic Operators](#arithmetic-operators)
    * [Relational Operators](#relational-operators)
    * [isLeapYear Method](#isleapyear-method)
  * [Exception Handling](#exception-handling)
## Overview

Date Library in C++ is a lightweight, user-friendly and comprehensive library designed for working with date in C++ applications. this library provide various date related tasks and offers extensive functionalities for data manipulation, comparision, parsing and other operations. It provides developers with a reliable and efficient solution for handling dates in their C++ projects.



## Methods And Operators


### Constructors
* It consists of `Date` class with `default constructor` to get the current date, a `parametrized constructor` to give the user defined date, and a `copy constructor` to copy the date of other Date class object in the new Date class object

  ```c++
  Date();
  Date(string str);
  Date(const Date &other);
  ```
  ```c++
  try
  {
  Date date1;`
  Date date2("29/3/2004");
  Date date3("9-4-2022");
  Date date4(date2);
  }catch(DateException dateException) // try-catch block is to catch the 
  dateException in case of invalid/out-of-range dates
  {
  cout<<dateException.what()<<endl;
  }
  ```


### Print Date
* The `cout` operator is overloaded to print the date
  ```c++
  ostream& operator<<(ostream& oo, Date& d);
  ```
  `cout<<date1<<endl;`

  `cout<<date2<<endl;`

  `cout<<date3<<endl;`

  `cout<<date4<<endl;`


### Get Methods
* The `Date` class consists of get methods to get day of week, month, year, month name, month short name, day of week name and day of week short name.

* To `get Day of Month` of a `Date` class object
  ```c++
  int getDayOfMonth();
  ```
* To `get Day of Week` of a `Date` class object
  ```c++
  int getDayOfWeek();
  ```
* To `get Month of Year` of a `Date` class object
  ```c++
  int getMonth();
  ```
* To `get Year` of a `Date` class object
  ```c++
  int getYear();
  ```
* To `get Name of Month` of a `Date` class object
  ```c++
  string getMonthString();
  ```
* To `get Short Name of Month` of a `Date` class object
  ```c++
  string getMonthShortString();
  ```
* To `get Name of Day Of Week` of a `Date` class object
  ```c++
  string getDayOfWeekString();
  ```
* To `get Short Name Of Day Of Week` of a `Date` class object
  ```c++
  string getDayOfWeekShortString()
  ```
#### Example
```c++
#include<iostream>
#include<date>
using namespace std;
using namespace myDate;

int main()
{
try
{
Date date("23/6/2023");
int day_of_month = date.getDayOfMonth(); // gives the day in month
int day_of_week = date.getDayOfWeek(); // gives the day of week with Sunday as day 1
int month = date.getMonth(); // gives the month of the year
int year = date.getYear(); // gives the year
string month_string = date.getMonthString(); // gives the name of month like January, February, March etc.
string month_short_string = date.getMonthShortString(); // gives the short name of month like Jan, Feb, Mar etc.
string day_of_week_string = date.getDayOfWeekString(); // gives the name of day of week like Sunday, Monday, Tuesday etc.
string day_of_week_short_string = date.getDayOfWeekShortString(); // gives the short name of day of week like Sun, Mon, Tue etc.
cout<<day_of_month<<endl;
cout<<day_of_week<<endl;
cout<<month<<endl;
cout<<year<<endl;
cout<<month_string<<endl;
cout<<month_short_string<<endl;
cout<<day_of_week_string<<endl;
cout<<day_of_week_short_string<<endl;
}catch(DateException dateException) // try-catch block is to catch the dateException in case of invalid/out-of-range dates
{
cout<<dateException.what()<<endl;
}
return 0;
}
```


### Assignment Operators
* `Date` class consists of two assignment operators to assign the new `Date` class object date of another object of the same class or date in the form of string

* To assign the date in form of string to the object of `Date` class
  ```c++
  Date& operator = (const Date &other);
  ```
* To assign the date in of another object of same class
  ```c++
  Date& operator = (string dateString);
  ```
#### Example
```c++
#include<iostream>
#include<date>
using namespace std;
using namespace myDate;

int main()
{
try
{
Date date("23/6/2023");
Date date1;
date1 = date; // Assigns the date Of date object to date1 
cout<<date1<<endl;
Date date2;
date2 = "24/12/2024"; // Assigns the date2 "24/12/2024" date
cout<<date2<<endl;

}catch(DateException dateException)
{
cout<<dateException.what()<<endl;
}
return 0;
}
```


### Arithmetic Operators
* `Date` class consists of arithmetic operators to add days, subtract days, post increment and decrement the date

* Addition operator
  ```c++
  Date operator+(int days);
  ```
* Subtraction operator
  ```c++
  Date operator-(int days);
  ```
* Shorthand Addition Operator
  ```c++
  void operator +=(int number);
  ```
* Shorthand Subtraction Operator
  ```c++
  void operator -=(int number);
  ```
* Post Increment Operator
  ```c++
  void operator++(int);
  ```
* Post Decrement Operator
  ```c++
  void operator--(int);
  ```
#### Example
```c++
#include<iostream>
#include<date>
using namespace std;
using namespace myDate;

int main()
{
try
{
Date date("24/5/2023");
Date date1;
date1 = date + 60;  // Add 60 days to Date date
cout<<date1<<endl;
Date date2;
date2 = date - 66; // Subtracts 66 days from Date date
cout<<date2<<endl;
Date date3;
date3 += 50; // Add 50 days to Date date3, which has current date;
cout<<date3<<endl;
Date date4("25/6/2022");
date4 -= 23; // Add 23 days to Date date4, which has "24/6/2022" date;
cout<<date4<<endl;
date++; // Increments the Date date by one day
cout<<date<<endl;
date--; // Decrements the Date date by one day
cout<<date<<endl;
}catch(DateException dateException)
{
cout<<dateException.what()<<endl;
}
return 0;
}
```


### Relational Operators
* `Date` class consists of relational operators to perform the comparision based operations between the `Date` class objects

* Less than Operators
  ```c++
  bool operator<(const Date &other);
  ```
* Greater than Operators
  ```c++
  bool operator>(const Date &other);
  ```
* Less than or Equal to Operator
  ```c++
  bool operator<=(const Date &other);
  ```
* Greater than or Equal to Operator
  ```c++
  bool operator>=(const Date &other);
  ```
* Equal to Operator
  ```c++
  bool operator==(const Date &other);
  ```
* Not Equal to Operator
  ```c++
  bool operator!=(const Date &other);
  ```
### Example
```c++
#include<iostream>
#include<date>
using namespace std;
using namespace myDate;

int main()
{
try
{
Date date1("4/8/2018");
Date date2("5/8/2018");
Date date3("4/8/2018");
cout<<(date1<date2)<<endl;
cout<<(date1>date2)<<endl;
cout<<(date3<=date2)<<endl;
cout<<(date1>=date3)<<endl;
cout<<(date1==date2)<<endl;
cout<<(date2!=date3)<<endl;
bool f = false;
cout<<f<<endl;
}catch(DateException dateException)
{
cout<<dateException.what()<<endl;
}
return 0;
}
```


### isLeapYear Method
* Date class consists of isLeapYear Method to check whether the follwing date falls in leap year or not

  ```c++
  bool isLeapYear();
  ```
#### Example
```c++
#include<iostream>
#include<date>
using namespace std;
using namespace myDate;

int main()
{
try
{
Date date1("4/8/2018");
Date date2("20/8/2022");
Date date3("4/12/2024");
cout<<date1.isLeapYear()<<endl;
cout<<date2.isLeapYear()<<endl;
cout<<date3.isLeapYear()<<endl;
}catch(DateException dateException)
{
cout<<dateException.what()<<endl;
}
return 0;
}
```



## Exception Handling

* The `Date` class throws DateException when an invalid or out-of-range date is encountered. It includes the invalid dates like 30/2/2022 and dates before 1/1/1901.
* To know the exception the declaration and operation performed on the `Date` class object should be inside try-catch block with catch block having the object of `DateException` class
* To know which exception has been raised '<name_of_object_defined_in_catch>.what()' method should be called inside the catch block
#### Example
```c++
#include<iostream>
#include<date>
using namespace std;
using namespace myDate;

int main()
{
try
{
Date date1("4/8/2018");
Date date2("29/2/2022"); // As Date is invalid this will raise exception
Date date3;
int x = -56000;
date3 -= 80000; // As subtraction gives date less than 1/1/1901 this will also raise exception
date3 += x; // As addition gives date less than 1/1/1901 this will also raise exception
}catch(DateException dateException)
{
cout<<dateException.what()<<endl;
}
return 0;
}
```
