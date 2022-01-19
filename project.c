#include <stdio.h>
#include <string.h>
 int choice=-1;
 int swithdrawall=0;
 int m=0;
 int useless[1]={0};
 int canprice[5]={10,6,5,8,7}; //%d
 int NoOfDrinksAvailable[6]={2019,5,1,2,1,9};
 char products[5][20]={"Juice","Cola","Tea","Water","Coffee"};

 int availability(int);
 int equal(void);
void VendingMachine(int m){

    printf("*---------------------------*\n");
    printf("|      Vending Machine      |\n");
    printf("*---------------------------*\n");
    printf("|   A    B    C    D    E   |\n");
    printf("|  $%d  $ %d  $ %d  $ %d  $ %d  |\n",canprice[0],canprice[1],canprice[2],canprice[3],canprice[4]);
    printf("|  [%c]",availability(1));
    printf("  [%c]",availability(2));
    printf("  [%c]",availability(3));
    printf("  [%c]",availability(4));
    printf("  [%c]",availability(5));
    printf("  |\n");
    printf("*---------------------------*\n");
    if (m>=0 && m<=9)
    printf("|                    [$ %d]",m);
    else
    printf("|                    [$%d]",m);
    printf("  |\n");
    printf("|                           |\n");
    printf("|           [=%c=]           |\n",equal());
    printf("*---------------------------*\n");

}

void MainMenu(){
    printf("\n");
   // int choice;
    printf("What would you like to do?\n");
    printf("1. Read product information\n");
    printf("2. Insert coin\n");
    printf("3. Press product button\n");
    printf("4. Press return button\n");
    printf("9. Open service menu (code required)\n");
    printf("0. Quit\n");
    printf("Your choice:");
}

void ProductInfo(){

    printf("\n");
    printf("(1) The displayed products are:\n");
    printf("A. %s ($%d)\n",products[0],canprice[0]);
    printf("B. %s ($%d)\n",products[1],canprice[1]);
    printf("C. %s ($%d)\n",products[2],canprice[2]);
    printf("D. %s ($%d)\n",products[3],canprice[3]);
    printf("E. %s ($%d)\n",products[4],canprice[4]);
    //printf("\n");
}
void /*int*/ choice1(){
  // int choice;
    ProductInfo();
    MainMenu();
    scanf("%d",&choice);
    if (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=9 && choice!=0){
            printf("Invalid choice!\n");

    }

}
void InsertCoin(){

    printf("\n");
    printf("(2) Which coin would you like to insert?\n");
    printf("1. $1\n");
    printf("2. $2\n");
    printf("3. $5\n");
    printf("4. $10\n");
    printf("0. Go back\n");
    printf("Your choice:");
}
    int ichoice=1;
void choice2(){

    int coin[5]={1,2,5,10,0};

  while (ichoice!=0){

    InsertCoin();


    scanf("%d",&ichoice);

    if (ichoice>=1 && ichoice<=4){
        printf("You have inserted $%d.\n",coin[ichoice-1]);
        m=m+coin[ichoice-1];
        swithdrawall=swithdrawall+coin[ichoice-1];
      // printf("swithdrawall amount %d\n",swithdrawall);
        if (m>=0 && m<=99){
            printf("\n");
            VendingMachine(m);}


    }

    else if (ichoice==0){
            printf("Going back!\n");
            printf("\n");
            VendingMachine(m);
            //MainMenu();

    }
    else {   //printf("\n");
            printf("Invalid choice!\n");
            // printf("\n");
           //  choice2();

    }

  }
}
 void PressProductButton(){ //ABCDE

    printf("\n");
    printf("(3) Which product button would you like to press?\n");
    printf("1. A\n");
    printf("2. B\n");
    printf("3. C\n");
    printf("4. D\n");
    printf("5. E\n");
    printf("0. Go back\n");
    printf("Your choice:");

}
int pchoice=-1;//product choice
char button[6]={'0','A','B','C','D','E'};
int temp=0;
int revenue=0;
void choice3(){
   // int storeavailability=0;
    PressProductButton();
    while (pchoice!=0 && pchoice!=1 && pchoice!=2 && pchoice!=3 && pchoice!=4 && pchoice!=5){

      scanf("%d",&pchoice);
     if (pchoice!=0 && pchoice!=1 && pchoice!=2 && pchoice!=3 && pchoice!=4 && pchoice!=5){
      printf("Invalid choice!\n");
      PressProductButton();
     }
    }
     // printf("\n");
        if (pchoice>=0 && pchoice<=5){
            printf("You have pressed button %c.\n",button[pchoice]);
            if (pchoice==0)
                printf("Going back!\n");
            else {
                temp=m;
                if (m>=canprice[pchoice-1]){
                  m=m-canprice[pchoice-1];
                  revenue+=canprice[pchoice-1];

                }
             printf("\n");
             VendingMachine(m);}}
        else {
        printf("Invalid choice!\n");
       // choice3();
    }


  //  printf("\n");
}


