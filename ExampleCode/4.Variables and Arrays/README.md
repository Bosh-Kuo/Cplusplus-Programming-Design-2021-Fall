# **CH4 Note**
## **Limit of C++**
一個可以查看各個資料型態極限大小的Libary，https://www.cplusplus.com/reference/climits/ ，使用時加上：  
```C++
#include <climits>
```
參考[4_1.cpp](./4_1.cpp)


---
## **sizeof**
回傳藝資料型態佔有的空間大小(byte)
```C++
int a;
sizeof(a);
```
參考[4_2.cpp](./4_2.cpp)


---
## **Overflow**
儲存超出該資量料型態範圍的數值
參考[4_3.cpp](./4_3.cpp)


---
## **char**
用one byte(-128~127)將字元編碼，`it's also integer!`  
參考[4_4.cpp](./4_4.cpp), [4_5.cpp](./4_5.cpp)


---
## **bool**
在c++中，非0數都被認定為`true`，在做控制流程時需注意


---
## **precision**
浮點數在２進位表示法中常常無法被精確表示，如：  
$3.5 = 011.1, 3.25=011.01, 3.375=011.011$  但是,  
$3.4?$  
僅有部分數字恰巧可以用２的冪次方相加來表示，因此浮點數幾乎都會遇到精確度的問題。  
參考[4_6.cpp](./4_6.cpp), [4_7.cpp](./4_7.cpp)


---
## **Array**
### **1d Array**
宣告方式： `data_type array_name [number of elements]  `  
佔據number of elements * sizeof(data_type) 的空間(byte)  
參考[4_8.cpp](./4_8.cpp)

C++ array不會自動初始化，在宣告array時電腦只是劃出一塊記憶體空間而已，這塊記憶體空間上可能存著任意的數值。並且就算存取超出array宣告範圍的index也可能不會發生compilation error，因此需要小心array boundary，若不小心存取到超出範圍的記憶體空間剛好是別的應用程式的空間，就會發生wrong time error。  
參考[4_9.cpp](./4_9.cpp), [4_10.cpp](./4_10.cpp), [4_11.cpp](./4_11.cpp), [4_12.cpp](./4_12.cpp)

### **2d Array**
2d Array在記憶體上沒有column的概念，假設一陣列array[2][3]，那麼a[1], &a[1], &a[1][0]回傳的都是同一個記憶體位置
參考[4_13.cpp](./4_13.cpp), [4_14.cpp](./4_14.cpp), [4_15.cpp](./4_15.cpp), [4_16.cpp](./4_16.cpp)