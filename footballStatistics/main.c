#include <stdio.h>
#include <stdlib.h>

struct {
    short teamid;
    short numofwin;
    short numofgame;
    short numofwinhome;
    short numofgamehome;
    float winmatchTotalGoal;
    short maxGoalDifference;
    short maxGoalDifferenceOpponent;
    struct matchData * mymatchData;
} team[30];

struct {
    short hometeamid;
    short awayteamid;
    short goalshometeam;
    short goalsawayteam;
} match;

struct matchData{
    short componentId;
    short totalScore;
    short numofMatch;
    struct matchData * next;
};

int main() {
    short numMatch = 0;
    struct matchData * tempMatchData;
    struct matchData * tempMatchData2;
    scanf("%hd",&numMatch);
//    printf("numMatch %d\n",numMatch);
    float maxscore=0;
    short maxcomponent =-1;
    float winratio=0;
    float winratiohome=0;
    short scoreDiff = 0;

//    team[0].score=10;
//    team[1].score=20;
//    printf("%d\n",team[0].score);

    //initlize all the team's statistics
    for(short i=0;i<30;i++){
        team[i].teamid=i;
        team[i].numofwin=0;
        team[i].numofgame=0;
        team[i].numofwinhome=0;
        team[i].numofgamehome=0;
        team[i].winmatchTotalGoal = 0;
        team[i].maxGoalDifference = 0;
        team[i].maxGoalDifferenceOpponent = -1;
        team[i].mymatchData = (struct matchData *)malloc( sizeof(struct matchData) );
        team[i].mymatchData->componentId = -1;
        team[i].mymatchData->totalScore = 0;
        team[i].mymatchData->numofMatch = 0;
        team[i].mymatchData->next  = NULL;
    }

    for(short i=0;i<numMatch;i++){
//        printf("Please input the match data of :");
        scanf("%hd",&match.hometeamid);
        scanf("%hd",&match.awayteamid);
        scanf("%hd",&match.goalshometeam);
        scanf("%hd",&match.goalsawayteam);

        /*
            printf("%d \n",match.hometeamid);
            printf("%d \n",match.awayteamid);
            printf("%d \n",match.goalshometeam);
            printf("%d \n",match.goalswaayteam);
         */
        scoreDiff = match.goalshometeam - match.goalsawayteam;
        team[match.hometeamid].numofgame ++;
        team[match.awayteamid].numofgame ++;
        team[match.hometeamid].numofgamehome ++;
        if(scoreDiff > 0){
            team[match.hometeamid].numofwin ++;
            team[match.hometeamid].winmatchTotalGoal +=scoreDiff;
            team[match.hometeamid].numofwinhome ++;
        }else if(scoreDiff < 0){
            team[match.awayteamid].numofwin ++;
            team[match.awayteamid].winmatchTotalGoal -=(scoreDiff);
        }

/*        //home game
        team[match.hometeamid].numofgamehome ++;
        if(match.goalshometeam > match.goalsawayteam){
            team[match.hometeamid].numofwinhome ++;
        }*/

        //update max goal difference
        if(team[match.hometeamid].numofwin == 0){
            if(abs(scoreDiff) >= abs(team[match.hometeamid].maxGoalDifference)){
                team[match.hometeamid].maxGoalDifference = scoreDiff;
                team[match.hometeamid].maxGoalDifferenceOpponent = match.awayteamid;
            }
        }else{
            if((scoreDiff) >= (team[match.hometeamid].maxGoalDifference)){
                team[match.hometeamid].maxGoalDifference = scoreDiff;
                team[match.hometeamid].maxGoalDifferenceOpponent = match.awayteamid;
            }
        }
        if(team[match.awayteamid].numofwin == 0){
            if(abs(scoreDiff) >= abs(team[match.awayteamid].maxGoalDifference)){
                team[match.awayteamid].maxGoalDifference = -scoreDiff;
                team[match.awayteamid].maxGoalDifferenceOpponent = match.hometeamid;
            }
        }else{
            if((-scoreDiff) >= (team[match.awayteamid].maxGoalDifference)){
                team[match.awayteamid].maxGoalDifference = -scoreDiff;
                team[match.awayteamid].maxGoalDifferenceOpponent = match.hometeamid;
            }
        }

        //
        if(team[match.hometeamid].mymatchData->componentId == -1){
            team[match.hometeamid].mymatchData->componentId = match.awayteamid;
            team[match.hometeamid].mymatchData->totalScore += (scoreDiff);
            team[match.hometeamid].mymatchData->numofMatch += 1;
        }else{
            tempMatchData =team[match.hometeamid].mymatchData;
            while(1){
                if(tempMatchData->componentId == match.awayteamid){
                    tempMatchData->totalScore += (scoreDiff);
                    tempMatchData->numofMatch += 1;
                    break;
                }else{
                    tempMatchData = tempMatchData->next;
                    if(tempMatchData == NULL){
                        tempMatchData = (struct matchData *)malloc( sizeof(struct matchData) );
                        tempMatchData->componentId = match.awayteamid;
                        tempMatchData->totalScore += (scoreDiff);
                        tempMatchData->numofMatch += 1;
                        tempMatchData->next = NULL;
                    }
                }
            }
        }
        if(team[match.awayteamid].mymatchData->componentId == -1){
            team[match.awayteamid].mymatchData->componentId = match.hometeamid;
            team[match.awayteamid].mymatchData->totalScore += (-scoreDiff);
            team[match.awayteamid].mymatchData->numofMatch += 1;
        }else{
            tempMatchData =team[match.awayteamid].mymatchData;
            while(1){
                if(tempMatchData->componentId == match.hometeamid){
                    tempMatchData->totalScore += (-scoreDiff);
                    tempMatchData->numofMatch += 1;
                    break;
                }else{
                    tempMatchData = tempMatchData->next;
                    if(tempMatchData == NULL){
                        tempMatchData = (struct matchData *)malloc( sizeof(struct matchData) );
                        tempMatchData->componentId = match.hometeamid;
                        tempMatchData->totalScore += (-scoreDiff);
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
            winratio = (float)team[i].numofwin/team[i].numofgame;
            if(team[i].numofgamehome != 0){
                winratiohome = (float)team[i].numofwinhome/team[i].numofgamehome;
            }else{
                winratiohome = -1;
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
            printf("%d %3.3f %3.3f %3.3f %d %d %3.3f %d\n",team[i].teamid,winratio,winratiohome,team[i].winmatchTotalGoal,
                   team[i].maxGoalDifference,team[i].maxGoalDifferenceOpponent,maxscore,maxcomponent);
            tempMatchData = team[i].mymatchData;
            //free the stack
            while(tempMatchData != NULL){
                tempMatchData2 = tempMatchData;
                tempMatchData = tempMatchData->next;
                free(tempMatchData2);
            }
        }
    }

    return 0;
}