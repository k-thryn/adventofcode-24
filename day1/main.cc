// day 1 
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void calculate_distances(vector<string> list1, vector<string> list2) 
{
// TODO: implement. 
}

int main() 
{
// Read input file.
ifstream input ("input.txt"); 
vector<string> list1;
vector<string> list2;
string line;

if (input.is_open()) 
{
    while (input) 
    {
        getline(input, line);
        // Split into items from list 1 and list 2.
        stringstream ss(line);
        string loc;
        // Read item from list 1.
        ss >> loc;
        list1.push_back(loc);
        // Read item from list 2.
        ss >> loc;
        list2.push_back(loc);
    }
}

input.close();

calculate_distances(list1, list2);

return 0;
}