#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct node *left;
    struct node *right;
    int nivel;

    Node(int k)
    {
        key = k;
    }

    void insert()
    {
    }

    void remove()
    {
    }

    void print()
    {
    }
};

bool is_number(const std::string &s);

int main()
{
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
