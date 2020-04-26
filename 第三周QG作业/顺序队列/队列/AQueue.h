
#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED

#define MAXQUEUE 10
#define INT 1
#define CHAR 2
#define DOUBLE 3
#define STRING 4

typedef struct Aqueue
{
    void* data[MAXQUEUE]; 
    int front;
    int rear;
    size_t length; 
    int type[MAXQUEUE];
} AQueue;

typedef enum
{
    FALSE = 0, TRUE = 1
} Status;

void InitAQueue(AQueue* Q);

void DestoryAQueue(AQueue* Q);


Status IsFullAQueue(const AQueue* Q);

Status IsEmptyAQueue(const AQueue* Q);

Status GetHeadAQueue(AQueue* Q, void* e);

int LengthAQueue(AQueue* Q);

Status EnAQueue(AQueue* Q, void* data);

Status DeAQueue(AQueue* Q);

void ClearAQueue(AQueue* Q);

Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q, int typeData));

void APrint(void* q, int typeData);

#endif // AQUEUE_H_INCLUDED


