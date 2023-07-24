#include <stdio.h>
#include <string.h>


/*
? Needed info about the users
* First & Last name
* ID Number
* Year & Program
* Date & Time fro Reservation
* Number of Participants
* Room to Reserved (preferred)
* Description of the Activity (short)
*/

#define MAX 9999
typedef char string20[21];
typedef char string1000[1001];


struct data{
    string20 buildingName;
    struct person{
        int ID;
        string20 firstName;
        string20 lastName;
        int year;
        string20 course;
    }data;
    struct room{
        int roomNum;
        int roomType;
        char Day[4];
        int timeslot[6];
        int status;
    }rooms;
    string1000 roomDesc;
};


/*
    TODO: Declare necessary variable names
*/
int Input_Form(struct data *A, int n)
{

    string20 tempfirstName, templastName, tempProgram; // Just in case they cancel whenever
    string1000 tempDesc;
    int tempID, tempYear, tempDate, successRT = 0, choiceRT, tempRType, successInput = 0;

    printf("Input ID Number: ");
    scanf("%d", A[n].data.ID); 

    printf("Input first name: ");
    gets(A[n].data.firstName);

    printf("Input last name: ");
    gets(A[n].data.lastName);

    printf("Input year: ");
    scanf("%d", A[n].data.year);

    printf("Input prgram (CS-ST18): ");
    gets(A[n].data.course);
    
    while(successRT == 0)
    {
        
        printf( "Select a room to reserve"
                "[1] Classroom (Capacity: 30)"
                "[2] Seminar Room (Capacity: 80)"
                "[3] Auditorium (Capacity: 200)"
                "[4] Training Room (Capacity: 50)");
        scanf("%d", &choiceRT);
        
        if(choiceRT >= 1 || choiceRT <= 4)
        {
            A[n].rooms.roomType = choiceRT;
        }

        else
            printf("Invalid input, try again.");
    }

    printf("Short description for the activity: ");
    gets(A[n].roomDesc);



    return successInput; // To add to the array of structs
}

void Add_Time_Condition()
{
    /*
        if Room Reservation > 3
            Reserve 
    */ 

    /*
        In case the activity will use more than 1.5hrs on specific days,
        they can reserve an additional time slot (must be consecutive time slot)
    */
}

void Cancel_Reservation(struct data info[], int n)
{
    

   /*
        if(A[i].status == reserved && A[i].room# == room to be canceled)
        {
            status == Vacant
        }

   */

}

void Change_Room_Reservation()
{
    /*
        if room status == 0
    */
}

void display_rooms(struct data info[])
{

}


/*
    Program should check:
    - Conflicting date,time, timeslot
    - Max Reservations per reserver
    - Max capacity each room to be used

    Features
    - Once the program is terminated, all reservations transactions gets saved
    to a text file. On Program Start, reservations must be loaded from memory
    - Cancel Reservation
    - Change Room Reservation if the room requested is available
    - Add time if more than 1.5hrs on specific days(Add_Time_Condition)

    Bonus Pero Required pala
    - Produce a report on the room reservation per room(as text file)
    - Produce a report on the list of room reservations for a particular
    date(as text file)

*/

int main()
{
    struct data info[MAX];
    int records = 0, choiceMain, successInput;


    printf("What would you like to do?");

    printf( "Select a room to reserve"
                "[1] Book a reservation"
                "[2] Cancel a reservation"
                "[3] Change a reservation"
                "[4] Exit program");
    scanf("%d", choiceMain);

    switch(choiceMain)
    {
        case 1:
            successInput = Input_Form(info, records);
            if(successInput != 0)
                records += successInput;
            break;
        case 2:
            Cancel_Reservation(info, records);
            break;
        case 3:
            Change_Room_Reservation();
            break;
        default:
            printf("Thank you for using our program!");
            getch(); // Para di magexit agad
    }

    return 0;
}

