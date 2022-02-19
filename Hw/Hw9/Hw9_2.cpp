#include <iostream>
#include <cstring>
#include <string>
#include <exception>
#include <stdexcept>
using namespace std;

// 定義global function
bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}
bool isLowerCase(char c)
{
    return c >= 'a' && c <= 'z';
}
int findOperator(string exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp.at(i) == '+' || exp.at(i) == '-')
        {
            return i;
        }
    }

    return -1;
}
int findAlphabet(string term)
{
    for (int i = 0; i < term.length(); i++)
    {
        if (isalpha(term.at(i)))
        {
            return i;
        }
    }

    return -1;
}

// 定義struct vector2i，用來表示Matrix size
typedef struct vector2i
{
    int x;
    int y;

    vector2i() : x(0), y(0)
    {
    }
    vector2i(const vector2i &other) : x(other.x), y(other.y)
    {
    }
    vector2i(int x, int y) : x(x), y(y)
    {
    }

    bool operator==(const vector2i &other) const
    {
        return this->x == other.x && this->y == other.y;
    }
    bool operator!=(const vector2i &other) const
    {
        return !(this->x == other.x && this->y == other.y);
    }
} vector2i;

// 定義class: Matrix
class Matrix
{
private:
    vector2i dim;
    int **ele;
    bool isNull;

public:
    // Constructors / Destructors
    Matrix();
    Matrix(const Matrix &other);
    Matrix(vector2i dim);
    ~Matrix();

    // Operators
    friend ostream &operator<<(ostream &os, const Matrix &mat);
    friend istream &operator>>(istream &is, Matrix &mat);
    Matrix &operator=(const Matrix &other);
    Matrix operator+(const Matrix &other) const; // addition
    Matrix operator-() const;                    // negation
    Matrix operator*(const Matrix &other) const; // matrix multiplication
    Matrix operator*(const int &scalar) const;   // scalar multiplication

    // Getters / Setters
    int getElement(vector2i index) const
    {
        return this->ele[index.x][index.y];
    }
    void setElement(int val, vector2i index)
    {
        this->ele[index.x][index.y] = val;
    }
};

// constructor / destructor
Matrix::Matrix() : dim(0, 0), isNull(true)
{
    this->ele = new int *[0];
}
Matrix::Matrix(const Matrix &other) : dim(other.dim), isNull(other.isNull)
{
    this->ele = new int *[dim.x];
    for (int i = 0; i < dim.x; i++)
    {
        ele[i] = new int[dim.y];

        for (int j = 0; j < dim.y; j++)
        {
            ele[i][j] = other.ele[i][j];
        }
    }
}
Matrix::Matrix(vector2i dim) : dim(dim), isNull(false)
{
    this->ele = new int *[dim.x];
    for (int i = 0; i < dim.x; i++)
    {
        ele[i] = new int[dim.y];
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < this->dim.x; i++)
    {
        // 釋放Matrix的每一個row
        delete[] this->ele[i];
        this->ele[i] = nullptr;
    }
    delete[] this->ele;
}

// overwiting: assignment
Matrix &Matrix::operator=(const Matrix &other)
{
    this->isNull = other.isNull;

    // 是放原本指向的動態記憶體空間
    for (int i = 0; i < this->dim.x; i++)
    {
        delete[] this->ele[i];
        this->ele[i] = nullptr;
    }
    delete[] this->ele;

    // 將other複製過來
    this->dim = other.dim;
    this->ele = new int *[this->dim.x];
    for (int i = 0; i < this->dim.x; i++)
    {
        this->ele[i] = new int[this->dim.y];

        for (int j = 0; j < this->dim.y; j++)
        {
            this->ele[i][j] = other.ele[i][j];
        }
    }
    return *this;
}

// overwiting(global): << and >
// 處理cin >> Matrix object, cout << Matrix object
ostream &operator<<(ostream &os, const Matrix &mat)
{
    for (int i = 0; i < mat.dim.x; i++)
    {
        for (int j = 0; j < mat.dim.y; j++)
        {
            j ? (os << ' ' << mat.ele[i][j]) : (os << mat.ele[i][j]);
        }
        os << '\n';
    }
    return os;
}
istream &operator>>(istream &is, Matrix &mat)
{
    for (int i = 0; i < mat.dim.x; i++)
    {
        for (int j = 0; j < mat.dim.y; j++)
        {
            is >> mat.ele[i][j];
        }
    }
    return is;
}

// overwiting: addition
Matrix Matrix::operator+(const Matrix &other) const
{
    if (this->dim != other.dim)
    {
        throw std::domain_error("Unmatched dimensions.");
    }

    Matrix rv(this->dim);
    for (int i = 0; i < this->dim.x; i++)
    {
        for (int j = 0; j < this->dim.y; j++)
        {
            rv.setElement(
                this->getElement(vector2i(i, j)) + other.getElement(vector2i(i, j)),
                vector2i(i, j));
        }
    }
    return rv;
}

