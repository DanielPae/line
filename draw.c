#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int a = y1 - y0;
  int b = x1 - x0;

  if(a * b > 0){
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
    }else if(a > b){
      int d = a - (2 * b);
      while(x0 < x1){
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
    int d = b - (2 * a);
    while(x0 < x1){
      plot(s, c, x0, y0);
      if(d < 0) {
	y0--;
	d -= 2 * b;
      }
      x0++;
      d += 2 * a;
      printf("%d ", d);
    }
  }
}
