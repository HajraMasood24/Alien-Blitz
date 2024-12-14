#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy(int x,int y);
void printMaze();
void printEnemy1();
void eraseEnemy1();
void moveEnemy1();
void printEnemy();
void eraseEnemy();
void moveEnemy();
void printEnemy2();
void eraseEnemy2();
void moveEnemy2();
void printplayer();
void eraseplayer();
void moveplayerLeft();
void moveplayerRight();
void moveplayerUp();
void moveplayerDown();
void printCoin();
void eraseCoin();
void pickcoins();
void health();
void setColor(int color);
void shootbullets();
void enemyfiring();
void enemy1firing();
void enemy2firing();
int mainpg();
void resetGameState();
void hideCursor();


int ex2=45, ey2=2;//enemy 3
int ex=6, ey=2;
int ex1=20, ey1=13;
int px=68, py=18;
int cx=30,cy=10; // Coin position
int bx,by;
int bex,bey=-1;
int bex1=-1,bey1;
int bex2=-1,bey2;

int score = 0;  
int d1=1;
int d2=1;
int d3=1;
int Health=100;
bool EnemyisAlive = true;
bool Enemy1isAlive = true;
bool Enemy2isAlive = true;
int health1=50;
int health2=50;
int health3=50;
int op;

int main()
{
    hideCursor();
    setColor(9);
    system("cls");

    while (true) {
        int op = mainpg(); 
        if(op==1){
            resetGameState(); 
            system("cls"); 
            printMaze();  
            printplayer();  
            printCoin();  

            while (true) {
                if (Health == 0) {  
                    system("cls");
                    setColor(12);
                    gotoxy(10, 5);
                    cout << "******************************** GAME OVER ********************************" << endl;
                    gotoxy(10, 6);
                    cout << "*                                                                       *" << endl;
                    gotoxy(10, 7);
                    cout << "*            Oops! You have lost the game! Your health reached zero.      *" << endl;
                    gotoxy(10, 8);
                    cout << "*                                                                       *" << endl;
                    gotoxy(10, 9);
                    cout << "*            Final Score: " << score << "                               *" << endl;
                    gotoxy(10, 10);
                    cout << "*                                                                       *" << endl;
                    gotoxy(10, 11);
                    cout << "***************************************************************************" << endl;
                    cout << "Enter 1 to return to main page" << endl;
                    int option;
                    cin >> option;
                    if (option == 1) {
						system("cls");
                        break;  
                    }
                }

                if (!EnemyisAlive  && !Enemy2isAlive) {  
                    system("cls");
                    setColor(10);
                    gotoxy(10, 5);
                    cout << "******************************* CONGRATULATIONS! *******************************" << endl;
                    gotoxy(10, 6);
                    cout << "*                                                                           *" << endl;
                    gotoxy(10, 7);
                    cout << "*            You have defeated all enemies and won the game!                *" << endl;
                    gotoxy(10, 8);
                    cout << "*                                                                           *" << endl;
                    gotoxy(10, 9);
                    cout << "*            Final Score: " << score << "                                   *" << endl;
                    gotoxy(10, 10);
                    cout << "*                                                                           *" << endl;
                    gotoxy(10, 11);
                    cout << "*******************************************************************************" << endl;
                    cout << "Enter 1 to return to main page" << endl;
                    int option;
                    cin >> option;
                    if (option == 1) {
						system("cls");
                        break;  
                    }
                }
                
                 health();
                setColor(6);
                gotoxy(83,3);
                if(Health>0){
                cout<<"Health:"<<endl;
                gotoxy(83,4); 
                cout<<Health<<endl;
                }
                gotoxy(83,13);
                cout<<"Enemy1 health:"<<endl;
                gotoxy(83,14);
                cout<<health1<<endl;
                gotoxy(83,16);
                
                gotoxy(83,19);
                cout<<"Enemy3 health:"<<endl;
                gotoxy(83,20);
                cout<<health3<<endl;
              
                if (GetAsyncKeyState(VK_LEFT)) {
                    moveplayerLeft();
                }
                if (GetAsyncKeyState(VK_RIGHT)) {
                    moveplayerRight();
                }
                if (GetAsyncKeyState(VK_UP)) {
                    moveplayerUp();
                }
                if (GetAsyncKeyState(VK_DOWN)) {
                    moveplayerDown();
                }
                if (GetAsyncKeyState(VK_SPACE)) {
                    shootbullets();
                }

               
                if (EnemyisAlive) {
                    moveEnemy();
                    Sleep(50);
                    enemyfiring();
                }
                if (Enemy2isAlive) {
                    moveEnemy2();
                    enemy2firing();
                }

                pickcoins();
                health();

                Sleep(10); 
            }
        } 
        if (op == 2) {  
            resetGameState(); 
            system("cls"); 
            printMaze();  
            printplayer();  
            printCoin();  

            while (true) {
                if (Health == 0) {  
                    system("cls");
                    setColor(12);
                    gotoxy(10, 5);
                    cout << "******************************** GAME OVER ********************************" << endl;
                    gotoxy(10, 6);
                    cout << "*                                                                       *" << endl;
                    gotoxy(10, 7);
                    cout << "*            Oops! You have lost the game! Your health reached zero.      *" << endl;
                    gotoxy(10, 8);
                    cout << "*                                                                       *" << endl;
                    gotoxy(10, 9);
                    cout << "*            Final Score: " << score << "                               *" << endl;
                    gotoxy(10, 10);
                    cout << "*                                                                       *" << endl;
                    gotoxy(10, 11);
                    cout << "***************************************************************************" << endl;
                    cout << "Enter 1 to return to main page" << endl;
                    int option;
                    cin >> option;
                    if (option == 1) {
						system("cls");
                        break;  
                    }
                }

                if (!EnemyisAlive && !Enemy1isAlive && !Enemy2isAlive) {  
                    system("cls");
                    setColor(10);
                    gotoxy(10, 5);
                    cout << "******************************* CONGRATULATIONS! *******************************" << endl;
                    gotoxy(10, 6);
                    cout << "*                                                                           *" << endl;
                    gotoxy(10, 7);
                    cout << "*            You have defeated all enemies and won the game!                *" << endl;
                    gotoxy(10, 8);
                    cout << "*                                                                           *" << endl;
                    gotoxy(10, 9);
                    cout << "*            Final Score: " << score << "                                   *" << endl;
                    gotoxy(10, 10);
                    cout << "*                                                                           *" << endl;
                    gotoxy(10, 11);
                    cout << "*******************************************************************************" << endl;
                    cout << "Enter 1 to return to main page" << endl;
                    int option;
                    cin >> option;
                    if (option == 1) {
						system("cls");
                        break;  
                    }
                }
                 health();
                setColor(6);
                gotoxy(83,3);
                cout<<"Health:"<<endl;
                gotoxy(83,4); 
                cout<<Health<<endl;
                gotoxy(83,13);
                cout<<"Enemy1 health:"<<endl;
                gotoxy(83,14);
                cout<<health1<<endl;
                gotoxy(83,16);
                cout<<"Enemy2 health:"<<endl;
                gotoxy(83,17);
                cout<<health2<<endl;
                gotoxy(83,19);
                cout<<"Enemy3 health:"<<endl;
                gotoxy(83,20);
                cout<<health3<<endl;

                
              
                if (GetAsyncKeyState(VK_LEFT)) {
                    moveplayerLeft();
                }
                if (GetAsyncKeyState(VK_RIGHT)) {
                    moveplayerRight();
                }
                if (GetAsyncKeyState(VK_UP)) {
                    moveplayerUp();
                }
                if (GetAsyncKeyState(VK_DOWN)) {
                    moveplayerDown();
                }
                if (GetAsyncKeyState(VK_SPACE)) {
                    shootbullets();
                }

                if (Enemy1isAlive) {
                    moveEnemy1();
                    
                    enemy1firing();
                }
                if (EnemyisAlive) {
                    moveEnemy();
                    enemyfiring();
                }
                if (Enemy2isAlive) {
                    moveEnemy2();
                    enemy2firing();
                }

                pickcoins();
                health();

                Sleep(10); 
            }
        }
        if (op == 3) {  
            resetGameState(); 
            system("cls"); 
            printMaze();  
            printplayer();  
            printCoin();  

            while (true) {
                if (Health == 0) {  
                    system("cls");
                    setColor(12);
                    gotoxy(10, 5);
                    cout << "******************************** GAME OVER ********************************" << endl;
                    gotoxy(10, 6);
                    cout << "*                                                                       *" << endl;
                    gotoxy(10, 7);
                    cout << "*            Oops! You have lost the game! Your health reached zero.      *" << endl;
                    gotoxy(10, 8);
                    cout << "*                                                                       *" << endl;
                    gotoxy(10, 9);
                    cout << "*            Final Score: " << score << "                               *" << endl;
                    gotoxy(10, 10);
                    cout << "*                                                                       *" << endl;
                    gotoxy(10, 11);
                    cout << "***************************************************************************" << endl;
                    cout << "Enter 1 to return to main page" << endl;
                    int option;
                    cin >> option;
                    if (option == 1) {
						system("cls");
                        break;  
                    }
                }

                if (!EnemyisAlive && !Enemy1isAlive && !Enemy2isAlive && score>=500) {  
                    system("cls");
                    setColor(10);
                    gotoxy(10, 5);
                    cout << "******************************* CONGRATULATIONS! *******************************" << endl;
                    gotoxy(10, 6);
                    cout << "*                                                                           *" << endl;
                    gotoxy(10, 7);
                    cout << "*            You have defeated all enemies and won the game!                *" << endl;
                    gotoxy(10, 8);
                    cout << "*                                                                           *" << endl;
                    gotoxy(10, 9);
                    cout << "*            Final Score: " << score << "                                   *" << endl;
                    gotoxy(10, 10);
                    cout << "*                                                                           *" << endl;
                    gotoxy(10, 11);
                    cout << "*******************************************************************************" << endl;
                    cout << "Enter 1 to return to main page" << endl;
                    int option;
                    cin >> option;
                    if (option == 1) {
						system("cls");
                        break;  
                    }
                }
                 health();
                 
                setColor(6);
                gotoxy(83,3);
                cout<<"Health:"<<endl;
                gotoxy(83,4); 
                cout<<Health<<endl;
                gotoxy(83,13);
                cout<<"Enemy1 health:"<<endl;
                gotoxy(83,14);
                cout<<health1<<endl;
                gotoxy(83,16);
                cout<<"Enemy2 health:"<<endl;
                gotoxy(83,17);
                cout<<health2<<endl;
                gotoxy(83,19);
                cout<<"Enemy3 health:"<<endl;
                gotoxy(83,20);
                cout<<health3<<endl;
              
                if (GetAsyncKeyState(VK_LEFT)) {
                    moveplayerLeft();
                }
                if (GetAsyncKeyState(VK_RIGHT)) {
                    moveplayerRight();
                }
                if (GetAsyncKeyState(VK_UP)) {
                    moveplayerUp();
                }
                if (GetAsyncKeyState(VK_DOWN)) {
                    moveplayerDown();
                }
                if (GetAsyncKeyState(VK_SPACE)) {
                    shootbullets();
                }

                if (Enemy1isAlive) {
                    
                    moveEnemy1();
                    enemy1firing();

                }
                if (EnemyisAlive) {
                   
                    moveEnemy();
                    enemyfiring();
                    if(bey==25)
                    {
                    Health-=10;
                    }
                }
                if (Enemy2isAlive) {
                   
                    moveEnemy2();
                    enemy2firing();
                    if(bey2==25)
                    {
                    Health-=10;
                    }
                }

                pickcoins();
                health();

                Sleep(10); 
            }
        } else if (op == 4) {  
            break;
        }
    }

    return 0;
}


