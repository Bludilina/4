#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

void printQueue(queue<char>& inputQueue)
{
    while (!inputQueue.empty())
    {
        cout << inputQueue.front();
        inputQueue.pop();
    }
}

int main()
{
    ifstream fin("input.txt");
    string buf;
    queue<char> digitsQueue, lettersQueue, otherQueue;

    getline(fin, buf);
    while (!fin.eof())
    {
        for (char symbol : buf)
        {
            if (isdigit(symbol))
                digitsQueue.push(symbol);
            else if (isalpha(symbol))
                lettersQueue.push(symbol);
            else
                otherQueue.push(symbol);
        }
        getline(fin, buf);
    }

    cout << "Digits: ";
    printQueue(digitsQueue);
    cout << endl;

    cout << "Letters: ";
    printQueue(lettersQueue);
    cout << endl;

    cout << "Other: ";
    printQueue(otherQueue);
    cout << endl;

}