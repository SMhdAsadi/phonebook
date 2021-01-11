#define NAME_SIZE 50
#define ADDRESS_SIZE 150
#define EMAIL_SIZE 50
#define NUMBER_SIZE 12


typedef struct _contact
{
    char firstName[50];
    char lastName[50];
    char address[150];
    char email[50];
    char phoneNumber[12];
    char homeNumber[12];
} Contact;

void printContact(Contact *contact);