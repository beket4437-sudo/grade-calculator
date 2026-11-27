C++
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string input;
    int studentCount = 0;
    double totalClassScore = 0.0;

    cout << "Enter student name or type 'end' to finish: ";
    while (cin >> input && input != "end") {
        string studentName = input;
        double sum = 0;
        int validScores = 0;

        cout << "Enter 5 scores for " << studentName << " (0-100):\n";
        while (validScores < 5) {
            double score;
            cin >> score;
            if (score < 0 || score > 100) {
                cout << "Invalid score. Please enter a value between 0 and 100: ";
            } else {
                sum += score;
                validScores++;
            }
        }

        double average = sum / 5.0;
        totalClassScore += average;
        studentCount++;

        char grade;
        if (average >= 90) grade = 'A';
        else if (average >= 75) grade = 'B';
        else if (average >= 60) grade = 'C';
        else grade = 'F';

        cout << fixed << setprecision(1);
        cout << "Student: " << studentName << " | Average: " << average << " | Grade: " << grade << "\n\n";

        cout << "Enter next student name or type 'end' to finish: ";
    }

    if (studentCount == 0) {
        cout << "No students entered." << endl;
    } else {
        cout << fixed << setprecision(1);
        cout << "\nTotal students: " << studentCount << endl;
        cout << "Class average: " << totalClassScore / studentCount << endl;
    }

    return 0;
}