void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
int mainpg()
{
    int op;
    setColor(13);
    gotoxy(10,3);
    cout<<"@@@@@@@@@@@@@   ####                                  ####                            @@@@@@@@@@@@@@@ "<<endl;
    gotoxy(10,4);
    cout<<"     @@@@@@@@  ##  ## ##    ####  ####  ##   #       ##   # ##    #### ###### #####   @@@@@@@@"<<endl;
    gotoxy(10,5);
    cout<<"@@@@@@@@@@@@@  ###### ##     ##   #     ###  #       #####  ##     ##    ##     ##    @@@@@@@@@@@@@@@"<<endl;
    gotoxy(10,6);
    cout<<"        @@@@@  ##  ## ##     ##   ##    ## # #       ##   # ##     ##    ##    ##     @@@@@"<<endl;
    gotoxy(10,7);
    cout<<"@@@@@@@@@@@@@  ##  ## ##### ####  ##### ##  ##       #####  ##### ####   ##   #####   @@@@@@@@@@@@@@@ "<<endl;
    setColor(13);
    gotoxy(10,9);
    cout<<"      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    gotoxy(10,10);
    cout<<"                              Defeat the alien invaders and save Earth!"<<endl;
    gotoxy(10,11);
    cout<<"      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    setColor(15);
    gotoxy(2,16);
    cout<<"GAME LEVELS"<<endl;
    gotoxy(4,17);
    cout<<"1.Easy"<<endl;
    gotoxy(4,18);
    cout<<"2.Medium"<<endl;
    gotoxy(4,19);
    cout<<"3.Hard"<<endl;
    gotoxy(2,20);
    cout<<"4.Exit"<<endl;
    cin>>op;
    return op;
}
void resetGameState() {
    ex2 = 45; ey2 = 4; 
    ex = 6; ey = 2;
    ex1 = 20; ey1 = 13;
    px = 66; py = 16;
    cx = 30; cy = 10; 
    bx = by = -1;
    bex = bey = -1;
    bex1 = bey1 = -1;
    bex2 = bey2 = -1;

    score = 0;
    Health = 100;
    EnemyisAlive = true;
    Enemy1isAlive = true;
    Enemy2isAlive = true;
    health1 = 50;
    health2 = 50;
    health3 = 50;
}

