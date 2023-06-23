#include<iostream>
#include<date>
#include<time.h>
using namespace std;
using namespace myDate;

void Date::toDayNumber()
{
int y = 1901;
int x = 0;
while(y<this->year)
{
if(isLeapYear(y)) x = x+366;
else x = x+365;
y++;
}
int mth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
if(isLeapYear(this->year)) mth[1] = 29;
int ep = this->month - 2;
int m = 0;
while(m<=ep) x = x+mth[m++];
x = x+this->dayOfMonth;
this->dayNumber = x;
}

void Date::fromDayNumber()
{
if(dayNumber <= 0) 
{
this->dayOfMonth = 0;
this->month = 0;
this->year = 0;
return;
}
int x,d,m,y;
int daysInYear;
int daysInMonth;
y = 1901;
x = this->dayNumber;
while(1)
{
if(isLeapYear(y)) daysInYear = 366;
else daysInYear = 365;
if(x<=daysInYear) break;
x = x-daysInYear;
y = y+1;
}
int mth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
if(isLeapYear(y)) mth[1] = 29;
m = 0;
while(1)
{
daysInMonth = mth[m];
if(x<=daysInMonth) break;
x = x-daysInMonth;
m++;
}
m++;
d = x;
this->dayOfMonth = d;
this->month = m;
this->year = y;
}

int Date::isLeapYear(int year)
{
if(year%400 == 0) return 1;
else if(year%100 == 0) return 0;
else if(year%4 == 0) return 1;
else return 0;
}

void Date::isValidDate(string& dateString, int& isValid, int& d, int& m, int& y)
{
isValid = 0;
int dd,mm,yy;
if(dateString.length() == 0) return;
int x = dateString.length();
if(x<8 || x>10) return;
int sepIndex1, sepIndex2;
char sep;
if(!(dateString[1] == '/' || dateString[2] == '/' || dateString[1] == '-' || dateString[2] == '-')) return;
if(dateString[1] == '/' || dateString[1] == '-') sepIndex1 = 1;
else sepIndex1 = 2;
sep = dateString[sepIndex1];
if(dateString[0]<48 || dateString[0]>57) return;
if(sepIndex1==2 && (dateString[1]<48 || dateString[1]>57)) return;
if(sepIndex1 == 1) dd = dateString[0]-48;
else dd = ((dateString[0]-48)*10) + (dateString[1]-48);
if(dd == 0) return;
int i = sepIndex1+1;
if(!(dateString[i+1] == '/' || dateString[i+2] == '/' || dateString[i+1] == '-' || dateString[i+2] == '-')) return;
if(dateString[i+1] == '/' || dateString[i+1] == '-') sepIndex2 = i+1;
else sepIndex2 = i+2; 
if(sep != dateString[sepIndex2]) return;
if(dateString[i]<48 || dateString[i]>57) return;
if(sepIndex2==i+2 && (dateString[i+1]<48 || dateString[i+1]>57)) return;
if(sepIndex2 == i+1) mm = dateString[i]-48;
else mm = ((dateString[i]-48)*10) + (dateString[i+1]-48);
if(mm==0 || mm>12) return;
i=sepIndex2+1;
int r=0;
yy = 0;
while(r<=3)
{
if(dateString[i+r]<48 || dateString[i+r]>57) return;
yy = (yy*10)+(dateString[i+r]-48);
r++;
}
if(yy == 0 || yy<1901) return;
int mth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
if(isLeapYear(yy)) mth[1] = 29;
if(dd>mth[mm-1]) return;
d = dd;
m = mm;
y = yy;
isValid = 1; 
}

Date::Date()
{
time_t x;
time(&x);
struct tm *now;
now = localtime(&x);
this->dayOfMonth = now->tm_mday;
this->month = now->tm_mon+1;
this->year = now->tm_year+1900;
this->toDayNumber();
}

Date::Date(string dateString)
{
int isValid;
this->isValidDate(dateString,isValid,this->dayOfMonth,this->month,this->year);
if(!isValid)
{
this->dayOfMonth = 0;
this->month = 0;
this->year = 0;
this->dayNumber = 0;
throw DateException("Invalid date "+dateString);
}
else
{
this->toDayNumber();
}
}

Date::Date(const Date &other)
{
if(this->dayNumber == 0 || other.dayNumber == 0) throw DateException("Invalid Date");
this->dayNumber = other.dayNumber;
this->dayOfMonth = other.dayOfMonth;
this->month = other.month;
this->year = other.year;
}

Date::~Date()
{
//do Nothing
}

int Date::getDayOfMonth()
{
return this->dayOfMonth;
}

int Date::getDayOfWeek()
{
if(this->dayNumber==0) throw DateException("Trying to access Day of Week for Invalid Date");
int leftDays = this->dayNumber%7;
int dow = 2+leftDays;
if(dow>7) dow = dow%7;
return dow;
}

