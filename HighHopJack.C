#include<stdio.h>
#include<conio.h>
#include<dos.h>
#define TRUE 1

int checkCollision(int left, int top, int left1, int top1, int left2, int top2, int left3, int top3)
{
	// Player ">O>" is 3 characters wide: columns left to left+2
	
	// Check collision with top part "(00)" - 4 chars wide at left1
	if(top == top1)
	{
		// Player overlaps if: player_right >= obstacle_left AND player_left <= obstacle_right
		if(left + 2 >= left1 && left <= left1 + 3)
			return 1;
	}
	
	// Check collision with middle part "/()\" - 4 chars wide at left2
	if(top == top2)
	{
		if(left + 2 >= left2 && left <= left2 + 3)
			return 1;
	}
	
	// Check collision with bottom part "||" - 2 chars wide at left3
	if(top == top3)
	{
		if(left + 2 >= left3 && left <= left3 + 1)
			return 1;
	}
	
	return 0; // No collision
}

int main()
{
	int left, top, count=0, flag=0, left1=40, top1=22, left2=40, top2=23, left3=41, top3=24;
	char keyValue = '\0';
	int left0, top0, score=0;
	int left5=2, top5=24, left6=2, top6=23;
	int count1=1, count2=1;
	int boxLength, boxWidth;
	int gameOver = 0;
	
	clrscr();
	gotoxy(40,2);
	printf("JUMPING BOY");
	gotoxy(2,2);
	printf("PRESS 'S' TO START");
	gotoxy(2,3);
	printf("PRESS 'J' TO JUMP");
	gotoxy(2,4);
	printf("PRESS 'E' TO EXIT");
	getch();
	clrscr();
	_setcursortype(_NOCURSOR);
	
	left=2;
	top=24;
	left0=2;
	top0=24;
	
	gotoxy(left,top);
	printf(">O>");
	gotoxy(left1,top1);
	printf("(00)");
	gotoxy(left2,top2);
	printf("/()\\");
	gotoxy(left3,top3);
	printf("||");
	
	boxLength=1;
	boxWidth=1;
	while(boxLength<80)
	{
		gotoxy(boxLength,boxWidth);
		printf("*");
		gotoxy(boxLength,boxWidth+24);
		printf("*");
		delay(20);
		boxLength++;
	}
	
	boxLength=1;
	boxWidth=1;
	while(boxWidth<25)
	{
		gotoxy(boxLength,boxWidth);
		printf("*");
		gotoxy(boxLength+78,boxWidth);
		printf("*");
		delay(20);
		boxWidth++;
	}

	while(TRUE)
	{
		if(kbhit())
		{
			keyValue=getch();
		}
		
		if(keyValue=='e' || keyValue=='E')
		{
			break;
		}
		else if(keyValue=='s' || keyValue=='S')
		{
			gotoxy(left,top);
			printf(">O>");
			
			if(left>20 || count1==0)
			{
				count1 = 0;
				gotoxy(left5,top5);
				printf(">O>");
			}
			
			if(left>35 || count2==0)
			{
				count2 = 0;
				gotoxy(left6,top6);
				printf(">O>");
			}
			
			delay(100);
			
			gotoxy(left,top);
			printf("   ");
			gotoxy(left5,top5);
			printf("   ");
			gotoxy(left6,top6);
			printf("   ");
			
			if(left==70) left=2;
			else left++;

			if(count1==0 && left5==70) left5=2;
			else if(count1==0) left5++;

			if(count2==0 && left6==70) left6=2;
			else if(count2==0) left6++;
			
			// Check collision for all three players AFTER moving
			if(checkCollision(left, top, left1, top1, left2, top2, left3, top3) ||
			   checkCollision(left5, top5, left1, top1, left2, top2, left3, top3) ||
			   checkCollision(left6, top6, left1, top1, left2, top2, left3, top3))
			{
				gameOver = 1;
				break;
			}
		}
		else if(keyValue=='j' || keyValue=='J')
		{
			// Jump up
			for(count=0; count<5; count++)
			{
				gotoxy(left1,top1);
				printf("(00)");
				gotoxy(left2,top2);
				printf("\\()/");
				gotoxy(left3,top3);
				printf("||");
				gotoxy(left,top);
				printf(">O>");
				gotoxy(left5,top5);
				printf(">O>");
				gotoxy(left6,top6);
				printf(">O>");
				
				delay(100);
				
				gotoxy(left1,top1);
				printf("    ");
				gotoxy(left2,top2);
				printf("    ");
				gotoxy(left3,top3);
				printf("    ");
				gotoxy(left,top);
				printf("   ");
				gotoxy(left5,top5);
				printf("   ");
				gotoxy(left6,top6);
				printf("   ");
				
				if(left==70) left=2;
				else left++;
				if(left5==70) left5=2;
				else left5++;
				if(left6==70) left6=2;
				else left6++;
				
				if(left==39 || left5==39 || left6==39)
				{
					gotoxy(65,5);
					printf("SCORE : %d",score);
					score++;
				}
				
				--top1;
				--top2;
				--top3;
				
				// Check collision during jump UP for all players
				if(checkCollision(left, top, left1, top1, left2, top2, left3, top3) ||
				   checkCollision(left5, top5, left1, top1, left2, top2, left3, top3) ||
				   checkCollision(left6, top6, left1, top1, left2, top2, left3, top3))
				{
					gameOver = 1;
					break;
				}
			}
			
			if(gameOver) break;
			
			// Jump down
			for(count=0; count<5; count++)
			{
				gotoxy(left1,top1);
				printf("(00)");
				gotoxy(left2,top2);
				printf("/()\\");
				gotoxy(left3,top3);
				printf("||");
				gotoxy(left,top);
				printf(">O>");
				gotoxy(left5,top5);
				printf(">O>");
				gotoxy(left6,top6);
				printf(">O>");
				
				delay(100);
				
				gotoxy(left1,top1);
				printf("    ");
				gotoxy(left2,top2);
				printf("    ");
				gotoxy(left3,top3);
				printf("   ");
				gotoxy(left,top);
				printf("   ");
				gotoxy(left5,top5);
				printf("      ");
				gotoxy(left6,top6);
				printf("      ");
				
				if(left==70) left=2;
				else left++;
				if(left5==70) left5=2;
				else left5++;
				if(left6==70) left6=2;
				else left6++;
				
				++top1;
				++top2;
				++top3;
				
				// Check collision during jump DOWN for all players
				if(checkCollision(left, top, left1, top1, left2, top2, left3, top3) ||
				   checkCollision(left5, top5, left1, top1, left2, top2, left3, top3) ||
				   checkCollision(left6, top6, left1, top1, left2, top2, left3, top3))
				{
					gameOver = 1;
					break;
				}
			}
			
			if(gameOver) break;
			
			keyValue='s';
			
			gotoxy(left1,top1);
			printf("(00)");
			gotoxy(left2,top2);
			printf("/()\\");
			gotoxy(left3,top3);
			printf("||");
		}
	}

	// Display Game Over message
	if(gameOver)
	{
		clrscr();
		gotoxy(35,12);
		printf("GAME OVER!");
		gotoxy(32,14);
		printf("FINAL SCORE: %d", score);
		gotoxy(30,16);
		printf("Press any key to exit...");
	}
	
	getch();
	return 0;
}
