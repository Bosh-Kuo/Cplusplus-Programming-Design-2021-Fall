# **CH10 Self-defined data types (in C)**

## **struct**

### **struct definition**

We want to group different data types into a single type. In C, we do so by using `struct` (abbreviation of structure).
- We do so when an item naturally consists of multiple attributes. 
- We do so to make the program easier to read and maintain.
exp:
```C++
struct Point 
{
    int x;
    int y; 
};

Point vector(Point A, Point B)
// Point as parameters 
{
    Point vecXY;
    vecXY.x = B.x - A.x;
    vecXY.y = B.y - A.y;
    return vecXY; // return a Point 
} 

int main() {
    Point a = {0, 0}, b = {10, 20};
    Point vecAB = vector(a, b);
    cout << vecAB.x << " ";
    cout << vecAB.y << "\n";
    return 0; 
}
```

- `Declare` variables with the self - defined type name. 
- `Assign` values to both attributes by grouping values by curly brackets. 
- `Access` attributes through the dot operator.
  
```C++
// 定義
struct struct_name 
{
    type1 field 1;
    type2 field 2;
    type3 field 3;
    // more fields 
};

// 宣告
struct_name variable_name;

// 存取
struct_variable.attribute_name
```

Partial assignments are allowed (with unassigned attributes set to 0).
```C++
Point A = {0, 0, -8}; 
Point B; 
B = {10, 20, 5}; 
C = {5, 0}; 
D = {2}
```

<br>

### **struct and functions**

You may pass a struct variable as an argument into a function.  
You may return a struct variable from a function, too.   
參考[10_1.cpp](10_1.cpp)

<br>

### **Memory allocation for struct**
參考[10_2.cpp](10_2.cpp)

<br>

## **typedef**
typedef is the abbreviation of “type definition”. It allows us to create a new data type from another data type. 

> `typedef` <u>old type</u> <u>new type</u>;

So we do not really create any new type. (只是幫old type取一個別名)


### **Example with typedef**

```C++
typedef double Dollar; // define Dollar as double D
ollar nt; // declare a variable as Dollar 
Dollar us; 
cin >> us; nt = us * 29; 
cout << nt << "\n";
```
- The self-defined type can be used only in the block (if you declare it in any block). The same rule applies to struct.

<br>

### **typedef from struct**

We may combine typedef and struct.
```C++
// define Vector from Point 
typedef Point Vector;

Point a = {0, 0}; 
Point b = {10, 20}; 
Vector vecAB = vector(a, b);
```

<br>

### `Example: <ctime>`

很多C++的standard library 都會用typedef來提供函式功能，ex: function **clock()**, (defined in <ctime>) 回傳程式開始執行後經過了幾個system clock ticks
參考[10_3.cpp](10_3.cpp)

`clock()` returns a type `clock_t` variable (for the number of ticks).
- `clock_t` is actually a long int. In <ctime>, there is a statement:
> `typedef` long int clock_t;

Why clock_t?
> 假如某天C++ standard library 想要更改clock()回傳的變數型態，若原本回傳為long int，就會遇到舊版與新版回傳變數形態不同而所有程式碼都都改的窘境

To print out the number of seconds instead of ticks:
```C++
cout << static_cast<double>(eTime - sTime) / CLOCKS_PER_SEC << "\n";
```
使用者就算不知道clock_t是什麼變數型態也可以直接使用，library就算改了clock_t的old type也不會影響到使用者。

<br>

## **struct with member functions**

### **A member-function implementation**

We may redefine Point to include a member function:
- distOri() is a `member function` of Point.
- `No argument` is needed.


```C++
struct Point 
{
int x;
int y;
double distOri()
    {
        return sqrt(pow(x, 2) + pow(y, 2)); 
    }
};

int main() 
{
Point a = {3, 4};
cout << a.distOri();
return 0; 
}
```

One may define a member function outside the struct statement.  
必須使用scope resolution operator `::`，並且把struct的名字加在前面，以區別出member-function與global-function。
```C++
struct Point 
{
    int x;
    int y;
    double distOri(); 
};

double Point::distOri() // scope resolution 
{                       // is required
    return sqrt(pow(x, 2) + pow(y, 2)); 
}
```

<br>

### **Two different perspectives**
- As a `global function`: I want to create a machine outside a point.
- As a `member function`: I want to attach an operation on a point.  
The second way also enhances modularity(讓每個模塊功能區分清楚，成為獨立自主的個體，也較容易維護)

參考[10_4.cpp](10_4.cpp)

<br>

## **Randomization**

### **rand()**

It “randomly” returns an integer between 0 and RAND_MAX (in <cstdlib>, typically 32767). Actually rand() returns a “pseudo-random” integer.
- They just look like random numbers. But they are not really random.
- There is a formula to produce each number.

參考[10_5.cpp](10_5.cpp)

<br>

### **srand()**

We use srand to determine the seed.
> void srand(unsigned int);

- A seed can be generated based on the input number. 
- The sequence will become different.

參考[10_6.cpp](10_6.cpp)

In many cases, we use time(nullptr) to be the argument of srand()
- The function time(0), defined in <ctime>, returns the number of seconds that have past since 0:0:0, Jan, 1st, 1970.

> time_t time(time_t* timer);

參考[10_7.cpp](10_7.cpp)

<br>

### **Random numbers in a range**

If you want to produce random numbers in a specific range, use `%`.

參考[10_8.cpp](10_8.cpp)
