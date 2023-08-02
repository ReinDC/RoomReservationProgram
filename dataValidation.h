#define MAX 999
#define length 20

typedef char string20[21];
typedef char string1000[1001];
typedef char string50[51];


void password(char *password);
int campreDate(int todayM, int todayD, int todayY, int futureM, int futureD, int futureY);
int dateValid(int dateM, int dateD, int dateY);
int dayValid(char *day);
