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
        level = 1;
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

    struct Node* getNode(struct Node* node, int k)
    {        
         if(node == NULL)
             return node;

         if(k<node->key){
             node = getNode(node->left,k);
         }else if(k>node->key){
             node = getNode(node->right,k);
         }
        return node;
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


    // Ao chamar a função passar 1 como parâmetro para ser o nível da raiz.
    void calculaNivel(struct Node* node, int l){
        node->level = l;
        //cout << "key = " << node->key << " level = " << node->level << endl;

        if(node->left != NULL){
            node->calculaNivel(node->left, l+1);
        }
        if(node->right != NULL){
            node->calculaNivel(node->right, l+1);
        }

        return;
    }

    int calcQtdDigitos(int numero){
        if ((numero / 10) == 0){ 
            return 1;
        }
        else{
            // efetua mais uma chamada recursiva
            return 1 + calcQtdDigitos(numero / 10);
        }
    }

    void imprimeFormato1(struct Node* node){
        for(int ii = 1; ii < node->level; ii++){
            cout << "    ";
        }

        cout<<node->key;

        for(int ii = 4; ii < 40-node->level*4-calcQtdDigitos(node->key); ii++){
            cout<<"-";
        }

        cout<<endl;

        if(node->left != NULL){
            imprimeFormato1(node->left);
        }if(node->right != NULL){
            imprimeFormato1(node->right);
        }
        
        return;
    }

    void imprimeFormato2(struct Node* node){
        cout<<"(" << node->key;

        if(node->left != NULL){
            cout<<" ";
            imprimeFormato2(node->left);
        }if(node->right != NULL){
            cout<<" ";
            imprimeFormato2(node->right);
        }


        cout<<")";
    }

    void imprimeArvore(struct Node* node, int s){
        node->calculaNivel(node, 1);
        if(s == 1){
            imprimeFormato1(node);
        }
        else if(s == 2){
            imprimeFormato2(node);
            cout<<endl;
        }
    }

    string pre_ordem(struct Node* node){
        string concatenados = to_string(node->key);

        if(node->left != NULL){
            concatenados = concatenados + " " + pre_ordem(node->left);
        }if(node->right != NULL){
            concatenados = concatenados + " " + pre_ordem(node->right);
        }
    
    return concatenados;
    }

    int getMedian(struct Node* node) {
        int count = 0;
        return getMedian(node,node->countChildren(node),count);
    }

    int getMedian(struct Node* node, int totalNodes, int& count) {
        if (node == NULL) {
            return -1; // valor inválido que indique erro
        }

        // Percorre a subárvore esquerda
        int median;
        median = getMedian(node->left, totalNodes, count);
        if (median != -1) {
            return median;
        }

        // Verifica se o nó atual é o da mediana
        count++;
        if (count == (totalNodes + 1) / 2) {
            //medianNode = node;
            return node->key;
        }        

        // Percorre a subárvore direita
        return getMedian(node->right, totalNodes, count);
    }
    double getAverage(struct Node* node,double& average){
        if(node == NULL){
             return 0;
        }
        average += node->key;
        getAverage(node->left,average);
        getAverage(node->right,average);
        return average;
    }

    double getAverage(int key, struct Node* node){        
        double average = 0;
        node = getNode(node,key);
        if(node != NULL){
            average = getAverage(node,average);
            return average/(node->numberOfChildrenLeft+node->numberOfChildrenRight+1);
        }
        else return -1;
    }

    bool ehCheia(struct Node * node){
        int count = 0,nivel = 0;
        bool eh = ehCheia(node,count,nivel);        
    }

    bool ehCheia(struct Node * node, int& count, int& nivel){
        bool eh = true;
        if(node == NULL){
            return nivel == count;
        }
        if((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL)){
            return false;
        }
        
        count++;
        if(nivel == 0){
            if(node->left == NULL && node->right == NULL) nivel = count;
        }else {
            if(node->left == NULL && node->right == NULL) return (nivel == count);
        }
        ehCheia(node->left,count,nivel); 
        ehCheia(node->right,count,nivel);
        count--;
        return eh;
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
                cout << node->ehCheia(node) << endl;
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

    cout << node->pre_ordem(node) << endl;
    cout << "Mediana: " << node->getMedian(node) << endl;
    cout << "Média: "<< node->getAverage(5,node) << endl;
    node->imprimeArvore(node, 1);
    node->imprimeArvore(node, 2);
    cout << node->ehCheia(node) << endl;
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
    // cout<<"(((("<<node->enesimoElemento(5,node)<<"))))";
    // cout<<"(((("<<node->posicao(3,node)<<"))))";

    


    return 0;
}

bool is_number(const std::string &s)
{
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}