void eraseplayer()
{
  	gotoxy(px,py);
	cout<<"        "<<endl;
	gotoxy(px,py+1);
        cout<<"        "<<endl;
	gotoxy(px,py+2);
	cout<<"        "<<endl;
	gotoxy(px,py+3);
	cout<<"        "<<endl;
}


void printplayer()
{	
    setColor(5);
 	gotoxy(px,py);
	cout<<"_::_::_"<<endl;
	gotoxy(px,py+1);
        cout<<"|,   ,|"<<endl;
	gotoxy(px,py+2);
	cout<<"|=| |=|"<<endl;
	gotoxy(px,py+3);
	cout<<"( ) ( )"<<endl;
}

void moveplayerLeft()
{
   if(px>3 )
   {
	eraseplayer();
	px=px-1;
	printplayer();
   }
}

void moveplayerRight()
{
   if (px<72)
   {
	eraseplayer();
	px=px+1;
	printplayer();
   }

}

void moveplayerUp()
{
    if (py > 2 )
    {
	eraseplayer();
	py=py-1;
	printplayer();
    }
}

void moveplayerDown()
{
    if (py < 22)
    {
	eraseplayer();
	py=py+1;
	printplayer();
    }

}
void shootbullets()
{
    bx=px+4;
    by=py-1;
    
    while(by>=2){
        
        gotoxy(bx,by);
    cout<<"*"<<endl;
    Sleep(10);
    gotoxy(bx,by);
    cout<<" "<<endl;
    by=by-1;
    if((by>=ey1 && by<=ey1+3 && by && bx>=ex1 && bx<=ex1+6))
     {
        bx=0;
        by=0;
	    score+=20;
		health2-=10;
		if(health2<=0){
		Enemy1isAlive=false;
        gotoxy(83,23);
        cout<<"Enemy2 is eliminated"<<endl;
        eraseEnemy1();
		health2=0;
        break;
        }
    }
    if(by>=ey && by<=ey+2 && bx>=ex && bx<=ex+4) 
	{
        bx=0;
        by=0;
	    score+=20;
		health1-=10;
		if(health1<=0){
        EnemyisAlive=false;
        gotoxy(83,24);
        cout<<"Enemy1 is eliminated"<<endl;
        eraseEnemy();
		health1=0;
        break;
		}
    }
	if(by>=ey2 && by<=ey2+3  && bx>=ex2 && bx<=ex2+8)
	{
        bx=0;
        by=0;
		score+=20;
		health3-=10;
		if(health3<=0){
        Enemy2isAlive=false;
        gotoxy(83,25);
        cout<<"Enemy3 is eliminated"<<endl;
        eraseEnemy2();
		health3=0;
        break;
		}
	}
	if(by==cy+1 && bx==cx)
	{
		bx=0;
		by=0;
	}
	
	}
}

