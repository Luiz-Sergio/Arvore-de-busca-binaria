#include <bits/stdc++.h>
using namespace std;


bool found = true;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int level;
    int numberOfChildrenLeft;
    int numberOfChildrenRight;

    Node()
    {
        key = -1;
        numberOfChildrenLeft = 0;
        numberOfChildrenRight = 0;
        left = NULL;
        right = NULL;
    }

    Node(int k)
    {
        key = k;
        numberOfChildrenLeft = 0;
        numberOfChildrenRight = 0;
        left = NULL;
        right = NULL;
    }

    struct Node* insert(struct Node* node, int k)
    {
        found = true;
        if(node == NULL){
            node = new Node(k);
            return node;
        }

        if(k<node->key){
            node->left = insert(node->left,k);

            if(found){
                node->numberOfChildrenLeft++;
            }
        }else if(k>node->key){
            node->right = insert(node->right,k);
            
            if(found){
                node->numberOfChildrenRight++;
            }
        }else{
            cout<<"Impossível inserir elemento, pois ele já existe!"<<endl;
            found = false;
        }
        return node;
    }

    bool search(struct Node* node, int k)
    {
        bool FOUNDkey;
        if(node == NULL)
            return false;

        if(k<node->key){
            FOUNDkey = search(node->left,k);
        }else if(k>node->key){
            FOUNDkey = search(node->right,k);
        }else{
            cout<<"Encontrou!!!!!"<<endl;
            return true;
        }
        return FOUNDkey;
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
    struct Node *node = NULL;
    
    node = node->insert(node,5);
    node = node->insert(node,5);
    node = node->insert(node,10);
    node = node->insert(node,3);
    node = node->insert(node,2);
    node = node->insert(node,4);
    node = node->insert(node,1);
    node = node->insert(node,10);
    node = node->insert(node,12);
    node = node->insert(node,12);
    node = node->insert(node,0);
    node = node->insert(node,0);
    
    if(node->search(node,12)){
        cout<<"Encontrou";
    }else{
        cout<<"Nao encontrou";
    }

    cout<<"["<<node->key<<"]"<<endl;
    cout<<"["<<node->numberOfChildrenRight<<"]"<<endl;
    cout<<"["<<node->numberOfChildrenLeft<<"]"<<endl;

    cout<<"["<<node->right->key<<"]"<<endl;
    cout<<"["<<node->right->numberOfChildrenRight<<"]"<<endl;
    cout<<"["<<node->right->numberOfChildrenLeft<<"]"<<endl;

    cout<<"["<<node->left->key<<"]"<<endl;
    cout<<"["<<node->left->numberOfChildrenRight<<"]"<<endl;
    cout<<"["<<node->left->numberOfChildrenLeft<<"]"<<endl;

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
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}
