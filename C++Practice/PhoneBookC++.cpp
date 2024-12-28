#include <iostream>
#include <vector>
#include <string>

using ContactVector = std::vector<class Contact>;

class Contact {
    private: 
        std::string firstName;
        std::string lastName;
        std::string phoneNum;
    public:
        Contact() : firstName("No"), lastName("Name"), phoneNum("123-456-7890") {} // Default constructor
        // Parameterized constructor passes by reference
        Contact(ContactVector &vectorName, const std::string &_newFirstName, const std::string &_newLastName, const std::string &_newPhoneNum)
            : firstName(_newFirstName), lastName(_newLastName), phoneNum(_newPhoneNum) { 
            vectorName.push_back(*this); // Adds new contact obj to vector
        }
        std::string getFirstName() const { return firstName; }
        std::string getLastName() const { return lastName; }
        std::string getPhoneNum() const { return phoneNum; }
        void setFirstName(std::string &newFirstName) { firstName = newFirstName; }
        void setLastName(std::string &newLastName) { lastName = newLastName; }
        void setPhoneNum(std::string &newPhoneNum) { phoneNum = newPhoneNum; }
        void 
};

int main() {
    ContactVector friends;
    int selection = 0; // Create error handling for this
    int lastIndexAdded = -1;
    std::string newFirstName, newLastName, newPhoneNum;

    while (selection != 3) {
        std::cout << "Phonebook App" << std::endl;
        std::cout << "----------------------------------" << std::endl;
        std::cout << "1) Add Friend" << std::endl;
        std::cout << "2) Delete Friend" << std::endl;
        std::cout << "3) Close Program" << std::endl;
        std::cout << "Make a selection (1-3): " << std::endl;
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

                Contact(friends, newFirstName, newLastName, newPhoneNum);

                lastIndexAdded++;

                std::cout << "----------------------------------" << std::endl;
                std::cout << "Current Index: " << lastIndexAdded << std::endl;
                std::cout << "First Name: " << friends.at(lastIndexAdded).getFirstName() << std::endl;
                std::cout << "Last Name: " << friends.at(lastIndexAdded).getLastName() << std::endl;
                std::cout << "Phone Number: " << friends.at(lastIndexAdded).getPhoneNum() << std::endl;
                std::cout << "----------------------------------" << std::endl;
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                std::cout << "Please enter a valid selection: " << std::endl;
        }

    }
    
    
}


