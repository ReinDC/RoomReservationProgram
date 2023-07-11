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

typedef char string20[20];

typedef struct Building{
    struct room;
// !idk building;
    int status;
}Building;


/*
    TODO: Declare necessary variable names
*/
void Input_Form(int IDN,char sFN,char sYnP, int nDnT,int nParticipants, char sRtR, char sDoA)
{
    /*
        ? I think we can separately get some of this info
        ? Yung full name, id number, year & program pwede 
        ? sa pag login or sign in ng tao
    */

    printf("Enter ID Number: ");
    scanf("%d\n", IDN);

    printf("Enter Full Name: ");
    scanf("%s\n", sFN);

    printf("Enter Year & Program: ");
    scanf("%s\n", sYnP);

    printf("Enter Date and Time: ");
    scanf("%d\n", nDnT);

    printf("Enter Number of Participants: ");
    scanf("%d\n", nParticipants);

    printf("Enter Room to Reserve: ");
    scanf("%s\n", sRtR);

    printf("Enter Description of Activity: ");
    scanf("%s\n", sDoA);
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
    Input_Form();    

    
}

