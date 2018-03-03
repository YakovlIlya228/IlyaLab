//
// Created by Ilya Yakovlev on 01.03.2018.
//

#ifndef CITIES_AND_CROSSINGS_CANDC_H
#define CITIES_AND_CROSSINGS_CANDC_H

#include <iostream>
using namespace std;
class Cities{
    int CandC[256], MAX_CROSSINGS=0, city_i=1;
public:
    Cities();
    void add_city(int crossings);
    void delete_city();
    void check();
};
#endif //CITIES_AND_CROSSINGS_CANDC_H
