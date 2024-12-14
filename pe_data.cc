#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <fstream>

using namespace std;

double insertion_sort(vector<int> &v) {
    int v_size = v.size();
    int val;
    clock_t start = clock();

    for (int i = 1; i < v_size; ++i) {
        val = v[i];
        int j = i;
        while (j > 0 and v[j - 1] > val) {
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

    for (int i = 0; i < v_size; ++i) {
        pos = i;
        for (int j = i + 1; j < v_size; ++j) if (v[pos] > v[j]) pos = j;
        swap(v[i],v[pos]);
    }
    clock_t end = clock();
    double duration = double(end - start)/CLOCKS_PER_SEC;

    return duration;
}

int main() {
    ofstream file("resultados.csv");
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo" << endl;
        return 1;
    }
    file << "Tamaño_Vector,Tiempo_Insertion,Tiempo_Selection\n";

    for (int i = 0; i < 50; ++i) {
        double insertion_time = 0;
        double selection_time = 0;

        // La mida de vector está entre 1000-5000
        int v_size = rand()%4001 + 1000;
        vector<int> v(v_size);
        vector<int> v_aux(v_size);
        for (int j = 0; j < v_size; ++j) {
            // Cada valor de vector és 0 <= v[j] <= 10^6
            v[j] = v_aux[j] = (rand()%int(pow(10, 6) + 1));
        }
        
        // L'ordre d'execució dels programes es totalment aleatori
        bool ordre = rand()%2;
        if (ordre) {
            insertion_time = insertion_sort(v);
            selection_time = selection_sort(v_aux);
        }
        else {
            selection_time = selection_sort(v_aux);
            insertion_time = insertion_sort(v);
        }
        file << v_size << "," << insertion_time << "," << selection_time << "\n";
    }
}
