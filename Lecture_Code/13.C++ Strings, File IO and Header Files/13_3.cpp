#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream inFile("test.txt");
    ofstream outFile("test1.txt");
    string name;
    int score;

    if (inFile && outFile)
    {
        while (inFile >> name >> score)
        {
            if (name == "Alex")
                name = "Alexander";
            outFile << name << " "
                    << score << endl;
        }
    }
    inFile.close();
    outFile.close();
    return 0;
}