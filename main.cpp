#include <iostream>

using namespace std;


struct treenodeavl
{
    int info;
    int altura;//nao é a altura deste no,mas da arvore enraizada
    treenodeavl *esq;
    treenodeavl *dir;
};
typedef treenodeavl *treenodeavlptr;

int maior(int l, int r)
{
    if(l > r)
        return l;
    else
        return r;
    // return 1>r ? l:r; // para retornar o maior valor
}

int tAltura(treenodeavlptr p)
{
    if(p == NULL)
        return -1;
    else
        return p->altura;
}

treenodeavlptr insereAVL(treenodeavlptr &t,int x)
{
    if(t == NULL)
    {
        t = new treenodeavl;
        t->info = x;
        t->altura = 0;
        t->esq = NULL;
        t->dir = NULL;

    }
    else if (x < t->info)
        t->esq = insereAVL(t->esq,x);
    else if (x>= t->info)
        t->dir = insereAVL(t->dir,x);
    t->altura = maior(tAltura(t->esq),tAltura(t->dir))+1;
    return t;
}

void emOrdem (treenodeavlptr arvore)
{
    if (arvore != NULL)
    {
        emOrdem(arvore->esq);
        cout <<"info = "<<arvore->info<<endl;
        cout <<"altura = "<<arvore->altura<<endl;
        emOrdem(arvore->dir);
    }
}

void tDestruir (treenodeavlptr &arvore)
{
    if (arvore != NULL)
    {
        tDestruir(arvore->esq);
        tDestruir(arvore->dir);
        delete arvore;
    }
    arvore = NULL;
}

void rot_dir(treenodeavlptr &p)
{
    treenodeavlptr q, temp;

    q = p->esq;
    temp = q->dir;
    q->dir = p;
    p->esq = temp;
    p = q;
}

void rot_esq(treenodeavlptr &p)
{
    treenodeavlptr q, temp;

    q = p->dir;
    temp = q->esq;
    q->esq = p;
    p->dir = temp;
    p = q;
}

int main()
{
    treenodeavlptr arvore = NULL;

    int x;

    cin >> x;

    while(x!=-1)
    {
        arvore = insereAVL(arvore,x);
        cin >> x;
    }

    emOrdem(arvore);

    tDestruir(arvore);


    cout << "SOMOS FODAS" << endl;
    return 0;
}
