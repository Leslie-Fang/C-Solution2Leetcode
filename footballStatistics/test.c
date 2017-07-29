#include <stdio.h>
#include <stdlib.h>

struct {
    int teamid;
    int numofwin;
    int numofgame;
    int numofwinhome;
    int numofgamehome;
    float winratio;
    float winratiohome;
    float winmatchTotalGoal;
    int maxGoalDifference;
    int maxGoalDifferenceOpponent;
    struct matchData * mymatchData;
} team[30];

struct {
    int hometeamid;
    int awayteamid;
    int goalshometeam;
    int goalsawayteam;
} match;

struct matchData{
    int componentId;
    int totalScore;
    int numofMatch;
    struct matchData * next;
};

int main() {
    int numMatch = 0;
    struct matchData * tempMatchData;
    scanf("%d",&numMatch);
//    printf("numMatch %d\n",numMatch);
    float maxscore=0;
    int maxcomponent =-1;
//    team[0].score=10;
//    team[1].score=20;
//    printf("%d\n",team[0].score);

    //initlize all the team's statistics
    for(int i=0;i<30;i++){
        team[i].teamid=i;
        team[i].numofwin=0;
        team[i].numofgame=0;
        team[i].numofwinhome=0;
        team[i].numofgamehome=0;
        team[i].winratio=0;
        team[i].winratiohome=-1;
        team[i].winmatchTotalGoal = 0;
        team[i].maxGoalDifference = 0;
        team[i].maxGoalDifferenceOpponent = -1;
        team[i].mymatchData = (struct matchData *)malloc( sizeof(struct matchData) );
        team[i].mymatchData->componentId = -1;
        team[i].mymatchData->totalScore = 0;
        team[i].mymatchData->numofMatch = 0;
        team[i].mymatchData->next  = NULL;
    }

    for(int i=0;i<numMatch;i++){
//        printf("Please input the match data of :");
        scanf("%d",&match.hometeamid);
        scanf("%d",&match.awayteamid);
        scanf("%d",&match.goalshometeam);
        scanf("%d",&match.goalsawayteam);

        /*
            printf("%d \n",match.hometeamid);
            printf("%d \n",match.awayteamid);
            printf("%d \n",match.goalshometeam);
            printf("%d \n",match.goalswaayteam);
         */
        team[match.hometeamid].numofgame ++;
        team[match.awayteamid].numofgame ++;
        if(match.goalshometeam > match.goalsawayteam){
            team[match.hometeamid].numofwin ++;
            team[match.hometeamid].winmatchTotalGoal +=(match.goalshometeam - match.goalsawayteam);

        }else if(match.goalshometeam < match.goalsawayteam){
            team[match.awayteamid].numofwin ++;
            team[match.awayteamid].winmatchTotalGoal +=(match.goalsawayteam - match.goalshometeam);

        }

        //home game
        team[match.hometeamid].numofgamehome ++;
        if(match.goalshometeam > match.goalsawayteam){
            team[match.hometeamid].numofwinhome ++;
        }

        //update max goal difference
        if(team[match.hometeamid].numofwin == 0){
            if(abs(match.goalshometeam - match.goalsawayteam) >= abs(team[match.hometeamid].maxGoalDifference)){
                team[match.hometeamid].maxGoalDifference = match.goalshometeam - match.goalsawayteam;
                team[match.hometeamid].maxGoalDifferenceOpponent = match.awayteamid;
            }
        }else{
            if((match.goalshometeam - match.goalsawayteam) >= (team[match.hometeamid].maxGoalDifference)){
                team[match.hometeamid].maxGoalDifference = match.goalshometeam - match.goalsawayteam;
                team[match.hometeamid].maxGoalDifferenceOpponent = match.awayteamid;
            }
        }
        if(team[match.awayteamid].numofwin == 0){
            if(abs(match.goalshometeam - match.goalsawayteam) >= abs(team[match.awayteamid].maxGoalDifference)){
                team[match.awayteamid].maxGoalDifference = match.goalsawayteam - match.goalshometeam;
                team[match.awayteamid].maxGoalDifferenceOpponent = match.hometeamid;
            }
        }else{
            if((match.goalsawayteam - match.goalshometeam) >= (team[match.awayteamid].maxGoalDifference)){
                team[match.awayteamid].maxGoalDifference = match.goalsawayteam - match.goalshometeam;
                team[match.awayteamid].maxGoalDifferenceOpponent = match.hometeamid;
            }
        }

        //
        if(team[match.hometeamid].mymatchData->componentId == -1){
            team[match.hometeamid].mymatchData->componentId = match.awayteamid;
            team[match.hometeamid].mymatchData->totalScore += (match.goalshometeam - match.goalsawayteam);
            team[match.hometeamid].mymatchData->numofMatch += 1;
        }else{
            tempMatchData =team[match.hometeamid].mymatchData;
            while(1){
                if(tempMatchData->componentId == match.awayteamid){
                    tempMatchData->totalScore += (match.goalshometeam - match.goalsawayteam);
                    tempMatchData->numofMatch += 1;
                    break;
                }else{
                    tempMatchData = tempMatchData->next;
                    if(tempMatchData == NULL){
                        tempMatchData = (struct matchData *)malloc( sizeof(struct matchData) );
                        tempMatchData->componentId = match.awayteamid;
                        tempMatchData->totalScore += (match.goalshometeam - match.goalsawayteam);
                        tempMatchData->numofMatch += 1;
                        tempMatchData->next = NULL;
                    }
                }
            }
        }
        if(team[match.awayteamid].mymatchData->componentId == -1){
            team[match.awayteamid].mymatchData->componentId = match.hometeamid;
            team[match.awayteamid].mymatchData->totalScore += (match.goalsawayteam - match.goalshometeam);
            team[match.awayteamid].mymatchData->numofMatch += 1;
        }else{
            tempMatchData =team[match.awayteamid].mymatchData;
            while(1){
                if(tempMatchData->componentId == match.hometeamid){
                    tempMatchData->totalScore += (match.goalsawayteam - match.goalshometeam);
                    tempMatchData->numofMatch += 1;
                    break;
                }else{
                    tempMatchData = tempMatchData->next;
                    if(tempMatchData == NULL){
                        tempMatchData = (struct matchData *)malloc( sizeof(struct matchData) );
                        tempMatchData->componentId = match.hometeamid;
                        tempMatchData->totalScore += (match.goalsawayteam - match.goalshometeam);
                        tempMatchData->numofMatch += 1;
                        tempMatchData->next = NULL;
                    }
                }
            }
        }
    }
    /*
    for(int i=0;i<numMatch;i++){
        //printf("Please input the match data of %d\n",team[i].score);
    }*/
 /*   for(int i=0;i<30;i++){
        if(team[i].numofgame != 0){
            printf("team[%d].numofgame %d\n",i,team[i].numofgame);
            printf("team[%d].numofwin %d\n",i,team[i].numofwin);
            printf("team[%d].numofgamehome %d\n",i,team[i].numofgamehome);
            printf("team[%d].numofwinhome %d\n",i,team[i].numofwinhome);
        }
    }
    printf("=====================================>\n");*/
    for(int i=0;i<30;i++){
        if(team[i].numofgame != 0){
            team[i].winratio = (float)team[i].numofwin/team[i].numofgame;
            if(team[i].numofgamehome != 0){
                team[i].winratiohome = (float)team[i].numofwinhome/team[i].numofgamehome;
            }
            if(team[i].winmatchTotalGoal == 0){
                team[i].winmatchTotalGoal = -1;
            }else{
                team[i].winmatchTotalGoal = (float)team[i].winmatchTotalGoal/team[i].numofwin;
            }

            maxscore=0;
            maxcomponent =-1;
            tempMatchData = team[i].mymatchData;
            while(tempMatchData != NULL){
                if(((float)tempMatchData->totalScore/tempMatchData->numofMatch) >= maxscore || (-(float)tempMatchData->totalScore/tempMatchData->numofMatch) >= maxscore){
                    maxscore = (float)tempMatchData->totalScore/tempMatchData->numofMatch;
                    maxcomponent = tempMatchData->componentId;
                }
                tempMatchData= tempMatchData->next;
            }

 /*           printf("team[%d].teamid %d\n",i,team[i].teamid);
            printf("team[%d].winratio %3.3f\n",i,team[i].winratio);
            printf("team[%d].winratiohome %3.3f\n",i,team[i].winratiohome);
            printf("team[%d].winmatchTotalGoal %3.3f\n",i,team[i].winmatchTotalGoal);
            printf("team[%d].maxGoalDifference %d\n",i,team[i].maxGoalDifference);
            printf("team[%d].maxGoalDifferenceOpponent %d\n",i,team[i].maxGoalDifferenceOpponent);
            printf("team[%d].maxAveragePointDifference %3.3f\n",i,maxscore);
            printf("team[%d].maxAveragePointDifferenceOpponent %d\n",i,maxcomponent);*/
            printf("%d %3.3f %3.3f %3.3f %d %d %3.3f %d\n",team[i].teamid,team[i].winratio,team[i].winratiohome,team[i].winmatchTotalGoal,
                   team[i].maxGoalDifference,team[i].maxGoalDifferenceOpponent,maxscore,maxcomponent);
        }
    }

    return 0;
}