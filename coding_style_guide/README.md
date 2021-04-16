# Project Coding Style Guide

- [Getting Started](#Getting-Started)
    - [Include Guard](#Include-Guard)
    - [Code Layout](#code-layout)

- [Classes](#Classes)
    - [Layout](#Layout)

- Functions

- Statements

- [Naming](#naming)
    - [Variables](#variables)
    - [Constants](#constants)
    - [Functions](#functions)
    - [Classes](#classes)
    - [Enumerators](#enumerators)
    - [Files](#files)

- [Comments](#Comments)
    - [Single-Line Comments](#[Single-Line-Comments)
    - [Multi-Line Comments](#[Multi-Line-Comments)

- [Formatting](#Formatting)
    - [Brackets](#Brackets)
    - [Separating Lines](#Separating-Lines)
    - [Avoiding Abundance](#Avoiding-Abundance)

- [Optimisations](#Optimisations)

The order (but not the style) generally follows Google C++ Style Guide: https://google.github.io/styleguide/cppguide

----------------------------------------------------------------

## Getting Started

### Include Guard

Header files must start with one of the following:

``` C++
#pragma once
```

or

``` C++
#ifndef FILE_NAME_HPP // corresponding to 'file_name.hpp'
#define FILE_NAME_HPP

// ...

#endif
```

### Code Layout

The general layout of the start of a file should follow as shown:

``` C++
#pragma once // 1. include guard

#include <iostream> // 2. standard libraries
#include <fstream>
#include <vector>
#include "nnet.hpp" // 3. cutom libraries
#include "launcher.hpp"

#define MAX_ARR_SIZE 2048 // 4. macro
#define MAX_VEC_SIZE 128

using namespace std; // 5. namespace
```




## Classes

### Layout

- A header file should contain only one class
- Function definitions are defined separately, in the same file
- General layout for a class is shown below:

``` C++
#ifndef YOUR_CLASS_NAME_HPP // include guard (or use #pragma)
#define YOUR_CLASS_NAME_HPP

class YourClassName
{
public: // 'public' before 'private'
    YourClassName();
    YourClassName(int);
    ~YourClassName();

    void fcn1();
    void fcn2();

    // function overload:
    int fcn3(int);
    int fcn3(int, int);
    int fcn3(double);

private:
    void printError();
};

YourClassName::YourClassName() // function definitions
{
    // ...
}

void YourClassName::fcn1()
{
    // ...
}

// ...

#endif // end of include guard (not needed for #pragma)
```





## Functions

### (...)


## Statements

### if Statement

### Ternary Operator

### for Statement

### while Statement






## Naming

Variable names should be short, simple but clear. Example formats for different types are: CamelCase, camelCase, lower_case, and UPPER_CASE.

### Variables

``` C++
bool isEven;        // camelCase

int count = 0;      // not 'countValidNums'
int i, j;           // not 'iterator' or 'i1', 'i2'
int numOfPeople;    // not 'num_of_people'

string names[8];    // not 'stringNames' or 'strNames'
```

### Constants

``` C++
#define MAX_ROW 16 // UPPER_CASE
#define MAX_COL 10

const int SIZE_OF_ARR = 8;
const double PI = 3.14159;
```

### Functions

``` C++
int getTotalNumber();       // getter, camelCase
void setCount(int count);   // setter

string toString;            // converter

bool isValidName(int n);    // boolean return
bool containsPrime(int n[]) // boolean return
```

### Parameters

``` C++

```

### Classes

``` C++
class EntityBase { /* ... */ }; // CamelCase
class PlayerData { /* ... */ };
class BoardGraphics { /* ... */ };
```

### Enumerators

``` C++
enum EColours { /* ... */ }; // ECamelCase
enum EDataType { /* ... */ };
enum EPlayerType { /* ... */ };
```

### Files

``` C++
main.cpp // lower_case.extension
test.c
header.hpp
header.h
game_launcher.hpp
graphics_manager.hpp
```







## Comments

### Single-Line Comments

Comment the general flow of your code:

``` C++
int isPrime(int n)
{
    // check divisibility upto sqrt(n)
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n % i == 0)
            return 0;
    }

    // is a prime if n has no proper factor
    return 1;
}

// rather than

// is prime
int isPrime(int n) // takes the parameter as n
{ // function starts
    for(int i=2; i<=sqrt(n); i++) // iterates from 2 to sqrt(n)
    { // for starts
        if(n % i == 0) // divide by i and check if i devides n
            return 0; // return true if divisible
    } // for ends

    return 1; // return true if there is no proper factor
} // function ends
```
Commenting side notes:

``` C++
if(i > threshold)
// ... 
else if(i < threshold)
// ... 
else // (i == threshold)
// ... 
```

### Multi-Line Comments

Commenting out a bit chunk of unused or test code:

``` C++
/*void printErrMsg(string fcn, string msg)
{
    cout << "[error] " << fcn << ": " << msg << endl;
}*/
```





## Formatting

### Brackets

Any bracket style can be used as long as used consistently:

``` C++
int main()
{

}

// or

int main() {

}
```

One-line statements can omit brackets:

``` C++
if(condition1)
{
    setMessage(msg);
}

// or

if(condition1)
    setMessage(msg);
```

Brackets used in-line should be consistent:

``` C++
if(conditionA) // okay
    i++;
else
    j++;

if(conditionB) // okay
{
    i++;
    setMessage(msg);
}
else
{
    j++;
}

if(conditionB) // not okay
{
    i++;
    setMessage(msg);
}
else
    j++;
```

### Separating Lines

Long horizontal code can be separated vertically:

``` C++
// too long
cout << "(" <<  num1 << " + " << num2 << ") / 2 = " << (num1 + num2) / 2 << endl;

// easier to see
cout << "(" <<  num1
     << " + " << num2
     << ") / 2 = " << (num1 + num2) / 2 << endl;

int getPlayerRanking(PlayerBase playerBase, GameManager gameManager, int currentRanking, int previousRanking)
{
    // this is too long
}

int getPlayerRanking(PlayerBase playerBase, GameManager gameManager,
                     int currentRanking, int previousRanking)
{
    // this is a bit shorter
}

int getPlayerRanking(PlayerBase player, GameManager game, int currRanking, int prevRanking)
{
    // another solution: shorter variable names
}
```

### Avoiding Abundance

Some statements have short-handed notations:

``` C++
i = i + j;
i += j; // better

k = k + 1;
k++; // better

// similarly -=, *=, /=, <<=, ^=, |=, etc.
```

Some if-else statements can be rewritten using the ternary statement:

``` C++
max = (num1 > num2)? num1 : num2;

// rather than

if(num1 > num2)
    max = num1;
else
    max = num2;
```

Boolean values can be returned directly:

``` C++
int isOdd(int n)
{
    return n % 2;
}

// rather than

int isOdd(int n)
{
    if(n % 2 == 1)
        return 1;
    else
        return 0;
}

if(node->right)
    traverse(node->right);

// rather than

if(node->right != NULL)
    traverse(node->right);
```


## Optimisations

