#include <cctype>   // Used for tolower() to make searches case-insensitive
#include <iostream> // Used for cin, cout, and endl
#include <limits>   // Used for numeric_limits to clear invalid user input
#include <string>   // Used for string variables and getline()
#include <fstream>  // Used for ifstream to read inventory from an external file
#include "Car.h"    // Includes the Car class and its functions
#include <queue>   // Used for queue to manage salespersons
using namespace std;

// Name: Nolan Michael Budzien

// Function declarations
void carsOnLot(Car myCars[]);
void carsSold(Car myCars[]);
void grossSales(Car myCars[]);
void searchForCar(Car myCars[]);
string toLower(string text);
void addInventory(Car myCars[]);
string nextSalesPersons(queue<string>& salesPersons);
// Input: The user's menu choices and any search details they enter.
// Process: Creates a sample inventory and runs the selected dealership action
//          until the user chooses Exit or ends the input.
// Return value: Zero when the program finishes.
int main() {
    //array of car objects/inventory
    Car myCars[10];
    //queue of salespersons
    queue<string> salesPersons;
    //pushes the names of the salespersons into the queue, names are arbitrary and not affiliated with any real dealerships
    salesPersons.push("John");
    salesPersons.push("Jane");
    salesPersons.push("Bob");
    salesPersons.push("Alice");
    salesPersons.push("Mike");

    //loads the inventory from the external file
    addInventory(myCars);

    int input = -1;
    //Random name I came up with on the spot because you said we needed a dealership name.
    //It seemed fitting for a car dealership. I am not affiliated with any real dealerships. 
    cout << "\nWelcome to Dougs Deals Dealership!\n\n";

    do {
        cout << "1. View all vehicles on the lot\n"
             << "2. View all vehicles sold\n"
             << "3. View total sales amount\n"
             << "4. Search for a Car\n"
             << "5. Get a salesperson\n"
             << "6. Exit\n"
             << "Enter your choice: ";

        cin >> input;

        // Exit if the input ended before a choice could be read.
        if (cin.eof() && cin.fail()) {
            return 0;
        }//end if

        cout << endl;

       // Handle input that could not be read as a whole number, such as "abc".
    if (cin.fail()) {
        // Reset the error flag so the program can read input again.
        cin.clear();
        // Discard the rest of the invalid input line, including the newline.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Set an invalid menu choice so the program displays an error and prompts again.
        input = -1;
    }//end if
        //proforms the task based on their selection
        if (input == 1) {
            carsOnLot(myCars);
        }//end if
        else if (input == 2) {
            carsSold(myCars);
        }//end else if
        else if (input == 3) {
            grossSales(myCars);
            cout << endl;
        }//end else if
        else if (input == 4) {
            searchForCar(myCars);
        }//end else if
        else if (input ==5){
            cout << "Next available Salesperson: " << endl;
            //displays the names of the available salespersons in the queue
            cout << nextSalesPersons(salesPersons) << "\n" << endl;
        }//end else if
        else if (input == 6) {
            cout << "Goodbye!";
        }//end else if
        else {
            cout << "\nInvalid choice. Try again.\n";
        }//end else

    } while (input != 6 && !cin.eof());

    return 0;
}//end main()

// Input parameter: A array of 10 car objects in the dealership inventory, including available and sold vehicles.
// Process: Displays the details of every vehicle still available on the lot.
// Return value: None.
void carsOnLot(Car myCars[]) {
    cout << "Cars On the Lot: \n" << endl;

    for (int i = 0; i < 10; i++) {
        if (myCars[i].getSold() == "No") {
            myCars[i].getInfo();
            cout << endl;
        }//end if
    }//end for
}//end carsOnLot()

// Input parameter: A array of 10 car objects in the dealership inventory, including available and sold vehicles.
// Process: Displays the details of every vehicle the dealership has sold.
// Return value: None.
void carsSold(Car myCars[]) {
    cout << "Sold Cars: \n" << endl;

    for (int i = 0; i < 10; i++) {
        if (myCars[i].getSold() == "Yes") {
            myCars[i].getInfo();
            cout << endl;
        }//end if
    }//end for
}//end carsSold()

// Input parameter: A array of 10 car objects in the dealership inventory, including available and sold vehicles.
// Process: Adds the prices of all sold vehicles and displays the total in dollars.
// Return value: None.
void grossSales(Car myCars[]) {
    int total = 0;

    for (int i = 0; i < 10; i++) {
        if (myCars[i].getSold() == "Yes") {
            total += myCars[i].getPrice();
        }//end if
    }//end for

    cout << "Gross Sales: $" << total << endl;
}//end grossSales()

