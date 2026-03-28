#pragma once
#include <iostream>
#include <concepts>

template <typename I> //requires std::integral<I>
class razionale {
    I num_;
    I den_;

    void riduz() {
        if (den_ != 0) {
            int a = abs(num_);
            int b = abs(den_);
            if (a != 0) {
                while (a!=b) {
                    while (a > b) {
                        a = a - b;
                    }
                    while (b > a) {
                        b = b - a;
                    }
                }
            }
            if (a!=0) {
                num_ /= a;
                den_ /= a;
            }
            if (den_ < 0) {
                num_ = -num_;
                den_ = -den_;
            }
        }
        else {
            return;   //Inf/NaN
        }
    }          
    
public:
    /* Costruttore di default */
    razionale()
        : num_(I{0.0}), den_(I{1.0})
    {}
    
    /* Costruttore user-defined */
    razionale(const I& numer, const I& denom)
        : num_(numer), den_(denom)
    {}
    
    /* Restituiscono i valori di numeratore e denominatore */
    I num() const { return num_; }
    I den() const { return den_; }
    
    /* Implementazione canonica dell'incremento */
    razionale& operator+=(const razionale& other) {
        if (den_ == 0 || other.den_ == 0) {
            if ((num_ == 0 && den_ == 0) || (other.num_ == 0 && other.den_ == 0)) {
                num_ = 0;   den_ = 0;    //NaN
            }
            else {
                num_ = 1;   den_ = 0;   //Inf
            }
        }
        else {
            num_ = num_ * other.den_ + other.num_ * den_;
            den_ = den_ * other.den_;
            (*this).riduz(); 
        }
        return *this;
    }
    
    /* Implementazione canonica della somma */
    razionale operator+(const razionale& other) const {
        if ((num_ == 0 && den_ == 0) || (other.num_ == 0 && other.den_ == 0)) 
        {
            razionale ret = {0,0};       //caso NaN (sia numeratore che denominatore nulli)
            return ret;    //restituisco NaN
        }
        else if ((num_ != 0 && den_ == 0) || (other.num_ != 0 && other.den_ == 0))
        {
            razionale ret = {1,0};       //caso Inf (solo denominatore nullo)
            return ret;    //restituisco Inf
        }
        else {
            razionale ret = *this;
            ret += other;
            ret.riduz();
            return ret;
        }
    }  

    /* Implementazione canonica del decremento */
    razionale& operator-=(const razionale& other) {
        razionale new_other = {0,0};
        new_other.num_ = -1*other.num_;
        new_other.den_ = other.den_;
        *this += new_other;
        return *this;
    }

    /* Implementazione canonica della differenza */
    razionale operator-(const razionale& other) const {
        razionale new_other={0,0};
        new_other.num_ = -1*other.num_;
        new_other.den_ = other.den_;
        razionale ret = operator+(new_other);
        return ret;
    } 

    /* Implementazione canonica di *= con uno scalare */
    razionale& operator*=(const I& s) {
        if (num_ == 0 && den_ == 0) {
            num_ = 0; den_ = 0; //NaN 
        }
        else if (den_ == 0) {
            num_ = 1; den_ = 0; //Inf
        }
        else {
            num_ *= s;
            riduz();
        }
        return *this;
    }
    
    /* Implementazione canonica del prodotto per scalare */
    razionale operator*(const I& s) const {
        if (num_ == 0 && den_ == 0) 
        {
            razionale ret = {0,0};       //caso NaN (sia numeratore che denominatore nulli)
            return ret;    //restituisco NaN
        }
        else if (num_ != 0 && den_ == 0)
        {
            razionale ret = {1,0};       //caso Inf (solo denominatore nullo)
            return ret;    //restituisco Inf
        }
        else 
        {
            razionale ret = *this;
            ret *= s;
            ret.riduz();
            return ret;
        }
    }

    /* Implementazione canonica di /= per scalare */
    razionale& operator/=(const I& s) {
        if (num_ == 0 && den_ == 0) {
            num_ = 0; den_ = 0; //NaN 
        }
        else if (den_ == 0) {
            num_ = 1; den_ = 0; //Inf
        }
        else {
            den_ *= s;  //moltiplico il denominatore per lo scalare (cioè divido il numeratore)
            riduz();
        }
        return *this;
    }

    /* Implementazione canonica della divisione per scalare */
    razionale operator/(const I& s) const {
        razionale ret = *this;
        ret /= s;
        return ret;
    }

};

template<typename T>
std::ostream&
operator<<(std::ostream& os, const razionale<T>& r)
{
    if (r.den() == 0) {
            if (r.num() == 0) {
                return os << "NaN";
            }
            else {
                return os << "Inf";
            }
        }
    else {
        if (r.num() == 0 && r.den() != 0) {
            return os << " 0 ";
        }
        else {
            os << " " << r.num() << "/" << r.den() << " ";
            return os;
        }
    }
}