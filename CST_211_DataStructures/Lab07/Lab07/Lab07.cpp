/*************************************************************
* Author: Kayleb Cook
* Filename: Lab07 
* Date Created: 1/30/2025
* Modifications:
*   - 1/30: Started Lab
*   - 1/31: Finished Lab & Made comments
**************************************************************/

/*************************************************************
*
* Lab/Assignment: Lab07 - LinkedList Based Stack
*
* Overview:
* This program's main function is to create a stack class based on 
* our linkedlist class made in Lab02. The program will have the basic
* stack functions such as Push, Pop, and Peek, and more for the sake of
* testing the function. We will use the LinkedList class to create our
* stack object, and then use the functions there to create the stack 
* based program
*
* Input:
* The input of the function is based on the created test functions. The
* stack based program must take in both regular and complex data types, and
* pass all the tests provided that test each fucnction, including manager functions
* and assignment operators. 
*
* Output:
* The output for this program will be if it passes each test, it should look
* something like this:
* Manager Functions Tests Passed
* Push Tests Passed
* Pop Tests Passed
* Peek Tests Passed
* Get Number of Elements Tests Passed
* isEmpty Tests Passed
*
* Now Testing Complex Data Members:
* Manager Functions Tests w/ Complex Data Passed
* Push Tests w/ Complex Data Passed
* Pop Tests w/ Complex Data Passed
* Peek Tests w/ Complex Data Passed
* Get Number of Elements Tests w/ Complex Data Passed
* isEmpty Tests  w/ Complex Data Passed
* All Tests Passed!
*
************************************************************/

bool managerFunctionsTest();
bool PushTest();
bool PopTest();
bool PeekTest();
bool getNumberOfElementsTest();
bool IsEmptyTest();
// Complex Functions:
bool managerFunctionsTestComplex();
bool PushTestComplex();
bool PopTestComplex();
bool PeekTestComplex();
bool getNumberOfElementsTestComplex();
bool IsEmptyTestComplex();


#include <iostream>
#include "Stack.h"

int main()
{
    int passed = 0;
    try
    {
        if (managerFunctionsTest() == true)
        {
            std::cout << "Manager Functions Tests Passed\n";
            passed++;
        }
        else
        {
            std::cout << "Manager Functions Tests Failed\n";
        }
        if (PushTest() == true)
        {
            std::cout << "Push Tests Passed\n";
            passed++;
        }
        else
        {
            std::cout << "Push Tests Failed\n";
        }
        if (PopTest() == true)
        {
            std::cout << "Pop Tests Passed\n";
            passed++;
        }
        else
        {
            std::cout << "Pop Tests Failed\n";
        }
        if (PeekTest() == true)
        {
            std::cout << "Peek Tests Passed\n";
            passed++;
        }
        else
        {
            std::cout << "Peek Tests Failed\n";
        }
        if (getNumberOfElementsTest() == true)
        {
            std::cout << "Get Number of Elements Tests Passed\n";
            passed++;
        }
        else
        {
            std::cout << "Get Number of Elements Tests Failed\n";
        }
        if (IsEmptyTest() == true)
        {
            std::cout << "isEmpty Tests Passed\n\n";
            passed++;
        }
        else
        {
            std::cout << "isEmpty Tests Failed\n\n";
        }

        std::cout << "Now Testing Complex Data Members: \n";

        // Complex: 
        if (managerFunctionsTestComplex() == true)
        {
            std::cout << "Manager Functions Tests w/ Complex Data Passed\n";
            passed++;
        }
        else
        {
            std::cout << "Manager Functions Tests w/ Complex Data Failed\n";
        }
        if (PushTestComplex() == true)
        {
            std::cout << "Push Tests w/ Complex Data Passed\n";
            passed++;
        }
        else
        {
            std::cout << "Push Tests w/ Complex Data Failed\n";
        }
        if (PopTestComplex() == true)
        {
            std::cout << "Pop Tests w/ Complex Data Passed\n";
            passed++;
        }
        else
        {
            std::cout << "Pop Tests w/ Complex Data Failed\n";
        }
        if (PeekTestComplex() == true)
        {
            std::cout << "Peek Tests w/ Complex Data Passed\n";
            passed++;
        }
        else
        {
            std::cout << "Peek Tests w/ Complex Data Failed\n";
        }
        if (getNumberOfElementsTestComplex() == true)
        {
            std::cout << "Get Number of Elements Tests w/ Complex Data Passed\n";
            passed++;
        }
        else
        {
            std::cout << "Get Number of Elements Tests w/ Complex Data Failed\n";
        }
        if (IsEmptyTestComplex() == true)
        {
            std::cout << "isEmpty Tests  w/ Complex Data Passed\n";
            passed++;
        }
        else
        {
            std::cout << "isEmpty Tests w/ Complex Data Failed\n";
        }
    }
    catch (const std::exception& exception)
    {
        std::cout << "Exception Caught, Check Code!" << exception.what() << "\n";
    }

    if (passed == 12)
    {
        std::cout << "All Tests Passed!\n";
    }
    else
    {
        std::cout << 12 - passed << " Tests Have Been Failed\n";
    }
}

