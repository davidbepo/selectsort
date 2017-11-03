#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
vector <int> lista;
int nn, nt;
cout << "cantidad de numeros a meter: "; cin >> nn;
for (int n = 0; n < nn; n++) {
	cout << "pon un numero: "; cin >> nt;
	lista.push_back(nt);
}
/* prueba de rendimiento
for (int c = 100000; c>=0; c--)
	lista.push_back(c);
clock_t begin = clock();
*/
int nac = 0, indicemenor = 0, menor = lista[0];//nac = numero a comprobar
while (not is_sorted(lista.begin(), lista.end())) {
	menor = lista[nac];
	for (int n = nac; n < lista.size(); n++) {
		if (lista[n] < menor) {
			indicemenor = n;
			menor = lista[n];
		}
	}
	if (nac != indicemenor)
		iter_swap(lista.begin() + nac, lista.begin() + indicemenor);
	nac++;
}
//clock_t end = clock();

cout << endl;
for (int elemento : lista)
	cout << elemento << ' ';
cout << endl;
//cout << endl <<  double(end - begin) / CLOCKS_PER_SEC;
}
