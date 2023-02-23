#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include "Contact.hpp"

// Colors
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define RST "\e[0m"

class PhoneBook
{
    private:
        Contact _contacts[8];
        int _total;
    public:
        PhoneBook(int added);
        void addContact();
        void displayContacts();
        void searchContacts();
        int getIndex();
        void updateTotal(int i);
};

#endif