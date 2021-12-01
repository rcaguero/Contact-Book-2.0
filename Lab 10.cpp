// Lab 10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Contact 
{
public:
    Contact(string name, string lastname, string email, string telephome, string notes); //Constructor
     
    string getFirstName();
    string getLastName(); 
    string getEmail();
    string getTelephone();
    string getNotes();

    void setFirstName(string s);
    void setLastName(string s);
    void setEmail(string s);
    void setTelephone(string s);
    void setNotes(string s); 

    void printContact();

private:
    string firstName;
    string lastName;
    string email;
    string telephone;
    string notes;
};

int main()
{
    vector<Contact> ContactBook;
    Contact contact1("Roberto","Aguero", "rcaguero@outlook.com","2339999","me");
    Contact contact2("Conner","Cheung", "ccheung@hotmail.com","4333 4219","friend");
    Contact contact3("Walter","Aguero", "walterhotmail.com","4793334296","cousin");

    ContactBook.push_back(contact1);
    ContactBook.push_back(contact2);
    ContactBook.push_back(contact3);

    for (int i = 0; i < ContactBook.size(); i++)
    {
        cout << "Contact #" << i+1 << ": " << endl;
        ContactBook[i].printContact();
    }
}

string Contact::getFirstName()
{
    return firstName;
}

string Contact::getLastName()
{
    return lastName;
}

string Contact::getEmail()
{
    return email;
}

string Contact::getTelephone()
{
    return telephone;
}

string Contact::getNotes()
{
    return notes;
}

void Contact::setFirstName(string s)
{
    firstName = s;
}

void Contact::setLastName(string s)
{
    lastName = s;
}

void Contact::setEmail(string s)
{
    size_t digit = s.find("@");
    if (digit!=std::string::npos)
    {
        email = s;
    }
    else
    {
        email = "Error - @ is needed for a valid email.";
    }
}

void Contact::setTelephone(string s) 
{
    int count = 0;
    string secondString = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            secondString += (s[i]);
            count++;
        }
    }
    if (count != 10 && count != 7)
    {
        telephone = "Error. Not a valid telephone number.";
    }

    if(count == 10)
    {
        secondString.insert(6, "-");

        secondString.insert(3, ") ");

        secondString.insert(0, "(");
        telephone = secondString;
    }

    if (count == 7)
    {
        secondString.insert(0, "(479) ");
        secondString.insert(9, "-");
        telephone = secondString;
    }
}

void Contact::setNotes(string s)
{
    notes = s;
}

void Contact::printContact() 
{
    cout << "Name: " << getFirstName() << " " << getLastName() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "Telephone: " << getTelephone() << endl;
    cout << "Notes: " << getNotes() << endl;
    cout << " " << endl;
}

Contact::Contact(string name, string lastname, string email, string telephone, string notes) 
{
    setFirstName(name);
    setLastName(lastname);
    setEmail(email);
    setTelephone(telephone);
    setNotes(notes);
}