#include "Con_and_Des.h"

Employee :: Employee(){
    setNameAndAge();;
}
Employee :: ~Employee() {
    cout << "Employee class destructor was executed!\n";
}
void Employee :: setNameAndAge(){
    printf("Enter name of an employee:\n");
    cin >> Name;
    printf("Enter age of an employee:\n");
    cin >> Age ;
}
void Employer :: setEmrName(){
    printf("Enter name of an employer:\n");
    cin >> EmrName;
};
void Employer :: setEmrAge(){
    printf("Enter age of an employer:\n");
    cin >> EmrAge;
}
Employer :: Employer(){
    setEmrName();
    setEmrAge();
    printf("How many employees does employer have?\n");
    int tmp;
    cin >> tmp;
    Employee emp[tmp];
}
Employer :: ~Employer(){
    cout << "Employer class destructor was executed!\n";
}
