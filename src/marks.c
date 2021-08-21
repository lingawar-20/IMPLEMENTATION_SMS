 #include "marks.h"
 
 void marks()
{
 m a,b;
 r c,d;
 int flag,tot,s1,s2,s3,s4,t1;
 char reg[10],g[2];
 flag=0;
 tot=s1=s2=s3=s4=t1=0;
 f1=fopen("c:\\student/result.dat","rb");
 if(f1==NULL)
 {
 printf("File can not open an error occored press any key to continue...");
 getch();
 fclose(f1);
 exit(0);
 }
 f2=fopen("C:\\student/main.dat","rb");
 if(f2==NULL)
 {
 printf("File can not open.Make sure your database is correpted press any key to continue...");
 getch();
 fclose(f1);
 exit(0);
 }
 clrscr();
 gotoxy(20,3);printf("Form for Marks Entry Of A Student");
 gotoxy(20,4);printf("---------------------------------") ;
 gotoxy(5,6); printf("Enter Student Registration no:-");fflush(stdin);gets(reg);
 while(fread(&a,size1,1,f2)==1)
 {
 if(strcmp(a.regn,reg)==0)
 { flag=1;
 break;
 }
 }
 while(fread(&c,size2,1,f1)==1)
 {
 if(strcmp(c.regn,reg)==0)
 {
 flag=2;
 break;
 }
 }
 if(flag==0)
 {
 gotoxy(10,40);printf("This Registration No Not Found....Press Any Key");
 getch();
 fclose(f1);
 fclose(f2);
 }
 else if(flag==2)
 {
 gotoxy(5,16);printf("The Marks Of This Candidate Already Exist....");
 getch();
 }
 else if(flag==1)
 {
 fclose(f1);
 f1=fopen("c:\\student/result.dat","ab");
 strcpy(d.regn,reg);
 gotoxy(5,8); printf("Enter Module 1 Marks :-");fflush(stdin);scanf("%d",&s1);
 gotoxy(5,10);printf("Enter Module 2 Marks :-");fflush(stdin);scanf("%d",&s2);
 gotoxy(5,12);printf("Enter Module 3 Marks :-");fflush(stdin);scanf("%d",&s3);
 gotoxy(5,14);printf("Enter Module 4 Marks :-");fflush(stdin);scanf("%d",&s4);
 t1=s1+s2+s3+s4;
 tot=t1/4;
 fflush(stdin);
 if(tot<50){g[0]='F';}else if(tot<55){g[0]='D';}else if(tot<64){g[0]='C';}else if(tot<75){g[0]='B';}else if(tot<85){g[0]='A';}else{g[0]='S';}
 gotoxy(5,16);printf("Total Marks Of Student :- %d",t1);
 gotoxy(5,17);printf("Grade Of The Student :- %s",g);
 d.m1 =s1;d.m2=s2;d.m3=s3;d.m4=s4;
 d.total=t1;
 fflush(stdin);
 strcpy(d.grade,g);
 fwrite(&d,size2,1,f1);
 fclose(f1);
 getch();
 }
 form1();
}
