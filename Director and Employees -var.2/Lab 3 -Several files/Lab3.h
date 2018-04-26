#ifndef CON_AND_DES_LAB3_CON_AND_DES_H
#define CON_AND_DES_LAB3_CON_AND_DES_H
#include <iostream>
using namespace std;

class Employee{
private:
    string Name;
    int Age;
public:
    Employee();
    ~Employee();
    void setNameAndAge();

};
class Employer{
private:
    string EmrName;
    int EmrAge;
public:
    void setEmrName();
    void setEmrAge();
    Employer();
    ~Employer();
};
#endif //CON_AND_DES_LAB3_CON_AND_DES_H
