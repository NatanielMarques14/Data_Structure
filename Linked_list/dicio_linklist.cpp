#include <iostream> 
using namespace std;

class Dicio
{
    private:
        struct Noh
        {
            
            int valor;
            int chave;
            Noh *prox;
        };
    
    public:
        Noh *inicio;
    
        Dicio()
        {
            inicio = nullptr;
        }

        bool consultar (int c)
        {
            if(inicio !=nullptr)
            {
                Noh *novo = inicio; // = new Noh; novo = inicio; it's wrong, you are not creating nothing here.
                while (novo != nullptr)
                {
                    if(novo->chave == c)
                    {
                        return true;
                    }
                    else
                    {
                        novo = novo->prox;
                    }
                }
            }
            return false;
        }

        bool inserir(int c, int v)
        {
            if(consultar(c))
            {
                return false;
            }

            Noh *novo = new Noh;
            novo->chave = c;
            novo->valor = v;
            novo->prox = inicio; //the prox field is now pointing to what inicio pointed first.
            inicio = novo; // inicio now points to the adress of novo, inicio it's a pointer to the first node, not a node.
            return true;
            
        }

        void remover (int c)
        {
            Noh *aux;
            aux = inicio;

            if(aux == nullptr)
            {
                return;
            }

            if(aux->chave == c)//if i have found the key in the first node.
            {
                inicio = inicio->prox;
                delete aux;
                return;
            }

            while(aux != nullptr)
            {
                if(aux->prox->chave == c)
                {
                    Noh *delet;
                    delet = aux->prox;
                    aux->prox = aux->prox->prox;
                    delete delet;
                    return;
                }
                aux = aux->prox;
            }

        }


};

int main()
{
    Dicio dic;

    dic.inserir(1, 100);
    dic.inserir(2, 200);
    dic.inserir(3, 300);

    cout << "Consulta chave 2: " << (dic.consultar(2) ? "Encontrado" : "Não encontrado") << endl;

    dic.remover(2);
    cout << "Consulta chave 2 após remover: " << (dic.consultar(2) ? "Encontrado" : "Não encontrado") << endl;

    return 0;
}