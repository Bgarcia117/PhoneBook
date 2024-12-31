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
int getContactIndex(ContactVector, int);
void deleteContact(ContactVector, int);
void findContact(ContactVector, int);
void displayContacts(ContactVector, int);


int main() {
    ContactVector friends; // Instantiates a Contact vector using its alias
    int selection = 0; // Stores user selection on menu
    int lastIndexAdded = -1; // Tracks index of the person added last
    std::string newFirstName, newLastName, newPhoneNum;

    while (selection != 6) {
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Phonebook" << std::endl;
        std::cout << "----------------------------------" << std::endl;
        std::cout << "1) Add Contact" << std::endl;
        std::cout << "2) Delete Contact" << std::endl;
        std::cout << "3) Find Number" << std::endl;
        std::cout << "4) Display Contacts" << std::endl;
        std::cout << "5) Erase All Contacts" << std::endl;
        std::cout << "6) Close Program" << std::endl;
        std::cout << "Make a selection (1-6): " << std::endl;
        std::cin >> selection;

        switch (selection) {
            case 1: // Adds a contact obj to the vector
                std::cout << "----------------------------------" << std::endl;
                std::cout << "Enter a first name: " << std::endl;
                std::cin >> newFirstName;
                std::cout << "Enter a last name: " << std::endl;
                std::cin >> newLastName;
                std::cout << "Enter a phone number: " << std::endl;
                std::cin >> newPhoneNum;
                std::cout << "----------------------------------" << std::endl;

                // Inserts a contact obj at the end of the vector and allows the paramaterized constructor to be invoked.
                // Type is inferred by declaration of "friends" vector so it is not necessary to include type (Contact)
                friends.emplace_back(newFirstName, newLastName, newPhoneNum);

                lastIndexAdded++;

                std::cout << "Current Index: " << lastIndexAdded << std::endl;
                std::cout << "First Name: " << friends.at(lastIndexAdded).getFirstName() << std::endl;
                std::cout << "Last Name: " << friends.at(lastIndexAdded).getLastName() << std::endl;
                std::cout << "Phone Number: " << friends.at(lastIndexAdded).getPhoneNum() << std::endl;
                break;
            case 2: // Deletes contact objs from the vector
                if (lastIndexAdded < 0) {
                    std::cout << "There are no contacts saved." << std::endl;
                    break;
                }
                else {
                    deleteContact(friends, getContactIndex(friends, lastIndexAdded));
                    lastIndexAdded -= 1;
                    break;
                }
                
            case 3: // Finds and displays contact info 
                if (lastIndexAdded < 0) {
                    std::cout << "----------------------------------" << std::endl;
                    std::cout << "There are no contacts saved." << std::endl;
                    break;
                }
                else {
                    findContact(friends, getContactIndex(friends, lastIndexAdded));
                    break;
                }

            case 4: // Displays Contacts
                if (lastIndexAdded < 0) {
                    std::cout << "----------------------------------" << std::endl;
                    std::cout << "There are no contacts saved." << std::endl;
                    break;
                }
                else {
                    displayContacts(friends, lastIndexAdded);
                    break;
                }
            case 5: // Erases all contact objs from vector
                friends.clear();
                lastIndexAdded = -1;
                std::cout << "All contacts were successfully deleted!" << std::endl;
                break;

            default:
                std::cout << "Please enter a valid selection: " << std::endl;
        }
    }
}

int getContactIndex(ContactVector vectorName, int _lastIndexAdded) {
    std::string firstNameSearch, lastNameSearch;
    std::cout << "Enter a first name: " << std::endl;
    std::cin >> firstNameSearch;
    std::cout << "Enter a last name: " << std::endl;
    std::cin >> lastNameSearch;

    for (int i = 0; i <= _lastIndexAdded; i++) {
        if (firstNameSearch == vectorName.at(i).getFirstName() && 
            lastNameSearch == vectorName.at(i).getLastName()) {
            return i; // Returns index of the contact info
        }
        else {
            std::cout << firstNameSearch << " " << lastNameSearch << " was not found." << std::endl;
            break;
        }
    }
}

void deleteContact(ContactVector vectorName, int nameIndex) {
    vectorName.erase(vectorName.begin() + nameIndex); // Removes contact from vector
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
