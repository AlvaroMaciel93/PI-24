#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Evento {
public:
    string nome;
    string data;
    string local;
    double custo;
    
    Evento(string nome, string data, string local, double custo)
        : nome(nome), data(data), local(local), custo(custo) {
    }
    
    void mostrarDetalhes() {
        cout << "Nome: " << nome << "\n";
        cout << "Data: " << data << "\n";
        cout << "Local: " << local << "\n";
        cout << "Custo: $" << custo << "\n";
    }
};

class Pacote {
public:
    string nome;
    vector<Evento> eventos;
    double preco;
    
    Pacote(string nome, double preco)
        : nome(nome), preco(preco) {
    }
    
    void adicionarEvento(const Evento& evento) {
        eventos.push_back(evento);
    }
    
    void mostrarDetalhes() {
        cout << "Nome do Pacote: " << nome << "\n";
        cout << "Preço: $" << preco << "\n";
        cout << "Eventos incluídos:\n";
        for (const Evento& evento : eventos) {
            cout << " - " << evento.nome << "\n";
        }
    }
};

class Dependente {
public:
    string nome;
    int idade;
    
    Dependente(string nome, int idade)
        : nome(nome), idade(idade) {
    }
};

class Cliente {
public:
    string nome;
    int idade;
    vector<Dependente> dependentes;
    
    Cliente(string nome, int idade)
        : nome(nome), idade(idade) {
    }
    
    void adicionarDependente(const Dependente& dependente) {
        dependentes.push_back(dependente);
    }
};

class Venda {
public:
    Cliente cliente;
    Pacote pacote;
    
    Venda(const Cliente& cliente, const Pacote& pacote)
        : cliente(cliente), pacote(pacote) {
    }
};

vector<Evento> eventos;
vector<Pacote> pacotes;
vector<Cliente> clientes;
vector<Venda> vendas;

void cadastrarEvento() {
    string nome, data, local;
    double custo;

    cout << "Nome do evento: ";
    cin >> nome;
    cout << "Data do evento: ";
    cin >> data;
    cout << "Local do evento: ";
    cin >> local;
    cout << "Custo do evento: $";
    cin >> custo;

    Evento evento(nome, data, local, custo);
    eventos.push_back(evento);

    cout << "Evento cadastrado com sucesso!\n";
}

void criarPacote() {
    string nome;
    double preco;

    cout << "Nome do pacote: ";
    cin >> nome;
    cout << "Preço do pacote: $";
    cin >> preco;

    Pacote pacote(nome, preco);

    // Adicione eventos ao pacote
    int numEventos;
    cout << "Quantos eventos deseja adicionar a este pacote? ";
    cin >> numEventos;

    for (int i = 0; i < numEventos; i++) {
        int index;
        cout << "Selecione o evento (índice): ";
        cin >> index;
        if (index >= 0 && index < eventos.size()) {
            pacote.adicionarEvento(eventos[index]);
        } else {
            cout << "Evento inválido. Tente novamente.\n";
            i--;
        }
    }

    pacotes.push_back(pacote);
    cout << "Pacote criado com sucesso!\n";
}

void criarCliente() {
    string nome;
    int idade;

    cout << "Nome do cliente: ";
    cin >> nome;
    cout << "Idade do cliente: ";
    cin >> idade;

    Cliente cliente(nome, idade);

    // Adicione dependentes
    int numDependentes;
    cout << "Quantos dependentes deseja adicionar a este cliente? ";
    cin >> numDependentes;

    for (int i = 0; i < numDependentes; i++) {
        string dependenteNome;
        int dependenteIdade;
        cout << "Nome do dependente: ";
        cin >> dependenteNome;
        cout << "Idade do dependente: ";
        cin >> dependenteIdade;
        Dependente dependente(dependenteNome, dependenteIdade);
        cliente.adicionarDependente(dependente);
    }

    clientes.push_back(cliente);
    cout << "Cliente criado com sucesso!\n";
}

