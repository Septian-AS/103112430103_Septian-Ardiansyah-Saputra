#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello Telkom Jaya Jaya"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}