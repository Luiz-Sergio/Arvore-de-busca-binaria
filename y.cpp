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
            cout<<"Imposs├¡vel inserir elemento, pois ele j├í existe!"<<endl;
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

    struct Node* findPredecessor(struct Node* node)
{
    struct Node* current = node->left;
    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}

struct Node* removeKey(struct Node* node, int k)
{
    found = true;
    if (node == NULL) {
        return node;
    }

    if (k < node->key) {
        node->left = removeKey(node->left, k);
        if (found) {
            node->numberOfChildrenLeft--;
        }
    } else if (k > node->key) {
        node->right = removeKey(node->right, k);
        if (found) {
            node->numberOfChildrenRight--;
        }
    } else {
        if (node->numberOfChildrenLeft == 0 && node->numberOfChildrenRight == 0) {
            delete node;
            return NULL;
        } else if (node->numberOfChildrenLeft > 0 && node->numberOfChildrenRight == 0) {
            struct Node* temp = node;
            node = node->left;
            delete temp;
        } else if (node->numberOfChildrenLeft == 0 && node->numberOfChildrenRight > 0) {
            struct Node* temp = node;
            node = node->right;
            delete temp;
        } else {
            struct Node* predecessor;
            predecessor = findPredecessor(node);
            node->key = predecessor->key;
            node->left = removeKey(node->left, predecessor->key);
        }
        found = false;
    }

    if (node != NULL) {
        node->numberOfChildrenLeft = countChildren(node->left);
        node->numberOfChildrenRight = countChildren(node->right);
    }

    return node;
}
int countChildren(struct Node* node)
{
    if (node == NULL) {
        return 0;
    }
    return 1 + countChildren(node->left) + countChildren(node->right);
}

int enesimoElemento(struct Node* node, int pos, int &count){
    int achou;
    if(node->left != NULL)
        achou = enesimoElemento(node->left, pos, count);
        if(achou!=0)
            return achou;
        
    count++;
    
    if(count == pos)
        return node->key;

    if(node->right != NULL)
        achou = enesimoElemento(node->right, pos, count);
        if(achou != 0)
            return achou;
    return 0;
}

int enesimoElemento(int pos, struct Node* node){
    int count = 0;
    return enesimoElemento(node,pos,count);
}

int posicao(struct Node* node, int value, int &count){
    int achou = 0;

    //só chama recursão se o nó esquerdo não for vazio
    if(node->left != NULL)
        achou = posicao(node->left, value, count);
        if(achou!=0)//se o nó foi encontrado pare recursão
            return achou;

    //se chave for maior que o valor que estamos procurando pare recursão e retorne 0 simbolizando que não foi achado
    if(node->key>value){
        return 0;
    }

    count++;

    //se chave for igual a que estamos procurando pare recursão e retorne o valor
    if(value == node->key){
        return count;
    }

    //só chama recursão se o nó direito não for vazio 
    if(node->right != NULL)
        achou = posicao(node->right, value, count);
        if(achou != 0)//se o nó foi encontrado pare recursão
            return achou;

    return 0;
}

int posicao(int value, struct Node* node){
    int count = 0;
    return posicao(node,value,count);
}

};

bool is_number(const std::string &s);

int main()
{
    struct Node *node = NULL;

    string s;
    int numbers;

    while (cin >> s)
    {
        // fill the three here
        if (is_number(s))
        {
            numbers = stoi(s);
            node = node->insert(node, numbers);
        }
        else
        { // read commands here
            if (s == "CHEIA")
            {
                
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
    // cout<<"["<<node->key<<"]"<<endl;
    // cout<<"["<<node->numberOfChildrenRight<<"]"<<endl;
    // cout<<"["<<node->numberOfChildrenLeft<<"]"<<endl;
    // if(node->search(node,4))
    //     cout<<"found"<<endl;
    // cout<<"chave a ser deletada"<<node->key<<endl;
    // cout<<"chave a ser deletada"<<node->right->left->key<<endl;
    // cout<<"chave a ser deletada"<<node->right->right->key<<endl;
    // node = node->removeKey(node,10);
    // cout<<"chave a ser deletada"<<node->key<<endl;
    // cout<<"chave a ser deletada"<<node->right->key<<endl;
    // cout<<"chave a ser deletada"<<node->right->left->key<<endl;
    // cout<<"chave a ser deletada"<<node->right->right->key<<endl;
    // cout<<"chave a ser deletada"<<node->right->left->right->key<<endl;
    cout<<"(((("<<node->enesimoElemento(5,node)<<"))))";
    cout<<"(((("<<node->posicao(3,node)<<"))))";


    return 0;
}

bool is_number(const std::string &s)
{
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}