void printEnemy1()
{
    setColor(4);
	gotoxy(ex1,ey1);
         cout<<"  ____  "<<endl;
	gotoxy(ex1,ey1+1);
	 cout<<" : -- : "<<endl;
	gotoxy(ex1,ey1+2);
	 cout<<"  ....   "<<endl;
	gotoxy(ex1,ey1+3);
	 cout<<"  ^  ^   "<<endl;
}


void eraseEnemy1()
{
	
	gotoxy(ex1,ey1);
         cout<<"        "<<endl;
	gotoxy(ex1,ey1+1);
	 cout<<"         "<<endl;
	gotoxy(ex1,ey1+2);
	 cout<<"        "<<endl;
	gotoxy(ex1,ey1+3);
	 cout<<"         "<<endl;
}

void moveEnemy1()
{
	eraseEnemy1();
	ex1 += d1;
		
	if(ex1 >= 60 || ex1 <=20)
	{
		d1=-d1;
		ex1 += d1;
	}
	
	printEnemy1();
}
void enemy1firing()
{
	 if (Enemy1isAlive){
		if(bex1==-1)
		{	
		bex1=ex1+9;
		bey1=ey1+2;
		}
	 
	else{
		gotoxy(bex1,bey1);
		cout<<" "<<endl;
    	bex1=bex1+1;
	
	if(bex1 < 79)
	 { 
    
    gotoxy(bex1,bey1);
	
    cout << "_"; 
	 
	    Sleep(50);
    
	
		if((bey1>=py && bey1<=py+3 && bex1>=px && bex1<=px+6))
		{
		Health-=10;
		 bex1=-1;
		
		}
        
	 }
		else{
			bex1=-1;
		}
    }
    
    }
    
}

