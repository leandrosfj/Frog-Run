#include "tempo.hpp"

#include<iostream>

using namespace std;

Tempo::Tempo():horas(0),minutos(0),segundos(0){}

Tempo::Tempo(short h, short m, short s):horas(h), minutos(m), segundos(s){}

short Tempo::getHoras() const{
	return this->horas;
}
short Tempo::getMinutos() const{
	return this->minutos;
}
short Tempo::getSegundos() const{
	return this->segundos;
}

Tempo Tempo::operator+(Tempo &t) const{
	short h = this->horas + t.getHoras();
	short m = this->minutos + t.getMinutos();
	short s = this->segundos + t.getSegundos();

	if (s>=60){
	    m += s/60;
	    s = s%60;
	}

    if (m>=60){
        h += m/60;
        m = m%60;
    }

	return Tempo(h, m, s); // NOLINT(modernize-return-braced-init-list)
}

ostream& operator<< (ostream &o, Tempo const t){
	o << t.getHoras() << ":" 
		<< t.getMinutos() << ":" 
		<< t.getSegundos();
	return o;
}
istream& operator>> (istream &i, Tempo &t){
	i >> t.horas >> t.minutos >> t.segundos;
	return i;
}