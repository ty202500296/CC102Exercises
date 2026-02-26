#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    char choice;

    do {
        int student, day;

        cout << "Enter number of students: ";
        cin >> student;

        cout << "Enter number of days: ";
        cin >> day;

        vector<vector<int>> attendance(student, vector<int>(day));

        for (int i = 0; i < student; i++) {
            cout << "Student " << i + 1 << " attendance: ";
            for (int j = 0; j < day; j++) {
                cin >> attendance[i][j];
            }
            cout<<"--------------------"<<endl;
        }
        cout << "\nStudent ";
        for (int d = 0; d < day; d++) {
            cout << "D" << d + 1 << " ";
        }
        cout << "Total Percentage Remarks\n";

        for (int i = 0; i < student; i++) {
            int total = 0;

            cout << setw(4) << i + 1 << "    ";

            for (int j = 0; j < day; j++) {
                cout << attendance[i][j] << "  ";
                total += attendance[i][j];
            }

            double percentage = (double(total) / day) * 100;

            cout << setw(3) << total << "   ";
            cout << fixed << setprecision(0) << percentage << "%   ";

            if (percentage < 50) {
                cout << "DRP";
            } else {
                cout << "OK";
            }

            cout << endl;
        }
        cout << "\nDo you want to try again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
