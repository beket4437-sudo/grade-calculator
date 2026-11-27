#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string userInputStudentName;
    int totalStudentCount = 0;
    double cumulativeClassScoreSum = 0.0;

    cout << "Enter student name or type 'end' to finish: ";
    while (cin >> userInputStudentName && userInputStudentName != "end") {
        string currentStudentName = userInputStudentName;
        double currentStudentScoreSum = 0;
        int validatedScoresCount = 0;

        cout << "Enter 5 scores for " << currentStudentName << " (0-100):\n";
        while (validatedScoresCount < 5) {
            double enteredTestScore;
            cin >> enteredTestScore;
            if (enteredTestScore < 0 || enteredTestScore > 100) {
                cout << "Invalid score. Please enter a value between 0 and 100: ";
            } else {
                currentStudentScoreSum += enteredTestScore;
                validatedScoresCount++;
            }
        }

        double calculatedStudentAverage = currentStudentScoreSum / 5.0;
        cumulativeClassScoreSum += calculatedStudentAverage;
        totalStudentCount++;

        char assignedLetterGrade;
        if (calculatedStudentAverage >= 90) assignedLetterGrade = 'A';
        else if (calculatedStudentAverage >= 75) assignedLetterGrade = 'B';
        else if (calculatedStudentAverage >= 60) assignedLetterGrade = 'C';
        else assignedLetterGrade = 'F';

        cout << fixed << setprecision(1);
        cout << "Student: " << currentStudentName << " | Average: " << calculatedStudentAverage << " | Grade: " << assignedLetterGrade << "\n\n";

        cout << "Enter next student name or type 'end' to finish: ";
    }

    if (totalStudentCount == 0) {
        cout << "No students entered." << endl;
    } else {
        cout << fixed << setprecision(1);
        cout << "\nTotal students: " << totalStudentCount << endl;
        cout << "Class average: " << cumulativeClassScoreSum / totalStudentCount << endl;
    }

    return 0;
}