void choice4(){
    printf("\n");
    printf("(4) Return button is pressed.\n$%d has been returned.\n",m);
    swithdrawall-=m;
  //  printf("swithdrawall amount2 %d\n",swithdrawall);
    m=0;
    printf("\n");
    VendingMachine(0);
    //MainMenu();
}

void s1(){
    printf("\n");
    printf("(9-1) Machine status\n");
    printf("Amount of revenue: $%d\n",revenue);
    printf("Amount of inserted coins: $%d\n",m);
    printf("Product information:\n");
    if (NoOfDrinksAvailable[1]==0) printf("A. %s ($%d) (sold out)\n",products[0],canprice[0]);
    else  printf("A. %s ($%d) (%d left)\n",products[0],canprice[0],NoOfDrinksAvailable[1]);

    if (NoOfDrinksAvailable[2]==0) printf("B. %s ($%d) (sold out)\n",products[1],canprice[1]);
    else printf("B. %s ($%d) (%d left)\n",products[1],canprice[1],NoOfDrinksAvailable[2]);

    if (NoOfDrinksAvailable[3]==0) printf("C. %s ($%d) (sold out)\n",products[2],canprice[2]);
    else printf("C. %s ($%d) (%d left)\n",products[2],canprice[2],NoOfDrinksAvailable[3]);

    if (NoOfDrinksAvailable[4]==0) printf("D. %s ($%d) (sold out)\n",products[3],canprice[3]);
    else printf("D. %s ($%d) (%d left)\n",products[3],canprice[3],NoOfDrinksAvailable[4]);

    if (NoOfDrinksAvailable[5]==0) printf("E. %s ($%d) (sold out)\n",products[4],canprice[4]);
    else printf("E. %s ($%d) (%d left)\n",products[4],canprice[4],NoOfDrinksAvailable[5]);

  //  printf("\n");
}
int rchoice=-1;
void s3(){

  printf("\n");

  printf("(9-3) Which product would you like to refill?\n");
  printf("1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\n");
  printf("Your choice:");
  scanf("%d",&rchoice);

  if (rchoice!=1 && rchoice!=2 && rchoice!=3 && rchoice!=4 && rchoice!=5 && rchoice!=0) {
    printf("Invalid choice!\n");
    //s3();
  }
  if (rchoice>=1 && rchoice<=5){

    NoOfDrinksAvailable[rchoice]=10;
    printf("You have refilled product %c to full.\n",button[rchoice]);
    //rchoice=-1;

  }
  else if (rchoice==0)
    {
      //rchoice=-1;
      printf("Going back!\n"); }
}

int cchoice=-1;
void s4(){
   //change product;
  printf("\n");
  char productname[20];
  printf("(9-4) Which product would you like to change?\n");
  printf("1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\n");
  printf("Your choice:");
  scanf("%d",&cchoice);

   if (cchoice!=1 && cchoice!=2 && cchoice!=3 && cchoice!=4 && cchoice!=5 && cchoice!=0) {
     printf("Invalid choice!\n");
     //scanf("%d",&cchoice);
     return;

   }

    if (cchoice>=1 && cchoice<=5){
      printf("You are changing product %c.\n\n",button[cchoice]);
      printf("Enter new product name:");
      scanf("%s",productname);
      strcpy(products[cchoice-1],productname);
      printf("Enter new product price:");
      scanf("%d",&canprice[cchoice-1]);
      NoOfDrinksAvailable[cchoice]=10;
      printf("The new product %c has been filled to full.\n",button[cchoice]);
     // cchoice=-1;
    }

    else if (cchoice==0)
      printf("Going back!\n");
     // cchoice=1;
}

void ServiceMenu(){//newline

    printf("\n");
    printf("(9) What would you like to do?\n");
    printf("1. Inspect machine status\n");
    printf("2. Withdraw all money\n");
    printf("3. Refill product\n");
    printf("4. Change product\n");
    printf("0. Go back\n");
    printf("Your choice:");//newline ends
}
/*void ServiceMenu(){

    printf("\n");
    printf("(9) What would you like to do?\n");
    printf("1. Inspect machine status\n");
    printf("2. Withdraw all money\n");
    printf("3. Refill product\n");
    printf("4. Change product\n");
    printf("0. Go back\n");
    printf("Your choice:");*/

  int schoice=-1; int goingback=0;
