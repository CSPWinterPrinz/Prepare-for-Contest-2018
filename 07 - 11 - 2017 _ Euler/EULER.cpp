#include <stdio.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0
#define VAIN 99
#define MAX 10
int G[MAX][MAX]; // Ma Tran ke Dinh-Dinh (co Khuyen)
int S[MAX][MAX]; // Ma Tran danh dau Cung da su dung
int Pred[MAX]; // Mang Nua-Bac-Trong cua 1 Dinh
int Succ[MAX]; // Mang Nua-Bac-Ngoai cua 1 Dinh
int path[MAX]; // Mang duong di cua chu trinh

// khai bao ham
void ReadData();
void PrintData();
int Check(int k); //bien toan cuc
int N,k,l=0;
void Euler();
void main()
{
    ReadData();
    PrintData();
    Euler();
}
void ReadData()
{
    int i,j;
    FILE* f=fopen("c:\\borlandc\\thuvien\\ltdt2\\EU_in.txt","rt");
    if (f==NULL)
    {
        printf("\nError Loading File!\n");
        return;
    }
    fscanf(f,"%d",&N);// gia tri dau tien cho biet so dinh cua Do Thi G
    for(i=1; i<=N; i++)
    {
        Succ[i]=Pred[i]=0;
        for(j=1; j<=N; j++)
        {
            S[i][j]=FALSE;
            // danh dau Cung khong con su dung nua
            fscanf(f,"%d",&G[i][j]);//lan luot doc cac phan tu MT ke
        }
    }
    fclose(f);
    for(i=1; i<=N; i++) for(j=1; j<=N; j++) if(G[i][j]>0)
            {
                S[i][j]=TRUE;    // Tinh Bac moi Dinh
                Succ[i]++;
                Pred[j]++;
            }
}
void PrintData()
{
    clrscr();
    int i,j;
    printf("\nMa Tran Ke G[%d*%d]:\n",N,N);
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++) printf("%4d",G[i][j]);
        printf("\n");
    }
}
void Euler()
{
    FILE *g=fopen("c:\\borlandc\\thuvien\\ltdt2\\EU_out.txt","wt");
    int i;
    for(i=1; i<=N; i++) if((Pred[i]+Succ[i])%2) // neu co dinh bac Le
        { printf("\nTon tai Dinh %d Bac Le!",i); printf("\nKhong co chu trinh Euler\n"); fclose(g); return; } printf("\nDo thi co chu trinh Euler\n"); int k,ok; // kiem tra va in ra man hinh chu trinh Euler 1 net ve
    printf("\nKet qua kiem tra xuat phat tu dinh 1:\n"); for(k=2;k<=N;k++) // kiem tra xuat phat tu Dinh 1
    { if((G[1][k]!=0)) // co Cung noi Dinh 1 voi Dinh k { S[1][k]=FALSE; // danh dau Cung(1,k) da duoc su dung
    ok=Check(k); // xet tiep Dinh k
    if(ok==FALSE) S[1][k]=TRUE;//duong nay khong nen qua Dinh k=>tra danh dau
    else // ok==TRUE {
        //printf(" %d",k);//lan luot hien thi nguoc cac Dinh da qua
        printf("Tong so dinh cua chu trinh: %d\n",l+2); fprintf(g,"%d\n",l+2); printf("Cac dinh cua duong di chu trinh:\n"); printf("1 %d ",k); fprintf(g,"1 %d ",k); for(int r=l-1;r>=0;r--) { printf("%d ",path[r]); fprintf(g,"%d ",path[r]); } fclose(g); getch(); return; } } } // end for } int Check(int k) // tiep tuc kiem tra, xuat phat tu Dinh k { int i,j,ok; for(i=1;i<=N;i++) { if((S[k][i]==TRUE)&&(G[k][i]!=0))//co Cung tu k den cac Dinh con lai ? { S[k][i]=FALSE;// neu co, danh dau khong su dung lai Cung(k,i) nua ok=Check(i); // xet tiep Dinh i den cac Dinh khac if(ok==FALSE) S[k][i]=TRUE;//lan nay khong nen qua Dinh i => bo danh dau else { //printf(" %d",i); path[l]=i; l++; return TRUE; } } } for(i=1;i<=N;i++) // khi khong con Cung di tu Dinh k nua for(j=1;j<=N;j++) // quet duyet do thi G xem da het Cung chua? if(S[i][j]==TRUE) // neu con sot Cung tren Ma Tran danh dau S => return FALSE;//huong di theo Dinh k nay la sai=>chon Dinh k khac return TRUE;
    // thanh cong, tra ve cac dinh nguoc tren duong di Euler
        }
