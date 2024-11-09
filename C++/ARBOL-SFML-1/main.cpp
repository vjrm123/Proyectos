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

    bool find(int valor, node**& p);
    bool add(int valor);
    bool del(int valor);
    void draw(sf::RenderWindow& window, node* p, sf::Font& font, sf::Vector2i mousePos);
    node* getRoot() { return root; }

private:
    node* root;
    void clear(node* p);
    node** Rep(node** p);
    void calculatePositions(node* p, int x, int y, int horizontalOffset, map<node*, pair<int, int>>& positions, int& depth);
    void drawNode(sf::RenderWindow& window, node* nodePtr, sf::Font& font, int xPos, int yPos, sf::Vector2i mousePos);
    void drawEdges(sf::RenderWindow& window, node* nodePtr, const map<node*, pair<int, int>>& positions);
    void drawInorder(sf::RenderWindow& window, node* p, sf::Font& font, map<node*, pair<int, int>>& positions);
    void drawPreorder(sf::RenderWindow& window, node* p, sf::Font& font, map<node*, pair<int, int>>& positions);
};

void cbintree::clear(node* p) {
    if (!p) return;
    clear(p->nod[0]);
    clear(p->nod[1]);
    delete p;
}

bool cbintree::find(int valor, node**& p) {
    p = &root;
    while (*p && (*p)->valor != valor) {
        p = &((*p)->nod[(*p)->valor < valor]);
    }
    return *p != nullptr;
}

bool cbintree::add(int valor) {
    node** P;
    if (find(valor, P)) return false;
    *P = new node(valor);
    return true;
}

node** cbintree::Rep(node** p) {
    node** q = &((*p)->nod[1]);
    while ((*q)->nod[0]) {
        q = &((*q)->nod[0]);
    }
    return q;
}

bool cbintree::del(int valor) {
    node** P;
    if (!find(valor, P)) return false;
    if ((*P)->nod[0] && (*P)->nod[1]) {
        node** q = Rep(P);
        (*P)->valor = (*q)->valor;
        P = q;
    }
    node* t = *P;
    *P = (*P)->nod[(*P)->nod[1] != nullptr];
    delete t;
    return true;
}

void cbintree::calculatePositions(node* p, int x, int y, int horizontalOffset, map<node*, pair<int, int>>& positions, int& depth) {
    if (!p) return;
    positions[p] = make_pair(x, depth++);
    calculatePositions(p->nod[0], x - horizontalOffset, y + 80, horizontalOffset / 2, positions, depth);
    calculatePositions(p->nod[1], x + horizontalOffset, y + 80, horizontalOffset / 2, positions, depth);
}


void cbintree::drawNode(sf::RenderWindow& window, node* nodePtr, sf::Font& font, int xPos, int yPos, sf::Vector2i mousePos) {
 
    sf::CircleShape circle(20);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(xPos, yPos);
    if (mousePos.x >= xPos && mousePos.x <= xPos + 40 && mousePos.y >= yPos && mousePos.y <= yPos + 40) {
        circle.setFillColor(sf::Color::Yellow);  
    }
    window.draw(circle);

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

void cbintree::drawEdges(sf::RenderWindow& window, node* nodePtr, const map<node*, pair<int, int>>& positions) {
    if (nodePtr->nod[0] != nullptr) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(positions.at(nodePtr).first + 20, positions.at(nodePtr).second * 80 + 50 + 20)),
            sf::Vertex(sf::Vector2f(positions.at(nodePtr->nod[0]).first + 20, positions.at(nodePtr->nod[0]).second * 80 + 50 + 20))
        };
        window.draw(line, 2, sf::Lines);
    }
    if (nodePtr->nod[1] != nullptr) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(positions.at(nodePtr).first + 20, positions.at(nodePtr).second * 80 + 50 + 20)),
            sf::Vertex(sf::Vector2f(positions.at(nodePtr->nod[1]).first + 20, positions.at(nodePtr->nod[1]).second * 80 + 50 + 20))
        };
        window.draw(line, 2, sf::Lines);
    }
}

void cbintree::drawInorder(sf::RenderWindow& window, node* p, sf::Font& font, map<node*, pair<int, int>>& positions) {
    if (p == nullptr) return;
    drawInorder(window, p->nod[0], font, positions);

    sf::Text text;
    text.setFont(font);
    text.setString(to_string(p->valor));
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(positions[p].first + 5, 2);
    window.draw(text);

    drawInorder(window, p->nod[1], font, positions);
}

void cbintree::drawPreorder(sf::RenderWindow& window, node* p, sf::Font& font, map<node*, pair<int, int>>& positions) {
    if (p == nullptr) return;

    sf::Text text;
    text.setFont(font);
    text.setString(to_string(p->valor));
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Red);
    text.setPosition(50, positions[p].second * 80 + 50);
    window.draw(text);

    drawPreorder(window, p->nod[0], font, positions);
    drawPreorder(window, p->nod[1], font, positions);
}

void cbintree::draw(sf::RenderWindow& window, node* p, sf::Font& font, sf::Vector2i mousePos) {
    if (p == nullptr) return;

    map<node*, pair<int, int>> positions;
    int depth = 0;
    calculatePositions(p, 400, 50, 200, positions, depth);

    drawPreorder(window, p, font, positions);  
    drawInorder(window, p, font, positions);  

    for (auto& it : positions) {
        drawNode(window, it.first, font, it.second.first, it.second.second * 80 + 50, mousePos);
        drawEdges(window, it.first, positions);
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Visualización de Árbol Binario");
    sf::Font font;

    if (!font.loadFromFile("Mayan.ttf")) {
        std::cerr << "Error cargando la fuente" << std::endl;
        return -1;
    }

    cbintree tree;
    tree.add(5);
    tree.add(2);
    tree.add(8);
    tree.add(1);
    tree.add(3);
    tree.add(9);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(173, 216, 230));  
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);  

        tree.draw(window, tree.getRoot(), font, mousePos);

        window.display();
    }

    return 0;
}