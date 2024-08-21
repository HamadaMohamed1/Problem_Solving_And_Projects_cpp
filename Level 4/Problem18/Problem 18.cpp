/*
* Problem #18
* Write a program to calculate your age in days
*/
#pragma warning(disable : 4996)

#include <iostream>
#include <string>

using namespace std;

int ReadNumber(string message)
{
    int num;
    cout << message << endl;
    cin >> num;
    return num;
}

string NumberToText(int number)
{
    if (number == 0)
    {
        return "";
    }

    if (number >=1 && number <= 19)
    {
        string arr[] = {"","One ","Two ","Three ","Four ","Five ","Six ","Seven ",
        "Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ",
        "Fifteen ","Sixteen ","Seventeen ","Eighteen ","Ninteen "};
        return arr[number];
    }

    if (number >= 20 && number <= 99)
    {
        string arr[] = {"","","Twenty ","Thirty ","Forty ","Fifty ","Sixty ",
        "Seventy ","Eighty ","Nintey "};
        return arr[number / 10] + NumberToText(number % 10);
    }

    if (number >= 100 && number <= 199)
    {
        return "One Handred " + NumberToText(number % 100);
    }

    if (number >= 200 && number <= 999)
    {
        return NumberToText(number / 100) + "Handreds " + NumberToText(number % 100);
    }

    if (number >= 1000 && number <= 1999)
    {
        return "One Thounsand " + NumberToText(number % 1000);
    }

    if (number >= 2000 && number <= 999999)
    {
        return NumberToText(number / 1000) + "Thounsands " + NumberToText(number % 1000);
    }

    if (number >= 1000000 && number <= 1999999)
    {
        return "One Million " + NumberToText(number % 1000000);
    }

    if (number >= 2000000 && number <= 999999999)
    {
        return NumberToText(number / 1000000) + "Millions " + NumberToText(number % 1000000);
    }

    if (number >= 1000000000 && number <= 1999999999)
    {
        return"One Billion " + NumberToText(number % 1000000000);
    } 
    else    
    { 
        return   NumberToText(number / 1000000000) + "Billions " + NumberToText(number % 1000000000);
    }
}

