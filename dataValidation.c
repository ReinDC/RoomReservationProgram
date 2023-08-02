#include "dataValidation.h"
#include <string.h>

/**************************************************************************
    Description : Compares the Date

    @param : int todayM, int todayD, int todayY, int futureM, int futureD, int futureY
    @return :  1,0
***************************************************************************/
int compareDate(int todayM, int todayD, int todayY, int futureM, int futureD, int futureY)
{
    // Compare the years
    if (futureY < todayY) 
        return 0;
    
    else if (futureY == todayY) 
    {
        // If years are the same, compare the months
        if (futureM < todayM)
            return 0;
        
        
        else if (futureM == todayM) 
        {
            // If months are the same, compare the days
            if (futureD <= todayD) 
                return 0;
            
        }
    }

    // If none of the above conditions are met
    return 1;
}

/**************************************************************************
    Description : Checking the validity of the inputted Date

    @param : int dateM, int dateD, int dateY
    @return :  1,0
***************************************************************************/
int dateValid(int dateM, int dateD, int dateY)
{
    
    // Check if the month is within a valid range (1 to 12)
    if (dateM < 1 || dateM > 12)
        return 0;
    

    // Check if the day is within a valid range based on the month
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (dateM == 2 && ((dateY % 400 == 0) || ((dateY % 4 == 0) && (dateY % 100 != 0))))
        daysInMonth[2] = 29;// Leap year
    
    if (dateD < 1 || dateD > daysInMonth[dateM])
        return 0;

    // Check if the year is within a valid range (e.g., 00 to 99 for YY format)
    if (dateY < 0 || dateY > 99)
        return 0;

    return 1;

}

/**************************************************************************
    Description : Checks if the correct day inputted

    @param : char *day
    @return :  1,0
***************************************************************************/
int dayValid(char *day)
{
    if((strcmp(day, "Mon") == 0) || (strcmp(day, "Tue") == 0) || (strcmp(day, "Wed") == 0) || (strcmp(day, "Thu") == 0) || (strcmp(day, "Fri") == 0) || (strcmp(day, "Sat") == 0))
        return 1;

    return 0;
}

/**************************************************************************
    Description : Checking of Admin Password

    @param : char *password 
***************************************************************************/
void password(char *password)
{
    int i = 0;
    char ch;
    printf("\nInput admin password: ");
    while (1) {
        ch = getch();

        if (ch == '\r' || ch == '\n')
        {
            // Check for Enter (carriage return) or Newline
            break;
        } 
        else if (ch == 27)
        {
            // Check for Escape key (27) to exit input process
            printf("\nPassword input cancelled.\n");
            password[0] = '\0'; // Clear the password
            return;
        }
        else if (ch == 8)
        {
            // Backspace (8) to handle erasing characters
            if (i > 0) {
                printf("\b \b"); // Erase the last character from the console
                i--;
            }
        }
        else if (i < length - 1)
        {
            // Mask the input with '*'
            putchar('*');
            password[i] = ch;
            i++;
        }
    }

    password[i] = '\0'; // Null-terminate the password string
    printf("\n"); // Move to the next line after entering the password
}

