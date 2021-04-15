# Project Coding Style Guide

- [Macro](#Macro)
    - [Include Guard](#Include-Guard)
    - [Order of Includes](#Order-of-Includes)
    - [define Keyword](#define-Keyword)

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

- Comments

- [Formatting](#Formatting)
    - [Brackets](#Brackets)
    - [Separating Lines](#Separating-Lines)

The order (but not the style) generally follows Google C++ Style Guide: https://google.github.io/styleguide/cppguide

----------------------------------------------------------------

## Macro

### Include Guard

- Header files start with one of the following:

``` C++
#pragma once
```

or

``` C++
#ifndef FILE_NAME_HPP
#define FILE_NAME_HPP

// ...

#endif
```

### Order of Includes

### define Keyword






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

### Variables

- Variable names should be simple but clear
- Variables are not prefixed with its type, e.g. str, arr
- camelCase

``` C++
int count = 0; // 'countNumbers' is not simple
int i, j; // not 'iterator' or 'i1', 'i2'
string names[8]; // not 'strNames'

int numOfPeople; // not 'num_of_people'
bool isEven;
```

### Constants

- All in capital letters
- Spaces are replaced with \_

``` C++
#define MAX_ROW 16
#define MAX_COL 10

const int SIZE_OF_ARR = 8;
const double PI = 3.14159265;
```

### Functions

- camelCase
- Parameters are postfixed with 'In' if the function has the same variable

``` C++
int getTotalNumber(); // getter
void setCount(int count); // setter
string toString; // converter

int countScore(int numPlayersIn, int minScore)
{
    int numPlayers = numPlayersIn;
    // ...
}
```

### Classes

- CamelCase

``` C++
class EntityBase { /* ... */ };
class PlayerModel { /* ... */ };
class BoardGraphics { /* ... */ };
```

### Enumerators

- Enumerators are prefixed with 'E'

``` C++
enum EColours { /* ... */ };
enum EDataType { /* ... */ };
enum EPlayerType { /* ... */ };
```

### Files

- File names are in lower case and separated by \_

```
main.cpp
test.c
header.hpp
header.h
game_launcher.hpp
graphics_manager.hpp
```





## Comments





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

if(conditionA) // okay
{
    i++;
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

if(conditionB) // okay
{
    i++;
    setMessage(msg);
}
else
{
    j++;
}
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