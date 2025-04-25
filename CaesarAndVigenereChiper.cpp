#include <bits/stdc++.h>
using namespace std;

//CÉSAR
unordered_map<char,char> buildCesarTable(int shift) {
    unordered_map<char,char> t;
    shift %= 26;
    for (char c = 'A'; c <= 'Z'; ++c)
        t[c] = char((c - 'A' + shift) % 26 + 'A');
    for (char c = 'a'; c <= 'z'; ++c)
        t[c] = char((c - 'a' + shift) % 26 + 'a');
    return t;
}

string applySubstitution(const string &msg,
                         const unordered_map<char,char> &table) {
    string out; out.reserve(msg.size());
    for (char ch : msg)
        if (isalpha((unsigned char)ch))
            out += table.at(ch);
        else
            out += ch;
    return out;
}

//VIGENÈRE
string extendKey(const string &key, const string &msg) {
    string ext; ext.reserve(msg.size());
    int ki = 0, klen = key.size();
    for (char ch : msg) {
        if (isalpha((unsigned char)ch))
            ext += key[ki++ % klen];
        else
            ext += ch;
    }
    return ext;
}

//CRIPTOGRAFAR VIGÈNERE
string cipherVigenere(const string &msg, const string &key) {
    string ext = extendKey(key, msg), out; out.reserve(msg.size());
    for (int i = 0; i < (int)msg.size(); ++i) {
        char ch = msg[i], k = ext[i];
        if (isupper(ch)) {
            int s = k - 'A';
            out += char((ch - 'A' + s) % 26 + 'A');
        }
        else if (islower(ch)) {
            int s = k - 'A';
            out += char((ch - 'a' + s) % 26 + 'a');
        }
        else out += ch;
    }
    return out;
}

//DECIFRAR VIGÈNERE
string decipherVigenere(const string &msg, const string &key) {
    string ext = extendKey(key, msg), out; out.reserve(msg.size());
    for (int i = 0; i < (int)msg.size(); ++i) {
        char ch = msg[i], k = ext[i];
        if (isupper(ch)) {
            int s = k - 'A';
            out += char((ch - 'A' - s + 26) % 26 + 'A');
        }
        else if (islower(ch)) {
            int s = k - 'A';
            out += char((ch - 'a' - s + 26) % 26 + 'a');
        }
        else out += ch;
    }
    return out;
}

//IMPRESSÃO DO ALFABETO DE CESAR
void printCesarAlphabets(const unordered_map<char,char> &t) {
    cout << "\nAlfabeto original: ";
    for (char c='A'; c<='Z'; ++c) cout<<c<<' ';
    cout << "\nAlfabeto cifrado:  ";
    for (char c='A'; c<='Z'; ++c) cout<<t.at(c)<<' ';
    cout<<"\n\n";
}

//IMPRESSÃO DO ALFABETO DE VIGENERE
void printVigenereTable() {
    cout << "\n   ";
    for (char c='A'; c<='Z'; ++c) cout<<c<<' ';
    cout<<"\n";
    for (char r='A'; r<='Z'; ++r) {
        cout<<r<<": ";
        for (char c='A'; c<='Z'; ++c) {
            cout<<char((r-'A'+c-'A')%26+'A')<<' ';
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int main(){
    while (true) {
        //MENU INICIAL
        int method;
        cout << "=== MENU INICIAL ===\n"
             << "1 - Cifra de Cesar\n"
             << "2 - Cifra de Vigenere\n"
             << "0 - Sair\n"
             << "Opcao: ";
        cin >> method;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (method == 0) {
            cout<<"Encerrando. Ate mais!\n";
            break;
        }
        if (method != 1 && method != 2) {
            cout<<"Opcao invalida.\n\n";
            continue;
        }

        //OPCIONAL: MOSTRAR TABELA
        int showTable;
        do {
            cout<<"Deseja ver a tabela (1-SIM / 0-NAO): ";
            cin>>showTable;
            if (!cin || (showTable!=0 && showTable!=1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Opcao invalida.\n";
                showTable = -1;
            }
        } while (showTable!=0 && showTable!=1);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //PARAMETROS PARA O METODO
        unordered_map<char,char> cesarTable, cesarReverse;
        string vKey;
        if (method == 1) {
            int shift;
            cout<<"Informe deslocamento (1-25): ";
            cin>>shift;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cesarTable = buildCesarTable(shift);
            for (auto &p:cesarTable) cesarReverse[p.second]=p.first;
            if (showTable) printCesarAlphabets(cesarTable);
        } else {
            cout<<"Informe palavra-chave: ";
            getline(cin, vKey);
            for (char &c:vKey) c = toupper(c);
            if (showTable) printVigenereTable();
        }

        //MENU SECUNDARIO
        while (true) {
            int opc;
            cout<<"--- Operacoes ---\n"
                <<"1 - Cifrar\n"
                <<"2 - Decifrar\n"
                <<"0 - Voltar ao menu inicial\n"
                <<"Opcao: ";
            cin>>opc;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (opc == 0) {
                cout<<"\nVoltando ao menu inicial...\n\n";
                break;
            }

            //VALIDA ENTRADA DA OPÇÃO
            if (opc != 1 && opc != 2) {
                cout<<"Opcao invalida.\n\n";
                continue;
            }

            //IF TERNÁRIO => SE A OPCAO FOR 1 É PARA CIFRAR/ SE FOR 2 É DECIFRAR
            //JA FOI VALIDADO A CIMA SE NÃO FOR 1 OU 2
            cout<<(opc==1 ? "Digite a mensagem a cifrar: "
                          : "Digite a mensagem a decifrar: ");
            string msg;
            getline(cin, msg);

            string result;
            if (method == 1) {
                //CÉSAR
                result = (opc==1
                    ? applySubstitution(msg, cesarTable)
                    : applySubstitution(msg, cesarReverse));
            } else {
                //VIGÈNERE
                result = (opc==1
                    ? cipherVigenere(msg, vKey)
                    : decipherVigenere(msg, vKey));
            }
            cout<<"Resultado: "<< result <<"\n\n";
        }
    }

    return 0;
}