void venderPacote() {
    int clienteIndex, pacoteIndex;
    cout << "Selecione o cliente (índice): ";
    cin >> clienteIndex;
    cout << "Selecione o pacote (índice): ";
    cin >> pacoteIndex;

    if (clienteIndex >= 0 && clienteIndex < clientes.size() && pacoteIndex >= 0 && pacoteIndex < pacotes.size()) {
        Venda venda(clientes[clienteIndex], pacotes[pacoteIndex]);
        vendas.push_back(venda);
        cout << "Pacote vendido com sucesso!\n";
    } else {
        cout << "Cliente ou pacote inválidos. Tente novamente.\n";
    }
}

void listarClientes() {
    cout << "Lista de clientes:\n";
    for (int i = 0; i < clientes.size(); i++) {
        cout << "Cliente " << i << ": " << clientes[i].nome << "\n";
        cout << "Idade: " << clientes[i].idade << "\n";
        cout << "Dependentes:\n";
        for (const Dependente& dependente : clientes[i].dependentes) {
            cout << " - " << dependente.nome << " (Idade: " << dependente.idade << ")\n";
        }
    }
}

void listarPacotes() {
    cout << "Lista de pacotes:\n";
    for (int i = 0; i < pacotes.size(); i++) {
        cout << "Pacote " << i << ": " << pacotes[i].nome << "\n";
        cout << "Preço: $" << pacotes[i].preco << "\n";
        cout << "Eventos no pacote:\n";
        for (const Evento& evento : pacotes[i].eventos) {
            cout << " - " << evento.nome << "\n";
        }
    }
}

void listarPacotesContratadosPorCliente() {
    int clienteIndex;
    cout << "Selecione o cliente (índice): ";
    cin >> clienteIndex;

    if (clienteIndex >= 0 && clienteIndex < clientes.size()) {
        cout << "Pacotes contratados por " << clientes[clienteIndex].nome << ":\n";
        for (const Venda& venda : vendas) {
            if (venda.cliente.nome == clientes[clienteIndex].nome) {
                cout << " - " << venda.pacote.nome << "\n";
            }
        }
    } else {
        cout << "Cliente inválido. Tente novamente.\n";
    }
}

void listarClientesQueContrataramPacote() {
    int pacoteIndex;
    cout << "Selecione o pacote (índice): ";
    cin >> pacoteIndex;

    if (pacoteIndex >= 0 && pacoteIndex < pacotes.size()) {
        cout << "Clientes que contrataram o pacote " << pacotes[pacoteIndex].nome << ":\n";
        for (const Venda& venda : vendas) {
            if (venda.pacote.nome == pacotes[pacoteIndex].nome) {
                cout << " - " << venda.cliente.nome << "\n";
            }
        }
    } else {
        cout << "Pacote inválido. Tente novamente.\n";
    }
}

int main() {
    int opcao;

    while (true) {
        cout << "\nEscolha uma opção:\n";
        cout << "1. Cadastrar Evento\n";
        cout << "2. Criar Pacote\n";
        cout << "3. Criar Cliente com Dependentes\n";
        cout << "4. Vender Pacote a Cliente\n";
        cout << "5. Listar Clientes com Dependentes\n";
        cout << "6. Listar Pacotes com Eventos\n";
        cout << "7. Listar Pacotes Contratados por Cliente\n";
        cout << "8. Listar Clientes que Contrataram um Pacote\n";
        cout << "9. Sair\n";
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarEvento();
                break;
            case 2:
                criarPacote();
                break;
            case 3:
                criarCliente();
                break;
            case 4:
                venderPacote();
                break;
            case 5:
                listarClientes();
                break;
            case 6:
                listarPacotes();
                break;
            case 7:
                listarPacotesContratadosPorCliente();
                break;
            case 8:
                listarClientesQueContrataramPacote();
                break;
            case 9:
                return 0;
            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    }

    return 0;
}
