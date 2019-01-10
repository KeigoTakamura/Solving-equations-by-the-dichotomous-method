#include<stdio.h>
#include<math.h>
#define maxcount 200//無限ループ防止用カウンタ定数

double func(double x){
    return (x-2.0)*(x*x+1.0);
}

int main()
{
    double x1=1.0,x2=4.0,eps=1.0E-03,xm,y1,y2,ym;

    y1 = func(x1);
    y2 = func(x2);
    

    if(y1*y2 >= 0){
        perror("error\n");
        return -1;
    }

    for(int i=0;i < maxcount;i++){
        //printf("xm=%30.20g \n",xm);
        
        xm=(x1+x2)*0.5;
        ym = func(xm);//xm


        if(ym==0.0){//ymがzeroなら終了
            printf("end zero cal!!!\n");
            break;
        }
        
        if(ym*y1 >= 0.0){
                x1=xm;
        }
        else
        {
                x2=xm;
        }

       
        printf("cal = %30.20g\n",xm);
        
        if (fabs(x1-x2) <= eps) {//収束したら反復処理終了
            printf("end cal!!\n");
            break;
        }
    }

  return 0;
}



