#include <bits/stdc++.h>
#include <random>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;

random_device rd; 
mt19937 gen(rd()); 
uniform_int_distribution<> distrib(1, 100);

vector<int> generadorPuntos(int dimensiones){
    vector<int> punto;
    for (int a = 0; a < dimensiones; ++a)
    {
        int rand = distrib(gen);
        punto.push_back(rand);
    }
    return punto;
}
float distanciaEuclidiana(int dimensiones, vector<int> a, vector<int> b){
    int dist = 0;
    for (int i = 0; i < dimensiones; ++i)
    {
        int t = a[i] - b[i];
        dist += (t * t);
    }
    return (sqrt(dist));
}
int main(){
    srand(time(NULL));
    ofstream file;
    file.open("tablas.txt");
    int num_puntos = 20000;
    vector<int> v_dimenciones = {1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100,200};
    vector<int> v_time;
    chrono::time_point<std::chrono::high_resolution_clock> start, end;
    for (int j = 0; j < v_dimenciones.size(); j++){
        start = chrono::high_resolution_clock::now();
        vector<vector<int>> puntos;
        int dimensiones = v_dimenciones[j];
        vector<int> distancias;
        int max = 0;
        int min = 500000;
        puntos.push_back(generadorPuntos(dimensiones));
        vector<int> p_ini = puntos[0];
        for (int i = 1; i < num_puntos; i++){
            puntos.push_back(generadorPuntos(dimensiones));
            distancias.push_back(distanciaEuclidiana(dimensiones, p_ini, puntos[i]));
            if (distancias[i - 1] > max){
                max = distancias[i - 1];
            }
            else if (distancias[i - 1] < min){
                min = distancias[i - 1];
            }
        }
        vector<int> tabla(11, 0);
        int razon = max - min;
        for (int i = 1; i < num_puntos; i++){
            double t = (distancias[i - 1] - min) / (razon + 0.0);

            double parteDecimal, parteEntera;
            parteDecimal = modf(t * 10, &parteEntera);

            int pos = (int)parteEntera;
            tabla[pos] += 1;
        }

        for (int i = 0; i < 11; i++){
            file << tabla[i] << " ";
        }
        file << endl;
        puntos.empty();
        distancias.empty();
        end = chrono::high_resolution_clock::now();
        int64_t duration = chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        v_time.push_back(duration);
    }
    for(int i=0;i<v_time.size();i++) {
        cout<<v_dimenciones[i]<<" Dimensiones "<< v_time[i]<<"s "<<endl;
    }
    file.close();
}   