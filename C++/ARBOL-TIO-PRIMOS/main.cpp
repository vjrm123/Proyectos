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
    void draw(sf::RenderWindow& window, sf::Font& font, sf::Vector2i mousePos, int selectedNodeValue);
    node* getRoot() { return root; }

private:
    node* root;

    void clear(node* p);
    void calculatePositions(node* p, int x, int y, int horizontalOffset, map<node*, pair<int, int>>& positions);
    void drawNodeWithColor(sf::RenderWindow& window, node* nodePtr, sf::Font& font, int xPos, int yPos, sf::Color color);
    void drawEdges(sf::RenderWindow& window, node* nodePtr, const map<node*, pair<int, int>>& positions);
    void drawTree(sf::RenderWindow& window, node* p, sf::Font& font, map<node*, pair<int, int>>& positions, int selectedNodeValue);
    node* findNode(node* p, int value);
    node* findParent(node* p, node* child);
    vector<node*> findUncles(node* p);
    vector<node*> findCousins(node* p);
};

bool cbintree::add(int valor) {
    node** p = &root;
    while (*p != nullptr) {
        if ((*p)->valor == valor) return false;
        p = &((*p)->nod[(*p)->valor < valor]);
    }
    *p = new node(valor);
    return true;
}

void cbintree::clear(node* p) {
    if (!p) return;
    clear(p->nod[0]);
    clear(p->nod[1]);
    delete p;
}

node* cbintree::findNode(node* p, int value) {
    if (!p) return nullptr;
    if (p->valor == value) return p;
    if (value < p->valor) return findNode(p->nod[0], value);
    return findNode(p->nod[1], value);
}

node* cbintree::findParent(node* p, node* child) {
    if (!p || !child) return nullptr;
    if (p->nod[0] == child || p->nod[1] == child) return p;
    if (child->valor < p->valor) return findParent(p->nod[0], child);
    return findParent(p->nod[1], child);
}

vector<node*> cbintree::findUncles(node* p) {
    vector<node*> uncles;
    if (!p || !root) return uncles;

    node* parent = findParent(root, p);
    if (parent) {
        node* grandParent = findParent(root, parent);
        if (grandParent) {
            if (grandParent->nod[0] && grandParent->nod[0] != parent) {
                uncles.push_back(grandParent->nod[0]);
            }
            if (grandParent->nod[1] && grandParent->nod[1] != parent) {
                uncles.push_back(grandParent->nod[1]);
            }
        }
    }
    return uncles;
}

vector<node*> cbintree::findCousins(node* p) {
    vector<node*> cousins;
    vector<node*> uncles = findUncles(p);
    for (node* uncle : uncles) {
        if (uncle->nod[0]) cousins.push_back(uncle->nod[0]);
        if (uncle->nod[1]) cousins.push_back(uncle->nod[1]);
    }
    return cousins;
}

void cbintree::calculatePositions(node* p, int x, int y, int horizontalOffset, map<node*, pair<int, int>>& positions) {
    if (!p) return;
    positions[p] = make_pair(x, y);
    calculatePositions(p->nod[0], x - horizontalOffset, y + 80, horizontalOffset / 2, positions);
    calculatePositions(p->nod[1], x + horizontalOffset, y + 80, horizontalOffset / 2, positions);
}

void cbintree::drawNodeWithColor(sf::RenderWindow& window, node* nodePtr, sf::Font& font, int xPos, int yPos, sf::Color color) {
    sf::CircleShape circle(20);
    circle.setFillColor(color);
    circle.setPosition(xPos, yPos);
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

void cbintree::drawTree(sf::RenderWindow& window, node* p, sf::Font& font, map<node*, pair<int, int>>& positions, int selectedNodeValue) {
    node* selectedNode = findNode(p, selectedNodeValue);
    vector<node*> uncles;
    vector<node*> cousins;

    if (selectedNode) {
        uncles = findUncles(selectedNode);
        cousins = findCousins(selectedNode);
    }

    for (auto& it : positions) {
        drawEdges(window, it.first, positions);
    }

    for (auto& it : positions) {
        node* currentNode = it.first;
        int xPos = it.second.first;
        int yPos = it.second.second;

        sf::Color color = sf::Color::Green; 

        if (currentNode == selectedNode) {
            color = sf::Color::Red;
        }
        else if (find(uncles.begin(), uncles.end(), currentNode) != uncles.end()) {
            color = sf::Color::Blue;
        }
        else if (find(cousins.begin(), cousins.end(), currentNode) != cousins.end()) {
            color = sf::Color::Cyan; 
        }

        drawNodeWithColor(window, currentNode, font, xPos, yPos, color);
    }
}

void cbintree::draw(sf::RenderWindow& window, sf::Font& font, sf::Vector2i mousePos, int selectedNodeValue) {
    if (root == nullptr) return;

    map<node*, pair<int, int>> positions;
    calculatePositions(root, 400, 50, 200, positions);
    drawTree(window, root, font, positions, selectedNodeValue);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Visualización de Árbol Binario");
    sf::Font font;

    if (!font.loadFromFile("Mayan.ttf")) {
        cerr << "Error cargando la fuente" << endl;
        return -1;
    }

    cbintree tree;

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

    int selectedNodeValue = 3; 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(173, 216, 230));
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        tree.draw(window, font, mousePos, selectedNodeValue);

        window.display();
    }

    return 0;
}