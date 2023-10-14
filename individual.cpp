
#include <vector>

class Pacote;
class Cliente;

class Evento{

};

class Roteiro : public Evento{

};
class Deslocamento : public Evento{

};

class Pernoite : public Evento{

};


class Dependente{

};

class Cliente{
    std::vector<Dependente*> dependentes;
    std::vector<Pacote*> pacotes;

};

class Pacote{
    std::vector<Cliente*> clientes;
    std::vector<Evento*> eventos;
};
