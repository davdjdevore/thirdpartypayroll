// David Devore

#include "person.h"


Person::Person(){
  firstName;
  lastName;
  employeeID;
  companyName;
  hoursWorked;
  payRate;
}
Person::Person(string fName, string lName, int id, string comName,
    float hours, float rate){
      firstName = fName;
      lastName = lName;
      employeeID = id;
      companyName = comName;
      hoursWorked = hours;
      payRate = rate;
    }
void Person::setFirstName(string fName){ firstName = fName;}
string Person::getFirstName(){return firstName;}

void Person::setLastName(string lName){lastName = lName;}
string Person::getLastName(){return lastName;}

void Person::setEmployeeId(int id){employeeID = id;}
int Person::getEmployeeId(){return employeeID;}

void Person::setCompanyName(string coName){companyName = coName;}
string Person::getCompanyName(){return companyName;}

void Person::setPayRate(float rate){payRate = rate;}
float Person::getPayRate(){return payRate;}

void Person::setHoursWorked(float hours){hoursWorked = hours;}
float Person::getHoursWorked(){return hoursWorked;}

float Person::totalPay(){ return payRate * hoursWorked;}
string Person::fullName() {return firstName + " " + lastName;}
