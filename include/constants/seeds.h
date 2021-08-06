#ifndef GUARD_CONSTANTS_SEEDS_H
#define GUARD_CONSTANTS_SEEDS_H

#define SEEDS_START 0x6000

#define SEED_TRAINER_PERSONALITY        (SEEDS_START + 0x0)
#define SEED_TRAINER_MON_A              (SEEDS_START + 0x1)
#define SEED_TRAINER_MON_B              (SEEDS_START + 0x2)
#define SEED_QUEUE_INSERTION            (SEEDS_START + 0x3)

#define SEEDS_END                       (SEEDS_START + 0xF)
#define SEEDS_COUNT                     (SEEDS_END - SEEDS_START + 1)

#endif // GUARD_CONSTANTS_SEEDS_H
