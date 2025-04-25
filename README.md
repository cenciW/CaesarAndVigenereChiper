## Leitor de Cifras: César e Vigenère

Este programa em C++ implementa as Cifras de César e Vigenère de forma interativa, permitindo ao usuário:

- Escolher o método de criptografia (César ou Vigenère).
- Visualizar as tabelas de substituição (alfabeto deslocado ou Vigenère tableau).
- Cifrar e decifrar mensagens.
- Navegar entre menus sem reiniciar o programa.

---

## Compilação

Para compilar, utilize um compilador compatível com C++11 ou superior. Exemplo com `g++`:

```bash
g++ -std=c++11 main.cpp -o cifra
```

---

## Executando

```bash
./cifra
```

---

## Menu Inicial

Ao iniciar, o programa apresenta o **Menu Inicial** com as opções:

1. **Cifra de César**
2. **Cifra de Vigenère**
0. **Sair**

- Digite o número correspondente e pressione Enter.
- Escolha `0` para encerrar o programa.

---

## Visualização de Tabela

Após escolher o método, o programa pergunta se deseja visualizar a tabela de substituição:

- **1** — Sim
- **0** — Não

### Para César

Exibe o alfabeto original e o alfabeto cifrado (com o deslocamento informado).

### Para Vigenère

Exibe o Vigenère tableau completo (matriz de Cifras de César para todas as chaves de A a Z).

---

## Parâmetros do Método

- **Cifra de César**: Informe o deslocamento (1–25).
- **Cifra de Vigenère**: Informe a palavra-chave (somente letras). A chave será repetida/truncada para o tamanho da mensagem.

---

## Menu de Operações

Após configuração, entra no **Menu de Operações**, com opções:

1. **Cifrar mensagem**
2. **Decifrar mensagem**
0. **Voltar ao Menu Inicial**

- Escolha `1` para cifrar a mensagem digitada.
- Escolha `2` para decifrar a mensagem digitada.
- Escolha `0` para retornar ao Menu Inicial (para mudar método ou sair).

---

## Exemplos de Uso

1. Inicie o programa.
2. Selecione `1` para Cifra de César.
3. Selecione `1` para visualizar o alfabeto cifrado.
4. Informe deslocamento: `3`.
5. No menu de operações, digite `1` e insira a mensagem: `HELLO`.
6. O programa exibirá `KHOOR`.
7. Digite `0` para voltar ao Menu Inicial.
8. Escolha `2` para Cifra de Vigenère e prossiga.

---

## Observações

- O programa preserva letras maiúsculas e minúsculas.
- Caracteres não alfabéticos (espaços, pontuação, números) não são alterados.

---

Desenvolvido para fins educativos e demonstrativos de técnicas básicas de criptografia.