bool managerFunctionsTest()
{
    // Default Ctor: Create Stack
    Stack<int> stack;
    if (stack.isEmpty() != true) // test if the stack is empty, if it isnt, then the stack wasnt created
    {
        return false;
    }
    stack.Push(1); // adding some data
    stack.Push(4);
    stack.Push(98);
    // Copy Ctor: 
    Stack<int> copy(stack);
    if (stack.getNumOfElements() != copy.getNumOfElements() || stack.Peek() != copy.Peek()) // test if the copied stack is the same as the original one
    {
        return false;
    }
    // Move Ctor:
    Stack<int> move(std::move(stack));
    if (move.getNumOfElements() != copy.getNumOfElements() || move.Peek() != copy.Peek()) // test if the moved stack is the same as the original 
    {
        return false;
    }
    // Copy Assignment
    Stack<int> cAssign;
    cAssign = copy;
    if (cAssign.getNumOfElements() != copy.getNumOfElements() || cAssign.Peek() != copy.Peek()) // test if the copied stack is the same as the original
    {
        return false;
    }
    // Move Assignment
    Stack<int> mAssign;
    mAssign = std::move(copy);
    if (mAssign.getNumOfElements() != cAssign.getNumOfElements() || mAssign.Peek() != cAssign.Peek()) // test if the moved stack is the same as the original
    {
        return false;
    }
    return true;
}

bool PushTest()
{
    Stack<int> push;
    push.Push(5); // add some data to the stack
    push.Push(3);
    push.Push(6);
    push.Push(9);
    push.Push(11);
    push.Push(54); // last piece of data added to the stack
    if (push.Peek() != 54 || push.getNumOfElements() != 6) // test if the top of the stack is the same as the last one we added & test if the number of elements is the right amount
    {
        return false;
    }
    return true;
}

bool PopTest()
{
    Stack<int> pop;
    pop.Push(10); // add data 
    pop.Push(20);
    pop.Push(30);
    pop.Push(40);
    pop.Push(50); // last piece of data = 50
    if (pop.Pop() != 50 || pop.Peek() == 50) // test if the popped data is the same as the top of the stack & test if it was removed correctly 
    {
        return false;
    }
    return true;
}

bool PeekTest()
{
    Stack<int> peek;
    peek.Push(5);
    peek.Push(10);
    peek.Push(15);
    peek.Push(20); // last piece of data = 20
    if (peek.Peek() != 20) // test if the top of the stack is equal to the one we added last 
    {
        return false;
    }
    return true;
}

