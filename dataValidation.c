#include "dataValidation.h"
#include <string.h>

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

int dateValid(int dateM, int dateD, int dateY)
{
    // Check if the month is within a valid range (1 to 12)
    if (dateM < 1 || dateM > 12)
        return 0;
    

    // Check if the day is within a valid range based on the month
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (dateD == 2 && (dateY % 4 == 0 && (dateY % 100 != 0 || dateY % 400 == 0)))
        daysInMonth[2] = 29;// Leap year
    
    if (dateD < 1 || dateD > daysInMonth[dateM])
        return 0;

    // Check if the year is within a valid range (e.g., 00 to 99 for YY format)
    if (dateY < 0 || dateY > 99)
        return 0;

    return 1;

}

int stringValid(char *string)
{
    // Check for empty string
    if (string[0] == '\0')
        return 0; // Invalid string

    return 1; // Valid string
}

int yearValid(int year)
{

    if(year > 0 || year <= 7) // Doctoral degree is upto 7 lang daw
        return 1; // Valid

    return 0; // Invalid
}


