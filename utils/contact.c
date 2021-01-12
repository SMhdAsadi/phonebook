#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define INITIAL_CONTACT_SIZE 5
#define NAME_SIZE 50
#define ADDRESS_SIZE 150
#define EMAIL_SIZE 50
#define NUMBER_SIZE 12

typedef struct _contact
{
    int id;
    char firstName[NAME_SIZE];
    char lastName[NAME_SIZE];
    char address[ADDRESS_SIZE];
    char email[EMAIL_SIZE];
    char phoneNumber[NUMBER_SIZE];
    char homeNumber[NUMBER_SIZE];
} Contact;

typedef struct _contacts
{
    Contact *elements;
    int length;
    int capacity;
} Contacts;


Contacts *newContacts()
{
    Contacts *contacts = malloc(sizeof(Contacts));
    contacts->elements = calloc(INITIAL_CONTACT_SIZE, sizeof(Contact));
    contacts->length = 0;
    contacts->capacity = INITIAL_CONTACT_SIZE;

    return contacts;
}

void doubleTheSize(Contacts *contacts)
{
    contacts->elements = realloc(contacts->elements, contacts->capacity * 2 * sizeof(Contact));
    contacts->capacity *= 2;
}

void copyContact(Contact *dest, Contact *src)
{
    dest->id = src->id;
    strcpy(dest->firstName, src->firstName);
    strcpy(dest->lastName, src->lastName);
    strcpy(dest->email, src->email);
    strcpy(dest->address, src->address);
    strcpy(dest->phoneNumber, src->phoneNumber);
    strcpy(dest->homeNumber, src->homeNumber);
}

void addContact(Contacts *contacts, Contact *contact)
{
    if (contacts->length == contacts->capacity)
    {
        doubleTheSize(contacts);
    }

    copyContact(contacts->elements + contacts->length, contact);

    contacts->elements[contacts->length] = *contact;
    contacts->length++;
}

void deleteContacts(Contacts *contacts)
{
    free(contacts->elements);
    free(contacts);
}
