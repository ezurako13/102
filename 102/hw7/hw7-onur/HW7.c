#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char table[16][16];
char filewords[50][10];

enum direction{BATI=0, KUZEYBATI, KUZEY, KUZEYDOGU, DOGU, GUNEYDOGU, GUNEY, GUNEYBATI};
/* Yönleri enum ile tanımladım böylece daha anlaşılır oldu*/

int randomnum(int a)// 8 taneden ya da 50 taneden seçmek için
{
    return (rand()%a);
}

void fill_file_array()
{
    FILE *fp=fopen("wordlist.txt", "r+");
    if(fp==NULL)
        printf("FILE reading is not success!\n");
    else
    {
        int i=0;
        while(!feof(fp))
        {
            fscanf(fp, "%s", filewords[i]);// dosyadaki her bir kelimeyi string arrayine attım rastgele seçebilmek için.
            i++;
        }
    }
    fclose(fp);
}

void fill_table_array()// arrayi boşluklarla doldurdum kontrol edebilmek için
{
    int i,j;
    for(i=0; i<16; i++)
    {
        for(j=0; j<16; j++)
        {
            table[i][j]=' ';
        }
    }
}

int control(int x, int y, int dir, int word_index)
{   
    /*Rastgele seçilen kelimeyi rastgele gelen koordinattan başlayarak rastgele seçilen yönde tek tek kontrol ediyor.
    Gittiği yönde kelimenin uzunluğu kadar boşluk varsa 1 ancak herhangi bir harf varsa 0 döndürüyor*/
    int i, j, len;
    len = strlen(filewords[word_index]);
    for(j=0; j<len; j++)
    {   
        if(table[x][y] != ' ')// boşluktan farklı bir şey varsa 0 döndürüyor uzunluğu boyunca sadece boşluk varsa buraya hiç girmiyor ve 1 döndürüyor.
            return 0;
        if(dir == BATI)
        {
            y--;
        }
        if(dir == KUZEYBATI)
        {
            y--;
            x--;
        }
        if(dir == KUZEY)
        {
            x--;
        }
        if(dir == KUZEYDOGU)
        {
            y++;
            x--;
        }
        if(dir == DOGU)
        {
            y++;
        }
        if(dir == GUNEYDOGU)
        {
            y++;
            x++;
        }
        if(dir == GUNEY)
        {
            x++;
        }
        if(dir == GUNEYBATI)
        {
            y--;
            x++;
        }
    }
    return 1;
}

void choosewords()// 50 tane kelime seçtim ve onları
{
    int i, j, dir, word_index, len, len_temp, x, y, counter=0;
    for(i=0; i<7; i++)
    {
        do
        {
            counter = 0;

            dir=randomnum(8);// while içinde rsatgele yön alıyorum
            word_index=randomnum(50);// array içinden rastgele kelime seçmek için
            len = strlen(filewords[word_index]);
            /*Rastgele koordinatlar*/
            x=randomnum(15);
            y=randomnum(15);

            /*Bu kısımda rastgele seçtiğim koordinatları konntrol ettim. Çünkü koordinatlar herhangi bir yönde tablonun sınırları dışına çıkabilrdi
            Bu yüzden ben de eğer x ya da y koordinatım bu sınır değerlerindeyse (yani tablodan çıkıp sıkıntı çıkaracak koordinatlar) while içinde
            sıkıntılı olmayan bir değer gelene kadar random sayı aldı. */
            if(dir == BATI)
            {
                while(y<len-1 )
                    y=randomnum(15);
            }
            if(dir == KUZEYBATI)
            {
                while(y<len-1 )
                    y=randomnum(15);
                while(x<len-1)
                    x=randomnum(15);
            }
            if(dir == KUZEY)
            {
                while(x<len-1)
                    x=randomnum(15);
            }
            if(dir == KUZEYDOGU)
            {
                while(y>=14-(len-2))
                    y=randomnum(15);
                while(x<len-1)
                    x=randomnum(15);
            }
            if(dir == DOGU)
            {
                while(y>=14-(len-2))
                    y=randomnum(15);
            }
            if(dir == GUNEYDOGU)
            {
                while(x>=14-(len-2))
                    x=randomnum(15);
                while(y>=14-(len-2))
                    y=randomnum(15);
            }
            if(dir == GUNEY)
            {
                while(x>=14-(len-2))
                    x=randomnum(15);
            }            
            if(dir == GUNEYBATI)
            {
                while(x>=14-(len-2))
                    x=randomnum(15);
                while(y<len-1 )
                    y=randomnum(15);
            }
            /*Tüm doğru koordinatları aldıktan sonra kelimenın yazılacağı yerler boş mu diye kontrol ettim eğer değilse counter bir artar ve şuanki
            while 'ın içine tekrar girer. While ın başında da sayacı sıfırlıyorum ki en sonunda while' dan çıkabilme olasılığı olsun.
            Yani counter 1 olduysa kelimeler çakışmıştır demektir. O zaman başa dönüp tekrardan kelime yön ve koordinatları seçer. tekrar kontrol eder
            eğer uygun pozisyon oluşursa while dan çıkar.*/
            if(control(x,y,dir,word_index))
            {
                for(j=0; j<len; j++)
                {
                    table[x][y] = filewords[word_index][j];
                    if(dir == BATI)
                    {
                        y--;
                    }
                    if(dir == KUZEYBATI)
                    {
                        y--;
                        x--;
                    }
                    if(dir == KUZEY)
                    {
                        x--;
                    }
                    if(dir == KUZEYDOGU)
                    {
                        y++;
                        x--;
                    }
                    if(dir == DOGU)
                    {
                        y++;
                    }
                    if(dir == GUNEYDOGU)
                    {
                        y++;
                        x++;
                    }
                    if(dir == GUNEY)
                    {
                        x++;
                    }
                    if(dir == GUNEYBATI)
                    {
                        y--;
                        x++;
                    }
                }
            }
            else
                counter++;/*counter'ı while da doğru kelimeyi bulabilmek için arttırdım*/
        }while(counter != 0);
    }
}

