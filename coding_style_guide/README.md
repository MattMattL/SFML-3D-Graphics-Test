# Project Coding Style Guide

1. Macro
1.1. Writing Header Files
1.2. Include Guard
1.3. Order of Includes
1.4. define Keyword

2. Classes
2.1.

3. Functions

4. (...)

5. Naming
5.1. [Variables](#5.1.-Variables)
5.2. [Constants](#5.2.-Constants)
5.3. [Functions](#5.3.-Functions)
5.4. [Classes](#5.4.-Classes)
5.5. [Enumerators](#5.5.-enumerators)

6. Comments

7. Formatting

The order generally follows Google C++ Style Guide: https://google.github.io/styleguide/cppguide

----------------------------------------------------------------

## 5. Naming

### 5.1. Variables

Variable names should be simple but clear:

``` C++
int count = 0;
int i, j;
string names[8];
```

Camel case with the first letter in lower case for multiple words:

``` C++
int countNums; // 'count' is better
int numOfPeople;
bool isEvenNumber; // 'isEven' is better
```

Not prefixed with its type:

``` C++
string userID; // rather than 'strUserID'

```

### 5.2. Constants

All in capital letters with '\_' instead of spaces:

``` C++
#define MAX_ROW 16
#define MAX_COL 10

const int SIZE_OF_ARR = 8; // sometimes 'ARRAY' is too lengthy
const double PI = 3.14159265;
```

### 5.3. Functions

Camel case with the first letter in lower case for multiple words:

``` C++
int getTotalNumber();
string toString;
void setCount(int count);
```

Parameters:

Postfixed with 'In' if the function has the same variable:

``` C++
int countScore(GameResult result, int numPlayersIn, int minScore)
{
	int numPlayers = numPlayersIn;
	// ...
}
```

### 5.4. Classes

Camel case throughout the entire name:

``` C++
class EntityBase {};
class PlayerModel {};
class BoardGraphics {};
```

### 5.5. Enumerators

Perfied with 'E':

``` C++
enum EColours { /* ... */ };
enum EDataType { /* ... */ };
enum EPlayerType { /* ... */ };
```
