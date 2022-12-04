#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

// Ширина и высота окна
const int height = 1080, width = 1920;

// Размер одного пикселя (измеряется в пикселях экрана)
const int pixel = 3;

// Количество блоков
const int N = 400;

// Высота точки(пикселя) волны
float waveH[N];

// Скорость точки(пикселя) волны
float waveV[N];



int main() {

    // Задание изначальных значений параметров блоков
    for (int i = 0; i < N; i++) {

        waveH[i] = 0;

        waveV[i] = 0;

        if (i >= 5 && i < 10)
            waveV[i] = -pixel * 10;
    }

    sf::RenderWindow window(sf::VideoMode(width, height), "Thread");


    while (window.isOpen())
    {

        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)

                window.close();

        }

        // Обработка перемещения блоков
        for (int i = 1; i < N - 1; i++) {

            waveH[i] += waveV[i];

        }

        // Обработка скорости блоков
        for (int i = 1; i < N - 1; i++) {

            float force = waveH[i - 1] + waveH[i + 1];

            waveV[i] += force / 2 - waveH[i];

        }

        sf::RectangleShape Pixel(sf::Vector2f(pixel, pixel));

        Pixel.setFillColor(sf::Color::White);

        window.clear();

        for (int i = 0; i < N; i++) {

            sf::RectangleShape Pixel(sf::Vector2f(pixel, pixel));

            // Визуальный сдвиг блоков
            Pixel.setPosition(width / 2 + pixel * i - N / 2 * pixel, height / 2 + waveH[i]);

            window.draw(Pixel);

        }

        window.display();

        window.setFramerateLimit(60);
    }

    return 0;

}