#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TYPE int

typedef struct list
{
    TYPE data;
    struct list *prox;
} list;

typedef struct tree
{
    TYPE data;
    struct tree *right;
    struct tree *left;
} tree;

void printlista(list *p);

tree *create_tree(TYPE x)
{
    tree *tree_node = malloc(sizeof(tree));
    tree_node->left = tree_node->right = NULL;
    tree_node->data = x;

    return tree_node;
}

tree *insert_sorted(tree *t, tree *node)
{
    if (t == NULL)
        return node;

    if (node->data < t->data)
        t->left = insert_sorted(t->left, node);

    if (node->data > t->data)
        t->right = insert_sorted(t->right, node);

    return t;
}

list *insert_list(list *p, TYPE x)
{

    //criar um ponteiro do tipo lista para ñ perder infos//
    list *copia; // = malloc(sizeof(list));
    list *novo = malloc(sizeof(list));

    copia = p;
    novo->data = x;
    novo->prox = NULL;

    if (p == NULL)
        return novo;

    while (copia->prox != NULL)
        copia = copia->prox;

    copia->prox = novo;

    return p;
}

list *pre_order(tree *t, list *p)
{

    /* vale para todas as funções, não faz sentido fazer:
     copia = malloc...
     e em seguida
     copia = NULL
     vc apenas descartou a alocação!
     */
    if (t == NULL)
        return p;

    /* preciso receber p pois no caso
     da lista vazia receberei um ponteiro para a nova lista
  */
    p = insert_list(p, t->data);
    p = pre_order(t->left, p);
    p = pre_order(t->right, p);

    return p;
}

void print_preorder(tree *t)
{

    if (t == NULL)
        return;

    printf("%d ", t->data);  // printa raiz
    print_preorder(t->left); // vai rodar até o max de left, qnd não tiver mais, vai pro right
    print_preorder(t->right);
}

list *in_order(tree *t, list *p)
{

    if (t == NULL)
        return p;

    p = in_order(t->left, p);
    p = insert_list(p, t->data);
    p = in_order(t->right, p);

    return p;
}

void print_inorder(tree *t)
{

    if (t == NULL)
        return;

    print_inorder(t->left);  // vai até o max de left
    printf("%d ", t->data);  // printa
    print_inorder(t->right); //
}

list *pos_order(tree *t, list *p)
{

    if (t == NULL)
        return p;

    p = pos_order(t->left, p);
    p = pos_order(t->right, p);
    p = insert_list(p, t->data);

    return p;
}

void print_posorder(tree *t)
{

    if (t == NULL)
        return;

    print_posorder(t->left);
    print_posorder(t->right);
    printf("%d ", t->data);
}

void printlista(list *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->prox;
    }
}

tree *search_insert(tree *t, int k)
{
    tree *p = t;
    tree *pai = t;

    while (1)
    {
        if (p == NULL)
            return insert_sorted(pai, create_tree(k));

        if (p->data == k)
        {
            p->data = -1;
            return p;
        }

        if (k < p->data)
        {
            pai = p;
            p = p->left;
        }

        else
        {
            pai = p;
            p = p->right;
        }
    }
    return NULL;
}

int num_nos(tree *t)
{

    if (t == NULL)
        return 0;

    return (num_nos(t->left) + num_nos(t->right) + 1);
}

int soma_nos(tree *t)
{

    if (t == NULL)
        return 0;

    return (t->data + soma_nos(t->left) + soma_nos(t->right));
}

void print_niveis(tree *t, int nivel)
{
    int a = nivel;

    if (t == NULL)
        return;

    if (nivel == 0)
    {
        printf("Nível 0: %d\n", t->data);
        nivel++;
    }

    if (t->right != NULL || t->left != NULL)
    {
        printf("Nível %d: ", nivel);
        nivel++;
    }

    if (t->left != NULL)
    {
        printf("%d ", t->left->data);
    }

    if (t->right != NULL)
    {
        printf("%d ", t->right->data);
    }

    if ((t->right != NULL) || (t->left != NULL))
    {
        printf("\n");
    }

    print_niveis(t->left, nivel);
    print_niveis(t->right, nivel);
}

int galho_esq(tree *t)
{

    if (t == NULL)
        return 0;

    if (t->left == NULL)
        return 1;

    return (galho_esq(t->left) + galho_esq(t->right) + 1);
}

int galho_dir(tree *t)
{
    if (t == NULL)
        return 0;

    return (galho_dir(t->right) + galho_dir(t->left) + 1);
}

int main(void)
{
    tree *t_sorted = NULL; //malloc(sizeof(tree));
    /* isso tudo vai ser feito pela função insert */
    list *p_sorted = NULL; // = malloc(sizeof(list));
    list *q_sorted = NULL; // = malloc(sizeof(list));
    list *r_sorted = NULL; // = malloc(sizeof(list));
    int i;
    int v[6] = {5, 3, 2, 4, 7, 9};

    /* o laço vai inserir tudo */
    //t_sorted = create_tree(5);
    //p_sorted = insert_list(p_sorted, 5);
    //q_sorted = insert_list(q_sorted, 5);
    //r_sorted = insert_list(r_sorted, 5);

    for (i = 0; i < 6; i++)
    {
        /* aqui vc está inserindo na lista na ordem do vetor */
        //p_sorted = pre_order(create_tree(v[i]), p_sorted);
        //q_sorted = pre_order(create_tree(v[i]), q_sorted);
        //r_sorted = pre_order(create_tree(v[i]), r_sorted);
        t_sorted = insert_sorted(t_sorted, create_tree(v[i]));
    }

    /* só faz sentido fazer o percurso quando a árvore 
     tem conteúdo, ou seja, depois do seu for
     Além disso o parametro é a árvore e não um nó!
  */
    p_sorted = pre_order(t_sorted, p_sorted);
    q_sorted = in_order(t_sorted, q_sorted);
    r_sorted = pos_order(t_sorted, r_sorted);

    printf("Pré-ordem: ");
    print_preorder(t_sorted);
    printf("\n\nEm-ordem: ");
    print_inorder(t_sorted);
    printf("\n\nPós-ordem: ");
    print_posorder(t_sorted);
    printf("\n\n");

    printlista(p_sorted);
    printf("\n\n");
    printlista(q_sorted);
    printf("\n\n");
    printlista(r_sorted);
    printf("\n\n");

    /*search_insert(t_sorted, 4);
  printf("Busca com inserção: ");
  print_preorder(t_sorted);
  printf("\n\n");*/

    int nodes, cont = 0;
    nodes = num_nos(t_sorted);
    printf("Nós: %d\n", nodes);

    int somanodes = 0;
    somanodes = soma_nos(t_sorted);
    printf("Soma dos Nós: %d\n", somanodes);
    printf("\n");

    print_niveis(t_sorted, 0);
    printf("\n");

    int galhoe = 0, galhor = 0;
    printf("Soma de nós do Galho Esquerdo: %d \n", galho_esq(t_sorted->left));
    printf("Soma de nós do Galho Direito: %d \n", galho_dir(t_sorted->right));
}

/* 

Grau: número de filhos
Altura de um nó: maior tamanho entre o nó e alguma das folhas.
Altura da raiz: maior tamanho entre raiz e algum nó.
Profundidade do nó: número de arestas do nó até a raiz
Nível do nó = 1+nível do seu pai.
Árvore cheia: todos os nós, exceto folhas, possuem 2 filhos.
Completa: todos os níveis, exceto o último, são completamente preenchidos.

• Pré-ordem: raíz - esquerda - direita.
• Em-ordem: esquerda - raíz - direita.
• Pós-ordem: esquerda - direita - raiz

*/