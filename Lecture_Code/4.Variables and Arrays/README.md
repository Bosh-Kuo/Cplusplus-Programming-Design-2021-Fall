# **CH4 Variables and Arrays**
## **Basic data type**
### **Limit of C++**
一個可以查看各個資料型態極限大小的Libary，https://www.cplusplus.com/reference/climits/ ，使用時加上：  
```C++
#include <climits>
// 從C語言就有的函式庫會以c開頭
```
參考[4_1.cpp](./4_1.cpp)

<br>

### **sizeof**
回傳一資料型態佔有的空間大小(byte)
```C++
int a;
sizeof(a);
```
參考[4_2.cpp](./4_2.cpp)

<br>

### **overflow**
儲存超出該資量料型態範圍的數值
參考[4_3.cpp](./4_3.cpp)

<br>

### **char**
用one byte(-128~127)將字元編碼，`it's also integer!`  
- char c = 'c';  
- char c = 99;
參考[4_4.cpp](./4_4.cpp), [4_5.cpp](./4_5.cpp)

<br>

### **bool**
在c++中，非0數都被認定為`true`，在做控制流程時需注意

<br>

### **precision**
浮點數在２進位表示法中常常無法被精確表示，如：  
$3.5 = 011.1, 3.25=011.01, 3.375=011.011$  但是,  
$3.4?$  
僅有部分數字恰巧可以用２的冪次方相加來表示，因此浮點數幾乎都會遇到精確度的問題。  
參考[4_6.cpp](./4_6.cpp), [4_7.cpp](./4_7.cpp)

<br>

## **Constants and casting**
變數就像是容器，不同型態的變數就像容量大小與形狀不同的容器，舉例來說：
- long >= int >= short
-  “Shapes” of int and float are different

<br>

### **Casting**
- Implicit casting: from a small type to a large type.
- Explicit casting: from a large type to a small type. (工程師需要明確指出如何cast)

<br>

### **Explicit casting**
- int a = 5.6; is not good.  
- int a = `static_cast<int>(5.6)`; is better. 
  
To cast basic data types, we use static_cast:
> `static_cast<type>(expression)`

<br>

## **Array**
### **1d Array**
宣告方式： `data_type array_name [number of elements]  `  
佔據number of elements * sizeof(data_type) 的空間(byte)  
參考[4_8.cpp](./4_8.cpp)

C++ array不會自動初始化，在宣告array時電腦只是劃出一塊記憶體空間而已，這塊記憶體空間上可能存著任意的數值。並且就算存取超出array宣告範圍的index也可能不會發生compilation error，因此需要小心array boundary，若不小心存取到超出範圍的記憶體空間剛好是別的應用程式的空間，就會發生wrong time error。  
參考[4_9.cpp](./4_9.cpp), [4_10.cpp](./4_10.cpp), [4_11.cpp](./4_11.cpp), [4_12.cpp](./4_12.cpp)

<br>

### **Things you cannot (should not) do**
```C++
// DO NOT do this 
int x = 0; 
cin >> x; 
// very bad! 
int array[x]; 
array[2] = 3; // etc
```

```C++
// Do this 
int x = 0; 
cin >> x; // good! 
int* array = new int[x]; 
array[2] = 3; // etc.
```

<br>

### **2d Array**
2d Array在記憶體上沒有column的概念，2d Array 實際上就是多個1d Array，假設一陣列array[2][3]，那麼a[1], &a[1], &a[1][0]回傳的都是同一個記憶體位置，2d Array的記憶體快快儲存方式是線性且連續的，也就是說array中相鄰的兩個index記憶體區塊也是相鄰的。
參考[4_13.cpp](./4_13.cpp), [4_14.cpp](./4_14.cpp), [4_15.cpp](./4_15.cpp), [4_16.cpp](./4_16.cpp)