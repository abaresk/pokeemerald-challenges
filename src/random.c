#include "global.h"
#include "main.h"
#include "random.h"

EWRAM_DATA static u8 sUnknown = 0;
EWRAM_DATA static u32 sRandCount = 0;

// IWRAM common
u32 gRngValue;
u32 gRng2Value;

u16 Random(void)
{
    gRngValue = ISO_RANDOMIZE1(gRngValue);
    sRandCount++;
    return gRngValue >> 16;
}

void SeedRng(u16 seed)
{
    gRngValue = seed;
    sUnknown = 0;
}

void SeedRng2(u16 seed)
{
    gRng2Value = seed;
}

u16 Random2(void)
{
    gRng2Value = ISO_RANDOMIZE1(gRng2Value);
    return gRng2Value >> 16;
}

u16 AdvanceSeed(u32 seed, u32 frames) {
    s32 i;
    u32 value = seed;

    for (i = 0; i < frames; i++) {
        value = ISO_RANDOMIZE1(value);
    }
    return value >> 16;
}

// Get the randomly generated u32 returned after the given number of frames. 
u32 AdvanceSeed32(u32 seed, u32 frames) {
    return AdvanceSeed(seed, frames * 2) << 16 |
           AdvanceSeed(seed, frames * 2 + 1);
}

void EnableTimerRNG(void) {
    StartTimer1();
    StartTimer2();
}

// Generate a random u32 using the GBA timer registers. For sufficient entropy,
// do not call consecutively without some player input in between.
u32 TimerRNG(void) {
    return (REG_TM2CNT_L << 16) | REG_TM1CNT_L;
}
