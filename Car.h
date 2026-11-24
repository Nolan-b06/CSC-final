#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;
// Name: Nolan Michael Budzien
class Car {
    private: 
        int price; //price of the car
        int year; //year the car was made
        string model; //model of the car
        string make; //make of the car
        bool isSold; //true if the car has been sold, false if it is still available
        string color; //color of the car
        string fuelType; //fuel type of the car (gas, diesel, electric, hybrid, etc.)
    public:
        //constructors
            Car();//defualt constructor
            Car(int price, int year, string model, string make, bool isSold, string color, string fuelType);//parameterized constructor

        //getters
            void getInfo(); // prints all of the cars info
            int getPrice(); // returns the cars price
            string getSold(); // returns yes or no depending on if the car is sold
            string getMake(); // returns the make
            string getModel(); // returns the model
            string getColor(); // returns the color
            int getYear(); //returns the year
         
}; // end class Car
#endif