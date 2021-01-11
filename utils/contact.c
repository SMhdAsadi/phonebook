#include <stdio.h>

typedef struct _contact
{
    char firstName[50];
    char lastName[50];
    char address[150];
    char email[50];
    char phoneNumber[12];
    char homeNumber[12];
} Contact;

void printContact(Contact *contact)
{
    printf("Contact [\n");
    printf("    first name: %s\n", contact->firstName);
    printf("    last name: %s\n", contact->lastName);
    printf("    address: %s\n", contact->address);
    printf("    email: %s\n", contact->email);
    printf("    phone: %s\n", contact->phoneNumber);
    printf("    home: %s\n", contact->homeNumber);
    printf("]\n");
}