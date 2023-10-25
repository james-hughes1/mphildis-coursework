#include<iostream>
#include<string>

class Rational {
public:
    int numer() {
        return r_num;
    };
    int denom() {
        return r_den;
    };
    float value() {
        return (float(r_num) / float(r_den));
    };
    Rational(int, int);
    Rational operator*(Rational x)const{
        return Rational(r_num * x.r_num, r_den * x.r_den);
    };
    Rational& operator*=(Rational x){
        r_num *= x.r_num;
        r_den *= x.r_den;
        return *this;
    };

    Rational operator+(Rational x)const{
        return Rational(r_num*x.r_den + x.r_num*r_den, r_den * x.r_den);
    };
    Rational operator/(Rational x)const{
        return Rational(r_num * x.r_den, r_den * x.r_num);
    };
    Rational operator-(Rational x)const{
        return Rational(r_num*x.r_den - x.r_num*r_den, r_den * x.r_den);
    };
private:
    int r_num;
    int r_den;
};

Rational::Rational(int p, int q) {
    if (q!=0) {
        int i=2;
        while ((i<p) | (i<q)) {
            if ((p%i==0) & (q%i==0)) {
                p /= i;
                q /= i;
                i=2;
            }
            i++;
        }
        r_num = p;
        r_den = q;
    }
    else {
        std::cout << "Zero Division is bad!" << std::endl;
    }
    
}

int main() {
    Rational x = Rational(2,3);
    Rational y = Rational(3,10);
    x *= y;
    Rational w = x+Rational(5,8);
    Rational s = x/w;
    std::cout << "x = " << x.value() << std::endl;
    std::cout << "Reduced fraction for x is " << x.numer() << "/" << x.denom() << std::endl;
    std::cout << "w = " << w.value() << std::endl;
    std::cout << "Reduced fraction for w is " << w.numer() << "/" << w.denom() << std::endl;
    std::cout << "s = " << s.value() << std::endl;
    std::cout << "Reduced fraction for s is " << s.numer() << "/" << s.denom() << std::endl;
    Rational t = Rational(7,0);
}