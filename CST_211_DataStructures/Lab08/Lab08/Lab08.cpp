/*************************************************************
* Author: Kayleb Cook
* Filename: Lab08
* Date Created: 2/1/2025
* Modifications:
*   - 2/1: Started Lab, made class and most of test functions
*   - 2/2: Finished Lab & Made comments
**************************************************************/

/*************************************************************
*
* Lab/Assignment: Lab08 - LinkedList Based Queue
*
* Overview:
* This program's function is to create a Queue class that is based on our doubly
* linked list class to create the queue object. We will give it the same properties
* as a queue using the functions of the linked list class such as Append for Enqueue.
*
* Input:
* The input of the function is based on the created test functions. The
* queue based program must take in both regular and complex data types, and
* pass all the tests provided that test each fucnction, including manager functions
* and assignment operators.
*
* Output:
* Manager Function Test Passed
* Enqueue Function Test Passed
* Dequeue Function Test Passed
* Peek Function Test Passed
* GetNumberOfElements Function Test Passed
* IsEmpty Function Test Passed
* Manager Function Test Complex Passed
* Enqueue Function Test Complex Passed
* Dequeue Function Test Complex Passed
* Peek Function Test Complex Passed
* GetNumberOfElements Function Test Complex Passed
* IsEmpty Function Test Complex Passed
* All Tests Passed!
*
************************************************************/

#include <iostream>
#include "Queue.h"

bool testManagerFunctions();
bool testEnqueue();
bool testDequeue();
bool testPeek();
bool testGetNumberOfElements();
bool testIsEmpty();

bool testManagerFunctionsComplex();
bool testEnqueueComplex();
bool testDequeueComplex();
bool testPeekComplex();
bool testGetNumberOfElementsComplex();
bool testIsEmptyComplex();

int main()
{
    int pass = 0;
    try { 
        if (testManagerFunctions() == true)
        {
            std::cout << "Manager Function Test Passed \n";
            pass++;
        }
        else
        {
            std::cout << "Manager Function Test Failed\n";
        }
        if (testEnqueue() == true)
        {
            std::cout << "Enqueue Function Test Passed \n";
            pass++;
        }
        else
        {
            std::cout << "Enqueue Function Test Failed\n";
        }
        if (testDequeue() == true)
        {
            std::cout << "Dequeue Function Test Passed \n";
            pass++;
        }
        else
        {
            std::cout << "Dequeue Function Test Failed\n";
        }
        if (testPeek() == true)
        {
            std::cout << "Peek Function Test Passed \n";
            pass++;
        }
        else
        {
            std::cout << "Peek Function Test Failed\n";
        }
        if (testGetNumberOfElements() == true)
        {
            std::cout << "GetNumberOfElements Function Test Passed \n";
            pass++;
        }
        else
        {
            std::cout << "GetNumberOfElements Function Test Failed\n";
        }
        if (testIsEmpty() == true)
        {
            std::cout << "IsEmpty Function Test Passed \n";
            pass++;
        }
        else
        {
            std::cout << "IsEmpty Function Test Failed\n";
        }

        if (testManagerFunctionsComplex() == true)
        {
            std::cout << "Manager Function Test Complex Passed \n";
            pass++;
        }
        else
        {
            std::cout << "Manager Function Test Complex Failed\n";
        }
        if (testEnqueueComplex() == true)
        {
            std::cout << "Enqueue Function Test Complex Passed \n";
            pass++;
        }
        else
        {
            std::cout << "Enqueue Function Test Complex Failed\n";
        }
        if (testDequeue() == true)
        {
            std::cout << "Dequeue Function Test Complex Passed \n";
            pass++;
        }
        else
        {
            std::cout << "Dequeue Function Test Complex Failed\n";
        }
        if (testPeek() == true)
        {
            std::cout << "Peek Function Test Complex Passed \n";
            pass++;
        }
        else
        {
            std::cout << "Peek Function Test Complex Failed\n";
        }
        if (testGetNumberOfElements() == true)
        {
            std::cout << "GetNumberOfElements Function Test Complex Passed \n";
            pass++;
        }
        else
        {
            std::cout << "GetNumberOfElements Function Test Complex Failed\n";
        }
        if (testIsEmpty() == true)
        {
            std::cout << "IsEmpty Function Test Complex Passed \n";
            pass++;
        }
        else
        {
            std::cout << "IsEmpty Function Test Complex Failed\n";
        }
    }
    catch (const std::exception& exception)
    {
        std::cout << "Exception Caught, Check Code!" << exception.what() << "\n";
    }
    if (pass == 12)
    {
        std::cout << "All Tests Passed!\n";
    }
    else
    {
        std::cout << 12 - pass << " tests were failed!\n";
    }
}

bool testManagerFunctions()
{
    Queue<int> queue; // testing default ctor; create object
    if (queue.isEmpty() == false)
    {
        return false;
    }
    for (int e = 0; e < 10; e++) {queue.Enqueue(5 * e);} // add some data to the queue for testing 
    Queue<int> copy(queue); // testing copy ctor
    if (copy.getNumElements() != queue.getNumElements() && copy.Peek() != queue.Peek())
    {
        return false;
    }
    Queue<int> move(std::move(copy)); // testing move ctor
    if (move.getNumElements() != queue.getNumElements() && move.Peek() != queue.Peek())
    {
        return false;
    }
    Queue<int> cAssign; // testing copy assignment
    cAssign = queue;
    if (cAssign.getNumElements() != queue.getNumElements() && cAssign.Peek() != queue.Peek())
    {
        return false;
    }
    Queue<int> mAssign; // testing move assignment
    mAssign = std::move(cAssign);
    if (mAssign.getNumElements() != queue.getNumElements() && mAssign.Peek() != queue.Peek())
    {
        return false;
    }


    return true;
}

