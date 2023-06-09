#include <map>
#include <vector>
#include <iostream>
#include "Memory.h"
#include "CPU.h"

extern CPU oneCPU;

//Phony If statment
#define tppIF(condition) if(condition) {
#define tppELSEIF(condition) } else if(condition) {
#define tppELSE } else {
#define END }

#define display
//class DataTypes;


Memory memBuffer;


#include <iostream>
#include <sstream>



class Integer;

namespace tpp {
    template<class T>
    void disp(T val) {std::cout<<val;}

    std::string newline = "\n";

    class InputGPT{ //By Mr.GPT but it didn't work, so I had to fix it.
    public:
        template<typename T>
        InputGPT& operator>>(T& value) {
            std::string input_str;
            std::getline(std::cin, input_str);
            std::istringstream stream(input_str);
            typeof(value.val) data;
            stream >> data;
            value = data;
            return *this;
        }
    };
    class Output { //Made my own version of the above for output
    public:
        template<typename T>
        Output& operator<<(const T& value) {
            std::ostringstream stream;
            stream << value;
            std::cout << stream.str();
            return *this;
        }
    };
    Output output;
    InputGPT input;



}
class Integer{ //
    template <class T,class D>
    friend T operator+(T one,D two);
    template <class T,class D>
    friend T operator-(T one,D two);
    friend class InputGPT;
    template <class T>
    friend bool operator!=(T one, T two);
    template <class T, class D>
    friend bool operator!=(T one, D two);
    template <class T>
    friend int operator%(T one, int num);
    friend void operator<<(std::ostream& o, Integer i);
    template <class T>
    friend bool operator==(T one, T two);
    template <class T, class D>
    friend bool operator==(T one, D two);
    template <class T>
    friend T operator+(T one,T two);
    template <class T>
    friend T operator-(T one,T two);
    template <class T>
    friend T operator*(T one,T two);
    template <class T>
    friend T operator/(T one,T two);

public:
    int val = 0;
    size_t address = 0;
public:
    Integer(int i):val(i) {
        memBuffer.allocateMemory(val,address);
    }

    Integer(){
        memBuffer.allocateMemory(val, address);
    }
    Integer& operator=(int val1){
        this->val = val1;
        oneCPU.store(val,address);
        return *this;}

    Integer& operator=(Integer val1){
        this->val = val1.val;
        oneCPU.store(val,address);
        return *this;}
};

class Decimal {
    template <class T,class D>
    friend T operator+(T one,D two);
    template <class T,class D>
    friend T operator-(T one,D two);
    friend class InputGPT;
    template <class T>
    friend bool operator!=(T one, T two);
    template <class T, class D>
    friend bool operator!=(T one, D two);
    template <class T>
    friend int operator%(T one, int num);
    friend void operator<<(std::ostream& o, Integer i);
    template <class T>
    friend bool operator==(T one, T two);
    template <class T, class D>
    friend bool operator==(T one, D two);
    template <class T>
    friend T operator+(T one,T two);
    template <class T>
    friend T operator-(T one,T two);
    template <class T>
    friend T operator*(T one,T two);
    template <class T>
    friend T operator/(T one,T two);
protected:
    float val = 0;
    size_t address =0;
public:
    Decimal(float f) : val(f) {
        memBuffer.allocateMemory(val, address);
    }
    Decimal() {
        memBuffer.allocateMemory(val, address);
    }
    Decimal& operator=(float val1){
        this->val = val1;
        oneCPU.store(val,address);
        return *this;}
    Decimal& operator=(Decimal val1){
        this->val = val1.val;
        oneCPU.store(val,address);
        return *this;}
};

class PreciseDecimal {
    friend class InputGPT;
    template <class T,class D>
    friend T operator+(T one,D two);
    template <class T,class D>
    friend T operator-(T one,D two);
    template <class T>
    friend bool operator!=(T one, T two);
    template <class T, class D>
    friend bool operator!=(T one, D two);
    template <class T>
    friend int operator%(T one, int num);
    friend void operator<<(std::ostream& o, Integer i);
    template <class T>
    friend bool operator==(T one, T two);
    template <class T, class D>
    friend bool operator==(T one, D two);
    template <class T>
    friend T operator+(T one,T two);
    template <class T>
    friend T operator-(T one,T two);
    template <class T>
    friend T operator*(T one,T two);
    template <class T>
    friend T operator/(T one,T two);
protected:
    double val = 0;
    size_t address = 0;
public:
    PreciseDecimal(double d) : val(d) {
        memBuffer.allocateMemory(val, address);
    }
    PreciseDecimal() {
        memBuffer.allocateMemory(val, address);
    }
    PreciseDecimal& operator=(double val1) {
        this->val = val1;
        oneCPU.store(val,address);
        return *this;
    }
    PreciseDecimal& operator=(const PreciseDecimal& val1) {
        this->val = val1.val;
        oneCPU.store(val,address);
        return *this;
    }
};



