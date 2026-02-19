#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char choice;

    do {
        double sales[5][4] = {0};
        int salespip, product;
        double amount;
        char choices;

        do {
            cout << "Salesperson (1-4): ";
            cin >> salespip;
            cout << "Product (1-5): ";
            cin >> product;
            cout << "Amount: ";
            cin >> amount;

            sales[product - 1][salespip - 1] += amount;

            cout << "Add another sale? (y/n): ";
            cin >> choices;

        } while (choices == 'y' || choices == 'Y');

        cout << "\nProduct ";
        for (int s = 0; s < 4; s++) {
            cout << setw(10) << "SP" << s + 1;
        }
        cout << setw(10) << "Total\n";

        double grandTotal = 0;
        double colTotal[4] = {0};

        for (int p = 0; p < 5; p++) {
            double rowTotal = 0;
            cout << setw(4) << p + 1 << "    ";

            for (int s = 0; s < 4; s++) {
                cout << setw(10) << fixed << setprecision(2) << sales[p][s];
                rowTotal += sales[p][s];
                colTotal[s] += sales[p][s];
            }

            cout << setw(10) << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << "Total ";
        for (int s = 0; s < 4; s++) {
            cout << setw(10) << colTotal[s];
        }
        cout << setw(10) << grandTotal << endl;

        cout << "\nDo you want to try again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
