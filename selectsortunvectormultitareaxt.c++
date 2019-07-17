#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <future>

using namespace std;

vector <int> selectsort(vector <int> lista) {
	int nac = 0; //nac = numero a comprobar
	while (not is_sorted(lista.begin() + nac, lista.end())) {
		auto indicemenor = min_element(lista.begin() + nac, lista.end()); //coje el menor numero de la lista
		if (distance(lista.begin(), indicemenor) != nac)
			iter_swap(lista.begin() + nac, indicemenor); //si no es nac los intercambia
		nac++;
	}
	return lista;
}

int main() {

//prueba de rendimiento
int cn = 100000;
const int tareas=cn/500;//valor mas rapido, probado con varios numeros
cout << "ejecutando con " << tareas << " tareas \n\n";
vector <int> lista[tareas];
vector <int> listax;
for (int c = 0; c < cn; c++)
	listax.push_back(rand() % cn+1);

clock_t begin = clock();
const size_t parte = listax.size() / tareas;
for(int t=0; t<tareas; t++) {
	vector <int> tmp(listax.begin() + parte*t, listax.begin() + parte*(t+1));
	lista[t] = tmp;
}
listax.clear();
future<vector <int>> futuro[tareas];
for(int t=0; t<tareas; t++) {
	futuro[t] = async(selectsort, lista[t]);
	lista[t] = futuro[t].get();
}
vector <int> listax2;
for(int t=0; t<tareas; t++) {
	merge(listax.begin(), listax.end(), lista[t].begin(), lista[t].end(), back_inserter(listax2));
	listax = listax2;
	listax2.clear();
	lista[t].clear();
}
clock_t end = clock();

for (int elemento : listax)
	cout << elemento << ' ';
cout << endl;
cout << "\n" <<  double(end - begin) / CLOCKS_PER_SEC << "\n";
}
