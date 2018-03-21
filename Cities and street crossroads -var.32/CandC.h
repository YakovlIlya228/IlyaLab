#ifndef CITIES_AND_CROSSINGS_CANDC_H
#define CITIES_AND_CROSSINGS_CANDC_H

#include <iostream>
using namespace std;
int CandC[256], MAX_CROSSINGS=0, city_i=1;

class Cities{
public:
    Cities();
    void add_city(int crossings);
    void delete_city();
};

class Operation{
public:
    void check();
    void show();
};
#endif //CITIES_AND_CROSSINGS_CANDC_H
