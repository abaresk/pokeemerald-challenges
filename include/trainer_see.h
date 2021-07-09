#ifndef GUARD_TRAINER_SEE_H
#define GUARD_TRAINER_SEE_H

enum
{
    TRSEE_NONE,
    TRSEE_EXCLAMATION,
    TRSEE_EXCLAMATION_WAIT,
    TRSEE_MOVE_TO_PLAYER,
    TRSEE_PLAYER_FACE,
    TRSEE_PLAYER_FACE_WAIT,
    TRSEE_REVEAL_DISGUISE,
    TRSEE_REVEAL_DISGUISE_WAIT,
    TRSEE_REVEAL_BURIED,
    TRSEE_BURIED_POP_OUT,
    TRSEE_BURIED_JUMP,
    TRSEE_REVEAL_BURIED_WAIT,
    TRSEE_PLAYER_FACE_AWAY,
    TRSEE_EXCLAMATION_FACE_AWAY_WAIT,
};

struct ApproachingTrainer
{
    u8 objectEventId;
    u8 radius; // plus 1
    const u8 *trainerScriptPtr;
    u8 taskId;
};

extern u16 gWhichTrainerToFaceAfterBattle;
extern u8 gPostBattleMovementScript[4];
extern struct ApproachingTrainer gApproachingTrainers[2];
extern u8 gNoOfApproachingTrainers;
extern bool8 gTrainerApproachedPlayer;
extern u8 gApproachingTrainerId;

bool8 CheckForTrainersWantingBattle(void);
void SetBuriedTrainerMovement(struct ObjectEvent *var);
void DoTrainerApproach(void);
void TryPrepareSecondApproachingTrainer(void);
u8 FldEff_ExclamationMarkIcon(void);
u8 FldEff_QuestionMarkIcon(void);
u8 FldEff_HeartIcon(void);
u8 GetCurrentApproachingTrainerObjectEventId(void);
u8 GetChosenApproachingTrainerObjectEventId(u8 arrayId);
void PlayerFaceTrainerAfterBattle(void);
void Task_RunTrainerSeeFuncList(u8 taskId);
void Task_TrainerEncounterWhiteOut(u8 taskId);
void Task_EndTrainerApproach(u8 taskId);

#endif // GUARD_TRAINER_SEE_H
