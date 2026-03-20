#include <iostream>
#include <string>
using namespace std;

void input(int n, void* ptr);
void display(int n, void* ptr);

int main() {

    struct employee {
        string name;
        string position;
        double salary;
    };

    int size;

    cout << "Enter number of employees: ";
    cin >> size;
    cin.ignore();

    employee obj[size];   

    input(size, obj);
    display(size, obj);

}

void input(int n, void* ptr) {

    struct employee {
        string name;
        string position;
        double salary;
    };

    employee* e = (employee*)ptr;

    for (int i = 0; i < n; i++) {

        cout << "\nEmployee " << i + 1 << endl;

        cout << "Name: ";
        getline(cin, e[i].name);

        cout << "Position: ";
        getline(cin, e[i].position);

        cout << "Salary: ";
        cin >> e[i].salary;
        cin.ignore();
    }
}

void display(int n, void* ptr) {

    struct employee {
        string name;
        string position;
        double salary;
    };

    employee* e = (employee*)ptr;

    cout << "\nEMPLOYEE LIST\n";

    for (int i = 0; i < n; i++) {

        cout << "\nEmployee " << i + 1 << endl;
        cout << "Name: " << e[i].name << endl;
        cout << "Position: " << e[i].position << endl;
        cout << "Salary: " << e[i].salary << endl;

        if (e[i].salary >= 1000)
            cout << "High salary\n";
        else
            cout << "Low salary\n";
    }
}