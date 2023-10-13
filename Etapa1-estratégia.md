# Estratégia de Implementação: 

Classe Roteiros, Deslocamentos e Pernoites como subclasses da classe Eventos:
Essa é uma relação de herança, onde as subclasses herdam características e comportamentos da classe Eventos, como datas e locais.

Classes Clientes e Dependentes:
A relação entre Cliente e Dependente é uma relação de composição.
A existência de um Dependente depende diretamente de um Cliente. Isso significa que um Dependente não faz sentido existir sem um Cliente.

Classes Clientes e Pacote:
A relação entre Cliente e Pacote é uma relação de agregação.
Um Cliente pode estar associado a vários Pacotes, mas um Pacote não faz parte essencial do Cliente.
Portanto, é uma relação de agregação, onde o Cliente possui uma coleção de Pacotes, mas eles podem existir independentemente.

Classes Pacote e Evento:
A relação entre Pacote e Evento é de agregação.
Um Pacote pode conter vários Eventos, mas um Evento não faz parte essencial de um Pacote.
