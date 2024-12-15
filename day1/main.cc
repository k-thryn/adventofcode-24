// day 1 
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void calculate_distances(vector<int> list1, vector<int> list2) 
{
    // Sort each list of locations in ascending order. 
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    int total_distance = 0;
    for (int i = 0; i < list1.size(); i++)
    {
        // Get pair; calculate diff
        total_distance += abs(list1[i] - list2[i]);
    }
    cout << "Solution: " << total_distance << "\n";
}

int main() 
{
// Read input file.
ifstream input ("input.txt"); 
vector<int> list1;
vector<int> list2;
string line;

if (input.is_open()) 
{
    while (input) 
    {
        getline(input, line);
        if (line.empty())
        {
            break;
        }
        // Split into items from list 1 and list 2.
        stringstream ss(line);
        string loc;
        // Read item from list 1.
        ss >> loc;
        list1.push_back(stoi(loc));
        // Read item from list 2.
        ss >> loc;
        list2.push_back(stoi(loc));
    }
}
input.close();

calculate_distances(list1, list2);

return 0;
}