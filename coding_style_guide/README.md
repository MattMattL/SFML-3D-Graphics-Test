# Project Coding Style Guide

- [Macro](#Macro)
	- [Include Guard](#Include-Guard)
	- [Order of Includes](#Order-of-Includes)
	- [define Keyword](#define-Keyword)

- Classes


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

- Formatting

The order generally follows Google C++ Style Guide: https://google.github.io/styleguide/cppguide

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


## Naming

### Variables

- Variable names should be simple but clear
- Variables are not prefixed with its type, e.g. str, arr
- camelCase

``` C++
int count = 0; // not 'countNumbers'
int i, j; // not 'iterator' or 'i1', 'i2'
string names[8]; // not 'stringNames' or 'strNames'

int numOfPeople; // not 'numofpeople' or 'num_of_people'
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

- Enumerators are perfied with 'E'

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