#include <stdio.h>
#include <stdlib.h>
struct no
{
 int info;
 struct no *next;
};
typedef struct no* noptr;
void push(noptr *lista, int x)
{
  noptr p;
  p = (noptr)malloc(sizeof(struct no));
  p->info = x;
  if(lista == NULL)
  {
    p->next = NULL;
  }
  else
    p->next = *lista;
  *lista = p;
}
int main()
{
  noptr lista = NULL;
  noptr p;
  int x;

  puts("Entre com os elementos da lista: -1 para sair \n");
  scanf("%d", &x);
  if(x == -1)
  {
    return -1;
  }
  else
  {
    push(&lista,x);
  }
  while(x != -1)
  {
    puts("Entre com os elementos da lista: -1 para sair \n");
    scanf("%d",&x);
    push(&lista,x);
  }
  for(p = lista; p != NULL; p=p->next)
  {
    printf("A lista e: \n");
    printf("%d\n", p->info);
  }
  return 0;
}
