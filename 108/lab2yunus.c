#include<stdio.h>
int standarthesap(int giden1, int giden2, int giden3);
int complex(int gercek1,int sanal1,int gercek2,int sanal2, int sec);
int complexhesap(int git1, int git2, int git3, int git4, int git5);
int hesapmakinesi(int gereksiz);

int main () {
	int secim,secim2,secim3;
	int sayi1,sayi2;
	int sayi3, sayi4;
	printf("enter the calculator type \n 1. Standart Calculator\n 2.Area&Perimeter Calculator\n 3. Temperature Calculator\n");
	scanf("%d",&secim);
	if(secim==1) {
	hesapmakinesi(secim);
	}


}
int hesapmakinesi(int gereksiz) {
int sayi1,sayi2,secim2,secim3;
	int sayi3, sayi4;
printf("1. Integer\n2.Complex\n");
		scanf("%d",&secim2);
		if(secim2==1) {
			printf("1.Toplama\n2.Carpma\n");
			scanf("%d",&secim3);
			printf("sayiları giriniz\n");
			scanf("%d",&sayi1);
			scanf("%d", &sayi2);
			standarthesap(sayi1,sayi2,secim3);
		}
		else if(secim2==2) {
			printf("1.Toplama\n2.Carpma\n");
			scanf("%d",&secim3);
			printf("sayiları giriniz gerçek sayıyı ilk yazınız\n");
			scanf("%d",&sayi1);
			scanf("%d", &sayi2);
			printf("ikinci sayıyı giriniz gerçek kısmını ilk yazınız ");
			scanf("%d",&sayi3);
			scanf("%d",&sayi4);
			complex(sayi1,sayi2,sayi3,sayi4,secim3);
		}

}

int standarthesap(int giden1,int giden2,int giden3) {
	if(giden3==1) {
		giden1=giden1+giden2;
		printf("%d",giden1);
	}
	else if (giden3==2) {
		giden1= giden1*giden2;
		printf("%d",giden1);
	}
	else return 0;
}
int complex(int gercek1, int sanal1, int gercek2, int sanal2, int sec) {
	if(sec==1) {
		gercek1=gercek1+gercek2;
		sanal1=sanal1+sanal2;
		printf("cevap %d+ (%di)",gercek1,sanal1);
	}
	else if (sec==2) {
	int kokgercek, koksanal;
	kokgercek= (gercek1*gercek2)-(sanal1*sanal2);
	koksanal=(gercek1*sanal2) +(gercek2*sanal1);
	printf("sonuc= %d + (%di)",kokgercek,koksanal);
	
	}
}