void eraseEnemy()
{
	gotoxy(ex,ey);
	cout<<"      "<<endl;
	gotoxy(ex,ey+1);
        cout<<"      "<<endl;
	gotoxy(ex,ey+2);
        cout<<"      "<<endl;
}

void printEnemy()
{
	setColor(4);
	gotoxy(ex,ey);
	cout<<" ___  "<<endl;
	gotoxy(ex,ey+1);
    cout<<"('_') "<<endl;
	gotoxy(ex,ey+2);
    cout<<" ^ ^  "<<endl;

}

void moveEnemy()
{
	eraseEnemy();
	ey += d2;
		
	if(ey >=13 || ey <=2)
	{
		d2=-d2;
		ey += d2;
	}
	
	printEnemy();

}
void enemyfiring()
{
	if (EnemyisAlive){
		if(bey==-1)
		{	
		bex=ex+2;
		bey=ey+4;
		}
	 
	else{
		gotoxy(bex,bey);
		cout<<" "<<endl;
    	bey=bey+1;
	
	if(bey < 26)
	 { 
    
    gotoxy(bex,bey);
	
    cout << "|"; 
	
        
    Sleep(50);
        
		if((bey>=py && bey<=py+3 && bex>=px && bex<=px+6))
		{
		Health-=10;
		bey=-1;
		}
        
	 }
		else{
			bey=-1;
		}
    }
    
} 
}

void eraseEnemy2()
{
	gotoxy(ex2,ey2);
	cout<<"         "<<endl;
	gotoxy(ex2,ey2+1);
        cout<<"         "<<endl;
	gotoxy(ex2,ey2+2);
        cout<<"         "<<endl;
	gotoxy(ex2,ey2+3);
	cout<<"         "<<endl;
}