// overwiting: negation(Matrix掛負號)
Matrix Matrix::operator-() const
{
    Matrix rv(this->dim);

    // negate every element of rv
    for (int i = 0; i < this->dim.x; i++)
    {
        for (int j = 0; j < this->dim.y; j++)
        {
            rv.setElement(
                -this->getElement(vector2i(i, j)),
                vector2i(i, j));
        }
    }
    return rv;
}

// overwiting: matrix multiplication
Matrix Matrix::operator*(const Matrix &other) const
{
    if (this->isNull)
    {
        return other;
    }

    if (this->dim.y != other.dim.x)
    {
        throw std::domain_error("Unmatched dimensions");
    }

    Matrix rv(vector2i(this->dim.x, other.dim.y)); // 乘積Matrix

    for (int i = 0; i < this->dim.x; i++)
    {
        for (int j = 0; j < other.dim.y; j++)
        {
            int sum = 0;
            for (int k = 0; k < this->dim.y; k++)
            {
                sum += this->getElement(vector2i(i, k)) * other.getElement(vector2i(k, j));
            }

            rv.setElement(sum, vector2i(i, j));
        }
    }
    return rv;
}
// overwiting: scalar multiplication
Matrix Matrix::operator*(const int &scalar) const
{
    Matrix rv(this->dim);

    for (int i = 0; i < this->dim.x; i++)
    {
        for (int j = 0; j < this->dim.y; j++)
        {
            rv.setElement(this->getElement(vector2i(i, j)) * scalar, vector2i(i, j));
        }
    }
    return rv;
}

// 定義class: Problem
class Problem
{
private:
    string transformation;
    string vectorIdent;

    Matrix matrices[30];
    string mitricesIdent[30];
    int matriceCount;

    void addMatrixDefinition(string ident, Matrix mat);
    Matrix getMatrixByIdent(string ident);
    Matrix evaluateExpression(string exp);
    Matrix evaluateTerm(string term);

public:
    // Constructor / Destructor
    Problem() : matriceCount(0){};
    ~Problem(){};

    void solve();
};

// Problem Class: member function
void Problem::addMatrixDefinition(string ident, Matrix mat)
{
    this->matrices[this->matriceCount] = mat;
    this->mitricesIdent[this->matriceCount] = ident;
    this->matriceCount++;
}
Matrix Problem::getMatrixByIdent(string ident)
{
    for (int i = 0; i < this->matriceCount; i++)
    {
        if (this->mitricesIdent[i] == ident)
        {
            return this->matrices[i];
        }
    }
}
// 運算輸入第一行的運算式
Matrix Problem::evaluateExpression(string exp)
{
    // exp為輸入第一行的運算式
    bool neg = exp.at(0) == '-';                 // 判斷Matrix正負
    int operIndex = findOperator(exp.substr(1)); //  index of operator found in exp

    if (operIndex == -1) // not found(單一Matrix，沒有運算式)
    {
        // base case, evaluate term
        return neg ? -this->evaluateTerm(exp.substr(1)) : this->evaluateTerm(exp.substr(1));
    }

    return (neg ? -this->evaluateTerm(exp.substr(1, operIndex)) : this->evaluateTerm(exp.substr(1, operIndex))) + this->evaluateExpression(exp.substr(operIndex + 1));
}
Matrix Problem::evaluateTerm(string term)
{
    int matIndex = findAlphabet(term);
    if (matIndex != 0) // scalar multiplication
    {
        return this->evaluateTerm(term.substr(matIndex)) * stoi(term.substr(0, matIndex));
    }
    else
    {
        if (term.length() == 1)
        {
            // base case, evaluate matrix
            return this->getMatrixByIdent(term);
        }
        else
        {
            return this->evaluateTerm(term.substr(0, 1)) * this->evaluateTerm(term.substr(1));
        }
    }
}
void Problem::solve()
{
    string ident;
    int m, n;

    cin >> this->transformation; // 輸入第一行運算式

    if (this->transformation.at(0) != '-') // 在運算式開頭加上+符號
    {
        this->transformation = "+" + this->transformation;
    }

    do
    {
        cin >> ident >> m >> n; // Matrix name, row, column
        Matrix mat(vector2i(m, n));
        cin >> mat; // >> 經過overloading，會逐筆輸入Matrix
        this->addMatrixDefinition(ident, mat);
    } while (!isLowerCase(ident.at(0))); // 向量(為小寫符號)

    this->vectorIdent = ident; // vector name

    try
    {
        Matrix transformationMatrix = evaluateExpression(this->transformation);  // 運算輸入第一行的運算式
        Matrix vector = this->getMatrixByIdent(this->vectorIdent);
        Matrix ans = transformationMatrix * vector;

        std::cout << ans;
    }
    catch (const std::exception &e)
    {
        std::cout << -1 << '\n';
    }
}

int main()
{
    Problem problem;

    problem.solve();

    return 0;
}