#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define INT_MAX 2147483647

int cmp(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}

typedef struct Huffman{
    char value;//值
    int weight;//权值
    int active;//激活状态
    char *code; //哈夫曼编码
    struct Huffman *parent,*left,*right,*next;
}HFM;

HFM *head = NULL;
int cnt = 1,cnt2 = 0,Size = 0;//新三年，旧三年，缝缝补补又三年

int inithfm();//初始化哈夫曼树
int create(int i);//生成链表
int create_start(int size);//开始生成哈夫曼树
int create_hfm();//生成哈夫曼树
int connect(HFM *pick1, HFM *pick2);//连接两个节点
int encode();
int dfs(HFM *now, char *code, int dep, int turn);
int print_code(int size);
int input_content();//输入正文
int encode_content(char *content);//编码正文并打印
int decode(char *content);//解码正文并打印
int print_tree(HFM *hfm_head);//打印树
int bfs(HFM *now,HFM **arr,int top,int bot);//层序遍历
int log_2();//判断是否为2的整数次方

int main()
{
    char n;
    do{
    int size = 0;
    size = inithfm();
    Size = size;
    int flag = create_start(size);
    if(flag) encode();
    print_code(size);
    input_content();
    printf("\n按n退出，任意键继续");
    n = getch();
    fflush(stdin);
    system("cls");
    }while(n != 'n' && n != 'N');
    return 0;
}


int inithfm()
{
    head = NULL;
    cnt = 1,cnt2 = 0,Size = 0;
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
    while(weight <= 0 || weight >= 100)
    {
        printf("请输入第%d个字符的权值(大于0小于100):",i);
        scanf("%d",&weight);
        fflush(stdin);
    }
    if(head == NULL)
    {
        head = (HFM*)malloc(sizeof(HFM));
        head->active = 0;
        head->left = NULL;
        head->right = NULL;
        head->parent = NULL;
        head->value = value;
        head->weight = weight;
        head->next = NULL;
    }
    else
    {
        HFM *now = head,*temp = NULL;
        while(now->next != NULL) now = now->next;
        temp = now;
        now = now->next;
        now = (HFM*)malloc(sizeof(HFM));
        now->active = 0;
        now->left = NULL;
        now->right = NULL;
        now->parent = NULL;
        now->value = value;
        now->weight = weight;
        now->next = NULL;
        temp->next = now;
    }
    return i;
}

int create_start(int size)
{
    int i = 0;
    size--;
    if(size == 0)
    {
        head->code = (char*)malloc(2*sizeof(char));
        head->code[0] = '0';
        head->code[1] = 0;
    }
    for(i = 0; i < size; i++)
    {
        create_hfm();
        printf("正在执行第%d次操作\n",i+1);
    }
    return size;
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
        }
        now = now->next;
    }
    pick1->active = 1;
    now = head;
    while(now != NULL)
    {
        if(now->weight >= min1 && now->active == 0 && now->weight < min2)
        {
            min2 = now->weight;
            pick2 = now;
        }
        now = now->next;
    }
    pick2->active = 1;
    connect(pick1,pick2);
    return 1;
}

int connect(HFM *pick1, HFM *pick2)
{
    HFM *link = NULL,*now = head;
    link = (HFM*)malloc(sizeof(HFM));
    pick1->parent = link;
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
    char code[500];
    HFM *hfm_head = NULL;
    hfm_head = head;
    while(hfm_head->next != NULL) hfm_head = hfm_head->next;
    dfs(hfm_head, code, 0, 0);
    print_tree(hfm_head);
    return 0;
}

int dfs(HFM *now, char *code, int dep,int turn)
{
    if(now->left == NULL)
    {
        code[dep] = turn + '0';
        code[dep+1] = 0;
        now->code = (char*)malloc(sizeof(int) * (dep+1));
        int i, j = 0;
        for(i = 1; i <= dep+1; i++)
        {
            now->code[j++] = code[i];
        }
        return 0;
    }
    code[dep] = turn + '0';
    dfs(now->left, code, dep+1, 0);
    dfs(now->right, code, dep+1, 1);
    return 1;
}

int print_code(int size)
{
    HFM *now = head;
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%c:  ",now->value);
        printf("%s",now->code);
        printf("\n");
        now = now->next;
    }
    return 0;
}

int input_content()
{
    char content[101];
    printf("请输入正文内容：\n");
    scanf("%s",content);
    printf("\n============================================================\n");
    encode_content(content);
    return 1;
}

int encode_content(char *content)
{
    int i, j=0, k = 0, len;
    char codes[1000];
    HFM *now = head;
    len = strlen(content);
    for(i = 0; i < len; i++)
    {
        now = head;
        while(now->value != 0)
        {
            if(now->value == content[i])
            {
                j = 0;
                while(now->code[j] != 0)
                {
                    codes[k] = now->code[j];
                    k++;
                    j++;
                }
                codes[k] = 0;
                break;
            }
            now = now->next;
        }
    }
    printf("%s\n",codes);
    printf("\n============================================================\n");
    decode(codes);
    return i;
}

int decode(char *content)
{
    char temp[50];//de[101];
    int i,j = 0,len;//k = 0;
    HFM *now = head;
    len = strlen(content);
    for(i = 0; i < len; i++)
    {
        temp[j] = content[i];
        temp[j+1] = 0;
        now = head;
        while(now->value != 0)
        {
            if(strcmp(temp,now->code) == 0)
            {
                temp[0] = 0;
                j = -1;
                //de[k++] = now->value;
                printf("%c",now->value);
                break;
            }
            now = now->next;
        }
        j++;
    }
    printf("\n");
    return 0;
}

int print_tree(HFM *hfm_head)
{
    HFM *arr[100];
    int top = 0, bot = 1;
    arr[0] = hfm_head;
    bfs(hfm_head, arr, top, bot);
    printf("\n");
    return 0;
}

int bfs(HFM *now, HFM **arr,int top,int bot)
{
    if(cnt2 >= Size)
        return 0;
    if(arr[top] == NULL)
    {
        printf("%3C",'/');
    }
    else
    {
        printf("%3d",arr[top]->weight);
        if(arr[top]->value > 0)
            cnt2++;
    }
    cnt++;
    if(log_2()==1)
        printf("\n");
    if(now!=NULL)
    {
        arr[bot] = now->left;
        arr[bot+1] = now->right;
    }
    else{
        arr[bot] = NULL;
        arr[bot+1] = NULL;
    }
    bfs(arr[top+1], arr, top+1, bot+2);
    return 0;
}

int log_2()
{
    if ((cnt&(cnt-1)))
		return -1;
	return 1;
}
