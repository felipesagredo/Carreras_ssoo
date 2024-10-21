#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <random>
#include <chrono>
#include <algorithm>

std::mutex mtx;  // Mutex para sincronizar el acceso a la consola.
int place = 1;   // Para mantener el orden de llegada.

void runCar(int carID, int distance, int &position) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);  // Avance aleatorio entre 1 y 10 metros.
    std::uniform_int_distribution<> time_dist(100, 500);  // Tiempo aleatorio entre 100 y 500 ms.

    int totalDistance = 0;

    while (totalDistance < distance) {
        int advance = dist(gen);  // Distancia aleatoria que avanza el auto.
        totalDistance += advance;

        if (totalDistance > distance) {
            totalDistance = distance;  // No puede exceder la distancia total.
        }

        {
            std::lock_guard<std::mutex> lock(mtx);  // Sincronizar la salida.
            std::cout << "Auto" << carID << " avanza " << advance << " metros (total: " << totalDistance << " metros)" << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(time_dist(gen)));  // Espera un tiempo aleatorio.

        if (totalDistance >= distance) {
            std::lock_guard<std::mutex> lock(mtx);
            position = place++;  // Asigna el lugar de llegada.
            std::cout << "Auto" << carID << " termina la carrera en el lugar " << position << "!" << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <distancia_total> <numero_de_autos>" << std::endl;
        return 1;
    }

    int M = std::stoi(argv[1]);  // Distancia total de la carrera.
    int N = std::stoi(argv[2]);  // Número de autos (hebras).

    std::vector<std::thread> cars;  // Vector para almacenar las hebras.
    std::vector<int> positions(N, 0);  // Vector para almacenar las posiciones finales de los autos.

    std::cout << "Distancia total carrera: " << M << " metros" << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Crear y lanzar las hebras.
    for (int i = 0; i < N; ++i) {
        cars.emplace_back(runCar, i, M, std::ref(positions[i]));
    }

    // Esperar a que todas las hebras terminen.
    for (auto &car : cars) {
        car.join();
    }

    std::cout << "\nLugar Auto" << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Mostrar el orden de llegada de los autos.
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (positions[j] == i) {
                std::cout << i << " Auto" << j << std::endl;
            }
        }
    }

    return 0;
}