bool testEnqueue()
{
    Queue<int> enqueue;
    for (int e = 0; e < 10; e++) { enqueue.Enqueue(5 * e); } // testing enqueue
    if (enqueue.getNumElements() != 10 && enqueue.isEmpty() == true && enqueue.Peek() != 50)
    {
        return false;
    }
    return true;
}

bool testDequeue()
{
    Queue<int> dequeue;
    for (int e = 0; e < 10; e++) { dequeue.Enqueue(5 * e); }
    // Dequeueing one item
    dequeue.Dequeue();
    if (dequeue.getNumElements() == 10 && dequeue.isEmpty() == true && dequeue.Peek() == 50)
    {
        return false;
    }
    // Dequeueing multiple items
    for (int e = 0; e < 9; e++) { dequeue.Dequeue(); }
    if (dequeue.isEmpty() == false)
    {
        return false;
    }
    return true;
}

bool testPeek()
{
    Queue<int> peek;
    for (int e = 0; e < 11; e++) 
    { 
        peek.Enqueue(5 * e); 
    }
    if (peek.Peek() != 0 && peek.Dequeue() != 0)
    {
        return false;
    }
    return true;
}

bool testGetNumberOfElements()
{
    Queue<int> number;
    for (int e = 0; e < 150; e++) { number.Enqueue(5 * e); }
    if (number.getNumElements() != 150 && number.Dequeue() != 750)
    {
        return false;
    }
    return true;
}

bool testIsEmpty()
{
    Queue<int> empty;
    if (empty.isEmpty() != true)
    {
        return false;
    }
    empty.Enqueue(5);
    if (empty.isEmpty() != false)
    {
        return false;
    }
    empty.Dequeue();
    if (empty.isEmpty() != true)
    {
        return false;
    }
    return true;
}

// complex functions: 
bool testManagerFunctionsComplex()
{
    Queue<std::string> queue; // testing default ctor; create object
    if (queue.isEmpty() == false)
    {
        return false;
    }
    for (int e = 0; e < 10; e++) { queue.Enqueue("test"); } // add some data to the queue for testing 
    Queue<std::string> copy(queue); // testing copy ctor
    if (copy.getNumElements() != queue.getNumElements() && copy.Peek() != queue.Peek())
    {
        return false;
    }
    Queue<std::string> move(std::move(copy)); // testing move ctor
    if (move.getNumElements() != queue.getNumElements() && move.Peek() != queue.Peek())
    {
        return false;
    }
    Queue<std::string> cAssign; // testing copy assignment
    cAssign = queue;
    if (cAssign.getNumElements() != queue.getNumElements() && cAssign.Peek() != queue.Peek())
    {
        return false;
    }
    Queue<std::string> mAssign; // testing move assignment
    mAssign = std::move(cAssign);
    if (mAssign.getNumElements() != queue.getNumElements() && mAssign.Peek() != queue.Peek())
    {
        return false;
    }


    return true;
}

bool testEnqueueComplex()
{
    Queue<std::string> enqueue;
    for (int e = 0; e < 10; e++) { enqueue.Enqueue("test"); } // testing enqueue
    if (enqueue.getNumElements() != 10 && enqueue.isEmpty() == true && enqueue.Peek() != "test")
    {
        return false;
    }
    return true;
}

bool testDequeueComplex()
{
    Queue<std::string> dequeue;
    for (int e = 0; e < 10; e++) { dequeue.Enqueue("test"); } 
    dequeue.Enqueue("TESTLASTELEMENT");
    // Dequeueing one item
    dequeue.Dequeue();
    if (dequeue.getNumElements() == 10 && dequeue.isEmpty() == true && dequeue.Peek() == "TESTLASTELEMENT")
    {
        return false;
    }
    // Dequeueing multiple items
    for (int e = 0; e < 9; e++) { dequeue.Dequeue(); }
    if (dequeue.isEmpty() == false)
    {
        return false;
    }
    return true;
}

bool testPeekComplex()
{
    Queue<std::string> peek;
    peek.Enqueue("TESTFIRSTTELEMENT");
    for (int e = 0; e < 10; e++) { peek.Enqueue("test"); }
    if (peek.Peek() != "TESTFIRSTTELEMENT" && peek.Dequeue() != "TESTFIRSTTELEMENT")
    {
        return false;
    }
    return true;
}

bool testGetNumberOfElementsComplex()
{
    Queue<std::string> number;
    for (int e = 0; e < 150; e++) { number.Enqueue("test"); }
    number.Enqueue("TESTLASTELEMENT");
    if (number.getNumElements() != 150 && number.Dequeue() != "TESTLASTELEMENT")
    {
        return false;
    }
    return true;
}

bool testIsEmptyComplex()
{
    Queue<std::string> empty;
    if (empty.isEmpty() != true)
    {
        return false;
    }
    empty.Enqueue("test");
    if (empty.isEmpty() != false)
    {
        return false;
    }
    empty.Dequeue();
    if (empty.isEmpty() != true)
    {
        return false;
    }
    return true;
}

    
