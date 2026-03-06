#include <iostream>
using namespace std;

int main() {
    int computers[5][10] = {0};
    int choice;

    do {
        cout << "\n===== COMPUTER SHOP RENTAL SYSTEM =====\n";
        cout << "1. View Computer Layout\n";
        cout << "2. Rent a Computer\n";
        cout << "3. Return a Computer\n";
        cout << "4. Reset Rental System\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n   ";
            for (int i = 1; i <= 10; i++) {
                cout << i << " ";
            }
            cout << endl;

            char rowName = 'A';

            for (int i = 0; i < 5; i++) {
                cout << rowName << "  ";
                for (int j = 0; j < 10; j++) {
                    cout << computers[i][j] << " ";
                }
                cout << endl;
                rowName++;
            }
        }

        else if (choice == 2) {
            int row, col, hours;
            bool full = true;

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 10; j++) {
                    if (computers[i][j] == 0)
                        full = false;
                }
            }

            if (full) {
                cout << "Shop is fully occupied!\n";
            } else {
                cout << "Enter row (1-5): ";
                cin >> row;
                cout << "Enter column (1-10): ";
                cin >> col;
                cout << "Enter hours: ";
                cin >> hours;

                if (row < 1 || row > 5 || col < 1 || col > 10) {
                    cout << "Invalid selection!\n";
                }
                else if (computers[row-1][col-1] > 0) {
                    cout << "Computer unit already rented!\n";
                }
                else {
                    computers[row-1][col-1] = hours;
                    char r = 'A' + (row - 1);
                    cout << "Computer unit " << r << col << " successfully rented for "
                         << hours << " hour(s)!\n";
                }
            }
        }

        else if (choice == 3) {
            int row, col;

            cout << "Enter row (1-5): ";
            cin >> row;
            cout << "Enter column (1-10): ";
            cin >> col;

            if (row < 1 || row > 5 || col < 1 || col > 10) {
                cout << "Invalid selection!\n";
            }
            else if (computers[row-1][col-1] == 0) {
                cout << "Computer unit is already available!\n";
            }
            else {
                int hours = computers[row-1][col-1];
                double sale = hours * 20.00;

                char r = 'A' + (row - 1);

                cout << "Computer unit " << r << col << " has been returned.\n";
                cout << "Rental Sale: P" << sale << endl;

                computers[row-1][col-1] = 0;
            }
        }

        else if (choice == 4) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 10; j++) {
                    computers[i][j] = 0;
                }
            }
            cout << "Rental system reset successfully!\n";
        }

    } while (choice != 5);

    cout << "Program exited.\n";

    return 0;
}