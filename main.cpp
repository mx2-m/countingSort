#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

bool Branje_Stevil(vector<int> &vec, const char s[]) {
    ifstream input(s);
    int st;

    if (!input.is_open()) {
        return false;
    }

    while (!input.eof()) {
        input >> st;
        vec.push_back(st);
        while (isspace(input.peek())) input.get();
    }
    input.close();
    return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost) {
    ofstream output("out.txt");

    for (int i = 0; i<velikost; i++)
        output << polje[i] << ' ';
}

void countingSort(vector<int> &A) {

    vector<int>B(A.size(),0);
    int min=0 ;
    int max=0 ;

    for (unsigned int m = 0; m < A.size(); m++) //iscemo najveci element v polju
    {
        if (A[m] > max)
            max = A[m];
    }

    for (unsigned int m = 0; m < A.size(); m++)
    {
        if (A[m] < min)
            min = A[m];
    }


    vector<int> C(max-min+ 1, 0);

    for (int i = 0; i < A.size(); i++) {
        C[A[i]-min] = C[A[i]-min] + 1;


    }

    cout << endl;
    for (int i = 1; i < C.size(); i++) {
        C[i] = C[i] + C[i - 1];


    }

    for (int i = A.size() - 1; i > -1; i--)
    {
        B[C[A[i]-min]- 1] = A[i];
        C[A[i]-min] = C[A[i]-min] - 1;

    }

    for (int i = 0; i < A.size(); i++){

        cout <<B[i] << " "<<endl;


        A[i]=B[i];

    }
}

/*int  SetBit(vector<int> A,int  k ){

         A[k/8] |= 1 << (k%8);
         for (unsigned int i = 0; i < A.size(); i++)
             cout << A[i] << " ";

}*/


void radixSort(vector<int> A) {
    int bit=1;
    int max = 255;
    while(max/bit >0){

        countingSort(A);
        bit*=10;
        cout<<bit;

    }

    Izpis_Stevil(&A[0],A.size());
}




int main(int argc, const char* argv[]) {
    vector<int> A;
    int stevilo;
    cout << "            DOMACA NALOGA 1" << endl;
    cin >> stevilo;

    if (argc < 3) return 0;
    if (!Branje_Stevil(A, argv[2])) return 0;

    if (argv[1][1] == '1') {

        radixSort(A);

    }
    /* for (int i = 0; i < argc; ++i)
            std::cout << argv[i] << std::endl;
*/

    return 0;
}
