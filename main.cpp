#include <iostream>
#include <string>
using namespace std;

const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;

string vardai[MAX_MOKINIU];
int pazymiai[MAX_MOKINIU][MAX_PAZYMIU];
int mokiniuKiekis = 0;

int rastiMokiniPagalVarda(string vardas) {
    for (int i = 0; i < mokiniuKiekis; i++) {
        if (vardai[i] == vardas) {
            return i;
        }
    }
    return -1;
}

void pridetiMokini() {
    if (mokiniuKiekis >= MAX_MOKINIU) {
        cout << "Negalima prideti daugiau mokiniu.\n";
        return;
    }

    string vardas;
    int kiekisPaz;

    cout << "Iveskite mokinio varda: ";
    cin >> ws;
    getline(cin, vardas);

    cout << "Kiek pazymiu turi mokinys? (1-10): ";
    cin >> kiekisPaz;

    while (kiekisPaz < 1 || kiekisPaz > MAX_PAZYMIU) {
        cout << "Neteisingas kiekis. Iveskite nuo 1 iki 10: ";
        cin >> kiekisPaz;
    }

    vardai[mokiniuKiekis] = vardas;
    for (int j = 0; j < MAX_PAZYMIU; j++) {
        pazymiai[mokiniuKiekis][j] = -1;
    }
    for (int j = 0; j < kiekisPaz; j++) {
        cout << "Iveskite " << j + 1 << "-aji pazymi: ";
        cin >> pazymiai[mokiniuKiekis][j];

        while (pazymiai[mokiniuKiekis][j] < 1 || pazymiai[mokiniuKiekis][j] > 10) {
            cout << "Pazymys turi buti nuo 1 iki 10. Bandykite dar karta: ";
            cin >> pazymiai[mokiniuKiekis][j];
        }
    }

    mokiniuKiekis++;
    cout << "Mokinys sekmingai pridetas.\n";
}

void rodytiVisusMokinius() {
    if (mokiniuKiekis == 0) {
        cout << "Mokiniu sarasas tuscias.\n";
        return;
    }

    cout << "\n--- Visu mokiniu pazymiai ---\n";
    for (int i = 0; i < mokiniuKiekis; i++) {
        cout << vardai[i] << " -- ";

        for (int j = 0; j < MAX_PAZYMIU; j++) {
            if (pazymiai[i][j] != -1) {
                cout << pazymiai[i][j] << " ";
            }
        }

        cout << endl;
    }
}

void rodytiVienaMokini() {
    if (mokiniuKiekis == 0) {
        cout << "Mokiniu sarasas tuscias.\n";
        return;
    }

    string vardas;
    cout << "Iveskite mokinio varda: ";
    cin >> ws;
    getline(cin, vardas);

    int indeksas = rastiMokiniPagalVarda(vardas);

    if (indeksas == -1) {
        cout << "Mokinys nerastas.\n";
        return;
    }

    cout << vardai[indeksas] << " -> ";
    for (int j = 0; j < MAX_PAZYMIU; j++) {
        if (pazymiai[indeksas][j] != -1) {
            cout << pazymiai[indeksas][j] << " ";
        }
    }
    cout << endl;
}

void atnaujintiPazymi() {
    if (mokiniuKiekis == 0) {
        cout << "Mokiniu sarasas tuscias.\n";
        return;
    }

    string vardas;
    cout << "Iveskite mokinio varda: ";
    cin >> ws;
    getline(cin, vardas);

    int indeksas = rastiMokiniPagalVarda(vardas);

    if (indeksas == -1) {
        cout << "Mokinys nerastas.\n";
        return;
    }

    cout << "Esami pazymiai: ";
    for (int j = 0; j < MAX_PAZYMIU; j++) {
        if (pazymiai[indeksas][j] != -1) {
            cout << "(" << j + 1 << ":" << pazymiai[indeksas][j] << ") ";
        }
    }
    cout << endl;

    int nr, naujas;
    cout << "Kuri pazymi norite keisti? ";
    cin >> nr;

    if (nr < 1 || nr > MAX_PAZYMIU || pazymiai[indeksas][nr - 1] == -1) {
        cout << "Toks pazymys neegzistuoja.\n";
        return;
    }

    cout << "Iveskite nauja pazymi: ";
    cin >> naujas;

    while (naujas < 1 || naujas > 10) {
        cout << "Pazymys turi buti nuo 1 iki 10. Bandykite dar karta: ";
        cin >> naujas;
    }

    pazymiai[indeksas][nr - 1] = naujas;
    cout << "Pazymys atnaujintas.\n";
}

