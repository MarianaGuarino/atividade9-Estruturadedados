typedef struct No {
    float valor;
    struct No *proximo_no;
} No;

No *criar_no(float valor, No *proximo_no);
void inserir_no_finalLista(No *lista, No *no);
void inserir_no_inicioLista(No *lista, No *no);
void inserir_no_entre_dois_nos(No *no_anterior, No *no);
void lista_inserir_no_ordenado(No *lista, No* no);
void imprimir_lista(No *lista);