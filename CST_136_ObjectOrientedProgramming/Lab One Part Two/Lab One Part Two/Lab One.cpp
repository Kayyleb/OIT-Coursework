// Name: Kayleb Cook
// Programming Assignment: Lab 2: Transport More Manager Functions

#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <string>
#include "Passenger.h"
#include "Transport.h"
#include "String.h"

// All Passing By Functions 
void passByPointer(Passenger* point) {}               //passing the memory address of the variable
void passByReference(Passenger& other) {}             //passing the variable as a reference, instead of a copy of it. Modifies the original variable.
void passByValue(Passenger point) {}                  //passing a copy of the varible. Does not modify the original variable
void passByConstReference(const Passenger& other) {}  //same as passing by reference, but combines constant data (not being able to modify the original variable)
void passByArray(Passenger passengerArray[], int size) {}
void passByTransport(Transport p) {}
// Class Functions
Passenger createPassenger()
{
    Passenger passenger(140, "Freddie", "Jones");
    return passenger;
}
Transport transportByValue()
{
    Transport transport;
    return transport;
}
Transport transportByReference(Transport& other) 
{
    Transport transport1;
    return transport1;
}

int main()
{
    // Instantiates two Passenger variables. Using a different constructor for each Passenger.
    std::cout << "1" << std::endl;
    Passenger passenger1;
    Passenger passenger2(140, "Freddie", "Jones");

    //Declares an array with four elements of your Passenger class.
    std::cout << "2" << std::endl;
    Passenger passengerArray[4] =
    {
        Passenger(46, "Richard", "Jordan"),
        Passenger(89, "Kyle", "MacLachlan"),
        Passenger(118, "Virginia", "Madsen"),
        Passenger(152, "Silvana", "Mangano")
    };

    //Instantiate a new Passenger object that uses another Passenger object for initialization.
    std::cout << "3" << std::endl;
    Passenger passenger3(passenger2);

    //Declares Passenger Pointer
    std::cout << "4" << std::endl;
    Passenger* point = nullptr;

    //Pass by pointer
    std::cout << "5" << std::endl;
    passByPointer(&passenger1);

    //Pass by reference
    std::cout << "6" << std::endl;
    passByReference(passenger1);

    //Pass by value
    std::cout << "7" << std::endl;
    passByValue(passenger1);

    //Pass by Const Reference
    std::cout << "8" << std::endl;
    passByConstReference(passenger1);

    //Pass by array
    std::cout << "9" << std::endl;
    passByArray(passengerArray, 4);

    //Allocates pointer memory
    std::cout << "10" << std::endl;
    point = new Passenger();

    //Deallocates the memory referenced by the pointer.
    std::cout << "11" << std::endl;
    delete point;

    //a function that instantiates a local Passenger object and then returns that object from the function.
    std::cout << "12" << std::endl;
    createPassenger();

    //Instantiates a Transport object using its default constructor.
    std::cout << "13" << std::endl;
    Transport transport1;

    //Pass a Transport by value to a function.
    std::cout << "14" << std::endl;
    Transport transport2;

    //Return a Transport by value from a function
    std::cout << "15" << std::endl;
    transportByValue();

    //In a single statement allocate a Transport and set it equal to a Transport returned by value from a function
    std::cout << "16" << std::endl;
    Transport transport5 = transportByValue();

    //In a single statement allocate a Transport and set it equal to a Transport returned by ref from a function
    std::cout << "17" << std::endl;
    Transport transport3 = transportByReference(transport1);

    //In a single statement set a previously allocated Transport equal to a Transport returned by value from a function
    std::cout << "18" << std::endl;
    transport1 = transportByValue();

    //In a single statement set a previously allocated Transport equal to a Transport returned by ref from a function
    std::cout << "19" << std::endl;
    transport1 = transportByReference(transport1);

    //Call the DisplayPassengers function to display all of the Passengers in the Transport .
    std::cout << "20" << std::endl;
    

    //Call Transport.MusicalChairs() then call the DisplayPassengers function to display all of the Passenger in the Transport.
    std::cout << "21" << std::endl;

    //Call Transport.MusicalChairs() then call the DisplayPassengers function to display all of the Passenger in the Transport.
    std::cout << "22" << std::endl;


}
