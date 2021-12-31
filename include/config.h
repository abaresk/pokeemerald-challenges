#ifndef GUARD_CONFIG_H
#define GUARD_CONFIG_H

// In the Generation 3 games, Asserts were used in various debug builds.
// Ruby/Sapphire and Emerald do not have these asserts while Fire Red
// still has them in the ROM. This is because the developers forgot
// to define NDEBUG before release, however this has been changed as
// Ruby's actual debug build does not use the AGBPrint features.
#define NDEBUG

// To enable print debugging, comment out "#define NDEBUG". This allows
// the various AGBPrint functions to be used. (See include/gba/isagbprint.h).
// Some emulators support a debug console window: uncomment NoCashGBAPrint()
// and NoCashGBAPrintf() in libisagbprn.c to use no$gba's own proprietary
// printing system. Use NoCashGBAPrint() and NoCashGBAPrintf() like you
// would normally use AGBPrint() and AGBPrintf().

#define ENGLISH

#ifdef ENGLISH
#define UNITS_IMPERIAL
#else
#define UNITS_METRIC
#endif

// Uncomment to fix some identified minor bugs
//#define BUGFIX

// Various undefined behavior bugs may or may not prevent compilation with
// newer compilers. So always fix them when using a modern compiler.
#if MODERN || defined(BUGFIX)
#ifndef UBFIX
#define UBFIX
#endif
#endif

// Uncomment the difficulty setting you'd like to build.
#define SOFT
// #define HARD
// #define HARDCORE

#define PARTY_INSERT_AFTER 3

// Uncomment to disable trainers from returning stolen items after battle.
#define RETURN_ITEMS

#ifdef SOFT
// Uncomment to stop trainers from giving you a mon back after battle.
#define REPLACE_MONS

#else
// Trainers steal the mon furthest in the steal queue. Uncomment to have
// trainers just steal their favorite mon.
#define STEAL_FROM_QUEUE
#define PREVIEW_NEXT_STEAL

#ifdef HARDCORE
#define SCALING_POKE_BALL_MULTIPLIER 250
#endif

#endif

// Flag logic enforcement -- keep at end of file
#ifndef STEAL_FROM_QUEUE
#undef PREVIEW_NEXT_STEAL
#endif

#endif // GUARD_CONFIG_H
