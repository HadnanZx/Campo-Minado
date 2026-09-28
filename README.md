# Campo-Minado

Jogo de tabuleiro desenvolvido em C como projeto acadêmico. O jogador define o tamanho do tabuleiro e a quantidade de minas, posiciona-as manualmente e tenta revelar todas as casas sem cair em uma mina.

## Como Jogar

1. Defina o tamanho do tabuleiro (entre 5 e 100)
2. Escolha a quantidade de minas (menor que o total de casas)
3. Posicione as minas informando linha e coluna
4. Revele casas tentando evitar as minas
5. Vença ao revelar todas as casas sem minas

## Tecnologias

- C
- stdio.h
- locale.h

## Compilação e Execução

### Usando GCC:

```bash
gcc "Campo Minado de Hadnan.c" -o campo-minado
./campo-minado
```

### Usando VSCode:

1. Abra a pasta no VSCode
2. Instale a extensão C/C++ da Microsoft
3. Compile com Ctrl+Shift+B ou use o terminal integrado

## Estrutura do Projeto

```
Campo-Minado/
├── Campo Minado de Hadnan.c    # Código fonte principal
├── Campo Minado de Hadnan.exe  # Executável compilado (Windows)
├── Campo Minado de Hadnan.o    # Objeto compilado
└── .gitattributes              # Configuração do Git
```

## Regras do Jogo

- O tabuleiro é uma matriz quadrada de tamanho N×N (5 ≤ N ≤ 100)
- As minas são posicionadas manualmente pelo jogador
- Cada casa mostra o número de minas nas casas vizinhas
- Revelar uma mina encerra o jogo
- Revelar todas as casas sem minas resulta em vitória

## Autor

Hadnan Menezes — Estudante de ADS no IFBA
