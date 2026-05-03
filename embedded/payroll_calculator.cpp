/*
 * Weekly Payroll Calculator
 *
 * Prompts for N employees' hours worked (1–40) and hourly rate,
 * computes each employee's weekly pay, and prints the company average.
 */

#include <iostream>
#include <iomanip>
using namespace std;

bool isValidHours(int hours) {
  return hours >= 1 && hours <= 40;
}

float calcPay(int hours, float rate) {
  return hours * rate;
}

float calcAveragePay(float total, int n) {
  return total / n;
}

int main() {
  int   numEmployees;
  float totalPay = 0.0f;

  cout << "=== Weekly Payroll Calculator ===\n";
  cout << "Number of employees: ";
  cin >> numEmployees;
  while (numEmployees < 1) {
    cout << "Must be at least 1. Try again: ";
    cin >> numEmployees;
  }

  cout << fixed << setprecision(2);

  for (int i = 1; i <= numEmployees; i++) {
    int   hours;
    float rate;

    cout << "\nEmployee " << i << ":\n";
    cout << "  Hours worked (1-40): ";
    cin >> hours;
    while (!isValidHours(hours)) {
      cout << "  Invalid. Enter 1-40: ";
      cin >> hours;
    }
    cout << "  Hourly rate ($): ";
    cin >> rate;

    float pay = calcPay(hours, rate);
    totalPay += pay;
    cout << "  Weekly pay: $" << pay << "\n";
  }

  cout << "\nCompany average weekly pay: $"
       << calcAveragePay(totalPay, numEmployees) << "\n";

  return 0;
}
