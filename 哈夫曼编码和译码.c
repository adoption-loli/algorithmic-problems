#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647

int cmp(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}

typedef struct Huffman{
    char value;//值
    int weight;//权值
    int active;//激活状态
    int *code; //哈夫曼编码
    struct Huffman *parent,*left,*right,*next;
}HFM;

HFM *head = NULL;


int inithfm();//初始化哈夫曼树
int create(int i);//生成链表
int create_start(int size);//开始生成哈夫曼树
int create_hfm();//生成哈夫曼树
int connect(HFM *pick1, HFM *pick2);//连接两个节点
int encode();
int dfs(HFM *now, int *code, int dep, int turn);
int print_code(int size);

int main()
{
    int size = 0;
    size = inithfm();
    create_start(size);
    encode();
    print_code(size);
    return 0;
}


int inithfm()
{
    int size = -1;
    int i = 0;
    while(size == -1)
    {
        printf("字符集大小(大于0的整数）:");
        scanf("%d",&size);
        fflush(stdin);
    }
    for(i = 1; i <= size; i++)
    {
        create(i);
    }
    return size;
}

int create(int i)
{
    char value;//值
    int weight = -1;//权值
    printf("请输入第%d个字符:",i);
    scanf("%c",&value);
    fflush(stdin);
    printf("当前输入的字符为“%c”",value);
    while(weight<0 || weight>100)
    {
        printf("请输入第%d个字符的权值(大于0小于100):",i);
        scanf("%d",&weight);
        fflush(stdin);
    }
    HFM *now = head;
    while(now != NULL) now = now->next;
    now = (HFM*)malloc(sizeof(HFM));
    now->active = 0;
    now->left = NULL;
    now->right = NULL;
    now->parent = NULL;
    now->value = value;
    now->weight = weight;
    now->next = NULL;
    return i;
}

int create_start(int size)
{
    int i = 0;
    size--;
    for(i = 0; i < size; i++)
    {
        create_hfm();
        printf("正在执行第%d次操作\n",i);
    }
    return i;
}

int create_hfm()
{
    int min1 = INT_MAX,min2 = INT_MAX;
    HFM *now = head, *pick1 = NULL, *pick2 = NULL;
    while(now != NULL)
    {
        if(now->weight < min1 && now->active == 0)
        {
            min1 = now->weight;
            pick1 = now;
            break;
        }
        now = now->next;
    }
    now = head;
    while(now != NULL)
    {
        if(now->weight > min1 && now->active == 0 && now->weight < min2)
        {
            min2 = now->weight;
            pick2 = now;
            break;
        }
        now = now->next;
    }
    connect(pick1,pick2);
    return 1;
}

int connect(HFM *pick1, HFM *pick2)
{
    HFM *link = NULL,*now = head;
    link = (HFM*)malloc(sizeof(HFM));
    pick1->parent = link;
    pick1->active = 1;
    pick2->active = 1;
    pick2->parent = link;
    link->left = pick1;
    link->right = pick2;
    link->weight = pick1->weight + pick2->weight;
    link->active = 0;
    link->value = 0;
    link->parent = NULL;
    link->next = NULL;
    while(now->next!=NULL) now = now->next;
    now->next = link;
    return 1;
}

int encode()
{
    int code[500] = {0};
    dfs(head, code, 0, 0);
    return 0;
}

int dfs(HFM *now, int *code, int dep,int turn)
{
    if(now->left == NULL)
    {
        code[dep] = turn;
        code[dep+1] = -1;
        now->code = (int*)malloc(sizeof(int) * (dep+1));
        int i, j = 0;
        for(i = 1; i <= dep; i++)
        {
            now->code[j++] = code[i];
        }
        return 0;
    }
    code[dep] = turn;
    dfs(now->left, code, dep+1, 0);
    dfs(now->right, code, dep+1, 1);
    return 1;
}

int print_code(int size)
{
    HFM *now = head;
    int i,j;
    for(i = 0; i < size; i++)
    {
        printf("%c:  ",now->value);
        for(j = 0; now->code[j] != -1; j++)
            printf("%d",now->code[j]);
        printf("\n");
    }
    return 0;
}
