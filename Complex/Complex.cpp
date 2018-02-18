#include <iostream>
#include <cmath>
using namespace std;

class Complex{
public:
    double re[256],im[256];
    Complex(){}; // конструктор по умолчанию

    Complex(int c, double a, double b){
        // конструктор задающий мнимую и действительную части комплексного числа
        if(a!=0 or b!=0){
            re[c]=a;
            im[c]=b;}

    }
    Complex(int c){ // конструктор для очистки действительной и мнимой части комп. числа , хранящегося в массиве
        re[c]=0;
        im[c]=0;
    }
    void show(int r){ //отображение заданного числа
        printf("Unit number %i: %.3f + %.3fi\n",r,re[r],im[r]);
    }
    void module(int c){ //модуль заданного числа
        double z;
        z=sqrt(re[c]*re[c] + im[c]*im[c]);
        printf("Module of the unit number %i = %.3f\n",c,z);
    }
    void Complex_plus(int first, int second) { //функция сложения комплексных чисел
        double z1, z2;
        z1 = re[first] + re[second];
        z2 = im[first] + im[second];
        printf("Sum of two values: %.3f + %.3fi\n", z1, z2);
    }

    void Complex_minus(int first, int second){ //Функция вычитания комплексных чисел
        double z1,z2;
        z1=re[first]-re[second];
        z2=im[first]-im[second];
        printf("Quotient of two values: %.3f + %.3fi\n", z1,z2);
    }

};



int main(){
    double temp1, temp2;
    while(true){
        int unit=0; char huy;
        printf("Enter the number to choose an action:\n1 - add complex value\n2 - delete last comlex value\n3 - sum two values\n4 - minus two values\n5 - show already created unit\n6 - calculate module of the unit\n7 - exit\n");
        cin >> huy;
        if(huy=='1'){
            cout << "Enter the values of the unit:\n" << endl;
            cin >> temp1; cin >> temp2;
            cout << "Enter the number of the unit (between 0 and 255):\n" << endl;
            cin >> unit;
            Complex obj1(unit,temp1,temp2);
            obj1.show(unit);
        }
        if(huy=='2'){
            cout << "Enter the number of the unit (between 0 and 255):\n" << endl;
            cin >> unit;
            Complex z(unit);
            z.show(unit);
        }
        if(huy=='3'){
            int tmp1,tmp2;
            printf("Choose units to plus\n");
            cin >> tmp1; cin >> tmp2;
            Complex z(tmp1,0,0);z.Complex_plus(tmp1,tmp2);
        }
        if(huy=='4'){
            int tmp1,tmp2;
            printf("Choose units to minus\n");
            cin >> tmp1; cin >> tmp2;
            Complex z(tmp1,0,0);z.Complex_minus(tmp1,tmp2);
        }
        if(huy=='5'){
            int tmp;
            printf("Enter the number of unit:\n");cin >> tmp;
            Complex z1(tmp,0,0);
            z1.show(tmp);
        }
        if(huy=='6'){
            Complex z; int tmp;
            printf("Enter the number of unit:\n");cin >> tmp;
            z.module(tmp);
        }
        if(huy=='7'){
            printf("Exiting...");
            exit(0);
        }


    }
}