void pasalintiMokini() {
        if (mokiniuKiekis == 0) {
            cout << "Mokiniu sarasas tuscias.\n";
            return;
        }

        string vardas;
        cout << "Iveskite mokinio varda, kuri norite pasalinti: ";
        cin >> ws;
        getline(cin, vardas);

        int indeksas = rastiMokiniPagalVarda(vardas);

        if (indeksas == -1) {
            cout << "Mokinys nerastas.\n";
            return;
        }

        for (int i = indeksas; i < mokiniuKiekis - 1; i++) {
            vardai[i] = vardai[i + 1];

            for (int j = 0; j < MAX_PAZYMIU; j++) {
                pazymiai[i][j] = pazymiai[i + 1][j];
            }
        }

        mokiniuKiekis--;

        vardai[mokiniuKiekis] = "";
        for (int j = 0; j < MAX_PAZYMIU; j++) {
            pazymiai[mokiniuKiekis][j] = -1;
        }

        cout << "Mokinys pasalintas.\n";
    }

void rodytiMeniu() {
    cout << "MENIU\n";
    cout << "1. Prideti mokini\n";
    cout << "2. Rodyti visu mokiniu pazymius\n";
    cout << "3. Rodyti konkretaus mokinio pazymius\n";
    cout << "4. Atnaujinti mokinio pazymi\n";
    cout << "5. Pasalinti mokini\n";
    cout << "0. Iseiti \n";
    cout << "Pasirinkite veiksma: ";
}

int main()
{
    int pasirinkimas;

    do {
        rodytiMeniu();
            cin >> pasirinkimas;
                switch (pasirinkimas)
                {
                case 1:
                    pridetiMokini();
                    break;
                case 2:
                    rodytiVisusMokinius();
                    break;
                case 3:
                    rodytiVienaMokini();
                    break;
                case 4:
                    atnaujintiPazymi();
                    break;
                case 5:
                    pasalintiMokini();
                    break;
                case 0:
                    cout << "Iseita. Geros dienos.\n";
                    break;
                default:
                cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";
                }

        } while (pasirinkimas != 0);

    return 0;
}
//
// Užduotis „Mokinių pažymių sistema“
//
// Tikslas:
//
// Sukurti C++ programą, kuri leidžia vartotojui:
//
//     Įvesti mokinių vardus ir jų pažymius.
//     Peržiūrėti visų mokinių arba konkretaus mokinio pažymius.
//     Atnaujinti konkretų pažymį konkrečiam mokiniui.
//     Pašalinti mokinį iš sąrašo.
//
// Reikalavimai:
//
//     Naudoti du masyvus: vienmatis masyvas skirtas mokinių vardams saugoti, dvimatis masyvas skirtas pažymiams: eilutės – mokiniai, stulpeliai – pažymiai.
//     Leisti į masyvą įvesti iki 100 mokinių, kiekvienas iš jų gali turėti iki 10 pažymių.
//     Naudoti ciklus ir sąlyginius sakinius duomenų valdymui.
//     Sukurti paprastą meniu, leidžiantį vartotojui pasirinkti veiksmą.

// #include <limits>
//
// int skaitytiSkaiciu(int nuo, int iki) {
//     int x;
//
//     while (true) {
//         cin >> x;
//
//         if (cin.fail()) {
//             cout << "Klaida: iveskite skaiciu: ";
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             continue;
//         }
//
//         if (x < nuo || x > iki) {
//             cout << "Klaida: iveskite skaiciu nuo " << nuo << " iki " << iki << ": ";
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             continue;
//         }
//
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         return x;
//     }
// }