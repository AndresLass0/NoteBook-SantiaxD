// Trie clásico con contador de prefijos.
// Permite insertar strings y consultar cuántas veces aparece un prefijo.
// query(s) devuelve cuántos caracteres de s existen como prefijo y cuántas veces ha sido insertado.

struct Node {
  int cont;              // Cuántas palabras pasan por este nodo
  Node* child[26];       // Hijos (una letra por cada caracter 'a'-'z')

  Node() {
    cont = 0;
    fill(child, child + 26, nullptr);
  }
};

struct Trie {
  Node* root;

  Trie() {
    root = new Node();
  }

  void insert(const string &s) {
    Node* curr = root;
    for (char c : s) {
      int idx = c - 'a';
      if (curr->child[idx] == nullptr) {
        curr->child[idx] = new Node();
      }
      curr = curr->child[idx];
      curr->cont++;
    }
  }

  // Devuelve {l, c}, donde:
  // - l = longitud del prefijo encontrado (puede ser < s.size())
  // - c = cuántas veces se insertó ese prefijo
  pair<int, int> query(const string &s) {
    Node* curr = root;
    for (int i = 0; i < (int)s.size(); ++i) {
      int idx = s[i] - 'a';
      if (curr->child[idx] == nullptr) {
        return {i, curr->cont};  // prefijo hasta i-1 existe
      }
      curr = curr->child[idx];
    }
    return {(int)s.size(), curr->cont};
  }
};

/*
Ejemplo de uso:

Trie trie;
trie.insert("app");
trie.insert("apple");
trie.insert("app");

auto res1 = trie.query("applesauce"); // {5, 1} porque "apple" existe y fue insertado 1 vez
auto res2 = trie.query("april");      // {2, 3} porque "ap" fue prefijo 3 veces (de "app", "apple", "app")
*/
