#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <ctime>

using namespace std;

int main() {
vector <int> listainicial, listafinal;
int nn, nt;
cout << "cantidad de numeros a meter: "; cin >> nn;
for (int n = 0; n < nn; n++) {
	cout << "pon un numero: "; cin >> nt;
	listainicial.push_back(nt);
}
/* prueba de rendimiento
for (int c = 100000; c>=0; c--)
	listainicial.push_back(c);
clock_t begin = clock();
*/
int n = 0, indicemenor = 0, menor = listainicial[0];
if (is_sorted(listainicial.begin(), listainicial.end())) {
	listafinal = listainicial;
	listainicial.clear();
} else {
	while (listainicial.size() > 0) {
		n = 0;
		menor = INT_MAX;
		for (int elemento : listainicial) {
			if (elemento < menor) {
				menor = elemento;
				indicemenor = n;
			}
		n++;
		}
		listainicial.erase(listainicial.begin()+indicemenor);
		listafinal.push_back(menor);
	}
}
//clock_t end = clock();

cout << endl;
for (int elemento : listafinal)
	cout << elemento << ' ';
cout << endl;
//cout << endl <<  double(end - begin) / CLOCKS_PER_SEC;
}
