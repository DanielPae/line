#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);
	
  draw_line(50, 50, 100, 125, s, c);
  draw_line(150, 50, 100, 125, s, c);
  draw_line(100, 125, 100, 190, s, c);
  draw_line(50, 205, 100, 190, s, c);
  draw_line(150, 205, 100, 190, s, c);
  draw_line(100, 190, 60, 255, s, c);
  draw_line(60, 255, 140, 255, s, c);
  draw_line(140, 255, 100, 190, s, c);
  draw_line(250, 50, 300, 125, s, c);
  draw_line(350, 50, 300, 125, s, c);
  draw_line(300, 125, 300, 220, s, c);
  draw_line(250, 125, 300, 220, s, c);
  draw_line(350, 125, 300, 220, s, c);
  draw_line(260, 220, 260, 270, s, c);
  draw_line(260, 270, 340, 270, s, c);
  draw_line(340, 270, 340, 220, s, c);
  draw_line(260, 220, 340, 220, s, c);
  //draw_line(60, 190, 115, 240, s, c);
  //draw_line(140, 190, 115, 240, s, c);
  


  display(s);
  save_extension(s, "lines.png");
}
