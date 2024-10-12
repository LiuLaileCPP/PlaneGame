#include<windows.h>
#include<mmsystem.h>
#include<stdio.h>
#include<Windows.h>
#include<easyx.h>

#pragma comment(lib,"winmm.lib")
#define BACK_WIDTH 600
#define BACK_HEIGHT 800
#define PLAYER_WIDTH 60
#define PLAYER_HEIGHT 60
#define GUNNER_WIDTH 12
#define GUNNER_HEIGHT 20

#define FOEBIG_WIDTH 150
#define FOEBIG_HEIGHT 100
#define FOEMID_WIDTH 80
#define FOEMID_HEIGHT 60
#define FOESMALL_WIDTH 60
#define FOESMALL_HEIGHT 40

#define FOEBIG_BLOOD 10
#define FOEMID_BLOOD 4
#define FOESMALL_BLOOD 1

#define FOEBIG_INIT_SHOWID 4
#define FOEMID_INIT_SHOWID 3
#define FOESMALL_INIT_SHOWID 2

#define FOEBIG_MOVE_STEP 2
#define FOEMID_MOVE_STEP 4
#define FOESMALL_MOVE_STEP 6

#define BACK_MOVE_STEP 2

#define PLAYER_MOVE_STEP 6

#define GUN_MOVE_STEP 10

#define BACK_MOVE_ID 1
#define BACK_MOVE_INTERVAL 10 //ms

#define CHECK_KEYDOWN_ID 2
#define CHECK_KEYDOWN_INTERVAL 10 //ms

#define SEND_GUN_ID 3
#define SEND_GUN_INTERVAL 100

#define GUN_MOVE_ID 4
#define GUN_MOVE_INTERVAL 30

#define FOE_CREATE_ID 5
#define FOE_CREATE_INTERVAL 2000

#define FOE_MOVE_ID 6
#define FOE_MOVE_INTERVAL 10

#define CHECK_HIT_ID 7
#define CHECK_HIT_INTERVAL 1

#define CHANGE_PIC_ID 8
#define CHANGE_PIC_INTERVAL 200

#define SHOW_SCORE_ID 9
#define SHOW_SCORE_INTERVAL 10










