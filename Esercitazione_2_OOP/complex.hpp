#pragma once
// classe per numeri complessi con template
template<typename T> requires std::floating_point<T>
class complex_number
{// privato
    T real;
	T imag;

public: 
	complex_number() // costruttore di default
		: real(0), imag(0)
	{}
	explicit complex_number(T r)
		: real(r), imag(0)
	{}
	complex_number(T r, T i) // costruttore user-default per inizializzare la parte reale e la parte immaginaria
        : real(r), imag(i)
    {}
	T real_part() const{ // restituisce parte reale del numero complesso
		return real;
	}
	T imag_part() const{ // restituisce parte immaginaria del numero complesso
		return imag;
	}
	complex_number coniugate() const{ // restituisce il coniugato
		return complex_number(real, -imag);
	}
	complex_number& operator+=(const complex_number& other) { // overload per l'operatore +=
		real+=other.real;
		imag+=other.imag;
		return *this;
	}
	complex_number operator+(const complex_number& other) const { // overload per l'operatore +
        complex_number comp = *this;
        comp += other;
        return comp;
	}
	complex_number& operator*=(const complex_number& other) { // overload per l'operatore *=
		real = real*other.real-imag*other.imag;
		imag = real*other.imag+imag*other.real;
		return *this;
	}
	complex_number operator*(const complex_number& other) const { // overload per l'operatore *
        return complex_number(real*other.real-imag*other.imag, real*other.imag+imag*other.real);
	}	
	
	complex_number& operator+=(const T& other) { // overload per l'operatore += con numero T a destra
		real+=other;
		return *this;
	}
	complex_number operator+(const T& other) const { // overload per l'operatore + con numero T a destra
        complex_number comp = *this;
        comp += other;
        return comp;
	}
	complex_number& operator*=(const T& other) { // overload per l'operatore *= con numero T a destra
		real = real*other;
		imag = real*other;
		return *this;
	}
	complex_number operator*(const T& other) const { // overload per l'operatore * con numero T a destra
        return complex_number(real*other, imag*other);
	}
};
template<typename T> // overload per l'operatore + con numero T a sinistra
complex_number<T>
operator+(const T& other, const complex_number<T>& comp)
{
    return comp+other;
}
template<typename T> // overload per l'operatore * con numero T a sinistra
complex_number<T>
operator*(const T& other, const complex_number<T>& comp)
{
    return comp*other;
}
template<typename T> // overload per stampare un numero complesso
std::ostream&
operator<<(std::ostream& os, const complex_number<T>& r) {
	os << r.real_part();
    if (r.imag_part()>=0)
        os << "+";
    os << r.imag_part() << "i";
    return os;
}   