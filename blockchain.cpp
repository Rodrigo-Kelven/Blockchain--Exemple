#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <openssl/sha.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

// Função para gerar o hash SHA-256
string sha256(const string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256_ctx;
    SHA256_Init(&sha256_ctx);
    SHA256_Update(&sha256_ctx, str.c_str(), str.length());
    SHA256_Final(hash, &sha256_ctx);
    
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

// Estrutura do Bloco
struct Block {
    int index;
    string timestamp;
    string data;
    string previous_hash;
    string hash;

    Block(int idx, const string& data, const string& previous_hash)
        : index(idx), data(data), previous_hash(previous_hash) {
        timestamp = currentDateTime();
        hash = calculateHash();
    }

    string calculateHash() const {
        stringstream ss;
        ss << index << timestamp << data << previous_hash;
        return sha256(ss.str());
    }

    static string currentDateTime() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        stringstream ss;
        ss << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday
           << " " << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec;
        return ss.str();
    }
};

// Classe Blockchain
class Blockchain {
public:
    vector<Block> chain;

    Blockchain() {
        // Adiciona o bloco gênese
        chain.push_back(Block(0, "Genesis Block", "0"));
    }

    void addBlock(const string& data) {
        Block lastBlock = chain.back();
        chain.push_back(Block(lastBlock.index + 1, data, lastBlock.hash));
    }

    void display() const {
        for (const Block& block : chain) {
            cout << "Index: " << block.index << endl;
            cout << "Timestamp: " << block.timestamp << endl;
            cout << "Data: " << block.data << endl;
            cout << "Previous Hash: " << block.previous_hash << endl;
            cout << "Hash: " << block.hash << endl;
            cout << "-----------------------------------" << endl;
        }
    }
};

int main() {
    // Criação da Blockchain
    Blockchain blockchain;

    string data;
    int blockCount = 1;

    // Loop infinito para adicionar blocos
    while (true) {
        cout << "Adicionando Bloco #" << blockCount << endl;
        cout << "Digite os dados para o bloco (ou digite 'sair' para parar): ";
        getline(cin, data);

        if (data == "sair") {
            cout << "Parando a blockchain." << endl;
            break;
        }

        blockchain.addBlock(data);
        blockCount++;

        // Exibindo a blockchain até o momento
        blockchain.display();

        // Pausa de 3 segundos antes de adicionar o próximo bloco
        cout << "Pausando por 3 segundos..." << endl;
        this_thread::sleep_for(seconds(3));
    }

    return 0;
}