bool IsLeapYear(short year)
{
    //if (year % 400 == 0)/*leap year if divisable by 400*/
    //{
    //    return true;
    //}
    //else if (year % 4 == 0 && year % 100 != 0)/*leap year if divisable by 4 and not ending with 00 i.e 1900*/
    //{
    //    return true;
    //}
    //else
    //{
    //    return false;
    //}
    
   // return (year % 400 == 0) ? true : (year % 4 == 0 && year % 100 != 0) ? true : false;
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

short NumberOfDayesInYear(short year)
{
    return IsLeapYear(year) ? 366 : 365;
}

int NumberOfHoursInYear(short year)
{
    return NumberOfDayesInYear(year) * 24;
}

int NumberOfMinutesInYear(short year)
{
    return NumberOfHoursInYear(year) * 60;
}

int NumberOfSecondsInYear(short year)
{
    return NumberOfMinutesInYear(year) * 60;
}

short NumberOfDayesInMonth(short Year , short Month)
{
    /*if (Month == 2)
    {
        return IsLeapYear(Year) ? 29 : 28;
    }
    else
    {
        if (Month == 1 || Month == 3 || Month == 5 ||
            Month == 7 || Month == 8 || Month == 10 || Month == 12)
        {
            return 31;
        }
        else
        {
            return 30;
        }
    }*/
    return (IsLeapYear(Year) && Month == 2) ? 29 : (Month == 2) ? 28 : (Month == 1 || Month == 3 || Month == 5 ||Month == 7 || Month == 8 || Month == 10 || Month == 12) ?31 : 30;
}

int NumberOfHoursInMonth(short Year, short Month)
{
    return NumberOfDayesInMonth(Year, Month) * 24;
}

int NumberOfMinutesInMonth(short Year, short Month)
{
    return NumberOfHoursInMonth(Year, Month) * 60;
}

int NumberOfSecondsInMonth(short Year, short Month)
{
    return NumberOfMinutesInMonth(Year, Month) * 60;
}

short GetDayNumberOfDate(short Year, short Month, short Day)
{
    short a, y, m;     
    a = (14 - Month) / 12; 
    y = Year - a;    
    m = Month + (12 * a) - 2;
    // Gregorian://0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

void PrintDayOfDate(short year, short month, short day)
{
    short dayNum =  GetDayNumberOfDate(year, month, day);

    string DayNames[] = {"Sun" , "Mon" ,"Tue" ,"Wen" ,"Thu" , "Fri" , "Sat"};

    cout << "Date      :" << day << "/" << month << "/" << year << endl;
    cout << "Day Order :" << dayNum << endl;
    cout << "Day Name  :" << DayNames[dayNum] <<endl;
}

short NumberOfDaysInAMonth(short Year , short Month)
{ 
    if (Month < 1 || Month > 12) 
        return  0; 
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; 
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

void PrintMonthCalender(short year, short month)
{
    string MonthNames[] = { "" , "Jan" , "Feb" ,"Mar" ,"Abr" , "May" , "Jun" ,"July" , "Aug" , "Seb" ,"Oct" , "Nov" , "Dec"};
    string DayNames[] = { "Sun" , "Mon" ,"Tue" ,"Wen" ,"Thu" , "Fri" , "Sat" };
    short current = GetDayNumberOfDate(year,month,1);
    short NumberOfDays = NumberOfDaysInAMonth(year, month);

    cout << "_________________" << MonthNames[month] << "_________________" << endl;
    cout << "  Sun  Mon  Tue  Wen  Thu  Fri  Sat" << endl;
    short i;
    for (i = 0; i < current; i++)
    {
        cout << "     ";
    }
    for (short j = 1; j <= NumberOfDays;j++)
    {
        printf("%5d",j);
        if (++i == 7) 
        {
            i = 0;
            cout << endl;
        }
    }
    cout << endl;
    cout << "_____________________________________" << endl;
}

void PrintYearCalender(short year)
{
    cout << "_____________________________________" << endl;
    cout << "___________Calender : " << year << "___________" << endl;
    cout << "_____________________________________" << endl;
    for (short i = 1; i <= 12; i++)
    {
        PrintMonthCalender(year,i);
        printf("\n");
    }
}

void PrintNumberOfDayesFromBeginingOfYear(short year, short month, short day)
{
    short DaysInYear = NumberOfDayesInYear(year);
    short days = 0;
    for (short i = month; i <= 12; i++)
    {
        days += NumberOfDayesInMonth(year , i);
    }
    printf("Number of days from the begining of the year is : %d\n", (DaysInYear - days + day) );
}

void PrintDateFromTheDayNumber(short dayNum ,short year)
{
    short dayes_in_month;
    short month = 0;
    for (short i = 1; i <= 12; i++)
    {
        dayes_in_month = NumberOfDayesInMonth(year, i);
        if ((dayNum - dayes_in_month) > 0)
        {
            dayNum -= dayes_in_month;
        }
        else
        {
            month = i;
            break;
        }
    }
    cout << "Date is : " << dayNum << "/" << month << "/" << year << endl;
}

void PrintTheDateOfDayAddedWithNumberOfDayes(short year, short month, short day , short addedDayes)
{

}

struct stdate
{
    short year;
    short month;
    short day;
};

bool CompareTwoDates(stdate date1  , stdate date2)
{
    return (date1.year > date2.year ? true : date1.month > date2.month ? true : date1.day > date2.day?true : false);
}

bool IsTwoDatesEquals(stdate date1, stdate date2)
{
    return (date1.year != date2.year ? false : date1.month !=date2.month? false : date1.day != date2.day?false : true);
}

bool IsLastDayInMonth(stdate date1)
{
    short days_in_month = NumberOfDayesInMonth(date1.year , date1.month);
    return (date1.day == days_in_month ? true : false);
}
bool IsLastMonthInYear(stdate date1)
{
    return (date1.month == 12 ? true : false);
}

stdate IncreaseDateBy1Day(stdate date)
{
    if (IsLastDayInMonth(date))
    {
        date.day = 1;
        if (IsLastMonthInYear(date))
        {
            date.month = 1;
            date.year++;
        }
        else
        {
            date.month++;
        }
    }
    else
    {
        date.day++;
    }
    return date;
}

stdate GetSystemDate()
{ 
    stdate Date; time_t t = time(0);
    tm* now = localtime(&t);  
    Date.year = now->tm_year + 1900;
    Date.month = now->tm_mon + 1;  
    Date.day = now->tm_mday; 
    return Date; 
}

int AgeInDayes(stdate DateOfBirth)
{
    stdate TodaysDate = GetSystemDate();

    int result = 0;
    
    while (!IsTwoDatesEquals(DateOfBirth , TodaysDate))
    {
        DateOfBirth = IncreaseDateBy1Day(DateOfBirth);
        result++;
    }

    return result;
}


int main()
{
    cout << "Enter date of birth" << endl;
    short day = (short)ReadNumber("Enter the day");
    short month = (short)ReadNumber("Enter the month");
    short year = (short)ReadNumber("Enter the year");
    
    stdate date1 = {date1.year = year , date1.month = month , date1.day = day};
    
   // cout << date1.day << "/" << date1.month << "/" << date1.year << endl;
   
    cout << "Your age is : " << AgeInDayes(date1) << " day(s)" << endl;

  

    return 0;
}

