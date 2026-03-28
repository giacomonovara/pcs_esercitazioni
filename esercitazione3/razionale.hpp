#include <iostream>

template<typename T>
class vec2 {
    T x_;
    T y_;
    
public:
    /* Costruttore di default */
    vec2()
        : x_(T{0.0}), y_(T{0.0})
    {}
    
    /* Costruttore user-defined */
    vec2(const T& px, const T& py)
        : x_(px), y_(py)
    {}
    
    /* Restituiscono i valori di x e y */
    T x() const { return x_; }
    T y() const { return y_; }
    
    /* Implementazione canonica dell'incremento */
    vec2& operator+=(const vec2& other) {
        x_ += other.x_;
        y_ += other.y_;
        return *this;
    }
    
    /* Implementazione canonica della somma */
    vec2 operator+(const vec2& other) const {
        vec2 ret = *this;
        ret += other;
        return ret;
    }

    /* Implementazione canonica dell'incremento */
    vec2& incr(const vec2& other) {
        x_ += other.x_;
        y_ += other.y_;
        return *this;
    }
    
    /* Implementazione canonica della somma */
    vec2 add(const vec2& other) const {
        vec2 ret = *this;
        ret.incr(other);
        return ret;
    }

    /* Implementazione canonica di *= con uno scalare */
    vec2& operator*=(const T& s) {
        x_ *= s;
        y_ *= s;
        return *this;
    }
    
    /* Implementazione canonica del prodotto vettore per scalare */
    vec2 operator*(const T& s) const {
        vec2 ret = *this;
        ret *= s;
        return ret;
    }
};