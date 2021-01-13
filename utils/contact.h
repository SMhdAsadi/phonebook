#define NAME_SIZE 50
#define ADDRESS_SIZE 150
#define EMAIL_SIZE 50
#define NUMBER_SIZE 12

/*
    a struct for demonstrating one Contact
*/
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

/*
    a struct acted as dynamic array for Contact
*/
typedef struct _contacts
{
    Contact *elements;
    int length;
    int capacity;
} ContactArray;


/*
    creates and return a new contact dynamic array, external free needed
*/
ContactArray *newContactArray();

/*
    adds a contact to the contact dynamic array
*/
void addContact(ContactArray *contactArray, Contact *contact);

/*
    frees allocated memory for the contact dynamic array
*/
void deleteContactArray(ContactArray *contacts);

/*
    copies contact src to contact dest
*/
void copyContact(Contact *dest, Contact *src);