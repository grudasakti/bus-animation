#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#define SPEED 30.0

float i=0.0,m=0.0,n=0.0,o=0.0,c=0.0;

int light=1,day=1,plane=0,comet=0,xm=900,train=0;

void declare(char *string){
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void draw_pixel(GLint cx, GLint cy){
	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y){
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r){
	GLint d=1-r, x=0, y=r;
	while(y>x){
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}


void draw_object(){
    int l;
    //siang
    if(day==1){
        //langit
        glColor3f(0.0,0.9,0.9);
        glBegin(GL_POLYGON);
        glVertex2f(0,380);
        glVertex2f(0,700);
        glVertex2f(1100,700);
        glVertex2f(1100,380);
        glEnd();

        //matahari
        for(l=0;l<=35;l++){
            glColor3f(1.0,0.9,0.0);
            draw_circle(100,625,l);
        }

        //pesawat
        if(plane==1){
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_POLYGON);
            glVertex2f(925+n,625+o);
            glVertex2f(950+n,640+o);
            glVertex2f(1015+n,640+o);
            glVertex2f(1030+n,650+o);
            glVertex2f(1050+n,650+o);
            glVertex2f(1010+n,625+o);
            glEnd();

            glColor3f(0.8,0.8,0.8);
            glBegin(GL_LINE_LOOP);
            glVertex2f(925+n,625+o);
            glVertex2f(950+n,640+o);
            glVertex2f(1015+n,640+o);
            glVertex2f(1030+n,650+o);
            glVertex2f(1050+n,650+o);
            glVertex2f(1010+n,625+o);
            glEnd();
        }

        //gunung
        glColor3f(0.961, 1.000, 0.980);
        glBegin(GL_POLYGON);
        glVertex2f(100,380);
        glVertex2f(400,600);
        glVertex2f(700,380);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(365,575);
        glVertex2f(400,600);
        glVertex2f(435,575);
        glEnd();

        glColor3f(0.961, 1.000, 0.980);
        glBegin(GL_POLYGON);
        glVertex2f(500,380);
        glVertex2f(800,600);
        glVertex2f(1100,380);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(765,575);
        glVertex2f(800,600);
        glVertex2f(835,575);
        glEnd();

        //awan1
        for(l=0;l<=20;l++){
            glColor3f(1.0,1.0,1.0);
            draw_circle(160+m,625,l);
        }
        for(l=0;l<=35;l++){
            glColor3f(1.0,1.0,1.0);
            draw_circle(200+m,625,l);
            draw_circle(225+m,625,l);
        }
        for(l=0;l<=20;l++){
            glColor3f(1.0,1.0,1.0);
            draw_circle(265+m,625,l);
        }

        //awan2
        for(l=0;l<=20;l++){
            glColor3f(1.0,1.0,1.0);
            draw_circle(370+m,615,l);
        }
        for(l=0;l<=35;l++){
            glColor3f(1.0,1.0,1.0);
            draw_circle(410+m,615,l);
            draw_circle(435+m,615,l);
            draw_circle(470+m,615,l);
        }
        for(l=0;l<=20;l++){
            glColor3f(1.0,1.0,1.0);
            draw_circle(500+m,615,l);
        }

        //rumput
        glColor3f(0.0,0.9,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0,160);
        glVertex2f(0,380);
        glVertex2f(1100,380);
        glVertex2f(1100,160);
        glEnd();
    }

    //malam
    else{
        //langit
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0,380);
        glVertex2f(0,700);
        glVertex2f(1100,700);
        glVertex2f(1100,380);
        glEnd();

        //bulan
        int l;

            for(l=0;l<=35;l++)
            {
                glColor3f(1.0,1.0,1.0);
                draw_circle(100,625,l);
            }

        //bintang 1

        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(575,653);
        glVertex2f(570,645);
        glVertex2f(580,645);
        glVertex2f(575,642);
        glVertex2f(570,650);
        glVertex2f(580,650);
        glEnd();

        //bintang 2
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(975,643);
        glVertex2f(970,635);
        glVertex2f(980,635);
        glVertex2f(975,632);
        glVertex2f(970,640);
        glVertex2f(980,640);
        glEnd();

        //bintang 3
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(875,543);
        glVertex2f(870,535);
        glVertex2f(880,535);
        glVertex2f(875,532);
        glVertex2f(870,540);
        glVertex2f(880,540);
        glEnd();

        //bintang 4
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(375,598);
        glVertex2f(370,590);
        glVertex2f(380,590);
        glVertex2f(375,587);
        glVertex2f(370,595);
        glVertex2f(380,595);
        glEnd();

        //bintang 5
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(750,628);
        glVertex2f(745,620);
        glVertex2f(755,620);
        glVertex2f(750,618);
        glVertex2f(745,625);
        glVertex2f(755,625);
        glEnd();

        //bintang 6
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(200,628);
        glVertex2f(195,620);
        glVertex2f(205,620);
        glVertex2f(200,618);
        glVertex2f(195,625);
        glVertex2f(205,625);
        glEnd();

        //bintang 7
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(100,528);
        glVertex2f(95,520);
        glVertex2f(105,520);
        glVertex2f(100,518);
        glVertex2f(95,525);
        glVertex2f(105,525);
        glEnd();

        //bintang 8
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(300,468);
        glVertex2f(295,460);
        glVertex2f(305,460);
        glVertex2f(300,458);
        glVertex2f(295,465);
        glVertex2f(305,465);
        glEnd();

        //bintang 9
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(500,543);
        glVertex2f(495,535);
        glVertex2f(505,535);
        glVertex2f(500,532);
        glVertex2f(495,540);
        glVertex2f(505,540);
        glEnd();


        //komet
        if(comet==1){
            for(l=0;l<=7;l++)
            {
                glColor3f(1.0,1.0,1.0);
                draw_circle(300+c,675,l);
            }

        glColor3f(1.0,1.0,1.0);
            glBegin(GL_TRIANGLES);
            glVertex2f(200+c,675);
            glVertex2f(300+c,682);
            glVertex2f(300+c,668);
            glEnd();
        }

        //Pesawat
        if(plane==1){
            for(l=0;l<=1;l++)
            {
                glColor3f(1.0,0.0,0.0);
                draw_circle(950+n,625+o,l);
                glColor3f(1.0,1.0,0.0);
                draw_circle(954+n,623+o,l);

            }
        }

        //rumput
        glColor3f(0.0,0.3,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0,160);
        glVertex2f(0,380);
        glVertex2f(1100,380);
        glVertex2f(1100,160);
        glEnd();
    }


    //Dasar Sudut Halte
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(330,150);
    glVertex2f(330,160);
    glVertex2f(1010,160);
    glVertex2f(1010,150);
    glEnd();

    //Dasar Halte
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_POLYGON);
    glVertex2f(330,160);
    glVertex2f(330,250);
    glVertex2f(1010,250);
    glVertex2f(1010,160);
    glEnd();

    //Pinggiran Halte
    glColor3f(0.753, 0.753, 0.75);
    glBegin(GL_POLYGON);
    glVertex2f(330,100);
    glVertex2f(330,150);
    glVertex2f(1010,150);
    glVertex2f(1010,100);
    glEnd();

    //Tangga Kanan
    glColor3f(0.502, 0.502, 0.502);
    glBegin(GL_POLYGON);
    glVertex2f(1010,100);
    glVertex2f(1010,200);
    glVertex2f(1040,200);
    glVertex2f(1040,100);
    glEnd();

    glColor3f(0.753, 0.753, 0.75);
    glBegin(GL_POLYGON);
    glVertex2f(1010,100);
    glVertex2f(1010,140);
    glVertex2f(1040,140);
    glVertex2f(1040,100);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(1010,140);
    glVertex2f(1010,150);
    glVertex2f(1040,150);
    glVertex2f(1040,140);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(1000,140);
    glVertex2f(1000,160);
    glVertex2f(1010,160);
    glVertex2f(1010,140);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(1030,100);
    glVertex2f(1030,140);
    glVertex2f(1040,140);
    glVertex2f(1040,100);
    glEnd();

    //Tangga kiri
    glColor3f(0.502, 0.502, 0.502);
    glBegin(GL_POLYGON);
    glVertex2f(300,100);
    glVertex2f(300,200);
    glVertex2f(330,200);
    glVertex2f(330,100);
    glEnd();

    glColor3f(0.753, 0.753, 0.75);
    glBegin(GL_POLYGON);
    glVertex2f(300,100);
    glVertex2f(300,140);
    glVertex2f(330,140);
    glVertex2f(330,100);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(300,140);
    glVertex2f(300,150);
    glVertex2f(330,150);
    glVertex2f(330,140);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(330,140);
    glVertex2f(330,160);
    glVertex2f(340,160);
    glVertex2f(340,140);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(300,100);
    glVertex2f(300,140);
    glVertex2f(310,140);
    glVertex2f(310,100);
    glEnd();

    //Trotoar Kanan Kiri
    glColor3f(0.871, 0.722, 0.529);
    glBegin(GL_POLYGON);
    glVertex2f(1040,100);
    glVertex2f(1040,160);
    glVertex2f(1100,160);
    glVertex2f(1100,100);
    glEnd();

    glColor3f(0.871, 0.722, 0.529);
    glBegin(GL_POLYGON);
    glVertex2f(0,100);
    glVertex2f(0,160);
    glVertex2f(300,160);
    glVertex2f(300,100);
    glEnd();


    //Kursi 1
    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(140,190);
    glVertex2f(140,210);
    glVertex2f(155,210);
    glVertex2f(155,190);
    glEnd();

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(130,210);
    glVertex2f(130,215);
    glVertex2f(225,215);
    glVertex2f(225,210);
    glEnd();

    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(200,190);
    glVertex2f(200,210);
    glVertex2f(215,210);
    glVertex2f(215,190);
    glEnd();

    //Kursi 2
    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(390,190);
    glVertex2f(390,210);
    glVertex2f(405,210);
    glVertex2f(405,190);
    glEnd();

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(380,210);
    glVertex2f(380,215);
    glVertex2f(475,215);
    glVertex2f(475,210);
    glEnd();

    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(450,190);
    glVertex2f(450,210);
    glVertex2f(465,210);
    glVertex2f(465,190);
    glEnd();

    //Kursi 3
    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(840,190);
    glVertex2f(840,210);
    glVertex2f(855,210);
    glVertex2f(855,190);
    glEnd();

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(830,210);
    glVertex2f(830,215);
    glVertex2f(925,215);
    glVertex2f(925,210);
    glEnd();

    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(900,190);
    glVertex2f(900,210);
    glVertex2f(915,210);
    glVertex2f(915,190);
    glEnd();

    //Jalan
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,100);
    glVertex2f(1100,100);
    glVertex2f(1100,0);
    glEnd();

    //Marka Jalan
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(50, 40);
    glVertex2f(50,60);
    glVertex2f(150,60);
    glVertex2f(150,40);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(200, 40);
    glVertex2f(200,60);
    glVertex2f(300,60);
    glVertex2f(300,40);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(350, 40);
    glVertex2f(350,60);
    glVertex2f(450,60);
    glVertex2f(450,40);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(500, 40);
    glVertex2f(500,60);
    glVertex2f(600,60);
    glVertex2f(600,40);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(650, 40);
    glVertex2f(650,60);
    glVertex2f(750,60);
    glVertex2f(750,40);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(800, 40);
    glVertex2f(800,60);
    glVertex2f(900,60);
    glVertex2f(900,40);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(950, 40);
    glVertex2f(950,60);
    glVertex2f(1050,60);
    glVertex2f(1050,40);
    glEnd();

    //Pagar
    glColor3f(0.545, 0.271, 0.075);
    glBegin(GL_POLYGON);
    glVertex2f(0,250);
    glVertex2f(0,310);
    glVertex2f(5,320);
    glVertex2f(10,310);
    glVertex2f(10,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(90,250);
    glVertex2f(90,310);
    glVertex2f(95,320);
    glVertex2f(100,310);
    glVertex2f(100,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(140,250);
    glVertex2f(140,310);
    glVertex2f(145,320);
    glVertex2f(150,310);
    glVertex2f(150,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(190,250);
    glVertex2f(190,310);
    glVertex2f(195,320);
    glVertex2f(200,310);
    glVertex2f(200,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(240,250);
    glVertex2f(240,310);
    glVertex2f(245,320);
    glVertex2f(250,310);
    glVertex2f(250,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(340,250);
    glVertex2f(340,310);
    glVertex2f(345,320);
    glVertex2f(350,310);
    glVertex2f(350,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(390,250);
    glVertex2f(390,310);
    glVertex2f(395,320);
    glVertex2f(400,310);
    glVertex2f(400,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(950,250);
    glVertex2f(950,310);
    glVertex2f(955,320);
    glVertex2f(960,310);
    glVertex2f(960,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(1000,250);
    glVertex2f(1000,310);
    glVertex2f(1005,320);
    glVertex2f(1010,310);
    glVertex2f(1010,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(1050,250);
    glVertex2f(1050,310);
    glVertex2f(1055,320);
    glVertex2f(1060,310);
    glVertex2f(1060,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(950,295);
    glVertex2f(950,305);
    glVertex2f(1100,305);
    glVertex2f(1100,295);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(950,265);
    glVertex2f(950,275);
    glVertex2f(1100,275);
    glVertex2f(1100,265);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0,295);
    glVertex2f(0,305);
    glVertex2f(400,305);
    glVertex2f(400,295);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0,265);
    glVertex2f(0,275);
    glVertex2f(400,275);
    glVertex2f(400,265);
    glEnd();

    //Pohon 1
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(50,185);
    glVertex2f(50,255);
    glVertex2f(65,255);
    glVertex2f(65,185);
    glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(40,250,l);
		draw_circle(80,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(50,290,l);
		draw_circle(70,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(60,315,l);
	}

    //Pohon 2
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(300,200);
    glVertex2f(300,255);
    glVertex2f(315,255);
    glVertex2f(315,200);
    glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(290,250,l);
		draw_circle(330,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(300,290,l);
		draw_circle(320,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(310,315,l);
	}


    //Pohon 3
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1050,185);
    glVertex2f(1050,255);
    glVertex2f(1065,255);
    glVertex2f(1065,185);
    glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1040,250,l);
		draw_circle(1080,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1050,290,l);
		draw_circle(1070,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1060,315,l);
	}


    //Halte
    glColor3f(0.827, 0.827, 0.827);
    glBegin(GL_POLYGON);
    glVertex2f(400,400);
    glVertex2f(400,450);
    glVertex2f(950,450);
    glVertex2f(950,400);
    glEnd();

    glColor3f(0.827, 0.827, 0.827);
    glBegin(GL_POLYGON);
    glVertex2f(400,250);
    glVertex2f(400,400);
    glVertex2f(450,400);
    glVertex2f(450,250);
    glEnd();

    glColor3f(0.827, 0.827, 0.827);
    glBegin(GL_POLYGON);
    glVertex2f(900,250);
    glVertex2f(900,400);
    glVertex2f(950,400);
    glVertex2f(950,250);
    glEnd();

    //Kursi Halte
    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(500,250);
    glVertex2f(500,270);
    glVertex2f(520,270);
    glVertex2f(520,250);
    glEnd();

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(480,270);
    glVertex2f(480,300);
    glVertex2f(870,300);
    glVertex2f(870,270);
    glEnd();

    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(830,250);
    glVertex2f(830,270);
    glVertex2f(850,270);
    glVertex2f(850,250);
    glEnd();

    //atap
    glColor3f(0.556863,0.419608,0.137255);
    glBegin(GL_POLYGON);
    glVertex2f(350,450);
    glVertex2f(450,500);
    glVertex2f(900,500);
    glVertex2f(1000,450);
    glEnd();

	//bus
    if(train==1){
        //atas roda bus
        glColor3f(1.0, 1.1, 1.1);
        glBegin(GL_POLYGON);
        glVertex2f(350+i-xm,50);
        glVertex2f(350+i-xm,125);
        glVertex2f(765+i-xm,125);
        glVertex2f(765+i-xm,50);
        glEnd();

        //badan bus
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(360+i-xm,125);
        glVertex2f(360+i-xm,325);
        glVertex2f(755+i-xm,325);
        glVertex2f(755+i-xm,125);
        glEnd();

        glColor3f(1.0,1.0,1.0);
        glRasterPos2f(400+i-xm,200);
        declare("BUS UKSW");

        //jendela
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(375+i-xm,265);
        glVertex2f(375+i-xm,315);
        glVertex2f(435+i-xm,315);
        glVertex2f(435+i-xm,265);
        glEnd();

        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(448+i-xm,265);
        glVertex2f(448+i-xm,315);
        glVertex2f(508+i-xm,315);
        glVertex2f(508+i-xm,265);
        glEnd();

        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(521+i-xm,265);
        glVertex2f(521+i-xm,315);
        glVertex2f(581+i-xm,315);
        glVertex2f(581+i-xm,265);
        glEnd();

        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(594+i-xm,265);
        glVertex2f(594+i-xm,315);
        glVertex2f(654+i-xm,315);
        glVertex2f(654+i-xm,265);
        glEnd();

        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(667+i-xm,265);
        glVertex2f(667+i-xm,315);
        glVertex2f(727+i-xm,315);
        glVertex2f(727+i-xm,265);
        glEnd();

        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(730+i-xm,265);
        glVertex2f(730+i-xm,315);
        glVertex2f(740+i-xm,315);
        glVertex2f(740+i-xm,265);
        glEnd();

        //pintu
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(667+i-xm,140);
        glVertex2f(667+i-xm,250);
        glVertex2f(740+i-xm,250);
        glVertex2f(740+i-xm,140);
        glEnd();

        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(680+i-xm,210);
        glVertex2f(680+i-xm,230);
        glVertex2f(700+i-xm,230);
        glVertex2f(700+i-xm,210);
        glEnd();

        //Atasan
        glColor3f(0.309804,0.184314,0.184314);
        glBegin(GL_POLYGON);
        glVertex2f(350+i-xm,325);
        glVertex2f(350+i-xm,350);
        glVertex2f(765+i-xm,350);
        glVertex2f(765+i-xm,325);
        glEnd();


        //lampu
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(755+i-xm,175);
        glVertex2f(765+i-xm,175);
        glVertex2f(765+i-xm,125);
        glVertex2f(755+i-xm,125);
        glEnd();

        glColor3f(0.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(755+i-xm,175);
        glVertex2f(785+i-xm,175);
        glVertex2f(755+i-xm,205);
        glEnd();

        //Ban
        for(l=0;l<50;l++){
            glColor3f(0.827, 0.827, 0.827);
            draw_circle(425+i-xm,50,l);
            draw_circle(700+i-xm,50,l);
        }
}

    //Papan Stasiun
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(580,500);
    glVertex2f(580,520);
    glVertex2f(590,520);
    glVertex2f(590,500);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(770,500);
    glVertex2f(770,520);
    glVertex2f(780,520);
    glVertex2f(780,500);
    glEnd();

    glColor3f(0.000, 0.000, 0.502);
    glBegin(GL_POLYGON);
    glVertex2f(560,510);
    glVertex2f(560,540);
    glVertex2f(580,550);
    glVertex2f(780,550);
    glVertex2f(800,540);
    glVertex2f(800,510);
    glEnd();

    glColor3f(1.0,1.0,1.0);
         glRasterPos2f(620,520);
         declare("HALTE FTI");
    glFlush();
}

void idle(){
    glClearColor(1.0,1.0,1.0,1.0);

    if(train=1){
        i+=SPEED/50;
        xm+=SPEED/150;
    }

    if(light==0 && (i>=0 && i<=1150)){
        i+=SPEED/25;
        m+=SPEED/150;
        n-=2;
        o+=0.2;
        c+=2;
    }

    if(light==0 && (i>=2600 && i<=3000)){
        i+=SPEED/25;
        m+=SPEED/150;
        n-=2;
        o+=0.2;
        c+=2;
     }

    if(light==0){
        i=i;
        m+=SPEED/150;
        n-=2;
        o+=0.2;
        c+=2;
     }

    else{
        i+=SPEED/25;
        m+=SPEED/150;
        n-=2;
        o+=0.2;
        c+=2;
     }

    if(i>2000){
         i=0.0;
    }
    if(m>1100){
         m=0.0;
    }
    if( o>75){
        plane=0;
     }
    if(c>500){
        comet=0;
    }

    glutPostRedisplay();
}

void keyboardFunc( unsigned char key, int x, int y ){
    switch( key ){
        case 'd':
        case 'D':
            day=1;
        break;

        case 'n':
        case 'N':
            day=0;
        break;

        case 'p':
        case 'P':
            plane=1;
            o=n=0.0;
        break;

        case 'k':
        case 'K':
            comet=1;
            c=0.0;
        break;
        };
}

void myinit(){
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1100.0,0.0,700.0);
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    draw_object();
    glFlush();
}

int main(int argc,char** argv)
{
    int c_menu;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("TR-ANIMASI");
	glutDisplayFunc(display);
    glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	myinit();
	glutMainLoop();
	return 0;
}
