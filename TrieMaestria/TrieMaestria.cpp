// TrieMaestria.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>


using namespace std;

// Trie's node
struct trie
{
    typedef map<char, trie*> next_t;

    // The set with all the letters which this node is prefix
    next_t next;

    // If word is equal to "" is because there is no word in the
    //  dictionary which ends here.
    string word;

    trie() : next(map<char, trie*>()) {}

    void insert(string w)
    {
        w = string("$") + w;

        int sz = w.size();

        trie* n = this;
        for (int i = 0; i < sz; ++i) {
            if (n->next.find(w[i]) == n->next.end()) {
                n->next[w[i]] = new trie();
            }

            n = n->next[w[i]];
        }

        n->word = w;
    }
};

// The tree
trie tree;

// The minimum cost of a given word to be changed to a word of the dictionary
int min_cost;
int target_cost = 1;

//
void search_impl(trie* tree, char ch, vector<int> last_row, const string& word, vector<string> &result)
{
    int sz = last_row.size();

    vector<int> current_row(sz);
    current_row[0] = last_row[0] + 1;

    // Calculate the min cost of insertion, deletion, match or substution
    int insert_or_del, replace;
    for (int i = 1; i < sz; ++i) {
        insert_or_del = min(current_row[i - 1] + 1, last_row[i] + 1);
        replace = (word[i - 1] == ch) ? last_row[i - 1] : (last_row[i - 1] + 1);

        current_row[i] = min(insert_or_del, replace);
    }

    // When we find a cost that is less than the min_cost, is because
    // it is the minimum until the current row, so we update
    if ((current_row[sz - 1] < min_cost) && (tree->word != "")) {
        min_cost = current_row[sz - 1];
    }

    if ((current_row[sz - 1] <= target_cost) && (tree->word != "")) {
        result.push_back(tree->word);
    }

    // If there is an element wich is smaller than the current minimum cost,
    //  we can have another cost smaller than the current minimum cost
    if (*min_element(current_row.begin(), current_row.end()) < min_cost) {
        for (trie::next_t::iterator it = tree->next.begin(); it != tree->next.end(); ++it) {
            search_impl(it->second, it->first, current_row, word, result);
        }
    }
}

int search(string word, vector<string> &result)
{
    word = string("$") + word;
    

    int sz = word.size();
    min_cost = 0x3f3f3f3f;

    vector<int> current_row(sz + 1);

    // Naive DP initialization
    for (int i = 0; i < sz; ++i) 
        current_row[i] = i;

    current_row[sz] = sz;

    // For each letter in the root map wich matches with a
    //  letter in word, we must call the search
    for (int i = 0; i < sz; ++i) {
        if (tree.next.find(word[i]) != tree.next.end()) {
            search_impl(tree.next[word[i]], word[i], current_row, word, result);
        }
    }

    return min_cost;
}

int main() {

    std::ifstream dic("palabras.txt");
    std::string line;
    

    cout << "Cargando palabras " << endl;
    int cont = 0;
    while (std::getline(dic,line)) {
        tree.insert(line);
        cont++;
    }
    cout << cont<< " palabras cargadas" << endl<<endl;

    string word;
    while (true) {
        vector<string> result;
        min_cost = 0x3f3f3f3f;

        cout << endl <<"Ingrese la palabra: ";
        cin >> word;
        if (word.size() == 0) {
            continue;
        }
        if (word == "exit") {
            break;
        }
        if (word == "cost") {
            cout << endl << "Ingrese el nuevo costo minimo:";
            cin >> target_cost;
            continue;
        }

        search(word, result);
        for (auto found : result) {
            cout << found.substr(1) << endl;
        }
    }

}
