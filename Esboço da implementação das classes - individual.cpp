#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Classe base Eventos
class Eventos {
public:
    // Atributos e métodos
};

// Subclasses de Eventos
class Roteiros : public Eventos {
public:
    // Atributos e métodos
};

class Deslocamentos : public Eventos {
public:
    // Atributos e métodos
};

class Pernoites : public Eventos {
public:
    // Atributos e métodos
};

// Classe Cliente
class Cliente {
public:
    // Atributos e métodos
};

// Classe Dependente
class Dependente {
public:
    // Atributos e métodos
};

// Classe Pacote
class Pacote {
public:
    // Atributos e métodos
};

// Relação de agregação entre Pacote e Evento
class Pacote {
public:
    vector<Eventos*> eventos; // Um Pacote pode conter vários Eventos
    // Atributos e métodos
};
