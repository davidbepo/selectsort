#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
vector <int> lista;
/* modo usuario
int cn, nt;
cout << "cantidad de numeros a meter: "; cin >> cn;
for (int n = 0; n < cn; n++) {
	cout << "pon un numero: "; cin >> nt;
	lista.push_back(nt);
}
*/

//prueba de rendimiento
int cn = 100000;
for (int c = 0; c < cn; c++)
	lista.push_back(rand() % cn+1);

clock_t begin = clock();
int nac = 0;//nac = numero a comprobar
while (not is_sorted(lista.begin() + nac, lista.end())) {
	auto indicemenor = min_element(lista.begin() + nac, lista.end());//coje el menor numero de la lista
	if (distance(lista.begin(), indicemenor) != nac)
		iter_swap(lista.begin() + nac, indicemenor);//si no es nac los intercambia
	nac++;
}
clock_t end = clock();

for (int elemento : lista)
	cout << elemento << ' ';
cout << endl;
cout << "\n" <<  double(end - begin) / CLOCKS_PER_SEC << "\n";
}
