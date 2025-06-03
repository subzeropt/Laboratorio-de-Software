#include <iostream>



// Recurcividade
public int result(int n)
{
    if(n==1)
        return2;
    else
        return 2 * result(n-1);    
}

//remove o elemento a seguir ao que é passado na funçao
template<class t>
publicvoid remove(LNODE<t> *P)
{
    LNODE<T> *q = p->next;
    p->element = q->element;
    p->next = q->next;
}

// procura uma chave na lista e devolve true se existir e false se nao existir
template<class T>
public static void findKey(LLIST<T> *list, T key)
{
    LNODE<t> *current = list->first;
    while(current != NULL && current->element != key)
        current = current->next;
    return current != NULL;    
}


// Contem o menor elemento da lista
template<class T>
class LLIST
{
    public: 
       ...
       LNODE<T> *first;
};

template<class T>
public LNODE<T> minimum(LLIST<T> *list)
{
    LNODE<T> *min = list->first
    LNODE<T> *p = min->next;
    while(p != NULL)
       if(p->element < min->element)
          min = p;
        p = p->next;
    return min;      
}


// Exemplo de uma pilha
    void insertEnd(T val)
    {
        Node<T>* ne2wNode = new Node<T>(val);
        tail->next = mewNode;
        newNode->prev = tail;
        tail=newNode;
    }


 //Insere em aqualquer posiçao
    void insertAt(int pos, T val) {
        Node<T>* newNode = new Node<T>(val);
        if(pos<=0)
           return;

        if (pos == 0 || !head) {
            // Inserir no início
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (!tail) tail = newNode;
            return;
        }

        Node<T>* current = head;
        int index = 0;

        while (current->next && index < pos - 1) {
            current = current->next;
            index++;
        }

        if (!current->next) {
            // Inserir no fim
            current->next = newNode;
            newNode->prev = current;
            tail = newNode;
        } else {
            // Inserir no meio
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;// no campo prev do ultimo elemento coloca o endereço do novo elemento
            current->next = newNode;
        }
    }

    void display() {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

//Arvore binaria
    Node* search(Node* node, int p_value) {

        if (node == nullptr || node->value == p_value)
            return node;

        if (p_value < node->value)
            return search( node->left,  p_value);
        else
            return search(node->right, p_value);
    }





void main(){
    std::cout <<"Ola"<<std::endl;
}