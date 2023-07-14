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
typedef char string20[20];


struct Building{
    string20 buildingName;
    struct room{
        int roomNum;
        int roomType;
        char Day[4];
        int timeslot[6];
        int status;
    }rooms;
};


/*
    TODO: Declare necessary variable names
*/
void Input_Form(struct building *A, int n)
{

    string20 tempfirstName, templastName, tempProgram; // Just in case they cancel whenever
    int tempID, tempYear, successRT = 0, choiceRT;

    printf("Input ID Number: ");
    scanf("%d", tempID); 

    printf("Input first name: ");
    gets(tempfirstName);

    printf("Input last name: ");
    gets(templastName);

    printf("Input year: ");
    scanf("%d", tempYear);



    printf("Input prgram (CS-ST18): ");
    gets(tempProgram);

    while(successRT == 0)
    {
        
        printf( "Select a room to reserve"
                "[1] Classroom (Capacity: 30)"
                "[2] Seminar Room (Capacity: 80)"
                "[3] Auditorium (Capacity: 200)"
                "[4] Training Room (Capacity: 50)"
                "[5] Cancel reservation");
        scanf("%d", &choiceRT);
        
        if(choiceRT >= 1 || choiceRT <= 4)
        {
            A[n].rooms.roomType = choiceRT;
            successRT = 1;
        }
        
        else if(choiceRT == 5) // We can add confirmation if we want
        {
            printf("Canceling the reservation...");
            successRT = 2; 
        }
        else
            printf("Invalid input, try again.");
}


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

void Cancel_Reservation(struct <placeholder> *A, int n, char login)
{
    /*
        if Room == Reserved
            Cancel
    */

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
    struct Building building[MAX];
    Input_Form();    

    
}

