#ifndef CONTACT_INCLUDED
#include "../utils/contact.h"
#endif

/*
    takes a contact and appends it to the database
*/
int appendContact(Contact *contact);

/*
    takes an id and deletes a contact with that id in database
    if didn't found contact, returns 0
*/
int deleteContactById(int id);

/*
    takes a updated contact and replaces it with outdated contact in database
*/
int updateContact(Contact *contact);