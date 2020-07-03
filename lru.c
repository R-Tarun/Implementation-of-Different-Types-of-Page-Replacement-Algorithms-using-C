#include <stdio.h> 
#include <stdlib.h> 
  

struct QNode { 
    int pno;
    struct QNode* next,*prev; 
}; 
  
struct Queue { 
    struct QNode *front, *rear; 
}; 
  
struct QNode* newNode(int pno) 
{ 
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode)); 
    temp->pno = pno;
    temp->next = NULL;
    temp->prev = NULL;
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
    temp->prev=q->rear;
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
    }printf("\n");
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
    else if (q->front->pno==pno){
        return 2;
    }
    else if (q->rear->pno==pno){
        return 3;
    }
    while (temp != q->rear)
    {
        if (temp->pno == pno){
            return 1 ;
        }
        temp = temp->next;
    }
    return 0;
}

struct QNode* del(struct Queue* q, int pno){
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp = q->front;
    if (!empty(q))
    {
        return NULL;
    }
    while (temp != q->rear)
    {
        if (temp->pno == pno){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            return temp;
        }
        temp = temp->next;        
    }
    return NULL;
}
int main() 
{ 
    struct Queue* q = createQueue(); 
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode)); 
    int p[10],n,f,i,pf=0,s;
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
        s=search(q,p[i]);
        if(s==0){
            deQueue(q);
            enQueue(q,p[i]);
            pf+=1;
        }else{
            if (s==2){
                temp=deQueue(q);
                enQueue(q,temp->pno);
            }
            else if(s==1){
                temp=del(q,p[i]);
                enQueue(q,temp->pno);
            }
        }
        display(q);
    }
    
    printf("Page faults: %d\n",pf);
    
    return 0;
} 
