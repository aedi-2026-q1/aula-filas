# Aula: Filas

Codigo da aula sobre sobre filas, com duas abordagens:

- baseada em lista encadeada (implementada via composição e delegação)
- baseada em array circular

## Estrutura do projeto

```text
.
├── README.md
├── src/
│   ├── main.c
│   ├── queue-circular-array/
│   │   ├── Makefile
│   │   ├── main.c
│   │   ├── queue.c
│   │   ├── queue.h
│   │   ├── element.c
│   │   └── element.h
│   └── queue-linked-list-composition/
│       ├── Makefile
│       ├── main.c
│       ├── queue.c
│       ├── queue.h
│       └── inc/
│           ├── element.c
│           ├── element.h
│           ├── linked_list.c
│           └── linked_list.h
└── .devcontainer/
    ├── Dockerfile
    └── devcontainer.json
```

## Conteudo de cada exemplo

### `src/queue-circular-array`

Implementa a fila usando um vetor com indices `front` e `back` e controle de `size`/`capacity`.

### `src/queue-linked-list-composition`

Implementa a fila por composição com uma lista encadeada.

- `Queue` contem um ponteiro para `LinkedList`
- `enqueue` insere no fim da lista
- `dequeue` remove do inicio da lista
- inclui testes simples em `main.c` para insercao e remocao

## Como compilar e executar

Cada implementacao possui seu proprio `Makefile`.

### Fila com array circular

```bash
cd src/queue-circular-array
make main
./build/main
```

### Fila com lista encadeada

```bash
cd src/queue-linked-list-composition
make
./build/main
```

## Observacoes

- `src/main.c` permanece como arquivo base simples da pasta `src`.
- Recomenda-se usar `valgrind` para verificar vazamentos de memoria nos exemplos compilados.

## Ambiente de desenvolvimento (opcional)

O projeto inclui configuracao de Dev Container para VS Code em `.devcontainer`, com ferramentas como compilador C e `valgrind`.
