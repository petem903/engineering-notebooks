/*
 * Grade Drop Calculator
 *
 * Reads 5 grades, identifies the lowest, drops it, and reports
 * both the raw average and the adjusted final average.
 */

#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 5;

void getGrades(double grades[]) {
  cout << "Enter " << SIZE << " grades:\n";
  for (int i = 0; i < SIZE; i++) {
    cout << "  Grade " << (i + 1) << ": ";
    cin >> grades[i];
  }
}

double calcAverage(const double grades[], int count) {
  double total = 0;
  for (int i = 0; i < count; i++) total += grades[i];
  return total / count;
}

int findLowest(const double grades[]) {
  int idx = 0;
  for (int i = 1; i < SIZE; i++)
    if (grades[i] < grades[idx]) idx = i;
  return idx;
}

double calcDropAverage(const double grades[], int dropIdx) {
  double total = 0;
  for (int i = 0; i < SIZE; i++) total += grades[i];
  return (total - grades[dropIdx]) / (SIZE - 1);
}

int main() {
  double grades[SIZE];
  getGrades(grades);

  int    lowestIdx = findLowest(grades);
  double rawAvg    = calcAverage(grades, SIZE);
  double finalAvg  = calcDropAverage(grades, lowestIdx);

  cout << fixed << setprecision(2);
  cout << "\nGrade dropped : " << grades[lowestIdx] << "\n";
  cout << "Raw average   : " << rawAvg   << "\n";
  cout << "Final average : " << finalAvg << "\n";

  return 0;
}
