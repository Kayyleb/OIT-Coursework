/*************************************************************
* Author: Kayleb Cook
* Filename: Lab06.cpp
* Date Created: 1/27/25
* Modifications:
*	1/27/25 - Created & Defined entire Stack class & wrote all tests
*	1/28/25 - Wrote all comment & comment blocks & checked for memory leaks
**************************************************************/

/*************************************************************
*
* Lab/Assignment: Lab 06 - Array Based Stack
*
* Overview:
* The purpose of this program is to create an Array based stack program.
* The program relies on our Array class made in Lab01, and creates another
* class that has stack like properties, like pushing onto the top, popping
* off the top, etc. 
*
* Input:
* No external input
* Test functions for all Manager Functions and Methods are included, and
* have their own inputs to test created a stack, puhing onto the stack, counting
* the elements in a stack, etc. 
*
* Output:
* The output outputs wether or not the test for each function is passed or not.
* Should look like this if all tests pass: 
* All Manager Functions tests passed
* Push tests passed
* Pop tests passed
* Peek tests passed
* NumElements tests passed
* GetSize tests failed
* SetSize tests passed
* IsEmpty tests passed
* IsFull tests passed
*
* All Manager Functions tests with Complex Data passed
* Push tests with Complex Data passed
* Pop tests with Complex Data passed
* Peek tests with Complex Data passed
* NumElements tests with Complex Data passed
* GetSize tests failed, with Complex Data
* SetSize tests with Complex Data passed
* IsEmpty tests with Complex Data passed
* IsFull tests with Complex Data passed
*
* All tests passed successfully, with Complex Data
*
************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Stack.h"
#include <cassert>

// Test function declarations
bool testManagerFunctions();
bool testPush();
bool testPop();
bool testPeek();
bool testNumElements();
bool testGetSize();
bool testSetSize();
bool testIsEmpty();
bool testIsFull();

bool testManagerFunctionsComplex();
bool testPushComplex();
bool testPopComplex();
bool testPeekComplex();
bool testNumElementsComplex();
bool testGetSizeComplex();
bool testSetSizeComplex();
bool testIsEmptyComplex();
bool testIsFullComplex();

int main() 
{       
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    int passed = 0;
    try {
        if (testManagerFunctions() == true)
        {
            std::cout << "All Manager Functions tests passed\n";
            passed++;
        }
        else
        {
            std::cout << "All Manager Functions tests failed\n";
        }
        
        if (testPush() == true) 
        {
            std::cout << "Push tests passed\n";
            passed++;
        }
        else 
        {
            std::cout << "Push tests failed\n";
        }
        
        if (testPop() == true) 
        {
            std::cout << "Pop tests passed\n";
            passed++;
        }
        else 
        {
            std::cout << "Pop tests failed\n";
        }

        if (testPeek() == true) 
        {
            std::cout << "Peek tests passed\n";
            passed++;
        }
        else 
        {
            std::cout << "Peek tests failed\n";
        }
        
        if (testNumElements() == true) 
        {
            std::cout << "NumElements tests passed\n";
            passed++;
        }
        else 
        {
            std::cout << "NumElements tests failed\n";
        }
        
        if (testGetSize() == true) 
        {
            std::cout << "GetSize tests passed\n";
            passed++;
        }
        else 
        {
            std::cout << "GetSize tests failed\n";
        }

        if (testSetSize() == true) 
        {
            std::cout << "SetSize tests passed\n";
            passed++;
        }
        else 
        {
            std::cout << "SetSize tests failed\n";
        }
        if (testIsEmpty() == true) 
        {
            std::cout << "IsEmpty tests passed\n";
            passed++;
        }
        else 
        {
            std::cout << "IsEmpty tests failed\n";
        }
        if (testIsFull() == true) 
        {
            std::cout << "IsFull tests passed\n";
            passed++;
        }
        else 
        {
            std::cout << "IsFull tests failed\n";
        }

        // just to seperate everything 
        std::cout << "\n";

        if (testManagerFunctionsComplex() == true)
        {
            std::cout << "All Manager Functions tests with Complex Data passed\n";
            passed++;
        }
        else
        {
            std::cout << "All Manager Functions tests failed, with Complex Data\n";
        }

        if (testPushComplex() == true)
        {
            std::cout << "Push tests with Complex Data passed\n";
            passed++;
        }
        else
        {
            std::cout << "Push tests failed, with Complex Data\n";
        }

        if (testPopComplex() == true)
        {
            std::cout << "Pop tests with Complex Data passed\n";
            passed++;
        }
        else
        {
            std::cout << "Pop tests failed, with Complex Data\n";
        }

        if (testPeekComplex() == true)
        {
            std::cout << "Peek tests with Complex Data passed\n";
            passed++;
        }
        else
        {
            std::cout << "Peek tests failed, with Complex Data\n";
        }

        if (testNumElementsComplex() == true)
        {
            std::cout << "NumElements tests with Complex Data passed\n";
            passed++;
        }
        else
        {
            std::cout << "NumElements tests failed, with Complex Data\n";
        }

        if (testGetSizeComplex() == true)
        {
            std::cout << "GetSize tests with Complex Data passed\n";
            passed++;
        }
        else
        {
            std::cout << "GetSize tests failed, with Complex Data\n";
        }

        if (testSetSizeComplex() == true)
        {
            std::cout << "SetSize tests with Complex Data passed\n";
            passed++;
        }
        else
        {
            std::cout << "SetSize tests failed, with Complex Data\n";
        }
        if (testIsEmptyComplex() == true)
        {
            std::cout << "IsEmpty tests with Complex Data passed\n";
            passed++;
        }
        else
        {
            std::cout << "IsEmpty tests failed, with Complex Data\n";
        }
        if (testIsFullComplex() == true)
        {
            std::cout << "IsFull tests with Complex Data passed\n";
            passed++;
        }
        else
        {
            std::cout << "IsFull tests failed, with Complex Data\n";
        }


        if (passed == 18)
        {
        std::cout << "\nAll tests passed successfully\n";
        }
        else 
        {
            passed = (16 - passed);
            std::cout << passed << " " << "tests failed\n";
        }

        }
        catch (const std::exception& exception)
        {
            std::cout << "Exception Caught, Check Code!" << exception.what() << "\n";
        }
        return 0;
    }
    


// Test default ctor, copy ctor, move ctor, move assignment, & copy assignment
bool testManagerFunctions() {
    
    Stack<int> s1; // Test default constructor by creating object
    s1.setSize(10);
    s1.Push(1);
    s1.Push(2);

    Stack<int> s2(s1); // Test copy constructor
    s2.setSize(10);

    // if the number of elements in the first stack doesnt match the ones in the second stack, then fail
    // if the top of the stack data in the first stack doesn't match the data in the second stack, then fail
    if (s2.getNumElements() != s1.getNumElements() && s2.Peek() != s1.Peek())
    {
        return false;
    }

    Stack<int> s3(std::move(s1)); // Test move constructor
    s3.setSize(10);

    // if the number of elements in the new stack doesn't equal the same amount in the previous, then fail
    // if the top of the new stack isn't the same as the old stack, then fail 
    if (s3.getNumElements() != 2 && s3.Peek() != 2)
    {
        return false;
    }

    Stack<int> s4;  // Test copy assignment operator
    s4.setSize(10);
    s4 = s2;

    // if the number of elements in the first stack doesnt match the ones in the second stack, then fail
    // if the top of the stack data in the first stack doesn't match the data in the second stack, then fail 
    if (s4.getNumElements() != s2.getNumElements() && s4.Peek() != s2.Peek())
    {
        return false;
    }

    Stack<int> s5;
    s5.setSize(10);
    s5 = std::move(s2);
 
    // if the number of elements in the new stack doesn't equal the same amount in the previous, then fail
    // if the top of the new stack isn't the same as the old stack, then fail 
    if (s5.getNumElements() != 2 && s5.Peek() != 2)
    {
        return false;
    }

    return true;
}

bool testPush() {
    Stack<int> PushTest;
    PushTest.setSize(10);

    
    // Test Push
    PushTest.Push(1); // push data onto stack
    PushTest.Push(2);
    PushTest.Push(3);
    
    // if the number of elements matches the number of elements pushed, then pass
    // if the top of the stack's data equals to the number pushed, then pass
    if (PushTest.getNumElements() == 3 && PushTest.Peek() == 3)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool testPop() {
    Stack<int> PopTest;
    PopTest.setSize(10);

    PopTest.Push(1); //push data onto the top of the stack
    PopTest.Push(2);
    PopTest.Push(3);

    //ifthe number popped off is the last number added & the number of elements has decreased by 1, & the top of the stack isnt the number popped, then pass
    if (PopTest.Pop() == 3 && PopTest.getNumElements() == 2 && PopTest.Peek() != 3)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool testPeek() {
    Stack<double> PeekTest;
    PeekTest.setSize(10);

    PeekTest.Push(1); //push data onto the top of the stack
    PeekTest.Push(2);
    PeekTest.Push(3);

    // if the top of the stack returned, is the last number added & the number of elements hasn't changed, then pass
    if (PeekTest.Peek() == 3 && PeekTest.getNumElements() == 3)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool testNumElements() {
    Stack<char> NumElementsTest;
    NumElementsTest.setSize(10);

    NumElementsTest.Push(1); //add data onto stack
    NumElementsTest.Push(2);
    NumElementsTest.Push(3);

    // if the number of elements matches the amount of numbers pushed onto the stack, then pass
    if (NumElementsTest.getNumElements() == 3)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool testGetSize()
{
    Stack<int> GetSizeTest;
    GetSizeTest.setSize(10);

    // if the size of the stack is the same to the amount set, then pass
    if (GetSizeTest.getSize() == 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

    bool testSetSize() 
    {
        Stack<int> SetSizeTest;
        SetSizeTest.setSize(10);

        SetSizeTest.setSize(2); // chanhe the size of the stack from 10 to 2

        // if the size of the stack is now 2, then pass
        if (SetSizeTest.getSize() == 2)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    bool testIsEmpty() {
        Stack<int> IsEmptyTest;
        IsEmptyTest.setSize(10);

        // Dont add any data, and if the stack is empty, then pass
        if (IsEmptyTest.isEmpty())
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    bool testIsFull() {
        Stack<int> IsFullTest;
        IsFullTest.setSize(2); // set size to two elements because im lazy
        IsFullTest.Push(1);    // push two numbers on
        IsFullTest.Push(2);

        // if the stack is full, then pass
        if (IsFullTest.isFull()) 
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    // Testing Complex, all functions are the same, but take in a string parameter
    bool testManagerFunctionsComplex() {
        // Test default constructor
        Stack<std::string> s1; // Create a stack object
        s1.setSize(10);
        s1.Push("hey");
        s1.Push("test");
        
        Stack<std::string> s2(s1); // Test copy constructor
        s2.setSize(10);

        if (s2.getNumElements() != s1.getNumElements() && s2.Peek() != s1.Peek())
        {
            return false;
        }

        Stack<std::string> s3(std::move(s1)); // Test move constructor
        s3.setSize(10);

        if (s3.getNumElements() != 2 && s3.Peek() != "test" && !s1.isEmpty())
        {
            return false;
        }

        Stack<std::string> s4; // Test copy assignment operator
        s4.setSize(10);
        s4 = s2;

        if (s4.getNumElements() != s2.getNumElements() && s4.Peek() != s2.Peek())
        {
            return false;
        }

        Stack<std::string> s5;
        s5 = std::move(s2);
        s5.setSize(10);

        if (s5.getNumElements() != 2 && s5.Peek() != "test" && !s2.isEmpty())
        {
            return false;
        }

        return true;
    }

    bool testPushComplex() 
    {
        Stack<std::string> PushTest;
        PushTest.setSize(10);
        PushTest.Push("hey"); // push data onto stack
        PushTest.Push("due");
        PushTest.Push("blue");

        if (PushTest.getNumElements() == 3 && PushTest.Peek() == "blue")
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool testPopComplex() 
    {
        Stack<std::string> PopTest;
        PopTest.setSize(10);

        PopTest.Push("hey");
        PopTest.Push("blue");
        PopTest.Push("green");
        if (PopTest.Pop() == "green" && PopTest.getNumElements() == 2 && PopTest.Peek() != "green")
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool testPeekComplex() 
    {
        Stack<std::string> PeekTest;
        PeekTest.setSize(10);

        PeekTest.Push("blue");
        PeekTest.Push("green");
        PeekTest.Push("red");
        if (PeekTest.Peek() == "red")
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool testNumElementsComplex() 
    {
        Stack<std::string> NumElementsTest;
        NumElementsTest.setSize(10);

        NumElementsTest.Push("green");
        NumElementsTest.Push("blue");
        NumElementsTest.Push("red");
        if (NumElementsTest.getNumElements() == 3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool testGetSizeComplex()
    {
        Stack<std::string> GetSizeTest;
        GetSizeTest.setSize(10);

        if (GetSizeTest.getSize() == 10)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool testSetSizeComplex()
    {
        Stack<std::string> SetSizeTest;
        SetSizeTest.setSize(10);
        SetSizeTest.setSize(2); // change the size of the stack from 10 to 2

        if (SetSizeTest.getSize() == 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool testIsEmptyComplex() 
    {
        Stack<std::string> IsEmptyTest;
        IsEmptyTest.setSize(10);

        if (IsEmptyTest.isEmpty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool testIsFullComplex() 
    {
        Stack<std::string> IsFullTest;
        IsFullTest.setSize(2);
        IsFullTest.Push("green");
        IsFullTest.Push("red");
        if (IsFullTest.isFull())
        {
            return true;
        }
        else
        {
            return false;
        }
    }