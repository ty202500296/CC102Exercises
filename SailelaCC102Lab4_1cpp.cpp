#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char choice;

    do {
        int stud, quiz;

        cout << "Enter number of students: ";
        cin >> stud;
        cout << "Enter number of quizzes: ";
        cin >> quiz;

        double score[50][50];
        double average[50];

        for (int i = 0; i < stud; i++) {
            cout << "Student " << i + 1 << endl;
            double sum = 0;

            for (int j = 0; j < quiz; j++) {
                cin >> score[i][j];
                sum += score[i][j];
            }
            average[i] = sum / quiz;
            cout << "--------------------------------"<<endl;
        }
        cout << "\nStudent ";
        for (int j = 0; j < quiz; j++) {
            cout << "Q" << j + 1 << " ";
        }
        cout << "Average\n";

        for (int i = 0; i < stud; i++) {
            cout << setw(4) << i + 1 << "    ";
            for (int j = 0; j < quiz; j++) {
                cout << setw(3) << score[i][j] << " ";
            }
            cout << fixed << setprecision(2) << average[i] << endl;
        }

        cout << "\nDo you want to try again? (y/n): ";
        cin >> choice;

    } while (choice== 'y' || choice == 'Y');

    return 0;
}
