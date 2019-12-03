#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
using namespace std;
int numOfDaysInAMonth(int);
void printHeader(int);
void printMonth(int);
void skipToDay(int);
int year;
int result;
char *tid;
char clok[] = {};
char tid1;
int io;
int check_m;
int check_m1;
int check_q;
int check_q1;
int q;
int q1;
int m;
int m1;
int control1;
char timeArray[24];
int userInput;
int userInputTwo;
struct Event
{
    string dateNotice;
    int date1;
    int date2;
    int date3;
    int timeH;
    int timeM;
    int timeS;
    int location;
};
/**************************************************************************/
/* Checks clock tics on the pc since January 1 since 1970 */
/**************************************************************************/
int checkYear()
{
    int currentYear;
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime); // Get the current time
    localTime = localtime(&currentTime);
    currentYear = localTime->tm_year + 1900;
    return (currentYear);
}
int checkHours()
{
    int currentHour;
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime); // Get the current time
    localTime = localtime(&currentTime);
    currentHour = localTime->tm_hour;
    return (currentHour);
}
int checkMin()
{
    int currentMinute;
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime); // Get the current time
    localTime = localtime(&currentTime);
    currentMinute = localTime->tm_min;
    return (currentMinute);
}
int checkSeconds()
{
    int currentSeconds;
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime); // Get the current time
    localTime = localtime(&currentTime);
    currentSeconds = localTime->tm_sec;
    return (currentSeconds);
}
/**************************************************************************/
/* Checks clock tics on the pc since January 1 since 1970 */
/**************************************************************************/
int checkMonth()
{
    int currentMonthcheck;
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    currentMonthcheck = localTime->tm_mon + 1;
    return (currentMonthcheck);
}
/**************************************************************************/
/* Checks clock tics on the pc since January 1 since 1970 */
/**************************************************************************/
int checkDay()
{
    int currentDaycheck;
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    currentDaycheck = localTime->tm_mday;
    return (currentDaycheck);
}
/**************************************************************************/
/* Zeller's Algorithm */
/* Checks day of a month and outputs whether it is monday, sunday etc. */
/**************************************************************************/
int dayNumber(int m, int d, int y)
{
    if (m == 1 || m == 2)
    {
        m = m + 12;
        y = y - 1;
    }
    return (d + (int)floor((13 * (m + 1)) / 5) + y % 100 + (int)floor((y % 100) / 4) + (int)floor(((int)floor(y / 100)) / 4) + 5 * (int)floor(y / 100)) % 7;
}
/**************************************************************************/
/* The main algorithm for the calendar program */
/**************************************************************************/
int main(int argc, char **argv)
{
    cout << "Welcome to the Turtlebot T.R.I.L.L.E.R's user interface." << endl;
    cout << "What would you like to do?" << endl;
    cout << "\n1: Make a new appointment." << endl;
    cout << "2: Check appointments." << endl;
    cout << "3: Print calendar for current month." << endl;
    cout << "4: Change an appointment." << endl;
    cout << "5: Program UI sleep." << endl;
    cout << "\nToday is the " << checkDay() << "-" << checkMonth() << "-" << checkYear() << endl;
    vector<Event> listOfEvents;
    Event p;
    ros::init(argc, argv, "mouth");
    ros::NodeHandle n;
    ros::Publisher location1_pub = n.advertise<std_msgs::String>("location1", 1000);
    ros::Publisher location2_pub = n.advertise<std_msgs::String>("location2", 1000);
    ros::Rate loop_rate(10);
    int count = 0;
    while (true && ros::ok())
    {
        if (userInputTwo == 1 && ros::ok())
        {
            system("clear");
            cout << "Welcome to the Turtlebot T.R.I.L.L.E.R's user interface." << endl;
            cout << "What would you like to do?" << endl;
            cout << "\n1: Make a new appointment." << endl;
            cout << "2: Check appointments." << endl;
            cout << "3: Print calendar for current month." << endl;
            cout << "4: Change an appointment." << endl;
            cout << "5: Program UI sleep." << endl;
            cout << "\nToday is the " << checkDay() << "-" << checkMonth() << "-" << checkYear() << endl;
            userInputTwo++;
        }
        cin >> userInput;
        if (userInput == 1)
        {
            system("clear");
            cout << "What is it you wan't to do?: ";
            cin.ignore();
            getline(cin, p.dateNotice);
            cout << "\nEnter the month of the event: ";
            cin >> p.date1;
            cout << "\nEnter the day of the event: ";
            cin >> p.date2;
            cout << "\nEnter the year of the event: ";
            cin >> p.date3;
            cout << "\nEnter the allocated time for the event: ";
            cin >> p.timeH;
            cin >> p.timeM;
            cin >> p.timeS;
            cout << "\nEnter the location (1 or 2): ";
            cin >> p.location;
            listOfEvents.push_back(p);
            cout << listOfEvents.size() << endl;
            userInputTwo = 1;
        }
        else if (userInput == 2)
        {
            system("clear");
            cout << "If you wish to change something in one of your appointments," << endl;
            cout << "please note the reference number for the specifik appointent.\n"
                 << endl;
            for (int n = 0; n < listOfEvents.size(); n++)
            {
                cout << "Date: " << listOfEvents[n].date2 << "-" << listOfEvents[n].date1 << "-" << listOfEvents[n].date3 << endl;
                cout << "Time: " << listOfEvents[n].timeH << ":" << listOfEvents[n].timeM << ":" << listOfEvents[n].timeS << endl;
                cout << "At location: " << listOfEvents[n].location << endl;
                cout << listOfEvents[n].dateNotice << endl;
                cout << "Ref nr: " << n << "\n"
                     << endl;
            }

            cin.ignore().get();
            userInputTwo = 1;
        }
        else if (userInput == 3)
        {
            while (true)
            {
                system("clear");
                int currentMonth = 1;
                int numDays;
                year = checkYear();
                cout << " Year: " << year << endl;
                while (currentMonth <= 12)
                {
                    numDays = numOfDaysInAMonth(currentMonth);
                    if (currentMonth == checkMonth())
                    {
                        printHeader(checkMonth());
                        printMonth(numDays);
                    }
                    currentMonth++;
                }
                cout << "\n"
                     << endl;
                cout << checkHours() << ":" << checkMin() << ":" << checkSeconds() << endl;
                userInputTwo = 1;
                break;
            }
        }
        else if (userInput == 4)
        {
            int RefNr;
            string newUserInput;
            system("clear");
            cout << "Enter reference number to the appointment you want to change." << endl;
            cout << "Ref nr: ";
            cin >> RefNr;
            cout << "\nDate: " << listOfEvents[RefNr].date2 << "-" << listOfEvents[RefNr].date1 << "-" << listOfEvents[RefNr].date3 << endl;
            cout << "Time: " << listOfEvents[RefNr].timeH << ":" << listOfEvents[RefNr].timeM << ":" << listOfEvents[RefNr].timeS << endl;
            cout << "Location: " << listOfEvents[RefNr].location << endl;
            cout << listOfEvents[RefNr].dateNotice << endl;
            cin.ignore().get();
            system("clear");
            cout << "Enter new description for date: ";
            cin.ignore();
            getline(cin, listOfEvents[RefNr].dateNotice);
            cout << "\nEnter new month: ";
            cin >> listOfEvents[RefNr].date1;
            cout << "\nEnter new day of month: ";
            cin >> listOfEvents[RefNr].date2;
            cout << "\nEnter new year: ";
            cin >> listOfEvents[RefNr].date3;
            cout << "\nEnter new time: ";
            cin >> listOfEvents[RefNr].timeH;
            cin >> listOfEvents[RefNr].timeM;
            cin >> listOfEvents[RefNr].timeS;
            cout << "\nEnter new location: ";
            cin >> listOfEvents[RefNr].location;
            cin.ignore().get();
            userInputTwo = 1;
        }
        else if (userInput == 5)
        {
            while (true && ros::ok())
            {
                sleep(1);
                checkYear();
                checkMonth();
                checkDay();
                checkHours();
                checkMin();
                checkSeconds();
                cout << checkHours() << ":" << checkMin() << ":" << checkSeconds() << endl;
                for (int n = 0; n < listOfEvents.size();)
                {
                    if (listOfEvents[n].date3 == checkYear() && lis - tOfEvents[n].date1 == checkMonth() &&
                        listOfEvents[n].date2 == checkDay() && checkHours() == listOfEvents[n].timeH &&
                        listOfEvents[n].timeM == checkMin() && listOfEvents[n].timeS == checkSeconds())
                    {
                        system("clear");
                        if (listOfEvents[n].location == 1)
                        {
                            std_msgs::String msg;
                            std::stringstream ss;
                            ss << listOfEvents[n].location;
                            msg.data = ss.str();
                            ROS_INFO("%s", msg.data.c_str());
                            location1_pub.publish(msg);
                            ros::spinOnce();
                            loop_rate.sleep();
                            ++count;
                        }
                        else if (listOfEvents[n].location == 2)
                        {
                            std_msgs::String msg;
                            std::stringstream ss;
                            ss << listOfEvents[n].location;
                            msg.data = ss.str();
                            ROS_INFO("%s", msg.data.c_str());
                            location2_pub.publish(msg);
                            ros::spinOnce();
                            loop_rate.sleep();
                            ++count;
                        }
                        //cout << listOfEvents[n].dateNotice << endl;
                        listOfEvents.erase(listOfEvents.begin() + n);
                    }
                    n++;
                }
                if (listOfEvents.size() == 0)
                {
                    userInputTwo = 1;
                    break;
                }
            }
        }
    }
    return 0;
}
/**************************************************************************/
/* Function to check for leap years. */
/**************************************************************************/
bool leapYearCheck()
{
    bool leapYear;
    if (((year % 4) == 0) && ((year % 100) != 0))
    {
        leapYear = true;
    }
    else if ((year % 400) == 0)
    {
        leapYear = true;
    }
    else
    {
        leapYear = false;
    }
    return leapYear;
};
/**************************************************************************/
/* This function returns the number of days in a month */
/**************************************************************************/
int numOfDaysInAMonth(int m)
{
    if (m == 1)
        return (31);
    else if ((m == 2) && (leapYearCheck() == false))
        return (28);
    else if ((m == 2) && (leapYearCheck() == true))
        return (29);
    else if (m == 3)
        return (31);
    else if (m == 4)
        return (30);
    else if (m == 5)
        return (31);
    else if (m == 6)
        return (30);
    else if (m == 7)
        return (31);
    else if (m == 8)
        return (31);
    else if (m == 9)
        return (30);
    else if (m == 10)
        return (31);
    else if (m == 11)
        return (30);
    else if (m == 12)
        return (31);
    else
        return (-1);
}
/**************************************************************************/
/* It takes the number of the month and prints outs the name of the */
/* month and the frame of the calander */
/**************************************************************************/
void printHeader(int m)
{
    if (m == 1)
        cout << " January" << endl;
    else if (m == 2)
        cout << " February" << endl;
    else if (m == 3)
        cout << " March" << endl;
    else if (m == 4)
        cout << " April" << endl;
    else if (m == 5)
        cout << " May" << endl;
    else if (m == 6)
        cout << " June" << endl;
    else if (m == 7)
        cout << " July" << endl;
    else if (m == 8)
        cout << " August" << endl;
    else if (m == 9)
        cout << " September" << endl;
    else if (m == 10)
        cout << " October" << endl;
    else if (m == 11)
        cout << " November" << endl;
    else if (m == 12)
        cout << " December" << endl;
    cout << " S M T W T F S" << endl;
    cout << "____________________" << endl;
}
/**************************************************************************/
/* Helps with the skipToDay function */
/**************************************************************************/
void skip(int i)
{
    while (i > 0)
    {
        cout << " ";
        i = i - 1;
    }
}
/**************************************************************************/
/* This function prints out the days in the month after the header for */
/* each month */
/**************************************************************************/
void printMonth(int numDays)
{
    int day = 1;
    int weekDay;
    weekDay = dayNumber(checkMonth(), 01, checkYear()) - 1; // -1 because Zeller's algorithm goes from 1 to 7 while the
    function works from 0 to 6. skipToDay(weekDay);
    while (day <= numDays)
    {
        cout << setw(2) << day << " ";
        if (weekDay == 6)
        {
            cout << endl;
            weekDay = 0;
        }
        else
            weekDay++;
        day++;
    }
}
/**************************************************************************/
/* Prints spaces in monthly calendar */
/**************************************************************************/
void skipToDay(int d)
{
    return skip(3 * d);
}