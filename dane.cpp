#include"dane.h"
#include<string>
#include<stdexcept>
using namespace std;

Emeryt::Emeryt()
{

}

Emeryt::~Emeryt()
{

}

string Emeryt::getImie()
{
    return Imie;
}

string Emeryt::getNazwisko()
{
    return Nazwisko;
}

string Emeryt::getPESEL()
{
    return PESEL;
}

string Emeryt::getDzien()
{
    string pesel=getPESEL();
    string dzien=pesel.substr(4,2);

    //int wynik=stoi(dzien);
    return dzien;
}

string Emeryt::getMiesiac()
{
    string pesel=getPESEL();
    string miesiac=pesel.substr(2,2);

    if(miesiac[0]=='2')
        miesiac[0]='0';

    else if(miesiac[0]=='3')
        miesiac[0]='1';

        //int wynik=stoi(miesiac);
    return miesiac;
}

string Emeryt::getRok()
{
    string rok="1234";  //musi byc jakas wartosc poczatkowa stringa bo inaczej moj super kod nie dziala xD
    string pesel=getPESEL();
    string miesiac=pesel.substr(2,2);

    if(miesiac[0]=='2' || miesiac[0]=='3')
        {
            rok[0]='2';
            rok[1]='0';
        }
    else
        {
            rok[0]='1';
            rok[1]='9';
        }

    string temp=pesel.substr(0,2);

    rok[2]=temp[0];
    rok[3]=temp[1];

    //int wynik=stoi(rok);
    return rok;
}

void Emeryt::setImie(string _imie)
{
    Imie=_imie;
}

void Emeryt::setNazwisko(string _nazwisko)
{
    Nazwisko=_nazwisko;
}

void Emeryt::setPesel(string _pesel)
{
    PESEL=_pesel;
}

bool Emeryt::operator<=(const Emeryt&E) const
{

 if(Rok <= E.Rok)
        return true;

    if(Rok == E.Rok)
    {
        if(Miesiac <= E.Miesiac)
            return true;

        if(Miesiac == E.Miesiac)
        {
            if(Dzien < E.Dzien)
                return true;
        }
    }

                return false;
}

bool Emeryt::operator<(const Emeryt&E) const
{
    if(Rok < E.Rok)
        return true;

    if(Rok > E.Rok)
        return false;

    if(Rok == E.Rok)
    {
        if(Miesiac < E.Miesiac)
            return true;
        if(Miesiac > E.Miesiac)
            return false;

        if(Miesiac == E.Miesiac)
        {
            if(Dzien < E.Dzien)
                return true;
        }
    }

                return false;
}


void Emeryt::setRok()
{
    string R=getRok();
    Rok=stoi(R);
}

void Emeryt::setMiesiac()
{
    string M=getMiesiac();
    Miesiac=stoi(M);
}

void Emeryt::setDzien()
{
    string D=getDzien();
    Dzien=stoi(D);
}

bool Emeryt::poprawnyPesel()
{
    string pes=getPESEL();
    char znak;
    int sumaK=0;

    znak=pes[0];
    znak=znak-'0';
    sumaK+=znak;

    znak=pes[1];
    znak=znak-'0';
    sumaK=sumaK+(znak*3);

    znak=pes[2];
    znak=znak-'0';
    sumaK=sumaK+(znak*7);

    znak=pes[3];
    znak=znak-'0';
    sumaK=sumaK+(znak*9);

    znak=pes[4];
    znak=znak-'0';
    sumaK+=znak;

    znak=pes[5];
    znak=znak-'0';
    sumaK=sumaK+(znak*3);

    znak=pes[6];
    znak=znak-'0';
    sumaK=sumaK+(znak*7);

    znak=pes[7];
    znak=znak-'0';
    sumaK=sumaK+(znak*9);

    znak=pes[8];
    znak=znak-'0';
    sumaK+=znak;

    znak=pes[9];
    znak=znak-'0';
    sumaK=sumaK+(znak*3);

    znak=pes[10];
    znak=znak-'0';
    sumaK+=znak;

    if(sumaK%10==0)
        return true;

    else
        return false;

}



