#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

void draw(int, int, int, int, int [200][200]);

int main(){
  int array [200][200];
  draw(0, 0, 100, 100, array);
  int file = open("image.ppm", O_WRONLY | O_CREAT, 0644);
  char header[15] = "P3\n200 200\n255\n";
  write(file, header, 15);
  int i = 0;
  int o = 0;
  char *dot = "254 254 254 ";
  char *blank = "0 0 0 ";
  /*for(; i < 200; i++){
    for(; o < 200; o++){
      if(array[i][o] == 1){
	write(file, dot, 12);
      }else{
	write(file, blank, 6);
      }
    }
    }*/
  for(; i < 200; i++){
    for(; o < 200; o++){
      printf("%d ", array[i][o]);
    }
    printf("\n");
  }
}

void draw(int x, int y, int x2, int y2, int array[200][200]){
  int a = y2 - y;
  int b = x2 - x;
  int d = 2 * a + b;
  while(x < x2){
    //plot(x, y);
    array[200 - x][200 - y] = 1;
    if(d > 0) {
      y++;
      d += 2 * b;
    }
    x++;
    d -= 2 * a;
  }
}

