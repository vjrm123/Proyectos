#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
    int valor;
    node* nod[2];

    node(int valor) {
        this->valor = valor;
        nod[0] = nod[1] = nullptr;
    }
};

class cbintree {
public:
    cbintree() : root(nullptr) {}
    ~cbintree() { clear(root); }

    bool add(int valor);
    void draw(sf::RenderWindow& window, sf::Font& font, sf::Vector2i mousePos);
    node* getRoot() { return root; }

private:
    node* root;

    void clear(node* p);
    void calculatePositions(node* p, int x, int y, int horizontalOffset, map<node*, pair<int, int>>& positions);
    void findLeftmostRightmost(node* p, int depth, map<int, node*>& leftmost, map<int, node*>& rightmost);
    void drawNodeWithColor(sf::RenderWindow& window, node* nodePtr, sf::Font& font, int xPos, int yPos, bool isContour);
    void drawEdges(sf::RenderWindow& window, node* nodePtr, const map<node*, pair<int, int>>& positions);
    void drawTree(sf::RenderWindow& window, node* p, sf::Font& font, map<node*, pair<int, int>>& positions);
};

// Agregar un nodo al árbol
bool cbintree::add(int valor) {
    node** p = &root;
    while (*p != nullptr) {
        if ((*p)->valor == valor) return false;
        p = &((*p)->nod[(*p)->valor < valor]);
    }
    *p = new node(valor);
    return true;
}

// Limpiar el árbol
void cbintree::clear(node* p) {
    if (!p) return;
    clear(p->nod[0]);
    clear(p->nod[1]);
    delete p;
}

// Calcular las posiciones de cada nodo
void cbintree::calculatePositions(node* p, int x, int y, int horizontalOffset, map<node*, pair<int, int>>& positions) {
    if (!p) return;
    positions[p] = make_pair(x, y);
    calculatePositions(p->nod[0], x - horizontalOffset, y + 80, horizontalOffset / 2, positions);
    calculatePositions(p->nod[1], x + horizontalOffset, y + 80, horizontalOffset / 2, positions);
}

// Encontrar nodos más a la izquierda y derecha por nivel
void cbintree::findLeftmostRightmost(node* p, int depth, map<int, node*>& leftmost, map<int, node*>& rightmost) {
    if (!p) return;

    // Nodo más a la izquierda
    if (leftmost.find(depth) == leftmost.end()) {
        leftmost[depth] = p;
    }

    // Nodo más a la derecha
    rightmost[depth] = p;

    findLeftmostRightmost(p->nod[0], depth + 1, leftmost, rightmost);
    findLeftmostRightmost(p->nod[1], depth + 1, leftmost, rightmost);
}

// Dibuja el nodo con el color adecuado
void cbintree::drawNodeWithColor(sf::RenderWindow& window, node* nodePtr, sf::Font& font, int xPos, int yPos, bool isContour) {
    sf::CircleShape circle(20);

    // Color según si es contorno o no
    if (isContour) {
        circle.setFillColor(sf::Color::Yellow); // Nodos de contorno
    }
    else {
        circle.setFillColor(sf::Color::Green);  // Nodos internos
    }

    circle.setPosition(xPos, yPos);
    window.draw(circle);

    // Texto del valor del nodo
    sf::Text text;
    text.setFont(font);
    text.setString(to_string(nodePtr->valor));
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Black);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(xPos + 20, yPos + 20);
    window.draw(text);
}

// Dibuja las conexiones entre nodos
void cbintree::drawEdges(sf::RenderWindow& window, node* nodePtr, const map<node*, pair<int, int>>& positions) {
    if (nodePtr->nod[0] != nullptr) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(positions.at(nodePtr).first + 20, positions.at(nodePtr).second + 20)),
            sf::Vertex(sf::Vector2f(positions.at(nodePtr->nod[0]).first + 20, positions.at(nodePtr->nod[0]).second + 20))
        };
        window.draw(line, 2, sf::Lines);
    }
    if (nodePtr->nod[1] != nullptr) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(positions.at(nodePtr).first + 20, positions.at(nodePtr).second + 20)),
            sf::Vertex(sf::Vector2f(positions.at(nodePtr->nod[1]).first + 20, positions.at(nodePtr->nod[1]).second + 20))
        };
        window.draw(line, 2, sf::Lines);
    }
}

// Dibujar todo el árbol
void cbintree::drawTree(sf::RenderWindow& window, node* p, sf::Font& font, map<node*, pair<int, int>>& positions) {
    map<int, node*> leftmost;
    map<int, node*> rightmost;

    findLeftmostRightmost(p, 0, leftmost, rightmost);

    // Dibujar las conexiones entre nodos
    for (auto& it : positions) {
        drawEdges(window, it.first, positions);
    }

    // Dibujar los nodos
    for (auto& it : positions) {
        node* currentNode = it.first;
        int xPos = it.second.first;
        int yPos = it.second.second;

        // Verificar si el nodo está en los contornos o es una hoja
        bool isContour = (leftmost[it.second.second / 80] == currentNode ||
            rightmost[it.second.second / 80] == currentNode ||
            (currentNode->nod[0] == nullptr && currentNode->nod[1] == nullptr));

        drawNodeWithColor(window, currentNode, font, xPos, yPos, isContour);
    }
}

// Función principal de dibujo
void cbintree::draw(sf::RenderWindow& window, sf::Font& font, sf::Vector2i mousePos) {
    if (root == nullptr) return;

    map<node*, pair<int, int>> positions;
    calculatePositions(root, 400, 50, 200, positions);
    drawTree(window, root, font, positions);
}

// Main para probar
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Visualización de Árbol Binario");
    sf::Font font;

    if (!font.loadFromFile("Mayan.ttf")) {
        cerr << "Error cargando la fuente" << endl;
        return -1;
    }

    cbintree tree;

    // Agregar más nodos
    tree.add(8);
    tree.add(4);
    tree.add(2);
    tree.add(1);
    tree.add(6);
    tree.add(3);
    tree.add(5);
    tree.add(7);
    tree.add(12);
    tree.add(14);
    tree.add(10);
    tree.add(9);
    tree.add(11);
    tree.add(13);
    tree.add(15);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(173, 216, 230));
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        tree.draw(window, font, mousePos);

        window.display();
    }

    return 0;
}

