#include <iostream>
#include <string>
#include <vector>

class Cliente {
public:
    std::string nome;
    int idade;
    // Outros atributos comuns e métodos
};

class Dependente : public Cliente {
public:
    std::string parentesco;
    // Outros atributos específicos para Dependente
};

class Pacote {
public:
    std::string destino;
    float preco;
    // Outros atributos comuns e métodos
};

class Evento : public Pacote {
public:
    std::string data;
    int duracao;
    // Outros atributos comuns e métodos
};

class Roteiro : public Evento {
public:
    std::vector<std::string> atracoes;
    // Outros atributos específicos para Roteiro
};

class Deslocamento : public Evento {
public:
    std::string meio_transporte;
    // Outros atributos específicos para Deslocamento
};

class Pernoite : public Evento {
public:
    std::string hotel;
    std::string tipo_quarto;
    // Outros atributos específicos para Pernoite
};

int main() {
    Cliente cliente1;
    cliente1.nome = "João";
    cliente1.idade = 30;

    Dependente dependente1;
    dependente1.nome = "Maria";
    dependente1.idade = 8;
    dependente1.parentesco = "Filha";

    Pacote pacote1;
    pacote1.destino = "Paris";
    pacote1.preco = 2000.0;

    Roteiro roteiro1;
    roteiro1.destino = "Roma";
    roteiro1.data = "2023-07-15";
    roteiro1.duracao = 7;
    roteiro1.atracoes.push_back("Coliseu");
    roteiro1.atracoes.push_back("Museu do Vaticano");

    // Uso das classes e seus atributos/métodos
    // ...

    return 0;
}
