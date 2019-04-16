#include "person.cpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include<vector>
using namespace std;

void readData(vector <Person> &employees);
void getCompanies(vector <Person> &employees, vector <string> &names);
void printHighestPaid(vector <Person> &employees);
void separateAndSave(vector <Person> &employees, vector <string> &companyNames);

int main(){

  vector <Person> employees;
  vector <string> companyNames;

  readData(employees);

  getCompanies(employees, companyNames);

  printHighestPaid(employees);

  separateAndSave(employees, companyNames);
  return 0;
};


void readData(vector <Person> &employees){

  ifstream inFile;
  inFile.open("input.txt");

  Person person;
  string fName;
  string lName;
  int    id;
  string cName;
  float  hours;
  float  pay;

  inFile >> fName;

  while (!inFile.eof()){

    inFile >> lName;
    inFile >> id;
    inFile >> cName;
    inFile >> hours;
    inFile >> pay;

    person.setFirstName(fName);
    person.setLastName(lName);
    person.setEmployeeId(id);
    person.setCompanyName(cName);
    person.setHoursWorked(hours);
    person.setPayRate(pay);

    employees.push_back(person);

    inFile >> fName;
  };

  inFile.close();

};

void getCompanies(vector <Person> &employees, vector <string> &names){

  string name;
  Person person;
  bool found = false;

  for (int i; i < employees.size(); i++){
    person = employees.at(i);
    name = person.getCompanyName();


// Compares name to list of companyNames
    for (int j =0; j< names.size(); j++){
      if (name.compare(names[j]) == 0){
        found = true;
        break;
      }
      else
        found = false;
    };

// If name was not found, it is added to list.
    if (found == false)
    names.push_back(name);
  };

};

void printHighestPaid(vector <Person> &employees){

  int highest = 0;
  Person person,person2;
//defaut highest paid is the first employee, loop compares them starting with 2nd employee
  for (int i=0; i < employees.size()-1; i++){
    person = employees.at(highest);
    person2 = employees.at(i+1);

    if (person.totalPay() < person2.totalPay())
      highest = i+1;
  };

  //highest paid output
  person = employees.at(highest);
  cout << fixed << setprecision(2);
  cout << "Highest Paid: " << person.fullName() << endl;
  cout << "Employee ID: " << person.getEmployeeId() <<endl;
  cout << "Employer: " << person.getCompanyName() << endl;
  cout << "Total Pay: $" << person.totalPay() <<endl;
};

void separateAndSave(vector <Person> &employees, vector <string> &companyNames){

    ofstream outfiles[companyNames.size()];
    Person person;
// Track the total pay for each company, default = 0
    float total[companyNames.size()] = {0};

//opens each file for each company
    for (int i = 0; i <companyNames.size(); i++){
      outfiles[i].open(companyNames[i]);
    };
// process employees for each company
    for (int i=0; i < companyNames.size(); i++){
      outfiles[i] << fixed << setprecision(2);

      for (int j =0; j< employees.size(); j++){
        person = employees[j];
        if (person.getCompanyName().compare(companyNames[i]) == 0){
          outfiles[i] << setw(15) << left << person.getFirstName();
          outfiles[i] << setw(15) << person.getLastName();
          outfiles[i] << setw(5) << person.getEmployeeId();
          outfiles[i] << setw(15) << person.getCompanyName();
          outfiles[i] << "$" << person.totalPay();
          outfiles[i] << "\n";
// Tracks a companies' total pay 
          total[i] += person.totalPay();
        };

      };
      outfiles[i] << "Total $" << total[i];
    };

//closes each file for each company
    for (int i = 0; i <companyNames.size(); i++){
      outfiles[i].close();
    };
};
