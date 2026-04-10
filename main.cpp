#include <iostream>
#include <iomanip>

using namespace std;
const float GBP_Bendras = 0.8729,
    GBP_Pirkti    = 0.8600,
    GBP_Parduoti  = 0.9220,
    USD_Bendras   = 1.1793,
    USD_Pirkti    = 1.1460,
    USD_Parduoti  = 1.2340,
    INR_Bendras   = 104.6918,
    INR_Pirkti    = 101.3862,
    INR_Parduoti  = 107.8546;

int main () {
    int operacija, valiuta;
    float kiekis, rezultatas;

    while (true) {
        cout<<"\nGalimos operacijos su Eurais: 1 - palyginimas su kita valiuta, 2 - pirkimas, 3 - pardavimas.\n"
              "Pasirinkite operacija:"<<endl;
        cin>>operacija;
         if (operacija != 1 && operacija != 2 && operacija != 3 ) {
             cout<<"Nera tokios operacijos"<<endl;
                 return 0;
         }
        cout<<"Galimos valiutos: 1 - GBP, 2 - USD, 3 - INR.\n "
        "Pasirinkite valiuta"<<endl;
        cin>>valiuta;
        if (valiuta != 1 && valiuta != 2 && valiuta != 3 ) {
            cout<<"Nera tokios valiutos"<<endl;
            return 0;
        }
        cout<<"Iveskite valiutos kieki:"<<endl;
        cin>>kiekis;
        if (kiekis >0)
        switch (operacija) {
            case 1:
                switch (valiuta) {
                    case 1:
                        rezultatas = kiekis * GBP_Bendras;
                        cout<<kiekis<<" EUR palyginus yra "<<fixed<< setprecision(2) <<rezultatas<<" GBP. "<<endl;
                        break;
                    case 2:
                        rezultatas = kiekis * USD_Bendras;
                        cout<<kiekis<<" EUR palyginus yra "<<fixed<< setprecision(2) <<rezultatas<<" USD. "<<endl;
                        break;
                    case 3:
                        rezultatas = kiekis * INR_Bendras;
                        cout<<kiekis<<" palyginus yra "<<fixed<< setprecision(2) <<rezultatas<<" INR. "<<endl;
                        break;
                    default:
                        cout<<"Ivedete nepalaikoma valiuta"<<endl;
                }
                break;
            case 2:
                switch (valiuta) {
                    case 1:
                        rezultatas = kiekis * GBP_Pirkti;
                        cout<<"Nusipirkote "<<fixed<< setprecision(2) <<rezultatas<<" GBP "<<endl;
                        break;
                    case 2:
                        rezultatas = kiekis * USD_Pirkti;
                        cout<<"Nusipirkote "<<fixed<< setprecision(2) <<rezultatas<<" USD "<<endl;
                        break;
                    case 3:
                        rezultatas = kiekis * INR_Pirkti;
                        cout<<"Nusipirkote "<<fixed<< setprecision(2) <<rezultatas<<" INR "<<endl;;
                        break;
                    default:
                        cout<<"Ivedete nepalaikoma valiuta"<<endl;
                }
                break;
            case 3:
                switch (valiuta) {
                    case 1:
                        rezultatas = kiekis / GBP_Parduoti;
                        cout<<"Nusipirkote "<<fixed<< setprecision(2) <<rezultatas<<" EUR "<<endl;
                        break;
                    case 2:
                        rezultatas = kiekis / USD_Parduoti;
                        cout<<"Nusipirkote "<<fixed<< setprecision(2) <<rezultatas<<" EUR "<<endl;
                        break;
                    case 3:
                        rezultatas = kiekis / INR_Parduoti;
                        cout<<"Nusipirkote "<<fixed<< setprecision(2) <<rezultatas<<" EUR "<<endl;;
                        break;
                default:
                        cout<<"Ivedete nepalaikoma valiuta"<<endl;
                }
                break;
            default:
                cout<<"Tokios operacijos nera";
        }
        else {
            cout<<"Ivedete netinkama skaiciu."<<endl;
            return 0;
        }
    }
}