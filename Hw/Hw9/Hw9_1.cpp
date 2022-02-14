#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
    static const int LEN_MAX = 20;
    int len;
    char str[LEN_MAX + 1];
    void clear();

public:
    MyString();
    MyString(char c[]);
    int length();
    int find(char ch, int index);
    void assign(const char st[]);
    void assign(MyString mStr);
    void print();
    char &operator[](int);
};

// constructor
MyString::MyString()
{
    this->clear();
}
MyString::MyString(char c[])
{
    this->clear();
    this->len = (strlen(c) > this->LEN_MAX ? this->LEN_MAX : strlen(c));
    for (int i = 0; i < this->len; i++)
        this->str[i] = c[i];
}

// member function
void MyString::clear()
{
    this->len = 0;
    for (int i = 0; i < this->LEN_MAX + 1; i++)
        this->str[i] = '\0';
}
int MyString::length()
{
    return this->len;
}
int MyString::find(char ch, int index = 0)
{
    index = index < 0 ? 0 : index;
    for (int i = index; i < this->len; i++)
    {
        if (this->str[i] == ch)
            return i;
    }
    return -1;
}
void MyString::assign(const char st[])
{
    this->clear();
    this->len = (strlen(st) > this->LEN_MAX ? this->LEN_MAX : strlen(st));
    for (int i = 0; i < this->len; i++)
        this->str[i] = st[i];
}
void MyString::assign(MyString mStr)
{
    this->clear();
    this->len = mStr.length();
    for (int i = 0; i < this->len; i++)
        this->str[i] = mStr[i];
}
void MyString::print()
{
    cout << this->str << '\n';
}
char &MyString::operator[](int index)
{
    return this->str[index];
}

const int VAR_CNT = 10;
const int VARNAME_LEN = 20;
const int ARGC_MAX = 10;
const int ARGV_LEN = 65536;
const int BUF_LEN = 65536;

MyString *nameToPtr(char *name, MyString var[], char varname[][VARNAME_LEN + 5], const int varcnt)
{
    for (int i = 0; i < varcnt; i++)
        if (strcmp(name, varname[i]) == 0)
            return var + i;  // 回傳該object的pointer
    return nullptr;
}

void digest(const char *buf, int &argc, char argv[][ARGV_LEN])
{
    // 初始化指令array
    for (int i = 0; i < ARGC_MAX; i++)
        for (int j = 0; j < ARGV_LEN; j++)
            argv[i][j] = '\0';

    int idx = 0, len = strlen(buf);  // 該行輸入的長度
    for (int i = 0, state = 0, pos = 0; i < len; i++)
        if (state)
            if (buf[i] == '\"')  // 輸入字串結尾引號
                state = 0;
            else
                argv[idx][pos++] = buf[i];  //輸入字串引號內的字串內容
        else if (buf[i] == ' ')  // 輸入當前指到的substring結尾
            idx++, pos = 0;
        else if (buf[i] == '\"')  // 輸入字串開頭引號
            state = 1;
        else
            argv[idx][pos++] = buf[i];
    argc = idx + 1;
}
int main()
{
    char buf[BUF_LEN + 5] = {0};

    int n = 0;
    cin.getline(buf, BUF_LEN);
    n = atoi(buf);  // 指令個數

    char varname[VAR_CNT + 5][VARNAME_LEN + 5] = {0};  // 儲存物件變數名稱
    MyString var[VAR_CNT + 5];
    int varcnt = 0;

    int argc = 0;
    char argv[ARGC_MAX][ARGV_LEN] = {0};  // 裝輸入的多個子字串

    while (n--)
    {
        cin.getline(buf, BUF_LEN);
        digest(buf, argc, argv);

        if (strcmp(argv[0], "declare") == 0)
        {
            strcpy(varname[varcnt], argv[1]);
            var[varcnt].assign(argv[2]);
            varcnt += 1;
        }
        else if (strcmp(argv[0], "length") == 0)
        {
            cout << nameToPtr(argv[1], var, varname, varcnt)->length() << '\n';
        }
        else if (strcmp(argv[0], "find") == 0)
        {
            cout << nameToPtr(argv[1], var, varname, varcnt)->find(argv[2][0], atoi(argv[3])) << '\n';
        }
        else if (strcmp(argv[0], "assignString") == 0)
        {
            nameToPtr(argv[1], var, varname, varcnt)->assign(argv[2]);
        }
        else if (strcmp(argv[0], "assignObject") == 0)
        {
            nameToPtr(argv[1], var, varname, varcnt)->assign(*nameToPtr(argv[2], var, varname, varcnt));
        }
        else if (strcmp(argv[0], "print") == 0)
        {
            nameToPtr(argv[1], var, varname, varcnt)->print();
        }
    }
    return 0;
}