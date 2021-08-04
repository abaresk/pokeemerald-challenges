#ifndef GUARD_STEAL_QUEUE_H
#define GUARD_STEAL_QUEUE_H

typedef struct {
    u16 value;
    u16 index;
} ValueIndex;

void InitStealQueue(StealQueue *queue);
u16 Queue_GetLength(StealQueue *queue);
u16 Queue_Index(StealQueue *queue, u16 index);
u16 Queue_IndexOf(StealQueue *queue, u16 monId);
u16 Queue_Push(StealQueue *queue, u16 monId);
u16 Queue_InsertAt(StealQueue *queue, u16 monID, u16 index);
u16 Queue_Remove(StealQueue *queue, u16 monId);
u16 Queue_RemoveAt(StealQueue *queue, u16 index);
u16 Queue_PopFront(StealQueue *queue);
ValueIndex Queue_FurthestInLine(StealQueue *queue, u16 *mons, u16 monsSize);

#endif // GUARD_STEAL_QUEUE_H
