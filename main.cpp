#include <iostream>
using namespace std;

double managerSalary(double hoursWorked);
double officerSalary(double hoursWorked);
double contractorSalary(double hoursWorked);

int main() {
  int employeeNo;
  cout << "Enter the number of employees you wish to calculate salaries for: ";
  cin >> employeeNo;
  string employeeName[employeeNo];
  string employeePos[employeeNo];
  double employeeWorkHrs[employeeNo];
  double weeklySalary[employeeNo];
  int changeCondition = 0;
  int changeSelector;
  int indexPoint;
  int printOption;
  string nameIndex;
  string positionIndex;
  double wrkHrsIndex;
  double salaryIndex;
  string reverseName[employeeNo];
  string reversePos[employeeNo];
  double reverseHrs[employeeNo];
  double reverseSalary[employeeNo];

  for(int i = 0; i < employeeNo; i++) {
    cout << "\nEnter employee name: ";
    cin >> employeeName[i];
    cout << "\nEnter employee position(Manager, Officer or Contractor can be entered only): ";
    cin >> employeePos[i];
    cout << "\nEnter hours worked for the week: ";
    cin >> employeeWorkHrs[i];
  }

  cout << "\nDo you want to make changes? If yes enter '1', if no enter '0': ";
  cin >> changeCondition;

  while(changeCondition > 0) {
    cout << "\nWhat do you want to change";
    cout << "\n1) Employee Name" << "\n2) Employee Position" << "\n3) Hours Worked";
    cout << "\nEnter corresponding number: ";
    cin >> changeSelector;
    switch(changeSelector) {
      case 1: cout << "\nWhich entry you want to change? e.g. 1 for first, 2 for second: ";
              cin >> indexPoint;
              cout << "\nEnter new name: ";
              cin >> employeeName[indexPoint - 1];
      break;
      case 2: cout << "\nWhich entry you want to change? e.g. 1 for first, 2 for second: ";
              cin >> indexPoint;
              cout << "\nEnter new position: ";
              cin >> employeePos[indexPoint - 1];
      break;
      case 3: cout << "\nWhich entry you want to change? e.g. 1 for first, 2 for second: ";
              cin >> indexPoint;
              cout << "\nEnter new hours worked: ";
              cin >> employeeWorkHrs[indexPoint - 1];
      break;
      default: cout << "\nWrong entry!";
    }
    cout << "\nDo you want to make additional changes? '1' for yes, '0' for no: ";
    cin >> changeCondition;
  }
  
  for(int y = 0; y < employeeNo; y++) {
    if(employeePos[y] == "Manager") {
      weeklySalary[y] = managerSalary(employeeWorkHrs[y]); 
    }
    else if(employeePos[y] == "Officer") {
      weeklySalary[y] = officerSalary(employeeWorkHrs[y]);
    }
    else if(employeePos[y] == "Contractor") {
      weeklySalary[y] = contractorSalary(employeeWorkHrs[y]);
    }
    else {
      cout << "Wrong position entry.";
    }
  }
  cout << "\nName\t" << "Position\t" << "Hours Worked\t" << "Weekly Salary\n";
  for(int j = 0; j < employeeNo; j++) {
    cout << employeeName[j];
    cout << "--";
    cout << employeePos[j];
    cout << "--";
    cout << employeeWorkHrs[j];
    cout << "Hours";
    cout << "--";
    cout << "$";
    cout << weeklySalary[j];
    cout << "\n";
  }

  for(int x = 0; x < employeeNo; x++) {
    for(int z = 0; z < employeeNo - 1; z++) {
      if(weeklySalary[z] > weeklySalary[z + 1]) {
        
        salaryIndex = weeklySalary[z];
        weeklySalary[z] = weeklySalary[z + 1];
        weeklySalary[z + 1] = salaryIndex;

        nameIndex = employeeName[z];
        employeeName[z] = employeeName[z + 1];
        employeeName[z + 1] = nameIndex;

        positionIndex = employeePos[z];
        employeePos[z] = employeePos[z + 1];
        employeePos[z + 1] = positionIndex;

        wrkHrsIndex = employeeWorkHrs[z];
        employeeWorkHrs[z] = employeeWorkHrs[z + 1];
        employeeWorkHrs[z + 1] = wrkHrsIndex;
      }
    }
  }
  cout << "\nIn Ascending Order";
  cout << "\nName\t" << "Position\t" << "Hours Worked\t" << "Weekly Salary\n";
  for(int a = 0; a < employeeNo; a++) {
    cout << employeeName[a];
    cout << "--";
    cout << employeePos[a];
    cout << "--";
    cout << employeeWorkHrs[a];
    cout << "Hours";
    cout << "--";
    cout << "$";
    cout << weeklySalary[a];
    cout << "\n";
  }
  for(int f = 0; f < employeeNo; f++) {
    reverseName[f] = employeeName[employeeNo - f - 1];
    reversePos[f] = employeePos[employeeNo - f - 1];
    reverseHrs[f] = employeeWorkHrs[employeeNo - f - 1];
    reverseSalary[f] = weeklySalary[employeeNo - f - 1];
  }
  cout << "\nIn Descending Order";
  cout << "\nName\t" << "Position\t" << "Hours Worked\t" << "Weekly Salary\n";
  for(int b = 0; b < employeeNo; b++) {
    cout << reverseName[b];
    cout << "--";
    cout << reversePos[b];
    cout << "--";
    cout << reverseHrs[b];
    cout << "Hours";
    cout << "--";
    cout << "$";
    cout << reverseSalary[b];
    cout << "\n";
  }
}

double managerSalary(double hoursWorked) {
  if(hoursWorked < 40) {
    return (11.75 * hoursWorked) - ((11.75 * hoursWorked) * 0.05);
  }
  else if(hoursWorked == 40) {
    return 11.75 * hoursWorked;
  }
  else {
    return (11.75 * hoursWorked) + ((11.75 * hoursWorked) * 0.05);
  }
}

double officerSalary(double hoursWorked) {
  if(hoursWorked < 40) {
    return (9.75 * hoursWorked) - ((9.75 * hoursWorked) * 0.05);
  }
  else if(hoursWorked == 40) {
    return 9.75 * hoursWorked;
  }
  else {
    return (9.75 * hoursWorked) + ((9.75 * hoursWorked) * 0.05);
  }
}

double contractorSalary(double hoursWorked) {
  if(hoursWorked < 40) {
    return (7.25 * hoursWorked) - ((7.25 * hoursWorked) * 0.05);
  }
  else if(hoursWorked == 40) {
    return 7.25 * hoursWorked;
  }
  else {
    return (7.25 * hoursWorked) + ((7.25 * hoursWorked) * 0.05);
  }
}