int Date::getMonth()
{
if(this->month == 0) throw DateException("Trying to access Month for Invalid Date");
return this->month;
}

int Date::getYear()
{
if(this->year == 0) throw DateException("Trying to access Year for Invalid Date");
return this->year;
}

string Date::getMonthString()
{
if(this->dayNumber == 0) throw DateException("Trying to access Month String for Invalid Date");

string monthString[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
return monthString[this->month-1];
}

string Date::getMonthShortString()
{
if(this->dayNumber == 0) throw DateException("Trying to access Month Short String for Invalid Date");
string monthShortString[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
return monthShortString[this->month-1];
}

string Date::getDayOfWeekString()
{
if(this->dayNumber == 0) throw DateException("Trying to access Week String for Invalid Date");
string dayOfWeekString[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
return dayOfWeekString[this->getDayOfWeek()-1];
}

string Date::getDayOfWeekShortString()
{
if(this->dayNumber == 0) throw DateException("Trying to access Month Short String for Invalid Date");
string dayOfWeekShortString[7] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
return dayOfWeekShortString[this->getDayOfWeek()-1];
}

//Operator Overloading
Date& Date::operator = (const Date &other)
{
if(this->dayNumber == 0 || other.dayNumber == 0) throw DateException("Operation on Invalid Date");
this->dayNumber = other.dayNumber;
this->dayOfMonth = other.dayOfMonth;
this->month = other.month;
this->year = other.year;
return *this;
}

Date& Date::operator = (string& dateString)
{
int isValid;
this->isValidDate(dateString,isValid,this->dayOfMonth,this->month,this->year);
if(!isValid)
{
this->dayOfMonth = 0;
this->month = 0;
this->year = 0;
this->dayNumber = 0;
throw DateException("Invalid date : "+dateString);
}
else this->toDayNumber();
return *this;
}

Date Date::operator+(int days)
{
if(this->dayNumber == 0) throw DateException("Operation on Invalid Date");
Date t;
t.dayNumber = this->dayNumber+days;
t.fromDayNumber();
return t;
}

Date Date::operator-(int days)
{
if(this->dayNumber == 0) throw DateException("Operation on Invalid Date");
if(this->dayNumber < days) throw DateException("Operation is giving Invalid Date"); 
Date t;
t.dayNumber = this->dayNumber-days;
t.fromDayNumber();
return t;
}

void Date::operator +=(int days)
{
if(this->dayNumber == 0) throw DateException("Operation on Invalid Date");
this->dayNumber += days;
this->fromDayNumber();
}

void Date::operator -=(int days)
{
if(this->dayNumber == 0) throw DateException("Operation on Invalid Date");
if(this->dayNumber < days) throw DateException("Operation is giving Invalid Date"); 
this->dayNumber = this->dayNumber - days;
this->fromDayNumber();
}

void Date::operator++(int)
{
if(this->dayNumber == 0) throw DateException("Operation on Invalid Date");
cout<<this->dayNumber<<endl;
this->dayNumber++;
this->fromDayNumber();
}

void Date::operator--(int)
{
if(this->dayNumber == 0) throw DateException("Operation on Invalid Date");
this->dayNumber--;
this->fromDayNumber();
}

int Date::operator<(const Date &other)
{
if(this->dayNumber == 0 || other.dayNumber == 0) return 0;
return this->dayNumber<other.dayNumber;
}

int Date::operator>(const Date &other)
{
if(this->dayNumber == 0 || other.dayNumber == 0) throw DateException("Operation on Invalid Date");
return this->dayNumber>other.dayNumber;
}

int Date::operator<=(const Date &other)
{
if(this->dayNumber == 0 || other.dayNumber == 0) throw DateException("Operation on Invalid Date");
return this->dayNumber<=other.dayNumber;
}

int Date::operator>=(const Date &other)
{
if(this->dayNumber == 0 || other.dayNumber == 0) throw DateException("Operation on Invalid Date");
return this->dayNumber>=other.dayNumber;
}

int Date::operator==(const Date &other)
{
if(this->dayNumber == 0 || other.dayNumber==0) throw DateException("Operation on Invalid Date");
return this->dayNumber==other.dayNumber;
}

int Date::operator!=(const Date &other)
{
if(this->dayNumber == 0 || other.dayNumber == 0) throw DateException("Operation on Invalid Date");
return this->dayNumber!=other.dayNumber;
}

int Date::isLeapYear()
{
if(this->year == 0) throw DateException("Invalid Year");
if(this->year%400 == 0) return 1;
else if(this->year%100 == 0) return 0;
else if(this->year%4 == 0) return 1;
else return 0;
}

ostream& operator <<(ostream &oo, Date &d)
{
oo<<d.getDayOfMonth()<<"/"<<d.getMonth()<<"/"<<d.getYear();
return oo;
}



