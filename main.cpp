#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "glut.h"
#include "color.h"
#include <stdlib.h>
#include "time.h"

#define DEPTH 3

color Color(1.0, 1.0, 1.0);
int matrix[25];

void init ()
{
	glClearColor (0.2, 0.2, 0.35, 0.0); // sets background Color to black
	glMatrixMode (GL_PROJECTION); // sets up viewing values (do not worry about this too much)
	glLoadIdentity ();
	glOrtho (-100.0, 100.0, -100.0, 100.0, -1.0, 1.0); // sets up “graph paper” for you to draw on
	char * line = new char;
	int i = 0;
	std::ifstream file("C:/Developing/Q/Q/Matrix.txt");
	if (file.is_open())	{
		while (file.good() && i < 25)		{
			int let = file.get();
			if (let != '\n' && let != ' ')	{
				matrix[i] = let - '0';
				i++;
			}
		}
	}
	else	{
		std::cout << "Error opening file." << std::endl;
	}
	file.close();
	srand(time(0));
	system("start notepad C:/Developing/Q/Q/Matrix.txt");
}

void perfect(float X, float Y, int sides, float sideWidth, int degOffset=0)	{
	int angleEach = (360 / sides);
	float halfHeight = sideWidth / 2.0 / tan(angleEach / 2 / (180.0 / M_PI));
	float hyp = halfHeight / cos(angleEach / 2 / (180 / M_PI));
	glBegin(GL_POLYGON);
		for (int i=0; i<sides; i++)   {
			float deg = (i * angleEach - angleEach / 2 + degOffset) / (180.0 / M_PI);
			glVertex3f(X + sin(deg) * hyp,
				Y + cos(deg) * hyp, 0.0);
		}
	glEnd();
}

float xByIndex(int i, float size)	{     return (i % 5) * size ; }
float yByIndex(int i, float size)	{return -1 * (i / 5  * size);}

void drawFractal(float x=-100.0, float y=100.0, float size=200.0, int frame=0)	{
	size = size / 5.0;
	for (int i=0; i<25; i++)	{
		if (matrix[i])	{
			if (frame < DEPTH)	{
				drawFractal(xByIndex(i, size) + x, yByIndex(i, size) + y, size, frame + 1);
			}
			else	{
				perfect(xByIndex(i, size) + size / 2.0 + x, yByIndex(i, size) + size / 2.0 + y, 4, size);
			}
		}
	}
}

void display()
{
    glClear (GL_COLOR_BUFFER_BIT); // clears screen
	glColor3f (Color[0], Color[1], Color[2]); // sets Color for drawing operations to white
	drawFractal();
  	glutSwapBuffers (); // makes sure commands are executed immediately
}

void update()	{
	char * line = new char;
	int i = 0;
	std::ifstream file("C:/Developing/Q/Q/Matrix.txt");
	if (file.is_open())	{
		while (file.good() && i < 25)		{
			int let = file.get();
			if (let != '\n' && let != ' ')	{
				matrix[i] = let - '0';
				i++;
			}
		}
	}
	else	{
		std::cout << "Error opening file." << std::endl;
	}
	file.close();
	glutPostRedisplay();
}

void refresh(unsigned char key, int x, int y)	{
	if (key == 'r')	{
		char * line = new char;
		int i = 0;
		std::ifstream file("C:/Developing/Q/Q/Matrix.txt");
		if (file.is_open())	{
			while (file.good() && i < 25)		{
				int let = file.get();
				if (let != '\n' && let != ' ')	{
					matrix[i] = let - '0';
					i++;
				}
			}
		}
		else	{
			std::cout << "Error opening file." << std::endl;
		}
		file.close();
		glutPostRedisplay();
	}
}

int main(int argc, char** argv)
{
	glutInit (&argc, argv); // initialization
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); // certain settings
	glutInitWindowSize (500, 500); // sets window size in pixels (horizontal and vertical)
	glutInitWindowPosition (10, 10); // upper left corner position
	glutCreateWindow ("Indidraw!"); // sets the window title
	init (); // calls the init() function 
	glutDisplayFunc (display); // uses the function called “display” for displaying
	glutKeyboardFunc(refresh);
	glutIdleFunc(update);
	glutMainLoop (); // will execute OpenGL functions continuously
	glutPostRedisplay();
	return 0;
}