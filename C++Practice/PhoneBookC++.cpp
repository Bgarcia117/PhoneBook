#include <iostream>
#include <vector>
#include <string>

// Alias to prevent writing out vector multiple times
using ContactVector = std::vector<class Contact>;

class Contact {
    private: 
        std::string firstName;
        std::string lastName;
        std::string phoneNum;
    public:
        Contact() : firstName("No"), lastName("Name"), phoneNum("123-456-7890") {} // Default constructor
        // Parameterized constructor that passes by reference
        Contact(const std::string &_newFirstName, const std::string &_newLastName, const std::string &_newPhoneNum)
            : firstName(_newFirstName), lastName(_newLastName), phoneNum(_newPhoneNum) {}

        std::string getFirstName() const { return firstName; }
        std::string getLastName() const { return lastName; }
        std::string getPhoneNum() const { return phoneNum; }

        void setFirstName(std::string &newFirstName) { firstName = newFirstName; }
        void setLastName(std::string &newLastName) { lastName = newLastName; }
        void setPhoneNum(std::string &newPhoneNum) { phoneNum = newPhoneNum; }
};

// Function prototypes for functions defined after main function
int searchForContact(ContactVector, int);
void deleteContact(ContactVector, int);
void findContact(ContactVector, int);
void displayContacts(ContactVector, int);
void eraseAllContacts(ContactVector, int);

int main() {
    ContactVector friends;
    int selection = 0;
    int lastIndexAdded = -1;
    std::string newFirstName, newLastName, newPhoneNum; // Add error handling for name search

    while (selection != 6) {
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Phonebook" << std::endl;
        std::cout << "----------------------------------" << std::endl;
        std::cout << "1) Add Friend" << std::endl;
        std::cout << "2) Delete Friend" << std::endl;
        std::cout << "3) Find Number" << std::endl;
        std::cout << "4) Display contacts" << std::endl;
        std::cout << "5) Erase All Contacts" << std::endl;
        std::cout << "6) Close Program" << std::endl;
        std::cout << "Make a selection (1-6): " << std::endl;
        std::cin >> selection;

        switch (selection) {
            case 1:
                std::cout << "----------------------------------" << std::endl;
                std::cout << "Enter a first name: " << std::endl;
                std::cin >> newFirstName;
                std::cout << "Enter a last name: " << std::endl;
                std::cin >> newLastName;
                std::cout << "Enter a phone number: " << std::endl;
                std::cin >> newPhoneNum;
                std::cout << "----------------------------------" << std::endl;

                // Inserts and obj at the end of the vector and allows the paramaterized constructor to be invoked.
                // Type is inferred by declaration of "friends" vector so it is not necessary to include type (Contact)
                friends.emplace_back(newFirstName, newLastName, newPhoneNum);

                lastIndexAdded++;

                std::cout << "Current Index: " << lastIndexAdded << std::endl;
                std::cout << "First Name: " << friends.at(lastIndexAdded).getFirstName() << std::endl;
                std::cout << "Last Name: " << friends.at(lastIndexAdded).getLastName() << std::endl;
                std::cout << "Phone Number: " << friends.at(lastIndexAdded).getPhoneNum() << std::endl;
                break;
            case 2:
                if (lastIndexAdded < 0) {
                    std::cout << "There are no contacts saved." << std::endl;
                    break;
                }
                else {
                    deleteContact(friends, searchForContact(friends, lastIndexAdded));
                    lastIndexAdded -= 1;
                    break;
                }
                
            case 3:
                if (lastIndexAdded < 0) {
                    std::cout << "----------------------------------" << std::endl;
                    std::cout << "There are no contacts saved." << std::endl;
                    break;
                }
                else {
                    findContact(friends, searchForContact(friends, lastIndexAdded));
                    break;
                }

            case 4:
                if (lastIndexAdded < 0) {
                    std::cout << "----------------------------------" << std::endl;
                    std::cout << "There are no contacts saved." << std::endl;
                    break;
                }
                else {
                    displayContacts(friends, lastIndexAdded);
                    break;
                }



            default:
                std::cout << "Please enter a valid selection: " << std::endl;
        }
    }
}

int searchForContact(ContactVector vectorName, int _lastIndexAdded) {
    std::string firstNameSearch, lastNameSearch;
    std::cout << "Enter a first name: " << std::endl;
    std::cin >> firstNameSearch;
    std::cout << "Enter a last name: " << std::endl;
    std::cin >> lastNameSearch;

    for (int i = 0; i <= _lastIndexAdded; i++) {
        if (firstNameSearch == vectorName.at(i).getFirstName() && 
            lastNameSearch == vectorName.at(i).getLastName()) {
            return i;
        }
        else {
            std::cout << firstNameSearch << " " << lastNameSearch << " was not found." << std::endl;
            break;
        }
    }
}

void deleteContact(ContactVector vectorName, int nameIndex) {
    vectorName.erase(vectorName.begin() + nameIndex);
    std::cout << "Name was deleted!" << std::endl;
}

void findContact(ContactVector vectorName, int nameIndex) {
    std::cout << "----------------------------------" << std::endl;
    std::cout << "First Name: " << vectorName.at(nameIndex).getFirstName() << std::endl;
    std::cout << "Last Name: " << vectorName.at(nameIndex).getLastName() << std::endl;
    std::cout << "Phone Number: " << vectorName.at(nameIndex).getPhoneNum() << std::endl;
}

void displayContacts(ContactVector vectorName, int _lastIndexAdded) {
    for (int i = 0; i <= _lastIndexAdded; i++) {
        std::cout << "----------------------------------" << std::endl;
        std::cout << "First Name: " << vectorName.at(i).getFirstName() << std::endl;
        std::cout << "Last Name: " << vectorName.at(i).getLastName() << std::endl;
        std::cout << "Phone Number: " << vectorName.at(i).getPhoneNum() << std::endl;
    }
}

void eraseAllContacts(ContactVector vectorName, int _lastIndexAdded) {

}