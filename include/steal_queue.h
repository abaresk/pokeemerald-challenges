#ifndef GUARD_STEAL_QUEUE_H
#define GUARD_STEAL_QUEUE_H

void InitStealQueue(StealQueue *queue);
u16 Index(StealQueue *queue, u16 index);
u16 IndexOf(StealQueue *queue, u16 monId);
u16 Push(StealQueue *queue, u16 monId);
u16 InsertAt(StealQueue *queue, u16 monID, u16 index);
u16 RemoveAt(StealQueue *queue, u16 index);
u16 PopFront(StealQueue *queue);
u16 FurthestInLine(StealQueue *queue, u16 *mons, u16 monsSize);

#endif // GUARD_STEAL_QUEUE_H
