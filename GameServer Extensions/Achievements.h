#ifndef ACHIEVEMENTS_H
#define ACHIEVEMENTS_H

extern AchievementList gAchievementList;

void AchievementCheck(classUSER* user, CustomAvatarData* data);
void AchievementOnKill(CGameOBJ* victim, CGameOBJ* killer);
void AchievementOnTrigger(classUSER* user, unsigned int hash, int result);

void UnlockAchievement(classUSER* user, Achievement* ach);

#endif
