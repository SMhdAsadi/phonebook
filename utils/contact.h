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

Contacts *newContacts();
void addContact(Contacts *contacts, Contact *contact);
void deleteContacts(Contacts *contacts);
void copyContact(Contact *dest, Contact *src);