#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char s[10005] = "kiglnmrmeiahenrteof4ardar";
char t[1005];int top;
int main()
{
    int pos = 0 ;
    for(int i=1;i<=34;i++){
        int x;
        scanf("%d",&x);
        if(x&1){
            while(x-->0){
                t[++top] = s[pos++];
            }
        }else {
            while(x-->0){
                printf("%c",t[top--]);
            }
        }
    }
    return 0;
}
// lgrmnimkeiharnetfo4e