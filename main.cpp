#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Projetos SFML");

    sf::Font font;
    if (!font.loadFromFile("SFML/Fonte/arial.ttf")) {
        return -1;
    }

    sf::Text texto;
    texto.setFont(font);
    texto.setCharacterSize(24);
    texto.setFillColor(sf::Color::White);
    sf::String utf8Text = L"Projetos em C++ com SFML\n";
    texto.setString(utf8Text);
    texto.setPosition(100, 50);  // Ajuste da posição

    std::string opcoes[] = {"Calculadora", "Adivinha o numero", "Jogo da velha", "Sair"};

    sf::Text opcao[4];  // Mova a declaração do array para fora do loop de eventos

    for (int i = 0; i < 4; i++) {
        opcao[i].setFont(font);
        opcao[i].setCharacterSize(24);
        opcao[i].setFillColor(sf::Color::White);
        opcao[i].setString(opcoes[i]);
        opcao[i].setPosition(100, 100 + (i * 50));
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

                for (int i = 0; i < 4; i++) {
                    sf::FloatRect bounds = opcao[i].getGlobalBounds();
                    if (bounds.contains(mousePosFloat)) {
                        std::cout << "Clicou na opção: " << opcoes[i] << std::endl;
                        // Adicione a lógica correspondente à opção clicada
                    }
                }
            }
        }

        window.clear();
        window.draw(texto);

        for (int i = 0; i < 4; i++) {
            window.draw(opcao[i]);
        }

        window.display();
    }

    return 0;
}
