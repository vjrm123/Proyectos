#include <iostream>
#include <queue>

struct CBinTreeNode
{
    CBinTreeNode(int v)
    {
        value = v;
        nodes[0] = nodes[1] = nullptr;
    }
    CBinTreeNode* nodes[2];
    int value;
};

class CBinTree
{
public:
    CBinTree();
    void Print();
    bool Insert(int x, bool isLeft);
private:
    bool Find(int x, CBinTreeNode**& p, bool isLeft);
    void Levels(CBinTreeNode* n);
    CBinTreeNode* root;
};

CBinTree::CBinTree()
{
    root = nullptr;
}

bool CBinTree::Find(int x, CBinTreeNode**& p, bool isLeft)
{
    for (p = &root; *p && (*p)->value != x;
        p = &((*p)->nodes[isLeft ? 0 : 1])); // Selecciona izquierda o derecha basado en isLeft
    return *p != nullptr;
}

bool CBinTree::Insert(int x, bool isLeft)
{
    CBinTreeNode** p;
    if (Find(x, p, isLeft)) return false; // Si ya existe, no lo inserta
    *p = new CBinTreeNode(x);
    return true;
}

void CBinTree::Levels(CBinTreeNode* n)
{
    if (!n) return;
    std::queue<std::pair<CBinTreeNode*, int>> q;
    q.push({ n,0 });
    int l = 0;
    while (!q.empty())
    {
        int last = l;
        std::pair<CBinTreeNode*, int> pp = q.front();
        CBinTreeNode* nn = pp.first;
        l = pp.second;
        if (nn->nodes[0])  q.push({ nn->nodes[0],l + 1 });
        if (nn->nodes[1])  q.push({ nn->nodes[1],l + 1 });
        if (last != l)    std::cout << "\n";
        std::cout << nn->value << "(" << l << ") ";
        q.pop();
    }
}

void CBinTree::Print()
{
    Levels(root);
    std::cout << "\n";
}

void VecInsert(CBinTree* t, int* v, int size)
{
    // Función para insertar elementos en el árbol según la paridad
    for (int i = 0; i < size; ++i)
    {
        bool isLeft = (v[i] % 2 != 0); // Si es impar, va a la izquierda
        t->Insert(v[i], isLeft);
    }
}

int main()
{
    CBinTree t;
    int v[] = { 20, 19, 18, 15, 16, 17, 14, 11, 13, 12, 9, 7, 8, 10, 6, 5, 2, 4, 3, 1 };
    int size = sizeof(v) / sizeof(v[0]);
    VecInsert(&t, v, size);
    t.Print();
}
