#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
vector <int> listainicial, listafinal;
/*int cn, nt;
cout << "cantidad de numeros a meter: "; cin >> cn;
for (int n = 0; n < cn; n++) {
	cout << "pon un numero: "; cin >> nt;
	listainicial.push_back(nt);
}
prueba de rendimiento*/
int cn = 100000;
for (int c = cn; c>=0; c--)
	listainicial.push_back(rand() % cn+1);

clock_t begin = clock();

int menor = listainicial[0];
while (listainicial.size() > 0 and not is_sorted(listainicial.begin(), listainicial.end())) {
	auto indicemenor = min_element(listainicial.begin(), listainicial.end());//coje el menor numero de la lista
	menor = listainicial[distance(listainicial.begin(), indicemenor)];
	listainicial.erase(indicemenor);
	listafinal.push_back(menor);
}
if (is_sorted(listainicial.begin(), listainicial.end())) {
	for (int elemento : listainicial)
		listafinal.push_back(elemento);
	listainicial.clear();
} 
clock_t end = clock();

for (int elemento : listafinal)
	cout << elemento << ' ';
cout << endl;
cout << "\n" <<  double(end - begin) / CLOCKS_PER_SEC;
}
