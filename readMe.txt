Big Project – Individual Dealership
CSC 1061 | Computer Science II (C++) | Class Coding Final

My Role as Architect:
    I served as the class architect for the dealership project. When we received the prompt, I led the class 
    discussion to clarify what the program needed to do and turn the prompt into a set of requirements. I guided
    the discussion about how the program should work and made the final decisions on the overall design and how
    the features would fit together and be implemented. Once we had a shared plan, each student wrote their own code 
    independently. I followed that plan when building my version of the program.


Part 1 – Dealership Requirements

Prompt:

    The customer owns an automobile dealership. We are hired to write a software application to handle inventory and sales of automobiles.

    User Stories

    - As the owner of a dealership, I want to know what vehicles are on my lot, their price, and which vehicles are being sold.
    - As a manager of a dealership, I need a list of vehicles in inventory, so my salespeople know what vehicles we have for immediate sale.
    - As a manager of a dealership, I need a list of vehicles that have been sold so I know what models to order from the manufacturer and 
      what to buy used for resale.
    - As a manager of a dealership, I want to know the gross sales.
    - As a car salesperson, I need to know what vehicles are on the lot so I can sell these vehicles.

My Implementation:

    I stored the dealership inventory in an array of 10 Car objects. I added separate menu options to view vehicles
    on the lot, view sold vehicles, and see the gross sales. The carsOnLot() and carsSold() functions use each vehicle's 
    sold status to decide which records to display. The grossSales() function adds the prices of the sold vehicles and 
    displays the total.


Part 2 – Search for a Car

Prompt:

    Search based on make, model, year, or color (e.g. display all the blue cars, display all the Fords, etc.).

My Implementation:  

    I wrote searchForCar() to let the user choose a field and enter a search value. The function checks every car in the 
    inventory and displays all exact matches. Make, model, and color searches ignore capitalization, so searching for "ford"
    also finds "Ford." Year searches compare the entered number with the vehicle's year. If there are no matches, the program 
    displays a message.


Part 3 – External File

Prompt:
    Load inventory from an external file.

My Implementation:
    I wrote addInventory() to open inventory.txt when the program starts. It skips the file's instructions until it reaches the 
    END INSTRUCTIONS marker. It then reads each car's price, year, model, make, sold status, color, and fuel type. The function 
    creates a Car object from each record and stores it in the inventory array. It displays an error if the file cannot be opened, 
    the marker is missing, or a record cannot be read.

Part 4 – Get a Salesperson

Prompt:
    - Who is the next salesperson to take this customer?
    - From a list of sales personnel (in order of helping a customer), select the next salesperson.
    - Once a salesperson helps a customer, they go to the back of the list.

My Implementation:
    I stored the salespeople's names in a queue in the order they would help customers. When the user selects option 5, 
    nextSalesPersons() gets the name at the front of the queue, removes it, and adds it to the back. The program then displays that name. 
    I pass the queue by reference so the updated order carries over to the next customer. For example, the rotation goes John, Jane, Bob, 
    Alice, Mike, and then back to John.