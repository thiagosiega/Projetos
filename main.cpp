#include <SFML/Window.hpp>

int main()
{
    // Cria uma nova janela com dimensões 800x600 pixels
    sf::Window window(sf::VideoMode(800, 600), "Projetos SFML ");

    // Loop principal do jogo
    while (window.isOpen())
    {
        // Processa eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Fecha a janela quando o usuário clica no botão de fechar
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}