void printtable()
{
    int i,j;
    for(i=0; i<15; i++)
    {
        for(j=0; j<15; j++)
        {
            if(table[i][j] == ' ')/* rastgele kelimeleri rastgele yerlere rastgele yinde yerleştirdikten sonra kalan boşluklara rastgele harfler atadım*/
            {   
                table[i][j] = 97 + randomnum(26);
                printf("%c ", table[i][j]);
            }
            else if(table[i][j] == 'X')
            {
                printf("\033[0;31m");
                printf("%c ", table[i][j]);
                printf("\033[0m");
            }
            else
            {
                printf("\033[0;34m");
                printf("%c ", table[i][j]);
                printf("\033[0m");
            }
        }
        printf("\n");
    }
}

int find_words(int y, int x, char word[])// ilk dikeyi sonra yatayı
{
    int len, i, j, k, a=0, dir1=-1, dir2=-1, counter1=0, counter2=0, counter3=0, counter4=0, counter5 = 0, xtemp, ytemp;
    int coordinate[8][2];/*Bu array kelimenin ilk harfinden sonra ne tarafa gideceğini tutuyor. yönler 1, -1 ve 0.*/
    for(i=0; i<8; i++)//arrayin içini 3 ile doldurdum
    {
        for(j=0; j<2; j++)
            coordinate[i][j]=3;
    }
    len = strlen(word);
    if(word[0] == table[y][x])
    {
        for(i=0; i<8; i++)// 8 yön olduğu için her yönü kontrol ediyor
        {
            if(y+dir1>=0 && x+dir2>=0 && y+dir1<15 && x+dir2<15)/* kelimenin ilk harfini merkez kabul edip 1 birim olacak şekilde çevresine bakıyorum.
             Ayrıca tablodan dışarı çıkmamasını kontrol ediyorum*/
            {       
                if(word[1] == table[y+dir1][x+dir2])//kelimenin ikinci harfinin ilk harfine göre ne tarafta olduğunu buluyorum ve arraye kaydediyorum
                {
                    coordinate[a][0]=dir1;
                    coordinate[a][1]=dir2;
                    a++;
                }
            }
            /*Kelimenin ilk harfini merkez alıyorum. kelimenin ikinci harfiyle eşleşen harfi bulabilmek için kelimenin ilk harfinin etrafını
            tek tek tarıyorum. etrafını tarayabilmek için de 1 birim şeklinde hareket ediyorum. kelimenin sol çaprazından başlayıp sağa, daha sonra
            aşağı sonra sola ve sonra yukarı olacak şekilde ilk harfin etrafında dikdörtgen çizerek harfleri tarıyorum */
                if(counter1<2)
                {
                    dir2++;
                    counter1++;
                }
                else if(counter2<2)
                {
                    dir1++;
                    counter2++;
                }
                else if(counter3<2)
                {
                    dir2--;
                    counter3++;
                }
                else if(counter4 <1)
                {
                    dir1--;
                    counter4++;
                }
        }
        for(i=0; i<8; i++)
        {
            if(coordinate[i][1] != 3)/*Bu array kelimenin olası yönlerini tutuyor. en başta sadece 3 ile doldurmuştum. ve yönlerimi de -1 ,0 ve 1
            olarak belirledim. O halde arrayde 3 dışındaki herhangi bir rakam kelimenin olası yönünü gösterir*/
                    counter5++;
        }
        for(i=0; i<counter5; i++)// kelimenin olası yön sayısı kadar dönüyor
        {
            /*Her kontrol için x ve y değerlerini temp değişkenlerime atıyorum ki x ve y değerlerini kaybetmeyelim*/
            xtemp=x;
            ytemp=y;
            for(j=0; j<len-1; j++)
            {
                if(x + coordinate[i][1]>=0 && y+coordinate[i][0]>=0 && x + coordinate[i][1]<15 && y+coordinate[i][0]<15)// yine tablodan çıkmaması için sınır kontrolü
                {
                    xtemp = xtemp + coordinate[i][1];/* kelimeyi koordinatlarca ilerletiyorum ve kontrol ediyorum. Eğer harfler farklıysa (varsa) diğer
                     olası yöne bakıyor, eğer olası başka yön yoksa kullancı yanlış girmiş demektir*/
                    ytemp = ytemp + coordinate[i][0];
                    if(word[j+1] != table[ytemp][xtemp])
                        break;
                }
                else
                    break;
            }
            if(j== len-1)//eğer üstteki döngüden break yapıp çıkmadıysa kelimeyi doğru bulmuşuz demektir.
            {   
                for(k=0; k<len; k++)//ilk önce harf yerine X yazdırıp daha sonra 2 puan return ediyorum
                {
                    table[y][x] = 'X';
                    x=x+coordinate[i][1];
                    y=y+coordinate[i][0];
                }
                return 2;
            }        
        }
    }
    return 0;// olası yönlerden hiçbiri kelimeyle eşleşmezse 0 puan return ediyor.
    }

