#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
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
    void draw(sf::RenderWindow& window, node* p, int x, int y, int horizontalOffset, int depth);
    node* getRoot() { return root; }

private:
    node* root;
    void clear(node* p);
    node** Rep(node** p);
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

void cbintree::draw(sf::RenderWindow& window, node* p, int x, int y, int horizontalOffset, int depth) {
    if (p == nullptr) return;

    sf::CircleShape circle(20);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(x, y);
    window.draw(circle);

    int childY = y + 80;
    if (p->nod[0] != nullptr) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 20, y + 20)),
            sf::Vertex(sf::Vector2f(x - horizontalOffset + 20, childY))
        };
        window.draw(line, 2, sf::Lines);
        draw(window, p->nod[0], x - horizontalOffset, childY, horizontalOffset / 2, depth + 1);
    }
    if (p->nod[1] != nullptr) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 20, y + 20)),
            sf::Vertex(sf::Vector2f(x + horizontalOffset + 20, childY))
        };
        window.draw(line, 2, sf::Lines);
        draw(window, p->nod[1], x + horizontalOffset, childY, horizontalOffset / 2, depth + 1);
    }
}

int main() {
    cbintree tree;
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(3);
    tree.add(7);
    tree.add(12);
    tree.add(17);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Binary Tree Visualization");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        tree.draw(window, tree.getRoot(), 400, 50, 200, 0);
        window.display();
    }
    return 0;
}
