# Usando a imagem oficial do GCC
FROM gcc:latest

# Atualizar o repositório e instalar dependências necessárias
RUN apt-get update && apt-get install -y \
    libssl-dev \
    && rm -rf /var/lib/apt/lists/*

# Defina o diretório de trabalho dentro do container
WORKDIR /app

# Copiar o código C++ para dentro do container
COPY . .

# Comando para compilar o código C++
RUN g++ -o blockchain blockchain.cpp -lssl -lcrypto

# Comando para rodar o programa
CMD ./blockchain
