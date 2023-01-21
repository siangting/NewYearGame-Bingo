#include <stdio.h>
#include <stdlib.h>
#include <time.h>						//因要產生亂數，利用時間產生亂數 
int delay(long delay){					//延遲副程式 
	delay=delay*2000;
	for (int wait=0;wait<=delay;wait++)  
	{}									//不需要任何輸出 
}

int Number(void){						//顯示1-80的副程式
	printf("================================================================\n");
	for(int temp=1;temp<=80;temp++){
	printf("%d",temp);
	if ((temp%8)==0)					//每輸出8個數字，切換到下一行 
	printf("\n");
	else
	printf("\t");
	}
	printf("================================================================\n");
}

int playiny(int play){                  //進行遊戲副程式 
printf("請在1-80的數字中選擇%d個數字\n",play);
Number();					        	//顯示1-80的副程式 
int player_Number[10];
int temp=1;
for(temp=1;temp<=play;temp++){
	printf("第%d個數字：",temp);
	scanf("%d",&player_Number[temp]);
	int cc=1;
	while((1>player_Number[temp])||(player_Number[temp]>80)){
	printf("數字超出限制，請輸入1-80數字\n");          //限制玩家輸入數字在1至80間
	printf("第%d個數字：",temp);
	scanf("%d",&player_Number[temp]);
}
		for (int v=temp-1;v>0;v--)
     while (player_Number[v]==player_Number[temp]){  //如有重覆，再輸入一次數字 
     printf("你輸入的數字已重複輸入，請選擇新數字\n");
     scanf("%d",&player_Number[temp]);}
}
for (temp=0;temp<50;temp++){
	printf(">");
	delay(3000);		//延遲副程式，美化介面用途
}
	printf("\n");
printf("你輸入的數字是：");
temp=1;
while(temp<=play) {
 printf("%d  ",player_Number[temp]);		//重複顯示玩家所輸入的數字 
 temp++;
 }
 printf("\n");
 int Bingo_Num[20];						//陣列 
  srand(time(NULL));					//亂數 
	printf("現在抽出20個數字\n");
	for(int loop=0;loop<20;loop++){
	Bingo_Num[loop]=(rand()%80)+1;					//限制亂數在1至80間
	for (temp=loop-1;temp>0;temp--)
     while (Bingo_Num[temp]==Bingo_Num[loop])				//如產生的亂數有重覆，再取一次亂數
     Bingo_Num[loop]=(rand()%80)+1;				//限制亂數在1至80間
}
printf("======================================\n");
	for(int temp_ONE=0;temp_ONE<20;temp_ONE++){
   printf("%d  ",Bingo_Num[temp_ONE]);
    	if((Bingo_Num[temp_ONE]-9)<1)
   		printf(" ");
   	if(temp_ONE==9)
   	printf("\n");
   }
	 printf("\n");
	 printf("======================================\n");
	 int check=0;
	 for (int loop=0;loop<=20;loop++){
	 	for (temp=0;temp<=play;temp++){
	 	
	 	if(Bingo_Num[loop]==player_Number[temp]){
	 	printf("中獎數字：%d \n",Bingo_Num[loop]);
	 	check++;
	 	}
	 }
	 }
	 if(check==0)
	 printf("\n抱歉，這一次你沒有中獎 \n祝你下次好運\n");
return check;
}

int Bonus_Help (void){			//遊戲獎金副程式 
printf("\n===========================================================================================================================");
printf("\n玩法  10          9          8          7          6          5          4          3          2          1          0  ");
printf("\n10星  $5,000,000  $250,000   $25,000    $2,500     $250       $25         ----      ----       ----       ----      $25 ");
printf("\n 9星     ----     $1,000,000 $100,000   $3,000     $500       $100       $25        ----       ----       ----      $25 ");	
printf("\n 8星     ----------------    $500,000   $20,000    $1,000     $200       $25        --------------------------      $25 ");	
printf("\n 7星     ----        ----      ----     $80,000    $3,000     $300       $50        $25        ----       ----      ----");	
printf("\n 6星     ----        ----      ----       ----     $25,000    $1,000     $200       $25        ----       ----      ----");	
printf("\n 5星     ------------------------------------------------     $7,500     $500       $50        -------------------------");	
printf("\n 4星     ----        ----      ----       ----       ----      ----      $1,000     $100       $25        ----      ----");	
printf("\n 3星     ----        ----      ----       ----       ----      ----       ----      $500       $50        ----      ----");	
printf("\n 2星     -------------------------------------------------------------------------------       $75        $25       ----");	
printf("\n 1星     ----        ----      ----       ----       ----      ----       ----      ----       ----       $50       ----");	
printf("\n===========================================================================================================================\n");
}

