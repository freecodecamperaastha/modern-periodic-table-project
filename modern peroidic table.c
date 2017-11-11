#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void signin();
void signup();
void dealy();
void home();
void table();
void atomic();
void symbol();
int main()
{
printf("\t\tWELCOME TO MODERN PERIODIC TABLE PROJECT DESIGNED BY AASTHA VASHISTHA(IT-A)\n");
int n;
printf("\t\t1.PRESS 1 FOR SIGNUP\n\t\t2.PRESS 2 FOR SIGNIN\n\t\t3.PRESS 3 FOR EXIT\n");
    while(1){

    printf("\n\t\tENTER YOUR CHOICE: ");
    scanf("%d",&n);

    switch(n){
        case 1:signup();
               break;
        case 2:signin();
               break;
        case 3:exit(1);
    }
    }
    return 0;
}	
void signup()
{
	FILE *fp;
    fp=fopen("detail.txt","a");
    char user[10],pass[10];
    printf("\t\tENTER USERNAME: ");
    scanf("%s",user);
    printf("\t\tENTER PASSWORD: ");
    scanf("%s",pass);
    fprintf(fp,"%s\t%s\n",user,pass);
    fclose(fp);
}
void signin()
{
	system("cls");
	char user[10],pass[10];
    char fuser[10],fpass[10];
    int f,i=0;
    char ch;
    printf("\t\tENTER USERNAME: ");
    scanf("%s",user);
    printf("\t\tENTER PASSWORD(should be maximum of 10 characters): ");
    //scanf("%s",pass);
    while((ch=getch())!=13)
	{
	pass[i]=ch;
	printf("*");
	i++;
	}   //    for password in asterik
	pass[i]='\0';
	FILE *fp;
    fp=fopen("detail.txt","r");
	while((fscanf(fp,"%s\t%s\n",fuser,fpass))!=-1)
    {
		if(strcmp(user,fuser)==0 && strcmp(pass,fpass)==0)
    	{
		f=1;
    	break;
    }
}
    if(f==1){
    	printf("\n\t\tloading\n");
	for(i=0;i<3;i++)
	delay(1);
    printf("\n\t\tWelcome %s\n",user);
	home();
	}
    else
    printf("\n\t\tInvalid Username or Password\n");
    fclose(fp);
}
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
void home()
{
   printf("\n\t\tWELCOME TO EXOPLORE MODERN PEROIDIC TABLE\n");
	printf("\n\t\t1.PRESS 1 FOR VIEWING WHOLE TABLE\n\t\t2.PRESS 2 FOR SEARCHING BY ATOMIC NUMBER\n\t\t3.PRESS 3 FOR SEARCHING BY CHEMICAL NAME\n\t\t4.PRESS 4 FOR EXIT\n");
	while(1)
	{
		int c;
		printf("\n\t\tENTER YOUR CHOICE: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:table();
					break;
			case 2:atomic();
					break;
			case 3:symbol();
					break;
			case 4:exit(1);
		}
	}
}
void table()
{
	system("cls");
	char ele[10],sy[10];
	int i,at;
	FILE *fp;
	fp=fopen("table.txt","r");
	 for(i=0;i<118;++i){
    fscanf(fp,"%s\t%d\t%s\n",ele,&at,sy);
    printf("%s\t%d\t%s\n",ele,at,sy);
	}
	printf("\n\t\t1.PRESS 1 FOR VIEWING WHOLE TABLE\n\t\t2.PRESS 2 FOR SEARCHING BY ATOMIC NUMBER\n\t\t3.PRESS 3 FOR SEARCHING BY CHEMICAL NAME\n\t\t4.PRESS 4 FOR EXIT\n");
	fclose(fp);
}
void atomic()
{
	system("cls");
	char ele[10],sy[10];
	int i,at;
	FILE *fp;
	fp=fopen("table.txt","r");
	 char fele[10],fsy[10];
    int fat;
    printf("\n\t\tENTER ATOMIC NUMBER: ");
    scanf("%d",&fat);
    for(i=0;i<118;++i)
    {
    	fscanf(fp,"%s\t%d\t%s\n",ele,&at,sy);
    	if(fat==at)
    	printf("\n\t\tELEMENT: %s\n\t\tATOMIC NUMBER: %d\n\t\tCHEMICAL NAME: %s\n",ele,at,sy);
    	
	}
	printf("\n\t\t1.PRESS 1 FOR VIEWING WHOLE TABLE\n\t\t2.PRESS 2 FOR SEARCHING BY ATOMIC NUMBER\n\t\t3.PRESS 3 FOR SEARCHING BY CHEMICAL NAME\n\t\t4.PRESS 4 FOR EXIT\n");
	fclose(fp);	
}
void symbol()
{
	system("cls");
	char ele[10],sy[10];
	int i,at;
	FILE *fp;
	fp=fopen("table.txt","r");
	 char fele[10],fsy[10];
    int fat;
    printf("\n\t\tENTER CHEMICAL NAME WITH INITIAL LETTER IN CAPITAL: ");
	scanf("%s",fsy);
	for(i=0;i<118;++i)
	{
	    fscanf(fp,"%s\t%d\t%s\n",ele,&at,sy);
    	if(strcmpi(fsy,sy)==0)
    	printf("\n\t\tELEMENT: %s\n\t\tATOMIC NUMBER: %d\n\t\tCHEMICAL NAME: %s\n",ele,at,sy);
		
	}
	printf("\n\t\t1.PRESS 1 FOR VIEWING WHOLE TABLE\n\t\t2.PRESS 2 FOR SEARCHING BY ATOMIC NUMBER\n\t\t3.PRESS 3 FOR SEARCHING BY CHEMICAL NAME\n\t\t4.PRESS 4 FOR EXIT\n");
	fclose(fp);
}


