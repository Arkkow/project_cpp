#include <iostream>
#include<string>
#include<fstream>
#include"dane.h"
#include"kontener.h"
using namespace std;

int main()
{
    Emeryt Edek;
    Lista<Emeryt> Li;

    ifstream dane;
    dane.open("osoby.txt");
    ifstream pesele;
    pesele.open("pesele.txt");
    string nazwisko,imie,pesel;


    while(!dane.eof() && !pesele.eof())
    {
        dane >> nazwisko;
        dane.get();
        dane >> imie;
        pesele >> pesel;
        if(dane.eof() && !pesele.eof())
        {
            imie="DO";
            nazwisko="WERYFIKACJI";
        }


        try
        {
            Edek.setNazwisko(nazwisko);
            Edek.setImie(imie);
            Edek.setPesel(pesel);

            Edek.setDzien();
            Edek.setMiesiac();
            Edek.setRok();
            Li.insert(Edek);
        }
        catch(exception &e)
        {
            cout<<e.what()<<endl;
        }
    }

    dane.close();
    pesele.close();

    ofstream wyn;
    wyn.open("wyniki.txt");
    int rozmiar=Li.size();

    for(int i=0; i<rozmiar; i++)
    {
        Edek=Li.pop();
        if(Edek.poprawnyPesel()==true)
        {
                    wyn << Edek.getDzien()<<"."
               << Edek.getMiesiac()<<"."
               << Edek.getRok()<<endl
               << Edek.getImie()<<endl
               << Edek.getNazwisko()<<endl<<endl;
        }

    }

    wyn.close();

    return 0;
}
