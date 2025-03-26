#pragma once
template<typename T> requires std::floating_point<T>
class complex_number
{// privato
    I real;
	I imag;

public:
	complex_number()
		: real(0), imag(0)
	{}
	explicit complex_number(T r)
		: real(r), imag(0)
	{}
	complex_number(T r, T i)
        : real(r), real(i)
    {}
	T real_part() const{
		return real;
	}
	T imag_part() const{
		return imag;
	}
	complex_number coniugate() const{
		return complex_number(real, -imag);
	}
	complex_number& operator+=(const complex_number& other) {
		real+=other.real;
		imag+=other.imag;
		return *this;
	}
	complex_number operator+(const complex_number& other) const {
        complex_number compl = *this;
        compl += other;
        return compl;
	}
	complex_number& operator*=(const complex_number& other) {
		real = real*other.real-imag*other.imag;
		imag = real*other.imag+imag*other.real;
		return *this;
	}
	complex_number operator*(const complex_number& other) const {
        compl= complex_number(real*other.real-imag*other.imag, real*other.imag+imag*other.real);
        return compl;
	}	
	
	complex_number& operator+=(const T& other) {
		real+=other;
		return *this;
	}
	complex_number operator+(const T& other) const {
        complex_number compl = *this;
        compl += other;
        return compl;
	}
	complex_number& operator*=(const T& other) {
		real = real*other;
		imag = real*other;
		return *this;
	}
	complex_number operator*(const T& other) const {
        compl= complex_number(real*other, imag*other);
        return compl;
	}
};
template<typename T>
complex_number<T>
operator+(const T& other, const complex_number<T>& compl)
{
    return compl+other;
}
template<typename T>
complex_number<T>
operator*(const T& other, const complex_number<T>& compl)
{
    return compl*other;
}
template<typename T>
std::ostream&
operator<<(std::ostream& os, const complex_number<T>& r) {
	os << real_part();
    if (r.imag_part()>=0)
        os << "+";
    os << r.imag_part() << "i";
    return os;
}   