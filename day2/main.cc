// day 2
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Read input file.
    ifstream input("input.txt");
      string line;

    if (input.is_open())
    {
        while (input)
        {
              getline(input, line);
        }
    }
    return 0;
}