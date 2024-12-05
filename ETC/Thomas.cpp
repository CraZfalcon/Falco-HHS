int msg = 1;
int x;

int COLOR;
#define RED 2
#define GREEN 3


void main(){


  if(msg<10)x=210;
  else if(msg>=10&&msg<100)x=102;
  else if(msg>=100)x=-6;
  else if(msg>130)COLOR=RED;
  else COLOR=GREEN;


}