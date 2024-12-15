// day 1 
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void calculate_distances(vector<int> list1, vector<int> list2) 
{
    int total_distance = 0;
    for (int i = 0; i < list1.size(); i++)
    {
        // Get pair; calculate diff
        total_distance += abs(list1[i] - list2[i]);
    }
    cout << "Solution: " << total_distance << "\n";
}

void calculate_similarity_score(vector<int> list1, vector<int> list2)
{
    int similarity_score = 0;

    // index for iterating through list2. 
    int j = 0;
    for (int i = 0; i < list1.size(); i++) 
    {
        if (list1[i] < list2[j])
        {
            continue;
        }
        while (list1[i] > list2[j])
        {
            // Increment j until we find it. 
            j++;
        }
        // Count how many times the element in list1 appears in list2. 
        int num_appearances = 0;
        while (list1[i] == list2[j])
        {
            num_appearances++;
            j++;
        }
        similarity_score += (num_appearances * list1[i]);
    }
    cout << "Solution: " << similarity_score << "\n";
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

// Sort each list of locations in ascending order. 
sort(list1.begin(), list1.end());
sort(list2.begin(), list2.end());

calculate_distances(list1, list2);
calculate_similarity_score(list1, list2);

return 0;
}