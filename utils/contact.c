#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct _contact
{
    int id;
    char firstName[50];
    char lastName[50];
    char address[150];
    char email[50];
    char phoneNumber[12];
    char homeNumber[12];
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
    contacts->elements = malloc(3 * sizeof(Contact));
    contacts->length = 0;
    contacts->capacity = 3;

    return contacts;
}

Contacts *doubleTheSize(Contacts *contacts)
{
    contacts = realloc(contacts, contacts->capacity * 2);
    contacts->capacity *= 2;
    return contacts;
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
        contacts = doubleTheSize(contacts);
    }

    // copyContact(contacts->elements + contacts->length, contact);

   contacts->elements[contacts->length] = *contact;
    contacts->length++;
    // return contacts;
}

void deleteContacts(Contacts *contacts)
{
    free(contacts->elements);
    free(contacts);
}