int charr_to_int(char num[])// :q yapıp programı sonlandrabilmek için her şeyi char olarak aldım o yüzden karakterleri integera çevirecek bir fonksiyon yazdım.
{
    int sum=0, i;
    int len = strlen(num);
    for(i=0; i<len; i++)
    {
        sum = sum*10;
        sum=sum+num[i]-48;
    }
    return sum;
}

int main()
{
    char a,b,c;
    int yatay1,dikey1, points, sayac=0, puan=0, left = 2;
    char word[10], yatay[3], dikey[3];
    srand(time(NULL));
    fill_table_array();
    fill_file_array();
    choosewords();
    printtable();

    while(sayac!=3)// bu while kullanıcı 3 kere hatalı karar verirse oyunu sonlandırmak için hata yapmazsa oyun devam eder.
    {
        printf("Enter coordinates and word:\n");
        scanf("%s", dikey);

        if(dikey[0] == ':' && dikey[1]=='q')// oyunu sonlandırma koşulu
        {   
             printf("Your total points %d \n", puan);
            break;
        }
        else
            scanf("%s %s", yatay, word);
        yatay1 = charr_to_int(yatay);
        dikey1 = charr_to_int(dikey);
        points = find_words(dikey1,yatay1,word);
        printtable();
        if(points == 0)
        {
            if(left != 0)
                printf("Wrong choice!!You have only %d lefts\n", left);
            sayac++;
            left--;
            if(sayac == 3)
                printf("You made 3 mistakes. Your total point is %d\n", puan);
        }
        else
        {   
            puan = puan + points;
            printf("Founded! You got 2 points. Your total points %d \n", puan);
        }
        if(puan == 14)// 14 puan alırsa 7 kelimeyi de bulmuş demektir böylece oyun biter.
        {
            printf("You won.!!\n");
            break;
        }
    }
    return 0;
}