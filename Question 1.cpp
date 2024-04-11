/* Problem Statement: Flight management: There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. 
                The cost of the edge can be the time that flight takes to reach city B from  A, or the amount of fuel used for the journey. 
                Write a menu driven C++ program to represent this as a graph using adjacency matrix and adjacency list. The node can be represented by the 
                airport name or name of the city. Check whether cities are connected through flight or not. Compare the storage representation.

*/

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX_CITIES = 26; // Maximum number of cities (based on character codes)

struct node {
    string source;
    string destination;
    int time;
    struct node* next; 
};

class flight {
private:
    struct node* head = nullptr;
    char cityNames[MAX_CITIES][20]; // Array to store city names
    int numCities = 0; // Keeps track of the number of unique cities

public:
    // Helper function to get city index
    int getCityIndex(const string &city) {
        for (int i = 0; i < numCities; ++i) {
            if (cityNames[i] == city) {
                return i;
            }
        }

        // If city not found, add it and return index
        strcpy(cityNames[numCities++], city.c_str());
        return numCities - 1;
    }

    void addFlight(string from, string to, int time) {
        node* newflight = new node;
        newflight->source = from;
        newflight->destination = to;
        newflight->time = time;
        newflight->next = head;
        head = newflight;

        // Update city names if necessary
        getCityIndex(from);
        getCityIndex(to);
    }

    void checkConnection(string from, string to) {
        node* current = head;
        bool isfound = false;

        while (current != nullptr) {
            if (current->source == from && current->destination == to) {
                cout << "There is a flight between: " << from << " to " << to << endl;
                isfound = true;
                return;
            }
            current = current->next;
        }

        if (!isfound) {
            cout << "No connection between: " << from << " to " << to << endl;
        }
    }

    void displayAdjacencyMatrix() {
        int adjacencyMatrix[MAX_CITIES][MAX_CITIES] = {0};

        node* current = head;

        while (current != nullptr) {
            int sourceIndex = getCityIndex(current->source);
            int destinationIndex = getCityIndex(current->destination);
            adjacencyMatrix[sourceIndex][destinationIndex] = current->time;
            adjacencyMatrix[destinationIndex][sourceIndex] = 0; // Adjust for directed flights if needed

            current = current->next;
        }

        cout << "Adjacency Matrix:\n";

        cout << "  ";
        for (int i = 0; i < numCities; ++i) {
            cout << cityNames[i][0] << " "; // Use first character of city name as reference
        }
        cout << endl;

        for (int i = 0; i < numCities; ++i) 
        {
            cout << cityNames[i][0] << " ";
            
            for (int j = 0; j < numCities; ++j) 
              {
                cout << adjacencyMatrix[i][j] << " ";
              }
            cout << endl;
        }
    }

    void displayAdjacencyList() {
        node* current = head;
        cout << "Adjacency List:\n";

        while (current != nullptr) {
            cout << current->source << " -> " << current->destination << " (Time: " << current->time << "hours)\n";
            current = current->next;
        }
    }
};

int main() {
    flight f;
    int choice;

    do {
        cout << "\nMenu"
             << "\n1. Add Flight"
             << "\n2. Check connection between flight"
             << "\n3. Display Adjacency Matrix"
             << "\n4. Display Adjacency List"
             << "\n5. Exit";
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string from, to;
                cout << "\n Flight\n";
                cout << "Source  : ";
                cin >> from;
                cout << "Destination : ";
                cin >> to;
                int time;
                cout << "Time    : ";
                cin >> time;
                f.addFlight(from, to, time);
                cout << "Flight Added Successfully!" << endl;
                break;
            }
            case 2: {
                string from, to;
                cout << "Check connection between flight ";
                cout << "Enter Source City : ";
                cin >> from;
                cout << "Enter Destination city : ";
                cin >> to;
                f.checkConnection(from, to);
                break;
            }
            case 3: {
                f.displayAdjacencyMatrix();
                break;
            }
            case 4: {
                f.displayAdjacencyList();
                break;
            }
            case 5: {
                cout << "Thank you!";
                break;
            }
            default: {
                cout << "Please enter valid choice ";
                break;
            }
        }
    } while (choice != 5);

    return 0;
}
/*
Output: Menu
1. Add Flight
2. Check connection between flight
3. Display Adjacency Matrix
4. Display Adjacency List
5. Exit
Enter your choice : 1

 Flight
Source  : Nashik
Destination : Pune
Time    : 4
Flight Added Successfully!

Menu
1. Add Flight
2. Check connection between flight
3. Display Adjacency Matrix
4. Display Adjacency List
5. Exit
Enter your choice : 1

 Flight
Source  : Goa
Destination : Mumbai
Time    : 6
Flight Added Successfully!

Menu
1. Add Flight
2. Check connection between flight
3. Display Adjacency Matrix
4. Display Adjacency List
5. Exit
Enter your choice : 3
Adjacency Matrix:
  N P G M
N 0 4 0 0
P 0 0 0 0
G 0 0 0 6
M 0 0 0 0

Menu
1. Add Flight
2. Check connection between flight
3. Display Adjacency Matrix
4. Display Adjacency List
5. Exit
Enter your choice : 4
Adjacency List:
Goa -> Mumbai (Time: 6hours)
Nashik -> Pune (Time: 4hours)

Menu
1. Add Flight
2. Check connection between flight
3. Display Adjacency Matrix
4. Display Adjacency List
5. Exit
Enter your choice : 5
Thank you!
*/