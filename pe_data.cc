#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

double insertion_sort(vector<int> &v) {

    int v_size = v.size();
    int val;
    clock_t start = clock();

    for(int i = 1; i < v_size; ++i) {

        val = v[i];
        int j = i;
        while(j > 0 and v[j - 1] > val) {
            v[j] = v[j - 1];
            --j;
        }
        v[j] = val;
    }

    clock_t end = clock();
    double duration = double(end - start)/CLOCKS_PER_SEC;

    return duration;
}

double selection_sort(vector<int> &v) {

    int v_size = v.size();
    int pos;
    clock_t start = clock();

    for(int i = 0; i < v_size; ++i) {

        pos = i;
        for(int j = i + 1; j < v_size; ++j) {

            if(v[pos] > v[j]) pos = j;
        }
        swap(v[i],v[pos]);
    }
    clock_t end = clock();
    double duration = double(end - start)/CLOCKS_PER_SEC;

    return duration;

}



int main() {

    for(int i = 0; i < 1000; ++i) {
        double insertion_time = 0;
        double selection_time = 0;

        //garanteix la mida de vector está entre 1000-5000
        int v_size = rand()%4001 + 1000;
        vector<int> v(v_size);
        vector<int> v_aux(v_size);
        for(int j = 0; j < v_size; ++j) {
            // garanteix cada valor de vector és 0 <= v[j] <= 10^6

            v[j] = v_aux[j] = (rand()%int(pow(10,6)+1));
        }
        cout << "la mida de vector és:" << v_size << endl;
        cout << endl;


        int orden = rand()%2;
        // si orden == 0, primer ordenem el vector amb selection sort
        // en cas contrari primer insertion sort i despres selection sort

        if(orden == 0) {

            insertion_time = insertion_sort(v);
            selection_time = selection_sort(v_aux);
            cout << "primer farem insertion_sort: el temps d'ordenació és : " << insertion_time << endl;
            cout << endl;

            cout << "segon farem selection_sort: el temps d'ordenació és : " << selection_time << endl;
            cout << endl;

        }
        else {
            selection_time = selection_sort(v_aux);
            insertion_time = insertion_sort(v);
            cout << "primer farem selection_sort: el temps d'ordenació és : " << insertion_time << endl;
            cout << endl;

            cout << "segon farem insertion_sort: el temps d'ordenació és : " << selection_time << endl;
            cout << endl;
        }

        cout << "temps total per l'ordenació és: "  << insertion_time + selection_time << endl;
        cout << endl;

    }

}
