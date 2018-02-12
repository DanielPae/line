#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if(x0 > x1){
    int x_temp = x1;
    int y_temp = y1;
    x1 = x0;
    x0 = x_temp;
    y1 = y0;
    y0 = y_temp;
  }
  printf("x0:%d, y0:%d, x1:%d, y1:%d\n", x0, y0, x1, y1); 

  int a = y1 - y0;
  int b = x1 - x0;

  if(a > 0){
    if(b > a){
      int d = 2 * a - b;
      while(x0 < x1){
	plot(s, c, x0, y0);
	if(d > 0) {
	  y0++;
	  d -= 2 * b;
	}
	x0++;
	d += 2 * a;
      }
    }else{
      int d = a - (2 * b);
      while(y0 < y1){
	plot(s, c, x0, y0);
	if(d < 0) {
	  x0++;
	  d += 2 * a;
	}
	y0++;
	d -= 2 * b;
      }
    }
  }else{
    if(b > (a * -1)){
      int d = b - (2 * a);
      while(x0 < x1){
	plot(s, c, x0, y0);
	if(d < 0) {
	  y0--;
	  d += 2 * b;
	}
	x0++;
	d += 2 * a;
      }
    }else{
      int d = b * 2 - a;
      while(y1 < y0){
	plot(s, c, x0, y0);
	if(d > 0) {
	  x0++;
	  d += 2 * a;
	}
	y0--;
	d += 2 * b;
      }
    }
  }
}
