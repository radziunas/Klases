#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

struct As
{
    string vardas;
    string pavarde;
};

struct Duomenys
{
    string Pavadinimas;
    double Kiekis;
    double Kaina;
    double Savikaina;
    double Pard_kaina;
    double Pelnas;
    double Pvm;
};

class Kioskas
{
public:
    string Pavadinimas;
    double Kiekis;
    double Kaina;
    double Savikaina;
    double Pard_kaina;
    double Pelnas;
    double Pvm;



    void Ivedimas()
    {
        cout<<"iveskite pavadinima: "<<endl;
        cin>>Pavadinimas;
        cout<<"Iveskite kieki: "<<endl;
        cin>>Kiekis;
        cout<<"Iveskite kaina: "<<endl;
        cin>>Kaina;
        cout<<endl;
    }

    void Skaiciavimai ()
    {
        Savikaina=Kaina*1.1;
        Pard_kaina=Savikaina*1.5;
        Pelnas=(Pard_kaina-Savikaina)*Kiekis;
        Pvm=Pelnas*0.21;
    }

};


int main()
{
    As mano;
    cout<<"iveskite savo varda: "<<endl;
    cin>>mano.vardas;
    cout<<"Iveskita savo pavarde: "<<endl;
    cin>>mano.pavarde;
    int n;
    n=5+(20173430%4);
    string pav1, pav2, txt1="_data.txt", txt2="_results.txt";
    pav1=mano.vardas+"_"+mano.pavarde+txt1;
    pav2=mano.vardas+"_"+mano.pavarde+txt2;
    ofstream out(pav1);
    out<<n;
    ofstream out2 (pav2, ios::app);
    Duomenys laik;
    vector <Duomenys> geras;

    Kioskas kioskas;
    for(int i=0;i<n;i++)
    {
        kioskas.Ivedimas();

        kioskas.Skaiciavimai();

        laik.Pavadinimas=kioskas.Pavadinimas;
        laik.Kiekis=kioskas.Kiekis;
        laik.Kaina=kioskas.Kaina;
        laik.Savikaina=kioskas.Savikaina;
        laik.Pard_kaina=kioskas.Pard_kaina;
        laik.Pelnas=kioskas.Pelnas;
        laik.Pvm=kioskas.Pvm;

        geras.push_back(laik);
    }



        cout<<mano.vardas<<" "<<mano.pavarde<<endl;
        cout.fill('-');
        cout.width(109);
        cout<<"-"<<endl;
        cout.fill(' ');

        cout<<"|"<<setw(10)<<"Eil. Nr."<<"|"<<
        setw(30)<<"Pavadinimas"<<"|"<<
        setw(10)<<"Kiekis"<<"|"<<
        setw(10)<<"Kaina"<<"|"<<
        setw(10)<<"Savikaina"<<"|"<<
        setw(10)<<"Pard_kaina"<<"|"<<
        setw(10)<<"Pelnas"<<"|"<<
        setw(10)<<"Pvm"<<"|"<<endl;
        cout.fill('-');
        cout.width(109);
        cout<<"-"<<endl;
        cout.fill(' ');

    for(int i=0;i<n;i++)
    {
        cout<<"|"<<setw(10)<<i+1<<"|"<<
        setw(30)<<setprecision(2)<<fixed<<geras.at(i).Pavadinimas<<"|"<<
        setw(20)<<setprecision(2)<<fixed<<geras.at(i).Kiekis<<"|"<<
        setw(20)<<setprecision(2)<<fixed<<geras.at(i).Kaina<<"|"<<
        setw(20)<<setprecision(2)<<fixed<<geras.at(i).Savikaina<<"|"<<
        setw(20)<<setprecision(2)<<fixed<<geras.at(i).Pard_kaina<<"|"<<
        setw(20)<<setprecision(2)<<fixed<<geras.at(i).Pelnas<<"|"<<
        setw(20)<<setprecision(2)<<fixed<<geras.at(i).Pvm<<"|"<<endl;

        out2<<setprecision(2)<<i+1<<
        " "<<setprecision(2)<<fixed<<geras.at(i).Pavadinimas<<
        " "<<setprecision(2)<<fixed<<geras.at(i).Kiekis<<
        " "<<setprecision(2)<<fixed<<geras.at(i).Kaina<<
        " "<<setprecision(2)<<fixed<<geras.at(i).Savikaina<<
        " "<<setprecision(2)<<fixed<<geras.at(i).Pard_kaina<<
        " "<<setprecision(2)<<fixed<<geras.at(i).Pelnas<<
        " "<<setprecision(2)<<fixed<<geras.at(i).Pvm<<endl;

    }
        out2<<endl;
        cout.fill('-');
        cout.width(109);
        cout<<"-"<<endl;
        cout.fill(' ');

    return 0;
}
