#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream inFile("score.txt");
    if (inFile)
    {
        string name;
        int score = 0;
        int sumScore = 0;
        int scoreCount = 0;

        while (inFile >> name >> score)
        {
            sumScore += score;
            scoreCount++;
        }
        if (scoreCount != 0)
            cout << static_cast<double>(sumScore) / scoreCount;
        else
            cout << "no grade!";
    }
    inFile.close();
    return 0;
}