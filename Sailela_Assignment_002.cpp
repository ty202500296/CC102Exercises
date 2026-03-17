#include <iostream>
using namespace std;

void processGrades(int arr[][100], int students, int subjects)
{
    cout << "\nGrade Matrix:\n";

    int highest = arr[0][0];

    for (int i = 0; i < students; i++)
    {
        int sum = 0;

        for (int j = 0; j < subjects; j++)
        {
            cout << arr[i][j] << " ";
            sum += arr[i][j];

            if (arr[i][j] > highest)
                highest = arr[i][j];
        }

        double avg = (double)sum / subjects;
        cout << " | Avg = " << avg;

        cout << endl;
    }

    cout << "\nHighest Grade = " << highest << endl;
}

int main()
{
    int numStudent, numSubject;

    cout << "Enter number of Student: ";
    cin >> numStudent;

    cout << "Enter number of Subject: ";
    cin >> numSubject;

    int grades[100][100];

    for (int i = 0; i < numStudent; i++)
    {
        cout << "Student " << i + 1 << endl;

        for (int j = 0; j < numSubject; j++)
        {
            cout << "Grade in subject " << j + 1 << ": ";
            cin >> grades[i][j];
        }
    }

    processGrades(grades, numStudent, numSubject);

    return 0;
}