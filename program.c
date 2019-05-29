#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define CHANGE 960979113899
#define INSERT 961221679226
#define DELETE 961015077464
#define QUERY 29137653787
#define PRINT 29136364274
#define LODE 882772937
#define SAVE 883009844
#define EXIT 882531359
#define HELP 882618574
#define EMPTY 741
typedef struct _List List;
struct _List {
    int id;
    int status;
    char word[48];
    List* next;
};

List* head;
int id_count;

void help()
{
    printf("insert word\n"
           "delete id\n"
           "change id word\n"
           "query word\n"
           "print\n");
}

unsigned long hash(const char* str)
{
    unsigned long hash = 741;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}
void insert(const char* s)
{
    List* p;
    if (!head) {
        head = malloc(sizeof(List));
        p = head;
    } else {
        for (p = head; p->next; p = p->next)
            ;
        p->next = malloc(sizeof(List));
        p = p->next;
    }
    p->next = NULL;
    p->id = id_count++;
    p->status = 0;
    strcpy(p->word, s);
}

int delete (int id)
{
    List *p, *n;
    if (!head)
        return -1;
    for (p = n = head; n && n->id != id; p = n, n = n->next)
        ;
    if (!n)
        return -1;
    if (n == head)
        head = n->next;
    else
        p->next = n->next;
    free(n);
    return 0;
}

int query(const char* s)
{
    List* p;
    for (p = head; p; p = p->next)
        if (!strcmp(s, p->word)) {
            p->status++;
            printf("id=%d status=%d word=%s\n",
                p->id, p->status, p->word);
            return 0;
        }
    return -1;
}

int change(int id, const char* s)
{
    List* p;
    for (p = head; p; p = p->next)
        if (p->id == id) {
            strcpy(p->word, s);
            return 0;
        }
    return -1;
}

void print()
{
    for (List* p = head; p; p = p->next)
        printf("id=%d status=%d word=%s\n",
            p->id, p->status, p->word);
}

void save(char* name)
{
    FILE* fd = fopen("config", "w");
    for (List* p = head; p; p = p->next)
        fprintf(fd, "%d %s\n", p->status, p->word);
    fclose(fd);
}
void load(char* name)
{
    FILE* fd = fopen("config", "r");
    if (!fd)
        return;
    char buf[256];
    char word[64];
    List* p = head;
    List* n = p;
    int status;
    while (fgets(buf, 256, fd) != NULL) {
        sscanf(buf, "%d %s", &status, word);
        if (!head) {
            n = p = malloc(sizeof(List));
            head = p;
        } else {
            n = malloc(sizeof(List));
            p->next = n;
            p = n;
        }
        n->id = id_count++;
        n->status = status;
        n->next = NULL;
        strcpy(n->word, word);
    }
}

int main(int argc, char* argv[])
{
    char buf[256] = { 0 };
    char command[128] = { 0 };
    char word[64] = { 0 };
    char* arg = NULL;
    int id = -1;
    int index = 0;
    load(argv[0]);
    for (;;) {
        printf("prompt> ");
        fflush(stdout);
        if (fgets(buf, 256, stdin) == NULL)
            break;
        sscanf(buf, "%s%n", command, &index);
        arg = buf + index;
        switch (hash(command)) {
        case EMPTY:
            break;
        case HELP:
            help();
            break;
        case INSERT:
            sscanf(arg, "%s", word);
            if (*word == '\0')
                printf("insert error\n");
            else
                insert(word);
            break;
        case QUERY:
            sscanf(arg, "%s", word);
            if (query(word) != 0)
                printf("query error\n");
            break;
        case CHANGE:
            sscanf(arg, "%d %s", &id, word);
            if (change(id, word) != 0)
                printf("change error\n");
            break;
        case DELETE:
            sscanf(arg, "%d", &id);
            if (delete (id) != 0)
                printf("delete error\n");
            break;
        case PRINT:
            print();
            break;
        case EXIT:
            save(argv[0]);
            return 0;
        default:
            printf("command not found: %s\n", command);
        }
        id = -1;
        word[0] = '\0';
    }
    return 0;
}
