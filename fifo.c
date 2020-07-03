#include <stdio.h> 
#include <stdlib.h> 
  

struct QNode { 
    int pno;
    struct QNode* next; 
}; 
  
struct Queue { 
    struct QNode *front, *rear; 
}; 
  
struct QNode* newNode(int pno) 
{ 
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode)); 
    temp->pno = pno;
    return temp; 
} 
  

struct Queue* createQueue() 
{ 
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
    q->front = q->rear = NULL; 
    return q; 
} 
  

void enQueue(struct Queue* q, int pno) 
{ 
    struct QNode* temp = newNode(pno); 
  
    if (q->rear == NULL) { 
        q->front = q->rear = temp; 
        return; 
    } 
    q->rear->next = temp; 
    q->rear = temp; 
} 
  
void display(struct Queue* q)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp = q->front;
    if ((temp == NULL) && (q->rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (temp != q->rear)
    {
        if (temp->pno!=-1){
        printf("%d ", temp->pno);}
        temp = temp->next;
    }
    if (temp == q->rear){
         if (temp->pno!=-1){
        printf("%d ", temp->pno);}
    }
}

struct QNode* deQueue(struct Queue* q) 
{ 
    if (q->front == NULL) {
        return NULL; 
    }
    struct QNode* temp = q->front; 
    q->front = q->front->next; 
  
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return temp; 
} 

int empty(struct Queue* q)
{
    if ((q->front == NULL) && (q->rear == NULL)){
        return 0;
    }
    else{
        return 1;
    }
}

int search(struct Queue* q, int pno)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp = q->front;
    if (!empty(q))
    {
        return 0;
    }
    while (temp != q->rear)
    {
        if (temp->pno == pno){
            return 1 ;
        }
        temp = temp->next;
    }
    if (temp == q->rear){
        if (temp->pno == pno){
            return 1;
        }
    }
    return 0;
}
  
int main() 
{ 
    struct Queue* q = createQueue(); 
    int p[10],n,f,i,pf=0;
    printf("Enter no of pages: ");
    scanf("%d",&n);
    printf("Enter reference string: ");
    for (i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter no of frames: ");
    scanf("%d",&f);
    for (i=0;i<f;i++){
       
        enQueue(q,-1);
    }
    for (i=0;i<n;i++){
        if(search(q,p[i])==0){
            deQueue(q);
            enQueue(q,p[i]);
            pf+=1;
        }
        display(q);
        printf("\n");
        
    }
    printf("Page faults: %d\n",pf);
    return 0;
} 