int Bonus_playing (int Bingo_TotalNum ,int player_star){			//獎金分配副程式
	if (player_star==10)     
	switch (Bingo_TotalNum){				//10星的獎金分配 
	case 10:			//中10個數字
		return 5000000;
		break;
	case 9:				//中9個數字
		return 250000;
		break;	
	case 8:				//中8個數字
		return 25000;
		break;	
	case 7:				//中7個數字
		return 2500;
		break;	
	case 6:				//中6個數字
		return 250;
		break;	
	case 5:				//中5個數字
		return 25;
		break;	
	case 0:				//中0個數字
		return 25;
		break;	
default:
	return 0;
}
//=================================
	if (player_star==9)
	switch (Bingo_TotalNum){				//9星的獎金分配 
	case 9:				//中9個數字
		return 1000000;
		break;	
	case 8:				//中8個數字
		return 100000;
		break;	
	case 7:				//中7個數字
		return 3000;
		break;	
	case 6:				//中6個數字
		return 500;
		break;	
	case 5:				//中5個數字
		return 100;
		break;	
	case 4:				//中4個數字
		return 25;
		break;
	case 0:				//中0個數字
		return 25;
		break;	
default:
	return 0;
}
//=================================
	if (player_star==8)
	switch (Bingo_TotalNum){				//8星的獎金分配 
	case 8:				//中8個數字
		return 500000;
		break;	
	case 7:				//中7個數字
		return 20000;
		break;	
	case 6:				//中6個數字
		return 1000;
		break;	
	case 5:				//中5個數字
		return 200;
		break;	
	case 4:				//中4個數字
		return 25;
		break;
	case 0:				//中0個數字
		return 25;
		break;	
default:
	return 0;
}
//=================================
	if (player_star==7)
	switch (Bingo_TotalNum){				//7星的獎金分配 		
	case 7:				//中7個數字
		return 280000;
		break;	
	case 6:				//中6個數字
		return 3000;
		break;	
	case 5:				//中5個數字
		return 300;
		break;	
	case 4:				//中4個數字
		return 50;
		break;
	case 3:				//中3個數字
		return 25;
		break;	
default:
	return 0;
}
//=================================
	if (player_star==6)
	switch (Bingo_TotalNum){				//6星的獎金分配 		
	case 6:				//中6個數字
		return 25000;
		break;	
	case 5:				//中5個數字
		return 1000;
		break;	
	case 4:				//中4個數字
		return 200;
		break;
	case 3:				//中3個數字
		return 25;
		break;	
default:
	return 0;
}
//=================================
	if (player_star==5)
	switch (Bingo_TotalNum){				//5星的獎金分配 			
	case 5:				//中5個數字
		return 7500;
		break;	
	case 4:				//中4個數字
		return 500;
		break;
	case 3:				//中3個數字
		return 50;
		break;	
default:
	return 0;
}
//=================================
	if (player_star==4)
	switch (Bingo_TotalNum){				//4星的獎金分配 			
	case 4:				//中4個數字
		return 1000;
		break;
	case 3:				//中3個數字
		return 100;
		break;	
	case 2:				//中2個數字
		return 25;
		break;
default:
	return 0;
}
//=================================
	if (player_star==3)
	switch (Bingo_TotalNum){				//3星的獎金分配 	
	case 3:				//中3個數字
		return 500;
		break;	
	case 2:				//中2個數字
		return 50;
		break;
default:
	return 0;
}
//=================================
	if (player_star==2)
	switch (Bingo_TotalNum){				//2星的獎金分配 			
	case 2:				//中2個數字 
		return 75;
		break;	
	case 1:				//中1個數字
		return 50;
		break;
default:
	return 0;
}
//=================================
	if (player_star==1)
	switch (Bingo_TotalNum){				//1星的獎金分配 				
	case 1:				//中1個數字
		return 50;
		break;
default:
	return 0;
}  }

int main (void){				//-----------------主程式 -----------------
	int play;
	int money;
	int loop=0;
	int check;
	int Winning_Num=0;
	int get_money=0;
	printf(">>>BINGO BINGO賓果賓果<<<\n");
	printf("請輸入預設金錢：");
	scanf("%d",&money); 
	printf("金錢設定為：%d",money);
	Bonus_Help();								//遊戲獎金副程式 
	do{
	printf("幾星玩法？\t 「1星」=1、 「2星」=2、 「3星」....、「10星」=10\n");
	scanf("%d",&play); 
	do{
	if (1<=play&&play<=10){ 							//限制玩家輸入數字在1-10內 
		printf("你選擇了%d星的玩法\n\n",play); 
		Winning_Num=playiny(play);				//return出遊戲得出的獎金 
		break;									//跳出迴圈 
		} 
	else
		printf("輸入錯誤，請重新輸入\n");
		scanf("%d",&play); 
}while(1);
if (Winning_Num>=1)
printf("共中獎了%d個數字\n",Winning_Num);				//顯示出中了幾個數字，如沒有中獎則不顯示 
get_money=Bonus_playing (Winning_Num,play); 		//return 出遊戲中得出的獎金 
printf("獲得獎金%d\n",get_money);
int RateOfRise=((get_money+money)-money)/money*100;		//計算出資金增長率
money=get_money+money; 								//計算出獎金+本金錢 
printf("===================================\n"); 
printf("現款為：%d\n",money); 						//顯示出玩家最新現款 
printf("資金增長率：%d %%\n",RateOfRise);  				//顯示出%，則需要用%% 
printf("===================================\n");
int output_I=1;
do{
printf("輸入「1」持續遊戲；    「2」幫助；    「3」退出遊戲\n");
scanf("%d",&check); 
switch (check){							//檢查輸入1,2,3,或其他按鍵 
	case 1:							//持續遊戲 
		loop=1;
		output_I=0;
		break;	
	case 2:							//幫助 
		Bonus_Help();
		loop=1;
		output_I=0;
		break;	
	case 3:							//退出遊戲
		loop=0;
		output_I=0;                                     
		break;
default:							//輸入其他按鍵，要求重新輸入一次 
output_I=1;
}
}while(output_I==1);
}while(loop==1);
printf("謝謝你，祝你新年快樂\n");
}