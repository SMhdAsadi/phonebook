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
} ContactArray;


ContactArray *newContactArray()
{
    ContactArray *contactArray = calloc(1, sizeof(ContactArray));
    contactArray->elements = calloc(INITIAL_CONTACT_SIZE, sizeof(Contact));
    contactArray->length = 0;
    contactArray->capacity = INITIAL_CONTACT_SIZE;

    return contactArray;
}

void doubleTheSize(ContactArray *contactArray)
{
    contactArray->elements = realloc(contactArray->elements, contactArray->capacity * 2 * sizeof(Contact));
    contactArray->capacity *= 2;
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

void addContact(ContactArray *contactArray, Contact *contact)
{
    if (contactArray->length == contactArray->capacity)
    {
        doubleTheSize(contactArray);
    }

    copyContact(contactArray->elements + contactArray->length, contact);

    contactArray->elements[contactArray->length] = *contact;
    contactArray->length++;
}

void deleteContactArray(ContactArray *contactArray)
{
    free(contactArray->elements);
    free(contactArray);
}
