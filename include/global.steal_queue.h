#ifndef GUARD_GLOBAL_STEAL_QUEUE_H
#define GUARD_GLOBAL_STEAL_QUEUE_H

#define STEAL_QUEUE_SIZE 428

typedef struct {
    u16 length;
    u16 queue[STEAL_QUEUE_SIZE];
} StealQueue;

#endif // GUARD_GLOBAL_STEAL_QUEUE_H