// Input parameter: A array of 10 car objects in the dealership inventory, including sold vehicles.
// Process: Asks what vehicle detail to search by and displays every exact match.
//          Text searches ignore capitalization.
// Return value: None.
void searchForCar(Car myCars[]) {
    int choice = -1;
    int year = 0;
    string value;
    bool found = false;
    
    //displays the menu of characteristics to search for
    cout << "Search by:\n"
         << "1. Make\n"
         << "2. Model\n"
         << "3. Year\n"
         << "4. Color\n"
         << "5. Exit\n";

    do {
        //gets users choice
        cout << "Enter your choice: ";
        cin >> choice;

        // Return to the main menu if the input ended before a choice was read.
        if (cin.eof() && cin.fail()) {
            return;
        }//end if

        // Reset the stream and discards the bad line if the choice cannot be read as an integer.
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }//end if

        if (choice < 1 || choice > 5) {
            cout << "Invalid choice.\n";
        }//end if
    } while (choice < 1 || choice > 5); // repeats until a valid choice is selected
    //ends if user selects 5
    if (choice == 5) {
        return;
    }//end if

    if (choice == 3) {
        bool valid = false;
        do {
            cout << "Enter the year you're searching for: ";
            cin >> year;

            if (cin.eof() && cin.fail()) {
                return;
            }//end if
             // Reset the stream and discard the bad line if the choice cannot be read as an integer.
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid year. Please enter a number.\n";
            }//end if
            else if (year <= 0) {
                cout << "Please enter a positive year.\n";
            }//end else if
            else {
                valid = true;
            }//end else
        } while (!valid);// repeats until a valid input is selected
    }//end if
    else {
        if (choice == 1) {//make
            cout << "Enter the make you're searching for: ";
        }//end if
        else if (choice == 2) {//model
            cout << "Enter the model you're searching for: ";
        }//end else if
        else {//color
            cout << "Enter the color you're searching for: ";
        }//end else

        // Skip the newline left by the menu choice and any leading whitespace.
        // Then read the rest of the line, keeping spaces within the search text.
        if (!getline(cin >> ws, value)) {
            return;
        }//end if

        value = toLower(value);
    }//end else

    cout << endl;

    for (int i = 0; i < 10; i++) {
        if ((choice == 1 && toLower(myCars[i].getMake()) == value) ||
            (choice == 2 && toLower(myCars[i].getModel()) == value) ||
            (choice == 3 && myCars[i].getYear() == year) ||
            (choice == 4 && toLower(myCars[i].getColor()) == value)) {

            myCars[i].getInfo();
            cout << endl;
            found = true;
        }//end if
    }//end for
    //no cars found in the search 
    if (!found) {
        cout << "No matching cars found.\n";
    }//end if
}//end searchForCar()

// Input parameter: A vehicle detail or search phrase to compare without
//                  regard to capitalization.
// Process: Converts uppercase letters to lowercase in a copy of the text.
// Return value: The copy used for case-insensitive comparison.
string toLower(string text) {
    for (char& character : text) {
        // The inner cast prevents negative char values from reaching tolower.
        // The outer cast converts the returned integer back to a character.
        character = static_cast<char>(
            std::tolower(static_cast<unsigned char>(character))
        );
    }//end for

    return text;
}//end toLower()

// Input parameter: The array of 10 car objects to fill with inventory.
// Process: Opens an external file, skips the instructions, and reads
//          the vehicle information into the array.
// Return value: None, modifys the array of car objects
void addInventory(Car myCars[]) {
    ifstream inFS;
    //Variables for each car's information
    int price;
    int year;
    string model;
    string make;
    bool isSold;
    string color;
    string fuelType;
    string skipLine;

    //open the inventory file
    inFS.open("inventory.txt");

    //check if the file opened successfully
    if (!inFS.is_open()) {
        cout << "Could not open inventory.txt" << endl;
        return;
    }//end if

    //skip instructions until the "END INSTRUCTIONS" marker
    bool foundEnd = false;

    while (getline(inFS, skipLine)) {
        if (skipLine == "END INSTRUCTIONS") {
            foundEnd = true;
            break;
        }//end if
    }//end while

    //check if the end of the instructions was found
    if (!foundEnd) {
        cout << "Could not find END INSTRUCTIONS." << endl;
        inFS.close();
        return;
    }//end if

    //read the information for each car
    for (int i = 0; i < 10; i++) {

        //read price and year
        inFS >> price;
        inFS >> year;

        //read model and make
        inFS >> ws; //ws skips any leading whitespace 
        getline(inFS, model);
        getline(inFS, make);

        //read sold status
        inFS >> isSold;// 0 = false, 1 = true

        //read color and fuel type
        inFS >> ws; //ws skips any leading whitespace
        getline(inFS, color);
        getline(inFS, fuelType);

        //check if reading the file failed
        if (inFS.fail()) {
            cout << "Error reading inventory." << endl;
            break;
        }//end if

        //create a car using the information from the file
        myCars[i] = Car(price, year, model, make,
                        isSold, color, fuelType);

    }//end for

    //close the file
    inFS.close();

}//end addInventory()

// Input parameter: A queue of salespersons to manage their availability.
// Process: Retrieves the name of the next available salesperson, removes them from the front of the queue, and adds them to the back of the queue. 
// Return value: The name of the next available salesperson.
string nextSalesPersons(queue<string>& salesPersons){
    //checks if the queue is empty, if it is, returns a message indicating that there are no available salespersons
    if (salesPersons.empty()) {
        return "No available salespersons.";
    }//end if
    //stores the name of the next available salesperson
    string nextSalesPerson = salesPersons.front();
    //removes the next available salesperson from the front of the queue and adds them to the back of the queue
    salesPersons.pop();
    salesPersons.push(nextSalesPerson);
    //returns the name of the next available salesperson
    return nextSalesPerson;
}//end nextSalesPersons()