int main() {

    Integer month = 0;
    Integer year = 0;
    Integer day = 0;
    Decimal money = 0;
    PreciseDecimal pi = 0;

    using namespace tpp;

    disp("What day were you born on?(1-31)");
    input >> day;
    disp(newline);
    disp("What month were you born on?(1-12)");
    input >> month;
    disp(newline);
    disp("What year were you born on?");
    disp(newline);
    input >> year;
    tppIF(month == 1){
        output << "\nYour birthday, January " << day << ", " << year;
    }
    tppELSEIF(month == 2){
        output << "\nYour birthday,February" << day << ", " << year;
    }
    tppELSEIF(month == 3){
        output << "\nYour birthday,March " << day << ", " << year;
    }

    tppELSEIF(month == 4)output << "\nYour birthday,April " << day << ", " << year;
    tppELSEIF(month == 5)output << "\nYour birthday,May " << day << ", " << year;
    tppELSEIF(month == 6)output << "\nYour birthday,June " << day << ", " << year;
    tppELSEIF(month == 7)output << "\nYour birthday,July " << day << ", " << year;
    tppELSEIF(month == 8)output << "\nYour birthday,August " << day << ", " << year;
    tppELSEIF(month == 9)output << "\nYour birthday,September " << day << ", " << year;
    tppELSEIF(month == 10)output << "\nYour birthday,October " << day << ", " << year;
    tppELSEIF(month == 11)output << "\nYour birthday,November " << day << ", " << year;
    tppELSEIF (month == 12)output << "\nYour birthday,December " << day << ", " << year;
    tppELSE output<<"\nNot a month!\n";
    END
    tppIF(((year%4==0 && year%100!=0)||year%400==0)) output<<" is a leap year.";
    tppELSE output<<" is not a leap year";
    END
}

//Overloaded Functions Below
void operator<<(std::ostream& o, Integer i){o<<i.val;}

template <class T>
int operator%(T one, int num) {
    int three;
    three = oneCPU.modulo(oneCPU.load<typeof(one.val)>(one.address), num);
    return static_cast<typeof(one.val)>(three);
}

template <class T>
T operator+(T one,T two){
    typeof(one.val) three;
    three = oneCPU.add(oneCPU.load<typeof(one.val)>(one.address)
            ,(oneCPU.load<typeof(two.val)>(two.address)));
    return three;

}

template <class T,class D>
T operator+(T one,D two){
    typeof(one.val) three;
    three = oneCPU.add(oneCPU.load<typeof(one.val)>(one.address)
            ,static_cast<typeof(one.val)>(two));
    return three;

}

template <class T,class D>
T operator-(T one,D two) {
    typeof(one.val) three;
    three = oneCPU.add(oneCPU.load<typeof(one.val)>(one.address), static_cast<typeof(one.val)>(-two));
    return three;
}

    template <class T>
T operator-(T one,T two){
    typeof(one.val) three;

    three = oneCPU.add(oneCPU.load<typeof(one.val)>(one.address)
            ,-(oneCPU.load<typeof(one.val)>(two.address)));
    return three;
}

template <class T>
T operator*(T one,T two){

    typeof(one.val) three;
    three = oneCPU.multiply(oneCPU.load<typeof(one.val)>(one.address)
            ,oneCPU.load<typeof(two.val)>(two.address));
    return three;
}

template <class T>
T operator/(T one,T two){

    float three;
    three = oneCPU.divide(static_cast<float>(oneCPU.template load<typeof(one.val)>(one.address))
            ,static_cast<float>(oneCPU.load<typeof(two.val)>(two.address)));

    return three;
}

template <class T>
tpp::Output& operator<<(tpp::Output& o, const T &i) {
    o << i.val;
    return o;
}

template <class T>
bool operator==(T one, T two){
    if(oneCPU.load<typeof(one.val)>(one.address) == oneCPU.load<typeof(two.val)>(two.address)){
        return true;
    }
    else return false;
}
template <class T, class D>
bool operator==(T one, D two){
    if(oneCPU.load<typeof(one.val)>(one.address) == two){
        return true;
    }
    else return false;
}
template <class T>
bool operator!=(T one, T two){
    if(oneCPU.load<typeof(one.val)>(one.address) != oneCPU.load<typeof(two.val)>(two.address)){
        return true;
    }
    else return false;
}
template <class T, class D>
bool operator!=(T one, D two){
    if(oneCPU.load<typeof(one.val)>(one.address) != two){
        return true;
    }
    else return false;
}

template <class T> bool operator==(T one, int two);
template <class T> bool operator==(T one, float two);
template <class T> bool operator==(T one, double two);
template <class T> bool operator!=(T one, int two);
template <class T> bool operator!=(T one, float two);
template <class T> bool operator!=(T one, double two);
