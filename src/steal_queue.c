#include "global.h"
#include "malloc.h"
#include "steal_queue.h"

void InitStealQueue(StealQueue *queue) {
    queue->length = 0;
    CpuFill16(0xFFFF, queue->queue, sizeof(u16) * STEAL_QUEUE_SIZE);
}

// Return current length of the queue.
u16 Queue_GetLength(StealQueue *queue) {
    return queue->length;
}

// Return mon at the given index, or -1 if the index is greater than the
// queue's length.
u16 Queue_Index(StealQueue *queue, u16 index) {
    if (index >= queue->length) return -1;

    return queue->queue[index];
}

// Return the index of a mon in the queue.
u16 Queue_IndexOf(StealQueue *queue, u16 monId) {
    u16 i;

    for (i = 0; i < queue->length; i++) {
        if (queue->queue[i] == monId) {
            return i;
        }
    }
    return -1;
}

// Append a mon to the end of the queue. Returns the index it was inserted at,
// or -1 if the queue is full.
u16 Queue_Push(StealQueue *queue, u16 monId) {
    u16 index;

    if (queue->length == STEAL_QUEUE_SIZE) return -1;

    index = queue->length;
    queue->queue[index] = monId;
    queue->length++;

    return index;
}

// Insert the mon at the given index. Returns the index it was inserted at, or
// -1 if the queue is full.
u16 Queue_InsertAt(StealQueue *queue, u16 monId, u16 index) {
    u16 *buffer;
    u16 copySize;

    if (queue->length == STEAL_QUEUE_SIZE || index > queue->length) return -1;

    // Get mons to move behind
    copySize = sizeof(u16) * (queue->length - index);
    buffer = AllocZeroed(copySize);
    CpuCopy16(&queue->queue[index], buffer, copySize);

    // Insert mon into index
    queue->queue[index] = monId;
    queue->length++;

    // Add mons back behind new mon
    CpuCopy16(buffer, &queue->queue[index+1], copySize);

    Free(buffer);
    return index;
}

// Remove the mon from the queue. Returns the index it was at or -1 if it wasn't
// in the queue.
u16 Queue_Remove(StealQueue *queue, u16 monId) {
    u16 index = Queue_IndexOf(queue, monId);
    if (index == 0xFFFF) return index;

    return Queue_RemoveAt(queue, index);
}

// Remove the mon at the given index. Returns the mon at the given index, or
// -1 if the queue is empty.
u16 Queue_RemoveAt(StealQueue *queue, u16 index)
{
    u16 *buffer;
    u16 copySize;
    u16 monId;

    if (queue->length == 0 || index >= queue->length) return -1;

    monId = queue->queue[index];
    queue->length--;

    // Get mons to move forward
    copySize = sizeof(u16) * (queue->length - index);
    buffer = AllocZeroed(copySize);
    CpuCopy16(&queue->queue[index + 1], buffer, copySize);

    // Add mons back back in
    CpuCopy16(buffer, &queue->queue[index], copySize);

    // Clear leftover data
    queue->queue[queue->length] = 0xFFFF;

    Free(buffer);
    return monId;
}

// Pops and returns mon at front of the queue. Returns -1 if queue is empty.
u16 Queue_PopFront(StealQueue *queue) {
    return Queue_RemoveAt(queue, 0);
}

// Returns the mon in the given list that is closest to the front of the queue
// and its index in the queue.
ValueIndex Queue_FurthestInLine(StealQueue *queue, u16 *mons, u16 monsSize) {
    u16 i;
    u16 idx;
    ValueIndex ret = { .value = -1, .index = -1};

    for (i = 0; i < monsSize; i++) {
        idx = Queue_IndexOf(queue, mons[i]);
        if (idx < ret.index) {
            ret = (ValueIndex) { .value = mons[i], .index = idx};
        }
    }

    return ret;
}

// Maybe Purge(), which removes mons from queue that aren't in given list.
