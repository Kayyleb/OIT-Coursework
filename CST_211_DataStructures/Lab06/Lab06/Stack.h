/*************************************************************
* Author: Kayleb Cook
* Filename: Lab06.cpp
* Date Created: 1/27/25
* Modifications:
*	1/27/25 - Created & Defined entire Stack class & wrote all tests
*	1/28/25 - Wrote all comment & comment blocks & checked for memory leaks
**************************************************************/

/************************************************************************
* Class: Stack
*
* Purpose: Creates an Array object  by calling array, then gives it stack
*          like properties, such as pushing data onto top of the stack,
*          popping data off the stack, etc.
*
* Manager functions:
*    Stack();
*       - Default Ctor
*    Stack(const Stack<T>& other);
*        - Copy Ctor
*    Stack(Stack<T>&& other) noexcept;
*        - Move Ctor
*    Stack<T>& operator=(const Stack<T>& other);
*        - Copy Assignment
*    Stack<T>& operator=(Stack<T>&& other) noexcept;
*        - Move Assignment
*    ~Stack();
*        - Default Dtor
* 
* Methods:
*    void Push(T data);
*        - Pushes the inputd data onto the top of the stack
*    T Pop();
*        - Pops the data off the top of the stack, returns it and removes it
*    T Peek() const;
*        - Returns the peek of the stack (top of the stack)
*    int getNumElements() const;
*        - Returns the number of elements in the stack
*    int getSize() const;
*        - Returns the size of the stack
*    void setSize(int new_size);
*        - Sets the size of the stack
*    bool isEmpty() const;
*        - Checks if the stack is empty
*    bool isFull() const;
*        - Checks if the stack is full
*
*************************************************************************/

#pragma once
#include "Array.h"
#include "Exception.h"
#include "string"

template <typename T>
class Stack {
private:
    Array<T> m_stack;
    int m_size;
    int m_top;

public: 
// Default Manager Functions
    Stack();
    Stack(const Stack<T>& other);
    Stack(Stack<T>&& other) noexcept;
    Stack<T>& operator=(const Stack<T>& other);
    Stack<T>& operator=(Stack<T>&& other) noexcept;
    ~Stack();

// Stack Functions
    void Push(T data);
    T Pop();
    T Peek() const;
    int getNumElements() const;
    int getSize() const;
    void setSize(int new_size);
    bool isEmpty() const;
    bool isFull() const;
};

/**********************************************************************
* Purpose: This function will create our stack object, and set it to a default
*          state so its ready to be used
*
* Precondition:
* No precondition
*
* Postcondition:
* Will create our stack aray object, and set it to default
*
************************************************************************/
template <typename T>
Stack<T>::Stack() : m_stack(), m_size(0), m_top(-1) // Base member initialization, set the stack to 0, the size to 0, and the top to -1 because the 
                                                    // stack is empty and c++ standard for array indexes is 0
{
}

/**********************************************************************
* Purpose: This function will create a copy of our stack object
*
* Precondition:
* Array's copy ctor must be defined, and ready to be called. Since our 
* stack object is derived from Array, it will use the Array's copy ctor
* to do all the copying
*
* Postcondition:
* Creates a brand new copy of our stack object by calling array's copy
* ctor and deep copying all the elements and variables into the new copy
*
************************************************************************/
template <typename T>
Stack<T>::Stack(const Stack<T>& other) : m_stack(other.m_stack), m_size(other.m_size), m_top(other.m_top) 
{
}

/**********************************************************************
* Purpose: This function will move our stack object to a new destination
*
* Precondition: 
* Array's move ctor must be defined, and ready to be called. Since our 
* stack object is derived from Array, it will use the Array's move ctor
* to do all the moving
*
* Postcondition:
* Moves our stack object to a new address, and deletes the old object, 
* making sure to set all variables to their default states. 
*
************************************************************************/
template <typename T>
Stack<T>::Stack(Stack<T>&& other) noexcept : m_stack(std::move(other.m_stack)), m_size(other.m_size), m_top(other.m_top)
{
    other.m_size = 0;
    other.m_top = -1;
}

/**********************************************************************
* Purpose: This function copies our stack object into an already 
* existing dedicated location
*
* Precondition:
* Array's copy assignment must be defined and correct, considering this is
* an Array object, it iwll call Array's copy assignment to do the work 
*
* Postcondition:
* Copies our stack object into an already existing address, so no new object
* is made. 
*
************************************************************************/
template <typename T>   
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (this != &other) {
        m_stack = other.m_stack;
        m_size = other.m_size;
        m_top = other.m_top;
    }
    return *this;
}

/**********************************************************************
* Purpose: This function moves our stack object into an already
* existing dedicated location
*
* Precondition:
* Array's move assignment must be defined and correct, considering this is
* an Array object, it iwll call Array's move assignment to do the work
*
* Postcondition:
* Moves our stack object into an already existing address, so no new object
* is made.
*
************************************************************************/
template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& other) noexcept
{
    if (this != &other) {
        m_stack = std::move(other.m_stack);
        m_size = other.m_size;
        m_top = other.m_top;

        other.m_size = 0;
        other.m_top = -1;
    }
    return *this;
}