void printEnemy2()
{
	setColor(4);
	gotoxy(ex2,ey2);
	cout<<"  ====   "<<endl;
	gotoxy(ex2,ey2+1);
        cout<<"== >< == "<<endl;
	gotoxy(ex2,ey2+2);
        cout<<"======== "<<endl;
	gotoxy(ex2,ey2+3);
	cout<<"  =  =   "<<endl;
}

void moveEnemy2()
{
	eraseEnemy2();
	ey2 += d3;
	ex2 += d3;
	
	if(ex2 >=50 || ex2<=5 ) 
	{
		d3=-d3;
	}
	 if(ey2 >= 17 || ey2 <= 2)
   	 {
       		 d3 = -d3; 
   	 }

	
	printEnemy2();
}
void enemy2firing()
{
	if (Enemy2isAlive){
        if(bex2==-1)
        {
            bex2=ex2;
            bey2=ey2+2;
        }
        else{
          gotoxy(bex2,bey2);
            cout<<" "<<endl;
            bex2=bex2-1;
            bey2=bey2+1;  
        
	if (bex2>2 && bey2<25 ) { 
    
        gotoxy(bex2,bey2);
	
        cout << "/"; 
        
	    Sleep(50);
        
        
    
    if((bey2>=py && bey2<=py+3 && bex2>=px && bex2<=px+6))
     {
	   Health-=10;
		bex2=-1;
    }
    }
    else{
        bex2=-1;
    }
    }
    }
}
void printCoin()
{
	setColor(14);
    gotoxy(cx, cy);
    cout<<"o";
	
}

void eraseCoin()
{
    gotoxy(cx, cy);
    cout<<" ";
}

void pickcoins()
{
	if (bx==cx && by==cy){
		printCoin();
		pickcoins();
	}
    if (cx >=px && cx <= px+6 && cy >= py && cy <= py+3)
    	{
         eraseCoin();
	 score += 10;
	 Health+= 10; 
	
	 cx += 15;
	 cy += 7;
	 if (cx > 72 || cy >25)
	 {
		cx=13;
		cy=5;
		
	  }
	 printCoin();
	 pickcoins();
       	 
        }
		setColor(6);
	 gotoxy(83,7);
    	 cout << "Score: " <<endl;
		 gotoxy(83,8);
		 cout<< score << endl;
	
}

void health()
{
	
	if ((px >= ex1 && px <= ex1 + 6 && py >= ey1 && py <= ey1 + 3) || (px >= ex && px <= ex + 4 && py >= ey && py <= ey + 2) || (px >= ex2 && px <= ex2 + 8 && py >= ey2 && py <= ey2 + 3)) {  

        Health -= 10;
       		if (Health < 0) {
		Health = 0;
		}
	}
	
	
}


void printMaze()
{
    setColor(9);
	gotoxy(1,1);
	cout<<"######################################################################################################"<<endl;
	gotoxy(1,2);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,3);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,4);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,5);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,6);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,7);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,8);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,9);
	cout<<"##                                                                             #######################"<<endl;
	gotoxy(1,10);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,11);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,12);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,13); 
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,14);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,15);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,16);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,17);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,18);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,19);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,20);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,21);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,22);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,23);
    cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,24);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,25);
	cout<<"##                                                                             ##                   ##"<<endl;
	gotoxy(1,26);
	cout<<"###########       #############                ###########                     ##                   ##"<<endl;
	gotoxy(1,27);
	cout<<"##    #  ##       ##   ###   ##########       ##   o    ## ########    ##########                   ##"<<endl;
	gotoxy(1,28);
    cout<<"## #     ##       ##  #   #  ##  #   ###########      o ## # ######    #   *   ##                   ##"<<endl;
	gotoxy(1,29);
	cout<<"##       ##  #######         ##    # ##  o       o      ## ## ## ## #### *   * ##                   ##"<<endl;
	gotoxy(1,30);
	cout<<"##  ||   ##  #######    {}   ##  []  ##     888         ## ###  ### ##    $$   ##                   ##"<<endl;
	gotoxy(1,31);
	cout<<"######################################################################################################"<<endl;
}



void gotoxy(int x,int y)
{
 COORD coordinates;
 coordinates.X = x;
 coordinates.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE; 
    SetConsoleCursorInfo(consoleHandle, &info);
}