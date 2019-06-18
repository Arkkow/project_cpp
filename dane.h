#ifndef DANE_H_INCLUDED
#define DANE_H_INCLUDED
#include<string>
using namespace std;

struct Emeryt
{
private:
    string Imie;
    string Nazwisko;
    string PESEL;
    string Rok;
    string Miesiac;
    string Dzien;

public:
    Emeryt();
    ~Emeryt();
    string getImie();
    string getNazwisko();
    string getPESEL();
    string getRok();
    string getMiesiac();
    string getDzien();
    void setRok();
    void setMiesiac();
    void setDzien();
    void setImie(string _imie);
    void setNazwisko(string _nazwisko);
    void setPesel(string _pesel);
    bool operator <=(const Emeryt&E) const;
    bool operator <(const Emeryt&E) const;
    bool poprawnyPesel();
};


#endif // DANE_H_INCLUDED