/**********************************************************************
* Purpose: This function cleans up the Stack object when it is destroyed
*
* Precondition:
* Array's destrcutor must be defined, will call it to delete our stack object
* because our stack object is derived from Array
*
* Postcondition:
* Deletes the object, to ensure cleanup. Also sets the variables to their
* default state for safety cleanup as well
*
************************************************************************/
template <typename T>
Stack<T>::~Stack()
{
    m_size = 0;
    m_top = -1;
}

/**********************************************************************
* Purpose: This function pushes the inputed data onto the top of our
*          stack
*
* Precondition:
* Stack cannot be full
*
* Postcondition:
* Will check if the stack is full first
* If the stack isn't full, then it will increment the counter to allocate
* for the data being put in, then will insert the data at the top
*
************************************************************************/
template <typename T>
void Stack<T>::Push(T data)
{
    if (isFull()) // check if stack is full
    {
        throw Exception("Overflow! Stack is full.");
    }

    m_top++;               // Increment the top index 
    m_stack[m_top] = data; // Add the data to the top index of the stack
}

/**********************************************************************
* Purpose: This function pops the data off the top of the stack, and
*          returns it
*
* Precondition:
* Stack cannot be empty, will not have anything to pop off
*
* Postcondition:
* Will check if the stack is empty
* If the stack isn't empty, then it will copy the data at the top of the
* stack into our data variable, then decrement the top index counter because
* we're removing that data. Then lastly will return the data popped off
*
************************************************************************/
template <typename T>
T Stack<T>::Pop()
{
    if (isEmpty()) 
    {
        throw Exception("Underflow! Stack is empty.");
    }

    T data = m_stack[m_top];  // Get the data at the top of the stack index
    m_top--;                  // Decrement the top index
    return data;              // Return the data
}

/**********************************************************************
* Purpose: This function returns the data that's on top of the stack
*
* Precondition:
* Stack cannot be empty, or there will be nothing to return
*
* Postcondition:
* Will check if the stack is empty first
* If it isn't empty, will then return the data that is currently on the
* top of the stack. 
*
************************************************************************/
template <typename T>
T Stack<T>::Peek() const
{
    if (isEmpty())
    {
        throw Exception("Stack is empty");
    }
    return m_stack[m_top];    // Return the data at the top of the stack index
}

/**********************************************************************
* Purpose: This function will return the number of elements in the array
*
* Precondition:
* No precondition
*
* Postcondition:
* Will return the number of elements in the stack. 
* Since we use m_top to keep track of the top of the stack's index we can
* return that + 1, because index in c++ starts at 0, we add 1 to make up
* for that. 
*
************************************************************************/
template <typename T>
int Stack<T>::getNumElements() const
{
    return m_top + 1;          // Return the top of the stack's index + 1 to make up for index starting at 0
}

/**********************************************************************
* Purpose: This function will return the size of the array
*
* Precondition:
* No precondition other than the stack's size must be initialized
*
* Postcondition:
* Will return the size of the stack
*
************************************************************************/
template <typename T>
int Stack<T>::getSize() const
{
    return m_size;              // Return the size of the stack
}   

/**********************************************************************
* Purpose: This function will set the size of the stack to a desired input
*
* Precondition:
* The inputed size cannot be negative
*
* Postcondition:
* Will call Array's set length function to set the length of the "array" stack
* with the new inputed size. The array function will create a new array with the
* same data and new size, then deep copy all elements into it and delete the old array
* This is to ensure there is no junk thrown in or our when the new size is
* shorter than before or longer than before.
*
************************************************************************/
template <typename T>
void Stack<T>::setSize(int new_size)
{
    if (new_size <= 0)
    {
        throw Exception("Index cant be negative");
    }
    m_stack.setLength(new_size);// Call setLength to properly set the size of the "array" stack object
    m_size = new_size;          // Set the size of the stack to the new size

    if (m_top >= m_size)        // If the top of the stack's index is out of bounds
    {
        m_top = m_size - 1;     // Reset the index to the correct size.
    }                           // If the stack is full, then the top index should always be 1 less than the size value
}

/**********************************************************************
* Purpose: This function is to check if the stack is empty
*
* Precondition:
* No precondition
*
* Postcondition:
* If the stack is empty, will return true.
* If the stack isn't, will return false
* Checks by checking if m_top is equal to its default state (-1), if it is
* then we know the stack is empty
************************************************************************/
template <typename T>
bool Stack<T>::isEmpty() const
{
    if (m_top == -1) // if top index is -1 (default state)
    {
        return true; // then theres nothing on the stack, return true
    }
    return false;    // if not, then it isn't empty
}   

/**********************************************************************
* Purpose: This function will check if the stack is full
*
* Precondition:
* No precondition
*
* Postcondition:
* If the stack is full, returns true
* If the stack isn't, returns false
* Checks by checking if the top index is the same as the size -1, if it is
* then we know the stack is full
*
************************************************************************/
template <typename T>
bool Stack<T>::isFull() const
{
    if (m_top == m_size - 1)    // if the top index is equal to the size -1
    {
        return true;            // then the stack is full, return true
    }
    return false;               // if not, then it's not full yet
}





