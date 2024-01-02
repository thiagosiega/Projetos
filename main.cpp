#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Cria uma nova janela com dimensões 800x600 pixels
    sf::RenderWindow window(sf::VideoMode(800, 600), "Projetos SFML ");

    // Cria uma instância de sf::Font para carregar a fonte
    sf::Font font;
    if (!font.loadFromFile("SFML/Fonte/arial.ttf")) {
        // Trate o caso de falha ao carregar a fonte
        return -1;
    }

    // Cria um objeto sf::Text
    sf::Text texto;
    texto.setFont(font); // Define a fonte para o texto
    texto.setCharacterSize(24); // Define o tamanho do caractere
    texto.setFillColor(sf::Color::White); // Define a cor do texto
    // Use sf::String para suportar UTF-8
    sf::String utf8Text = L"Projetos em C++ com SFML\n";
    texto.setString(utf8Text);// Define o texto a ser exibido
    // Define a posição do texto
    texto.setPosition(300.f, 100.f);

    //defino o botao
    sf::RectangleShape botao(sf::Vector2f(100, 50)); //tamanho do botao 100x50
    botao.setPosition(300, 300); //posicao do botao
    botao.setFillColor(sf::Color::Red); //cor do botao

    //defino o texto do botao
    sf::Text textoBotao;
    textoBotao.setFont(font); // Define a fonte para o texto
    textoBotao.setCharacterSize(24); // Define o tamanho do caractere
    textoBotao.setFillColor(sf::Color::White); // Define a cor do texto
    // Use sf::String para suportar UTF-8
    sf::String utf8TextBotao = L"Botao\n";
    textoBotao.setString(utf8TextBotao);// Define o texto a ser exibido
    // Define a posição do texto
    textoBotao.setPosition(320.f, 315.f);



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
            
            //evento de clique do mouse
            if (event.type == sf::Event::MouseButtonPressed) {
                //verifico se o clique foi dentro do botao
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

                if (botao.getGlobalBounds().contains(mousePosFloat))
                {
                    // Ação quando o botão é clicado
                    std::cout << "Botão clicado!" << std::endl;
                }
            }
        }

        // Limpa a janela
        window.clear();

        // Desenha o texto na janela
        window.draw(texto);
        // Desenha o botao na janela
        window.draw(botao);
        // Desenha o texto do botao na janela
        window.draw(textoBotao);

        // Exibe o conteúdo desenhado
        window.display();
    }

    return 0;
}
