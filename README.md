# Blockchain Exemple in C++


![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white) ![SHA-256](https://img.shields.io/badge/SHA--256-4CAF50?style=for-the-badge&logo=security&logoColor=white)




#### Este projeto implementa uma blockchain simples em Java, com foco em demonstrar os conceitos básicos de como funciona uma blockchain: encadeamento de blocos, hash, e geração de um novo bloco a cada intervalo de tempo.

## Funcionalidade

- ### O projeto cria uma blockchain simples onde:

    - #### Um bloco gênese (o primeiro bloco da cadeia) é criado.

    - #### Após a criação do bloco gênese, um novo bloco é gerado automaticamente a cada 3 segundos, com base no bloco anterior.

    - #### Cada bloco contém:

        - Um índice (posição do bloco na cadeia).
        - Um timestamp (data e hora de criação).
        - O hash do bloco anterior, garantindo a integridade da cadeia.
        - O próprio hash do bloco, que é recalculado toda vez que um novo bloco é criado.

## Como Funciona?

- Bloco Gênese: O primeiro bloco é criado manualmente. Ele não tem um bloco anterior e não possui hash (é um caso especial na blockchain).
- Blocos Subsequentemente Criados: A cada 3 segundos, um novo bloco é criado, com base no bloco anterior.
- Hashing: O hash de cada bloco é calculado usando a função de hash SHA256. Esse hash é a "impressão digital" do bloco, garantindo sua integridade.
- Encadeamento de Blocos: Cada bloco aponta para o bloco anterior por meio de seu hash, garantindo que, se qualquer bloco for alterado, todos os blocos subsequentes serão invalidos.

## Como Usar
- ### Requisitos:
  - #### Ter Docker instalado.

- ### Clone o repositório:

        git clone https://github.com/Rodrigo-Kelven/Blockchain--Exemple/
        cd Blockchain--Example

- ### Execute o código:

        docker build -t blockchain-app .
        docker run blockchain-app

##### Saída esperada: O programa começará exibindo o bloco gênese, seguido de novos blocos gerados automaticamente a cada 3 segundos, imprimindo detalhes como índice, timestamp, dados, hash do bloco anterior e o hash do bloco atual.

### Exemplo de Saída
    
    Adicionando Bloco #1
    Digite os dados para o bloco (ou digite 'sair' para parar): Index: 0
    Timestamp: 2025-8-9 21:35:43
    Data: Genesis Block
    Previous Hash: 0
    Hash: e0519e5dae4fb5ff02b506d5e380a2859ac2d613f916b2b160af22ed60507195
    -----------------------------------
    Index: 1
    Timestamp: 2025-8-9 21:35:43
    Data: 
    Previous Hash: e0519e5dae4fb5ff02b506d5e380a2859ac2d613f916b2b160af22ed60507195
    Hash: 2fe58e31bfdb064c1f518864ae91101a57355b626629fa62758577390eac0c82
    -----------------------------------
    Pausando por 3 segundos...
    Adicionando Bloco #2
    Digite os dados para o bloco (ou digite 'sair' para parar): Index: 0
    Timestamp: 2025-8-9 21:35:43
    Data: Genesis Block
    Previous Hash: 0
    Hash: e0519e5dae4fb5ff02b506d5e380a2859ac2d613f916b2b160af22ed60507195
    -----------------------------------
    Index: 1
    Timestamp: 2025-8-9 21:35:43
    Data: 
    Previous Hash: e0519e5dae4fb5ff02b506d5e380a2859ac2d613f916b2b160af22ed60507195
    Hash: 2fe58e31bfdb064c1f518864ae91101a57355b626629fa62758577390eac0c82
    -----------------------------------
    Index: 2
    Timestamp: 2025-8-9 21:35:46
    Data: 
    Previous Hash: 2fe58e31bfdb064c1f518864ae91101a57355b626629fa62758577390eac0c82
    Hash: 7fbdff6db737ad06c00592c31d53683aba1cb5a4eada4374cd3543b233b19b63
    -----------------------------------




### Tecnologias Utilizadas

- C++: Linguagem utilizada para a implementação da blockchain.
- SHA-256: Função de hash criptográfico usada para gerar os hashes dos blocos.

### Contribuições

Se você deseja contribuir para este projeto, fique à vontade para criar pull requests ou relatar issues. Melhorias como persistência de dados, maior segurança, e otimizações de desempenho são sempre bem-vindas.

## Autores
- [@Rodrigo_Kelven](https://github.com/Rodrigo-Kelven)