bool getNumberOfElementsTest()
{
    int NumberOfElements = 2;
    Stack<int> numElements;
    for (int e = 0; e < 5; e++) // add 5 pieces of data to the stack
    {
        numElements.Push(NumberOfElements);
        NumberOfElements = (NumberOfElements * NumberOfElements); // just for fun, make the numbers grow
    }
    if (numElements.getNumOfElements() != 5) // test if the number of elements is the same as the amount we added
    {
        return false;
    }
    return true;
}

bool IsEmptyTest()
{
    Stack<int> empty;
    if (empty.isEmpty() != true) // create a stack, and dont add anything. Then test if it is empty
    {
        return false;
    }
    for (int e = 0; e < 10; e++) // now add 10 items to the stack
    {
        empty.Push(5 * e);
        if (empty.isEmpty() == true)
        {
            return false;
        }
    }
    for (int e = 0; e < 10; e++) // then remove the 10 items
    {
        empty.Pop();
    }
    if (empty.isEmpty() != true) // check if the stack is empty now
    {
        return false;
    }
    return true;
}

// all complex are the same 
bool managerFunctionsTestComplex()
{
    // Default Ctor: Create Stack
    Stack<std::string> stack;
    stack.Push("red"); // adding some data
    stack.Push("green");
    stack.Push("blue");
    // Copy Ctor: 
    Stack<std::string> copy(stack);
    if (stack.getNumOfElements() != copy.getNumOfElements() || stack.Peek() != copy.Peek())
    {
        return false;
    }
    // Move Ctor:
    Stack<std::string> move(std::move(stack));
    if (move.getNumOfElements() != copy.getNumOfElements() || move.Peek() != copy.Peek())
    {
        return false;
    }
    // Copy Assignment
    Stack<std::string> cAssign;
    cAssign = copy;
    if (cAssign.getNumOfElements() != copy.getNumOfElements() || cAssign.Peek() != copy.Peek())
    {
        return false;
    }
    // Move Assignment
    Stack<std::string> mAssign;
    mAssign = std::move(copy);
    if (mAssign.getNumOfElements() != cAssign.getNumOfElements() || mAssign.Peek() != cAssign.Peek())
    {
        return false;
    }
    return true;
}

bool PushTestComplex()
{
    Stack<std::string> push;
    push.Push("5"); // add some data to the stack
    push.Push("3");
    push.Push("6");
    push.Push("9");
    push.Push("11");
    push.Push("last"); // last piece of data added to the stack
    if (push.Peek() != "last" || push.getNumOfElements() != 6)
    {
        return false;
    }
    return true;
}

bool PopTestComplex()
{
    Stack<std::string> pop;
    pop.Push("10"); // add data 
    pop.Push("20");
    pop.Push("30");
    pop.Push("40");
    pop.Push("last"); // last piece of data = 50
    if (pop.Pop() != "last")
    {
        return false;
    }
    return true;
}

bool PeekTestComplex()
{
    Stack<std::string> peek;
    peek.Push("5");
    peek.Push("10");
    peek.Push("15");
    peek.Push("last"); // last piece of data = 20
    if (peek.Peek() != "last")
    {
        return false;
    }
    return true;
}

bool getNumberOfElementsTestComplex()
{
    std::string NumberOfElements = "2";
    Stack<std::string> numElements;
    for (int e = 0; e < 5; e++)
    {
        numElements.Push(NumberOfElements);
    }
    if (numElements.getNumOfElements() != 5)
    {
        return false;
    }
    return true;
}

bool IsEmptyTestComplex()
{
    Stack<std::string> empty;
    if (empty.isEmpty() != true) // create a stack, and dont add anything. Then test if it is empty
    {
        return false;
    }
    for (int e = 0; e < 10; e++)
    {
        empty.Push("addMe");
        if (empty.isEmpty() == true)
        {
            return false;
        }
    }
    for (int e = 0; e < 10; e++)
    {
        empty.Pop();
    }
    if (empty.isEmpty() != true)
    {
        return false;
    }
    return true;
}