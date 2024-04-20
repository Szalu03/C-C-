// Wejście:
// W pierwszej linii wejścia znajduje się liczba całkowita n.
// W drugiej linii wejścia znajdują się trzy litery oddzielone spacjami: 's', 'd' i 'm', a ich kolejność decyduje o kolejności uporządkowania dzieci.
//  W kolejnych n liniach są wiersze opisujące kolejne pary uczniów szkoły. 
//  Każda linia składa się z opisu dwóch uczniów: dziewczynki i chłopca.
// Na opis ucznia składa się kolejno jednowyrazowy napis kod oznaczający kod ucznia,
//  jednej liczby zmiennoprzecinkowej s oznaczającej średnią,
//  dwóch liczb całkowitych d i m, oznaczajacych kolejno odległość od miejsca zamieszkania w metrach oraz numer miesiąca urodzenia ucznia.
// Miesiące numerowane są od 1.
// 1 ≤ n ≤ 1000000
// Wyjście:
// Na wyjściu program powinien wypisać uporządkowane listy dziewczynek i chłopców w parach według podanej kolejności kryteriów.
//  Para powinna być wyświetlona w postaci: kod1 kod2. Całą listę należy wyświetlić w jednej linii.
//   W przypadku dwóch uczniów, których wszystkie odpowiadające wartości są równe, należy zachować kolejność wystąpienia na liście.

#include<iostream>
#include<vector>

using namespace std;

struct dziewczyny{
    string code;
    float srednia;
    int metry;
    int miesiac;

};
struct chlopcy{
    string code;
    float srednia;
    int metry;
    int miesiac;

};

struct uczniowie{
    chlopcy chlop;
    dziewczyny dziew;
};

void sort(vector<uczniowie>& uczen,int n, char znak[] ){
    if( znak[0] == 'm' && znak[1] == 's' && znak[2] == 'd'){
        for(int i =0; i < n-1;i++){
            for(int j = 0; j < n-i-1; j++){
                if(uczen[j].dziew.miesiac<uczen[j+1].dziew.miesiac )
                swap(uczen[j].dziew, uczen[j+1].dziew);
                if(uczen[j].chlop.miesiac<uczen[j+1].chlop.miesiac )
                swap(uczen[j].chlop, uczen[j+1].chlop);
                if(uczen[j].dziew.miesiac == uczen[j+1].dziew.miesiac && uczen[j].dziew.srednia<uczen[j+1].dziew.srednia)
                {
                    swap(uczen[j].chlop, uczen[j+1].chlop);

                }
                if(uczen[j].dziew.miesiac == uczen[j+1].dziew.miesiac && uczen[j].dziew.srednia ==uczen[j+1].dziew.srednia && uczen[j].dziew.metry<uczen[j+1].dziew.metry)
                {
                    swap(uczen[j].dziew, uczen[j+1].dziew);

                }

                if(uczen[j].chlop.miesiac == uczen[j+1].chlop.miesiac && uczen[j].chlop.srednia<uczen[j+1].chlop.srednia)
                {
                    swap(uczen[j].chlop, uczen[j+1].chlop);

                }
                if(uczen[j].chlop.miesiac == uczen[j+1].chlop.miesiac && uczen[j].chlop.srednia ==uczen[j+1].chlop.srednia && uczen[j].chlop.metry<uczen[j+1].chlop.metry)
                {
                    swap(uczen[j].chlop, uczen[j+1].chlop);

                }



            }
        }

    }



}




int main(){


    int n;
    cin >> n;

    char znaki[3];

    cin >> znaki[0] >> znaki[1] >> znaki[2];

   
    vector<uczniowie> uczen(n);

    for(int i =0; i < n;i++){
    cin >> uczen[i].dziew.code >> uczen[i].dziew.srednia >> 
    uczen[i].dziew.metry >> uczen[i].dziew.miesiac >>
    uczen[i].chlop.code >> uczen[i].chlop.srednia >> 
    uczen[i].chlop.metry >> uczen[i].chlop.miesiac;
}

    sort(uczen,n,znaki);
    
    for(int j= 0; j< n;j++){
            cout << uczen[j].dziew.code << " " << uczen[j].chlop.code<<" ";

    }














    return 0;
}