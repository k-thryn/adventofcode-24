// day 2
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void calculate_num_safe(vector< vector<int> > report)
{
    int num_safe = 0;
    for (int i = 0; i < report.size(); i++)
    {
        // Determine safety of entry.
        vector<int> entry = report[i];
        int prev = 0;
        bool is_ascending = false;
        bool is_safe = true;
        for (int j = 0; j < entry.size(); j++)
        {
            if (j == 0)
            {
                prev = entry[j];
                continue;
            }

            // Get diff. 
            int diff = entry[j] - prev;
            int diff_abs = abs(diff);

            if (j == 1)
            {
                // Second item; check interval and set direction if safe.
                if (diff_abs >= 1 && diff_abs <= 3)
                {
                    is_ascending = diff > 0;
                    prev = entry[j];
                } else {
                    is_safe = false;
                }
            } else {
                // Check both direction and interval. 
                bool matches_direction = diff > 0 == is_ascending;
                if (matches_direction && diff_abs >= 1 && diff_abs <= 3)
                {
                    prev = entry[j];
                } else {
                    is_safe = false;
                }
            }
        }
        if (is_safe) 
        {
            num_safe++;
        }
    }
    cout << "num_safe = " << num_safe <<  "\n";
}

int main()
{
    // Read input file.
    ifstream input("input.txt");
    string line;
    vector< vector<int> > report;

    if (input.is_open())
    {
        while (getline(input, line))
        {
            // Split into items;
            stringstream ss(line);
            vector<int> entry;
            string level;
            while (ss >> level)
            {
                entry.push_back(stoi(level));
            }
            report.push_back(entry);
        }
    }
    calculate_num_safe(report);
    return 0;
}
