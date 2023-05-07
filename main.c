#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>

void MenuYazdir()
{
	printf("\tMen�\n");
	printf("1-) Kay�t Ekle\n");
	printf("2-) ��renci Ara\n");
	printf("3-) Kay�tlari Sil\n");
	printf("4-) Kay�t De�i�tir\n");
	printf("5-) Kay�tlar� Listele\n");
	printf("6-) Ba�ar� Notlar�n� Hesapla\n");
	printf("7-) Kay�tlar� S�rala\n");
	printf("8-) �statistiki Bilgiler\n");
	printf("9-) ��k��\n");
	printf("\nBir Se�im Yap�n�z : ");
}

void Menu2Yazir()
{
	printf("De�i�ritmek �sted�iniz Veriyi Se�in : \n");
	printf("1-) �sim\n");
	printf("2-) Soyisim\n");
	printf("3-) No\n");
	printf("4-) Notlar\n");
	printf("5-) De�i�tirmek istedi�im bir veri yok\n");
	printf("Bir Se�im Yap�n�z : ");
}

int NotHesapla(float sinav1,float sinav2, float sinavFinal)
{
	float Not = (sinav1/5)+((sinav2*3)/10)+(sinavFinal/2);
	return round(Not);
}

struct ogrenci	// ogrenci yapisi
 	{
 	char isim[15];
 	char soyisim[15];
 	int no;
 	int vize1;
 	int vize2;
 	int final;
 	int nott;
 	};

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Turkish");	// t�rk�e karakter kullanma
	
	int sayac;
	struct ogrenci ogrenciler[100];
	
	FILE *f;
	
	if(f=fopen("sayac.txt","r"))
	{
		fscanf(f,"%d",&sayac);
	}
	else
	{
		f = fopen("sayac.txt","w");
		fprintf(f,"0");
		sayac = 0;
	}
	fclose(f);
	
	int i;
	FILE *fliste;
	if(fliste=fopen("liste.txt","r"))
	{
		for(i=0;i<sayac;i++)
		{
		fscanf(fliste,"%s\n",ogrenciler[i].isim);
		fscanf(fliste, "%s\n",ogrenciler[i].soyisim);
		fscanf(fliste, "%d\n",&ogrenciler[i].no);
		fscanf(fliste, "%d\n",&ogrenciler[i].vize1);
		fscanf(fliste, "%d\n",&ogrenciler[i].vize2);
		fscanf(fliste, "%d\n",&ogrenciler[i].final);
		fscanf(fliste, "%d\n",&ogrenciler[i].nott);
		}
	}
	else
	{
		fliste = fopen("liste.txt","a");	
	}
	fclose(fliste);
	//---------------------------------------------
	int secim;
	do
	{
		MenuYazdir();
		scanf("%d",&secim);
		if(secim <=9 && secim >=1)
		{
			if(secim==1)
			{
				if(sayac<=100)
				{
					printf("Ad� : ");
					scanf("%s",ogrenciler[sayac].isim);
					printf("Soyad� : ");
					scanf("%s",ogrenciler[sayac].soyisim);
					
					int noA;
					printf("No : ");
					scanf("%d",&noA);

					int sart2 = 0;
					for(i=0;i<sayac;i++){if(noA==ogrenciler[i].no){sart2++;}}
					
					if(sart2>0)
					{
						int donguKir = 0;
						do
						{
							donguKir = 0;
							printf("Bu No ya sahip bir ogrenci zaten var ba�ka bir no giriniz ...\n");
							printf("No : ");
							scanf("%d",&noA);
							for(i=0;i<sayac;i++){if(noA == ogrenciler[i].no){donguKir++;}}
						}	while(donguKir != 0);
					}
					
					ogrenciler[sayac].no = noA;
					
					float sinav1A,sinav2A,finalA;
					printf("1. S�nav Notu : ");
					scanf("%f",&sinav1A);
					printf("2. S�nav Notu : ");
					scanf("%f",&sinav2A);
					printf("Final Notu : ");
					scanf("%f",&finalA);
					
					int sart = 0;
					if(sinav1A<0 || sinav1A>100 || sinav2A<0 || sinav2A>100 || finalA<0 || finalA>100 )
					{
						printf("Hatal� Not Giri�i Yapt�n�z . Notlar 0-100 aral���nda olmal�d�r .\nL�tfen Tekrar Not Giriniz ... \n ");
						while(sart != 1)
						{
							
							printf("1. S�nav Notu : ");
							scanf("%f",&sinav1A);
							printf("2. S�nav Notu : ");
							scanf("%f",&sinav2A);
							printf("Final Notu : ");
							scanf("%f",&finalA);
							
							if(sinav1A<0 || sinav1A>100 || sinav2A<0 || sinav2A>100 || finalA<0 || finalA>100 )
								{printf("Hatal� Not Giri�i Yapt�n�z . Notlar 0-100 aral���nda olmal�d�r .\nL�tfen Tekrar Not Giriniz ... \n ");}
							else{sart++;}
						}
					}
					
					printf("\n");
					
					
					ogrenciler[sayac].vize1 = sinav1A;
					ogrenciler[sayac].vize2 = sinav2A;
					ogrenciler[sayac].final = finalA;
					ogrenciler[sayac].nott = NotHesapla(sinav1A,sinav2A,finalA);
					sayac++;
				}
				else
				{
					printf("S�n�f Mevcudu Dolu !!! \n");
				}
			}
			else if(secim==2)
			{
				int x;
				printf("Bilgilerini g�r�nt�lemek istedi�iniz ��rencinin numaras�n� giriniz : ");	
				scanf("%d",&x);
				int indeks2,i;
				for(i=0;i<sayac;i++)
				{
					if(x == ogrenciler[i].no){indeks2 = i;}
				}
				
				printf("Ad� : %s\nSoy Ad� : %s\nNo : %d\n",ogrenciler[indeks2].isim,ogrenciler[indeks2].soyisim,ogrenciler[indeks2].no);
				printf("1. S�nav : %d\n2. S�nav : %d\nFinal : %d\n",ogrenciler[indeks2].vize1,ogrenciler[indeks2].vize2,ogrenciler[indeks2].final);
				printf("Notu : %d\n",ogrenciler[indeks2].nott);
				
				if(ogrenciler[indeks2].nott>=90) {printf("Harf Notu : AA\nDurum : Gecti\n");}	
				if(ogrenciler[indeks2].nott>=85 && ogrenciler[indeks2].nott <90) {printf("Harf Notu : AB\nDurum : Gecti\n");}
				if(ogrenciler[indeks2].nott>=75 && ogrenciler[indeks2].nott <85) {printf("Harf Notu : BB\nDurum : Gecti\n");}
				if(ogrenciler[indeks2].nott>=70 && ogrenciler[indeks2].nott <75) {printf("Harf Notu : CB\nDurum : Gecti\n");}
				if(ogrenciler[indeks2].nott>=60 && ogrenciler[indeks2].nott <70) {printf("Harf Notu : CC\nDurum : Gecti\n");}
				if(ogrenciler[indeks2].nott>=55 && ogrenciler[indeks2].nott <60) {printf("Harf Notu : DC\nDurum : Gecti\n");}
				if(ogrenciler[indeks2].nott>=45 && ogrenciler[indeks2].nott <55) {printf("Harf Notu : DD\nDurum : Gecti\n");}
				if(ogrenciler[indeks2].nott>=40 && ogrenciler[indeks2].nott <45) {printf("Harf Notu : DF\nDurum : �artl� Gecti\n");}
				if(ogrenciler[indeks2].nott <40) {printf("Harf Notu : FF\nDurum : Kald�\n");}
				
			}
			else if(secim==3)
			{
				printf("Kayd�n� Silmek �stedi�iniz ��rencinin No ' sunu Giriniz : ");
				int noS;
				scanf("%d",&noS);
				int indeks3;
				int onay,kontrol=0;
				for(i=0;i<sayac;i++)
				{
					if(noS == ogrenciler[i].no){indeks3=i;	kontrol++;}
				}
				if(kontrol>0)
				{
					printf("Ad�: %s\nSoyad�: %s\nNo: %d\n1.S�nav: %d\n2.S�nav: %d\nFinal: %d\nNot: %d\nBu ��rencinin kayd�n� silmek sitedi�inize eminmisiniz ? \n1-)Evet\t2-)Hay�r",ogrenciler[indeks3].isim,ogrenciler[indeks3].soyisim,ogrenciler[indeks3].no,ogrenciler[indeks3].vize1,ogrenciler[indeks3].vize2,ogrenciler[indeks3].final,ogrenciler[indeks3].nott);
					printf("\nSeciminiz : ");
					scanf("%d",&onay);	struct ogrenci ogrencilerS[100];
					if(onay == 1)
					{
						int j=0;	int sayacYedek = sayac-1;	
						for(i=0;i<indeks3;i++){ogrencilerS[j]=ogrenciler[i]; j++;}
						for(i=indeks3+1;i<sayac;i++){ogrencilerS[j]=ogrenciler[i]; j++;}
						for(i=0;i<sayac;i++){ogrenciler[i]=ogrencilerS[i];}	sayac--;
					}
					else
					{
						printf("Kay�t silme i�lemi iptal edildi\n");
					}
				}
				else{
					printf("Kayd� silinecek ��renci (no) bulunamad� . \n");
				}
			}
			else if(secim==4)
			{
				printf("bilgilerini de�itirmek isted�iniz ��rencinin no. sunu giriniz : ");
				int yedekNo;	scanf("%d",&yedekNo);	int indeks4,kontrol2=0;
				for(i=0;i<sayac;i++){if(yedekNo == ogrenciler[i].no){indeks4=i;	kontrol2++;}}
				if(kontrol2>0)
				{
					int secim2;
					printf("Se�ti�iniz ��rencinin Bilgileri : \n");
					printf("Ad�: %s\nSoyad�: %s\nNo: %d\n1.S�nav: %d\n2.S�nav: %d\nFinal: %d\nNot: %d\n",ogrenciler[indeks4].isim,ogrenciler[indeks4].soyisim,ogrenciler[indeks4].no,ogrenciler[indeks4].vize1,ogrenciler[indeks4].vize2,ogrenciler[indeks4].final,ogrenciler[indeks4].nott);
					do
					{
						Menu2Yazir();
						scanf("%d",&secim2);
						if(secim2 == 1){printf("Ad� : ");	scanf("%s",ogrenciler[indeks4].isim);}
						else if(secim2 == 2){printf("Soyad� : ");	scanf("%s",ogrenciler[indeks4].soyisim);}
						else if(secim2 == 3)
						{
							int noA;
							printf("No : ");
							scanf("%d",&noA);

							int sart2 = 0;
							for(i=0;i<sayac;i++){if(noA==ogrenciler[i].no){sart2++;}}
						
							if(sart2>0)
							{
								int donguKir = 0;
								do
								{
								donguKir = 0;
								printf("Bu No ya sahip bir ogrenci zaten var ba�ka bir no giriniz ...\n");
								printf("No : ");
								scanf("%d",&noA);
								for(i=0;i<sayac;i++){if(noA == ogrenciler[i].no){donguKir++;}}
								}		while(donguKir != 0);
							}					
							ogrenciler[indeks4].no = noA;	
						}
						else if(secim2 == 4)
						{
							float sinav1A,sinav2A,finalA;
							printf("1. S�nav Notu : ");
							scanf("%f",&sinav1A);
							printf("2. S�nav Notu : ");
							scanf("%f",&sinav2A);
							printf("Final Notu : ");
							scanf("%f",&finalA);
					
							int sart = 0;
							if(sinav1A<0 || sinav1A>100 || sinav2A<0 || sinav2A>100 || finalA<0 || finalA>100 )
							{
								printf("Hatal� Not Giri�i Yapt�n�z . Notlar 0-100 aral���nda olmal�d�r .\nL�tfen Tekrar Not Giriniz ... \n ");
								while(sart != 1)
								{
									printf("1. S�nav Notu : ");
									scanf("%f",&sinav1A);
									printf("2. S�nav Notu : ");
									scanf("%f",&sinav2A);
									printf("Final Notu : ");
									scanf("%f",&finalA);
								
									if(sinav1A<0 || sinav1A>100 || sinav2A<0 || sinav2A>100 || finalA<0 || finalA>100 )
										{printf("Hatal� Not Giri�i Yapt�n�z . Notlar 0-100 aral���nda olmal�d�r .\nL�tfen Tekrar Not Giriniz ... \n ");}
									else{sart++;}
								}
							}
					
							printf("\n");
					
					
							ogrenciler[indeks4].vize1 = sinav1A;
							ogrenciler[indeks4].vize2 = sinav2A;
							ogrenciler[indeks4].final = finalA;
							ogrenciler[indeks4].nott = NotHesapla(sinav1A,sinav2A,finalA);	
						}
						else if(secim2 == 5){printf("De�i�iklikleriniz Kaydedildi ... \n");}
						else{printf("hatal� bir se�im yaptiniz ... l�tfen tekrar se�im yap�n . \n");}
					}
					while(secim2 != 5);
				}
				else{printf("Girdiniz No'ya sahip bir ��renci bulunumad� ... \n'");}
			}
			else if(secim==5)
			{
				printf("Ad\tSoyad\tNo\t1.s�nav\t2.s�nav\tfinal\tNot\tHarf Notu\tGe�ti/Kald� \n");
				for(i = 0;i<sayac;i++)// ogrenciler dizisindeki indeks sayisi sayac �n 1 eksisigi oldugundan i<sayac yap�l�rsa butun elemanlara bak�l�r
				{
					printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\t",ogrenciler[i].isim,ogrenciler[i].soyisim,ogrenciler[i].no,ogrenciler[i].vize1,ogrenciler[i].vize2,ogrenciler[i].final,ogrenciler[i].nott);
					// ogrenci bilgileri yazdir
					if(ogrenciler[i].nott>=90) {printf("AA\t\tGecti\n");}	// harf notlarini ve gecti kaldi durumlarini yazdir
					if(ogrenciler[i].nott>=85 && ogrenciler[i].nott <90) {printf("AB\t\tGecti\n");}
					if(ogrenciler[i].nott>=75 && ogrenciler[i].nott <85) {printf("BB\t\tGecti\n");}
					if(ogrenciler[i].nott>=70 && ogrenciler[i].nott <75) {printf("CB\t\tGecti\n");}
					if(ogrenciler[i].nott>=60 && ogrenciler[i].nott <70) {printf("CC\t\tGecti\n");}
					if(ogrenciler[i].nott>=55 && ogrenciler[i].nott <60) {printf("DC\t\tGecti\n");}
					if(ogrenciler[i].nott>=45 && ogrenciler[i].nott <55) {printf("DD\t\tGecti\n");}
					if(ogrenciler[i].nott>=40 && ogrenciler[i].nott <45) {printf("DF\t\t�artl� Gecti\n");}
					if(ogrenciler[i].nott <40) {printf("FF\t\tKald�\n");}
				}
			}
			else if(secim==6)
			{
				int i;
				printf("Ad\tSoyad\tNo\tBasari Notu\tGe�ti/Kald�\n");
				for(i = 0;i<sayac;i++)
				{
					printf("%s\t%s\t%d\t%d\t\t",ogrenciler[i].isim,ogrenciler[i].soyisim,ogrenciler[i].no,ogrenciler[i].nott);
					if(ogrenciler[i].nott>45) {printf("Gecti\n");}
					if(ogrenciler[i].nott>=40 && ogrenciler[i].nott <45) {printf("�artl� Gecti\n");}
					if(ogrenciler[i].nott <40) {printf("Kald�\n");}
					
				}
			}
			else if(secim==7)
			{
				int i,j,s;
				struct ogrenci ogrencilerA[100];
				printf("Kay�tlar� ba�ar� notuna g�re mi s�ralamak istersiniz , numaralara g�re mi ?");	
				printf("\n1-)Basari Notu\t2-)No\nSeciminiz : ");	int secimSiralama;	scanf("%d",&secimSiralama);
				if(secimSiralama==1)
				{
					for(j = 0;j<sayac;j++)
					{
						for(i = 0;i<sayac-1;i++) {if(ogrenciler[i].nott>ogrenciler[i+1].nott){s = i;}}
						if(ogrenciler[sayac-1].nott>ogrenciler[s].nott) {s = sayac-1;}
						ogrencilerA[j] = ogrenciler[s];
						ogrenciler[s].nott = 0;
					}
						
					for(i = 0;i<sayac;i++) {ogrenciler[i] = ogrencilerA[i]; }
					
				printf("Ba�ar�yla S�ralama Yap�ld� . \n");
				printf("S�ralanm�� Yeni Listeyi G�rmek ��in 3. Se�im �le Kay�tlar� Listeleyiniz .\n");		
				}
				
				else if(secimSiralama==2)
				{
					for(j = 0;j<sayac;j++)
					{
						for(i = 0;i<sayac-1;i++) {if(ogrenciler[i].no<ogrenciler[i+1].no){s = i;}}
						if(ogrenciler[sayac-1].no<ogrenciler[s].no) {s = sayac-1;}
						ogrencilerA[j] = ogrenciler[s];
						ogrenciler[s].no = 102;
					}
					
					for(i = 0;i<sayac;i++) {ogrenciler[i] = ogrencilerA[i];}
					
					printf("Ba�ar�yla S�ralama Yap�ld� . \n");
					printf("S�ralanm�� Yeni Listeyi G�rmek ��in 3. Se�im �le Kay�tlar� Listeleyiniz .\n");
				}
				
				else{printf("Hatali Secim Yapt�n�z L�tfen Tekrar Deneyin\n");}
				
			}		
			else if(secim==8)
			{
				int ortalama,toplam = 0;
				int sayi = sayac;
				int i;
				for(i = 0;i<sayac;i++) {toplam = toplam + ogrenciler[i].nott;}
				ortalama = toplam/sayi;
				printf("S�n�f Ortalamas� : %d\t",ortalama);
									
				int sToplam = 0;
				for(i = 0;i<sayac;i++) {sToplam = sToplam + pow((ortalama - ogrenciler[i].nott),2);}
				
				float karekok = sqrt(sToplam);
				printf("Standart Sapma : %f\n",karekok);
				
				
				int min = 100,max = 0;
				for(i = 0;i<sayac;i++) {if(ogrenciler[i].nott > max){max = ogrenciler[i].nott; } }
				for(i = 0;i<sayac;i++) {if(ogrenciler[i].nott < min){min = ogrenciler[i].nott; } }
				printf("En Y�ksek Not : %d\t En D���k Not : %d\n",max,min);
			
				
				int ortUstu = 0;
				for(i = 0;i<sayac;i++) {if(ogrenciler[i].nott > ortalama){ortUstu++; } }
					
					
				int gecenOgr = 0;
				for(i = 0;i<sayac;i++) {if(ogrenciler[i].nott >= 45){gecenOgr++; } }
				float BasariOrt = gecenOgr*100/sayi;
				
				printf("Ortalama �st� Not Alan ��renci Say�s� : %d \tGecen Ogrenci Sayisi : %d \t Basari Ortalamasi : %%%f \n",ortUstu,gecenOgr,BasariOrt);
			}
			else if(secim==9)
			{
				int i;
				FILE *fyazdir = fopen("liste.txt","w");
				for(i=0;i<sayac;i++)
				{
					fprintf(fyazdir,"%s\n%s\n%d\n%d\n%d\n%d\n%d\n",ogrenciler[i].isim,ogrenciler[i].soyisim,ogrenciler[i].no,ogrenciler[i].vize1,ogrenciler[i].vize2,ogrenciler[i].final,ogrenciler[i].nott);
				}
				fclose(fyazdir);
				FILE *sayacyazdir = fopen("sayac.txt","w");
				fprintf(sayacyazdir,"%d",sayac);
				fclose(sayacyazdir);
				printf("Cikis Saglaniyor...");
			}
		}
		else{printf("Hatali Secim Yaptiniz ... L�tfen Tekrar Se�im Yap�n\n");}
	}
	while(secim != 9);
	
	return 0;
}