void SMSchoice(){

  while (schoice!=0){

    scanf("%d",&schoice);

    while (schoice!=1 && schoice!=2 && schoice!=3 && schoice!=4 && schoice!=0){
      printf("Invalid choice!\n");
      ServiceMenu();
      scanf("%d",&schoice);
    }

    if  (schoice==1){
        s1();
        ServiceMenu();
        scanf("%d",&schoice);
        if (schoice!=1 && schoice!=2 && schoice!=3 && schoice!=4 && schoice!=0){
          printf("Invalid choice!\n");
          continue;
        }
         // scanf("%d",&schoice);
    }

    if (schoice==2){
      printf("\n");
      printf("(9-2) All money is being withdrawn.\n $%d is withdrawn.\n",swithdrawall);
      swithdrawall=0;
      m=0;
      revenue=0;
      ServiceMenu();
      if (schoice!=1 && schoice!=2 && schoice!=3 && schoice!=4 && schoice!=0){
          printf("Invalid choice!\n");
          continue;
      }
    }

    if (schoice==3){
      s3();
      while (rchoice!=1 && rchoice!=2 && rchoice!=3 && rchoice!=4 && rchoice!=5 && rchoice!=0)
        s3();

      ServiceMenu();
      if (schoice!=1 && schoice!=2 && schoice!=3 && schoice!=4 && schoice!=0){
          printf("Invalid choice!\n");
          continue;
      }
    }

    if (schoice==4){
      s4();
      while  (cchoice!=1 && cchoice!=2 && cchoice!=3 && cchoice!=4 && cchoice!=5 && cchoice!=0)
        s4();

      ServiceMenu();
      if (schoice!=1 && schoice!=2 && schoice!=3 && schoice!=4 && schoice!=0){
          printf("Invalid choice!\n");
          continue;
      }
    }

    if (schoice==0 && goingback==0)
      {
        printf("Going back!\n");
          goingback=1;
          continue;
        }
  }
}


 int accesscode;
void OpeningServiceMenu(){

    printf("\n");
    printf("(9) Opening service menu. Access code is required.\n");
    printf("Enter access code: ");
    scanf("%d",&accesscode);
    if (accesscode!=1110 && accesscode!=001110) {
        printf("Incorrect code!\n");

    }
    else {
      printf("Correct code!\n");
      ServiceMenu();
      SMSchoice();}

}


int main(void){

    VendingMachine(m);


while (choice!=0 ){

   MainMenu();
   scanf("%d",&choice);

    if (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=9 && choice!=0){
        printf("Invalid choice!\n");

        continue;
    }

    if (choice==1){
             choice1();
               if (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=9 && choice!=0)
                  continue;
            }


      if (choice==2) {
        choice2();
       if (ichoice==0) {ichoice=1;continue;};
    }

      if (choice==3){
        choice3();
        if (pchoice==0) {pchoice=-1;continue;}
    }

      if (choice==4){
        choice4();
        continue;
    }

    if (choice==9){
      OpeningServiceMenu();
      if ((accesscode!=1110 && accesscode!=001110) || schoice==0){
        goingback=0;
        printf("\n");
        VendingMachine(m);
        continue;

        }

    }


  }

  return 0;
}


    int forOnce=0; int tempdrinks=0; int equalreturn;
int equal(){

    if (forOnce==0){
        forOnce=1;
        equalreturn='=';
        return '=';
        }
    else if  (choice==4){
        equalreturn='=';}

    else if (ichoice>=0 && ichoice<=5 && pchoice==0){
          equalreturn='=';
         pchoice=-1;
    }
    else if (canprice[pchoice-1]<=temp && tempdrinks!=0){
            temp=-100;
            equalreturn=button[pchoice];
            pchoice=-1;}
    else
    {

         equalreturn='=';
    }


  return equalreturn;
}

int availability(int i){
    int forreturn;

    if (m>=canprice[i-1] && NoOfDrinksAvailable[i]>0 && choice!=4)
            forreturn='O';

    else if (NoOfDrinksAvailable[i]==0)
            forreturn='X';

    else
            forreturn=' ';

    if (temp>=canprice[i-1] && pchoice==i)
            {
                    tempdrinks=NoOfDrinksAvailable[i];
                    NoOfDrinksAvailable[i]--;

                    if (NoOfDrinksAvailable[i]==0)
                        forreturn='X';
                    else if (m>=canprice[i-1])
                        forreturn='O';}

    return forreturn;
}


