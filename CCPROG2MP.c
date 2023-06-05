#include <stdio.h>
#include <string.h>




typedef struct Building{
    int status;


}Building;


/*
    TO DOs
    - Declare necessary variable names
*/
void Input_Form(int IDN)
{
    printf("Enter ID Number: ");
    scanf("%d\n", IDN);

    printf("Enter Full Name: ");
    scanf("%s\n", );

    printf("Enter Year & Program: ");
    scanf("%s\n", );

    printf("Enter Date and Time: ");
    scanf("%d\n", );

    printf("Enter Number of Participants: ");
    scanf("%d\n", );

    printf("Enter Room to Reserve: ");
    scanf("%s\n", );

    printf("Enter Description of Activity: ");
    scanf("%s\n", );
}

void Add_Time_Condition()
{
    /*
        if Room Reservation > 3
            Reserve 
    */ 

    /*
        In case the activity will use more than 1.5hrs on specific days,
        they can reserve an additional timeslot(must be consecutive timeslot)
    */
}

void Cancel_Reservation()
{
    /*
        if cancel < Actual Date of Reservation

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

