#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct node *left;
    struct node *right;
    int nivel;
    int numFilhosEsquerda;
    int numFilhosDireita;

    Node()
    {
        key = -1;
        numFilhosEsquerda = 0;
        numFilhosDireita = 0;
        left = NULL;
        right = NULL;
    }

    Node(int k)
    {
        key = k;
        numFilhosEsquerda = 0;
        numFilhosDireita = 0;
        left = NULL;
        right = NULL;
    }

    struct Node* insert(struct Node* node, int k)
    {
        if(node == NULL){
            struct Node* node = (struct Node*) malloc(sizeof(struct Node));
            node->key = k;
            node->left = NULL;
            node->right = NULL;
            return node;
        }

        if(k<node->key){
            node->left = insert(node->left,k);
        }else if(k>node->key){
            node->right = insert(node->right,k);
        }else{
            cout<<"Impossível inserir elemento, pois ele já existe!"<<endl;
        }
        return node;
    }

    // void remove()
    // {
    // }

    // void print()
    // {
    // }
};

bool is_number(const std::string &s);

int main()
{
    //Node node = Node(5);
    struct Node *node = NULL;
    
    node = node->insert(node,5);
    node = node->insert(node,5);

    

    cout<<"["<<node->key<<"]"<<endl;
    cout<<"["<<node->numFilhosDireita<<"]"<<endl;
    cout<<"["<<node->numFilhosEsquerda<<"]"<<endl;
    if(node->left==0)
        cout<<"É NULO COROI"<<endl;
    else
        cout<<"Não é nulo";
    if(node->right==NULL)
        cout<<"É NULO COROI"<<endl;    

    string s;
    int numbers;

    while (cin >> s)
    {
        // fill the three here
        if (is_number(s))
        {
            numbers = stoi(s);
            cout << numbers;
        }
        else
        { // read commands here
            if (s == "CHEIA")
            {
                // call function isCheia
                cout << "Cheia" << endl;
            }
            else if (s == "MEDIANA")
            {
                // call function mediana
            }
            else if (s == "COMPLETA")
            {
                cout << "completa" << endl;
            }
            else if (s == "ENESIMO")
            {
            }
            else if (s == "POSICAO")
            {
            }
            else if (s == "MEDIANA")
            {
            }
            else if (s == "IMPRIMA")
            {
            }
            else if (s == "REMOVA")
            {
            }
        }
    }

    return 0;
}

bool is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}
