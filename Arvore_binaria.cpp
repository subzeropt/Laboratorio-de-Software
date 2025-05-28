// Arvore binaria, o valor mais pequeno esta sempre no lado esquerdo
Node* search(Node* node, int p_value) {

    if (node == nullptr || node->value == p_value)
        return node;

    if (p_value < node->value  )
        return search( node->left,  p_value);
    else
        return search(node->right, p_value);
}






// Arvores binarias representadas por meio de um vetor com a particularidade de ser um HeapMinimo

// Construtor: inicializa um heap vazio com capacidade nv (por padrão, 15 elementos)
Iminh::Iminh(int nmax) {
    nv = nmax;
    v = new int[nv]; // alocação dinâmica do vetor que armazenará o heap
    n = 0;           // heap começa vazio
}







// Função auxiliar: sobe um elemento no vetor para manter a propriedade de min heap
void Iminh::subir(int i) {
    // Enquanto não for a raiz (índice 0)
    while (i > 0) {
        int pai = (i - 1) / 2; // índice do pai
        if (v[i] < v[pai]) {
            // Se o filho é menor que o pai, troca-os
            swap(v[i], v[pai]);
            i = pai; // sobe para continuar verificando
        } else {
            // Caso contrário, está na posição correta
            break;
        }
    }
}



// Função auxiliar: desce um elemento para reorganizar o heap após remoção
void Iminh::descer(int i) {
    while (2 * i + 1 < n) { // enquanto tiver pelo menos um filho
        int esq = 2 * i + 1, dir = 2 * i + 2; // descobre o filho a esquerda e a direita(i é o pai)
        int menor = esq; // assume que o filho da esquerda é o menor
        if (dir < n && v[dir] < v[esq]) { // verifica se o filho da direita é menor
            menor = dir;
        }
        if (v[menor] < v[i]) {
            swap(v[i], v[menor]); // desce o valor trocando com o menor filho
            i = menor;
        } else {
            break;
        }
    }
}


// Bloco para ler o input do usuario e chamar a funçao inserir

stringstream iss(linha);// le a linha inteira do input do usuario, "insert 7396"
string cmd; // recebe os dados passados pelo iss >> cmd
iss >> cmd // passa a informaçao contida na primeira posiçao da string, neste caso é o insert

if(cmd == "insert"){
    int val;   
    while(iss >> val) // vai ler cada um dos dados da linha e armazenando na variavel val
    {
        if(!heap.inserir(val))// vai tentar inserir o valor val no heap
        {
            printf("Comando insert: Heap cheio!\n");
            break;
        }
    }
}



// Bloco para inserir um item na heap

bool Iminh::inserir(int item) {
    if (cheio()) {
        // Não permite inserir se o heap estiver cheio
        return false;
    } else {
        v[n] = item;  // insere no fim do heap
        subir(n);     // corrige posição com base no valor
        n++;          // incrementa o tamanho do heap
        return true;
    }
}












