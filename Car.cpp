#include "Car.h"

// Name: Nolan Michael Budzien

//constructors-----------------------------------------------
//defualt constructor
Car::Car(){
    price = 0;
    year = 0;
    model = "N/A";
    make = "N/A";
    isSold = false;
    color = "N/A";
    fuelType = "N/A";
}//end defualt constructor

//parameterized constructor
Car::Car(int price, int year, string model, string make, bool isSold, string color, string fuelType){
    this->price = price;
    this->year = year;
    this->model = model;
    this->make = make;
    this->isSold = isSold;
    this->color = color;
    this->fuelType = fuelType;
}//end parameterized construcotr

//getters -----------------------------------------------------------------------------------------------
//input param: none
//process: Displays the car's year, make, model, price, sold status, color, and fuel type
//return: none
void Car::getInfo(){
    cout << "Year: " << year << endl; 
    cout<< "Make and Model: " << make << " " << model << endl;
    cout<< "price: $" << price << endl;
    cout<< "Is it sold: " << getSold() << endl; //used getSold() to display "Yes" or "No", instead of true or false
    cout<< "Color: " << color << endl;
    cout<< "Fuel Type: " << fuelType << endl;
}//end getInfo()

//input param: none
//process: Gets the car's price
//return: The car's price as an integer
int Car::getPrice(){
    return price;
}//end getPrice()

//input param: none
//process: Checks whether the car has been sold
//return: "Yes" if sold, or "No" if not sold
string Car::getSold(){
    if(isSold == true){
        return "Yes";
    }
    else{
        return "No";
    }
}//end getSold()

//input param: none
//process: Gets the car's make
//return: The car's make as a string
string Car::getMake() {
    return make;
}//end getMake()

//input param: none
//process: Gets the car's model
//return: The car's model as a string
string Car::getModel() {
    return model;
}//end getModel()

//input param: none
//process: Gets the car's color
//return: The car's color as a string
string Car::getColor() {
    return color;
}//end getColor()

//input param: none
//process: Gets the car's year
//return: The car's year as an integer
int Car::getYear() {
    return year;
}//end getYear()