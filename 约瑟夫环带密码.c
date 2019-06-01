#include <stdio.h>
#include <stdlib.h>

typedef struct Joseph{
    int id;
    int password;
    int die;
    struct Joseph *next;
}jos;
jos *head = NULL;

int init(jos *j);
int newall();
int newone(int i);
int printdie(int all, int start);
jos* die(jos *now);


int main()
{
    printdie(newall(),init(head));
    return 0;
}


int init(jos *j)
{
    int m = -1;
    while(m == -1)
    {
        printf("输入初始值:");
        scanf("%d",&m);
        fflush(stdin);
    }
    return m;
}


int newall()
{
    int i = 1;
    printf("输入每个人的密码，以-1表示结束\n");
    printf("输入第%d个人的密码:",i);
    while(newone(i)!=-1)
    {
        printf("输入第%d个人的密码:",++i);
    }
    printf("\n输入结束\n");
    return i-1;
}

int newone(int i)
{
    int password = -2;
    jos *now = head,*nnext;
    if(head == NULL)
    {
        head = (jos*)malloc(sizeof(jos));
        while(password <= -2 || password == 0)
        {
            scanf("%d",&password);
            fflush(stdin);
            if(password <= -2 || password == 0)
                printf("请输入一个正整数:");
        }
        head->next = NULL;
        head->die = 0;
        head->password = password;
        head->id = i;
        if(password == -1)
            head->next = head;
        return password;
    }
    while(now->next!=NULL) now = now->next;
    nnext = (jos*)malloc(sizeof(jos));
    while(password <= -2 || password == 0)
    {
        scanf("%d",&password);
        fflush(stdin);
        if(password <= -2 || password == 0)
            printf("请输入一个正整数:");
        if(password == -1)
            now->next = head;
    }
    nnext->next = NULL;
    nnext->die = 0;
    nnext->password = password;
    nnext->id = i;
    now->next = nnext;
    if(password == -1)
        now->next = head;
    return password;
}

int printdie(int all,int start)
{
    int i = 0;
    jos* now = NULL;
    now = head;
    start--;
    if(all == 0)
        return 0;
    while(start--)
    {
        now = now->next;
    }
    now->die = 1;
    printf("%d",now->id);
    if(all > 1)
        printf("-->");
    for(i = 1; i < all; i++)
    {
        now = die(now);
        printf("%d",now->id);
        if(i != all-1)
            printf("-->");
    }
    return (all-i);
}


jos* die(jos *now)
{
    int m = now->password;
    while(m--)
    {
        now = now->next;
        if(now->die == 1)
            m++;
    }
    now->die = 1;
    return now;
}
