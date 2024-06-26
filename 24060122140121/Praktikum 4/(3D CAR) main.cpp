/*
Nama   = Rosidah Rahmati
NIM    = 24060122140121
Lab    = B2
Projek = Mobil 3 Dimensi
*/

#include <math.h> 
#include <GL/glut.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

float angle=0.0, deltaAngle = 0.0, ratio; 
float x=0.0f,y=1.75f,z=15.0f; // posisi awal kamera 
float lx=0.0f,ly=0.0f,lz=-1.0f; 
int deltaMove = 0,h,w; 
int bitmapHeight=12; 

void Reshape(int w1, int h1) 
{ 
 	// Fungsi reshape 
 	if(h1 == 0) h1 = 1; 
 	w = w1; 
 	h = h1; 
 	ratio = 1.0f * w / h; 
 	glMatrixMode(GL_PROJECTION); 
 	glLoadIdentity(); 
 	glViewport(0, 0, w, h); 
 	gluPerspective(45,ratio,0.1,1000); 
 	glMatrixMode(GL_MODELVIEW); 
 	glLoadIdentity(); 
 	gluLookAt(
 		x, y, z, 
 		x + lx,y + ly,z + lz, 
 		0.0f,1.0f,0.0f); 
} 

void orientMe(float ang) 
{ 
 // Fungsi ini untuk memutar arah kamera (tengok kiri/kanan) 
 	lx = sin(ang); 
 	lz = -cos(ang); 
 	glLoadIdentity(); 
 	gluLookAt(x, y, z, 
 		x + lx,y + ly,z + lz, 
 		0.0f,1.0f,0.0f); 
} 

void moveMeFlat(int i) 
{ 
 // Fungsi ini untuk maju mundur kamera 
 	x = x + i*(lx)*0.1; 
 	z = z + i*(lz)*0.1; 
 	glLoadIdentity(); 
 	gluLookAt(x, y, z, 
 		x + lx,y + ly,z + lz, 
 	0.0f,1.0f,0.0f); 
} 

void Grid() { 
 // Fungsi untuk membuat grid di "lantai" 
 	double i; 
 	const float Z_MIN = -50, Z_MAX = 50; 
 	const float X_MIN = -50, X_MAX = 50; 
 	const float gap = 1.5; 
 	glColor3f(0.5, 0.5, 0.5); 
 	glBegin(GL_LINES); 
	 	for(i=Z_MIN;i<Z_MAX;i+=gap) 
	 	{ 
	 		glVertex3f(i, 0, Z_MIN); 
	 		glVertex3f(i, 0, Z_MAX); 
	 	} 
	 	for(i=X_MIN;i<X_MAX;i+=gap) 
	 	{ 
			 glVertex3f(X_MIN, 0, i); 
	 		glVertex3f(X_MAX, 0, i); 
		 } 
 	glEnd(); 
} 

void Mobil() 
{  	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glPushMatrix();
			//Badan Mobil
			glPushMatrix();
				glColor3f(0.8f, 0.0f, 0.0f);                   
				glScalef(4.0, 1.0, 2.0);
			    glutSolidCube(2.5);
		    
			    glTranslatef(-0.05, 1.5, 0.0);
			    glScalef(0.5, 3.0, 2.0);
			    glutSolidCube(1.25);
			    
			    glTranslatef(-0.52, -0.01, 0.0);  
			    glScalef(3.0, 1.8, 2.48);
			    glRotatef(230.0, 0.0, 0.0, 250.0);
			    glutSolidCube(0.5);
		    glPopMatrix();
			
			//Plat Mobil
			glPushMatrix();
				glColor3f(0.0f, 0.0f, 0.0f);
				glTranslatef(0.0, -0.5, 0.0);
				glScalef(5.2, 0.3, 0.8);
			    glutSolidCube(2.0);
			glPopMatrix();
			
			//Lampu Depan Kanan
			glPushMatrix();
				glColor3f(1.0f, 0.45f, 0.0f);
				glTranslatef(-4.7, 0.0, -2.15);
				glScalef(0.4, 0.4, 0.4);
			    glutSolidCube(2.0);
			glPopMatrix();
			
			//Lampu Depan Kiri
			glPushMatrix();
				glColor3f(1.0f, 0.45f, 0.0f);
				glTranslatef(-4.7, 0.0, 2.15);
				glScalef(0.4, 0.4, 0.4);
			    glutSolidCube(2.0);
			glPopMatrix();
			
			//Lampu Belakang Kanan
			glPushMatrix();
				glColor3f(1.0f, 0.45f, 0.0f);
				glTranslatef(4.7, 0.0, -2.15);
				glScalef(0.4, 0.4, 0.4);
			    glutSolidCube(2.0);
			glPopMatrix();
			
			//Lampu Belakang Kiri
			glPushMatrix();
				glColor3f(1.0f, 0.45f, 0.0f);
				glTranslatef(4.7, 0.0, 2.15);
				glScalef(0.4, 0.4, 0.4);
			    glutSolidCube(2.0);
			glPopMatrix();
			
			//Ban Mobil Kanan
			glTranslatef(0.0, 0.0, -2.8);
			glPushMatrix();
				glColor3f(0.0f, 0.0f, 0.0f);
			    glTranslatef(-2.8,-1.1,0.0);
			    glutSolidTorus(0.35,0.7,16.0,16.0);   
				    
			    glTranslatef(5.8,0.0,0.0);
			    glutSolidTorus(0.35,0.7,16.0,16.0);       
		    glPopMatrix();
		    
		    //Ban Mobil Kiri
		    glTranslatef(0.0,0.0,5.6);
		    glPushMatrix();
			    glTranslatef(-2.8,-1.1,0.0);
			    glutSolidTorus(0.35,0.7,16.0,16.0);   
				    
			    glTranslatef(5.8,0.0,0.0);
			    glutSolidTorus(0.35,0.7,16.0,16.0);     
		    glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	glFlush();
}

void BagianMobil()
{
	glPushMatrix();
		//Spion Kanan
	    glColor3f(0.6f, 0.0f, 0.0f); 
	    glBegin(GL_POLYGON); 
		    glVertex3f(-2.85f, 1.1f, -2.6f); 
		    glVertex3f(-2.85f, 1.6f, -2.6f); 
		    glVertex3f(-2.0f, 1.6f, -2.6f); 
		    glVertex3f(-2.0f, 1.1f, -2.6f); 
	    glEnd();
	    
	    //Spion Kiri
	    glColor3f(0.6f, 0.0f, 0.0f); 
	    glBegin(GL_POLYGON); 
		    glVertex3f(-2.85f, 1.1f, 2.6f); 
		    glVertex3f(-2.85f, 1.6f, 2.6f); 
		    glVertex3f(-2.0f, 1.6f, 2.6f); 
		    glVertex3f(-2.0f, 1.1f, 2.6f); 
	    glEnd();
	    
		//Kaca Kanan 
	    glColor3f(0.0f, 0.0f, 0.0f); 
	    glBegin(GL_POLYGON); 
		    glVertex3f(0.7f, 1.4f, -2.6f); 
		    glVertex3f(-2.8f, 1.4f, -2.6f); 
		    glVertex3f(-1.3f, 3.1f, -2.6f); 
		    glVertex3f(0.7f, 3.1f, -2.6f); 
	    glEnd();
	    
	    //Kaca Kiri
	    glColor3f(0.0f, 0.0f, 0.0f); 
	    glTranslatef(0.0, 0.0, 5.15);
	    glBegin(GL_POLYGON); 
		    glVertex3f(0.7f, 1.4f, -2.6f); 
		    glVertex3f(-2.8f, 1.4f, -2.6f); 
		    glVertex3f(-1.3f, 3.1f, -2.6f); 
		    glVertex3f(0.7f, 3.1f, -2.6f); 
	    glEnd();
	    
	    //Kaca Depan
	    glColor3f(0.0f, 0.0f, 0.0f);
	    glBegin(GL_POLYGON); 
		    glVertex3f(-3.3f, 1.4f, -7.3f);
		    glVertex3f(-3.3f, 1.4f, -3.0f);
		    glVertex3f(-1.8f, 3.1f, -3.0f);
		    glVertex3f(-1.8f, 3.1f, -7.3f); 
	    glEnd();
	    
	    //Kaca Belakang
	    glColor3f(0.0f, 0.0f, 0.0f);
	    glBegin(GL_POLYGON); 
		    glVertex3f(1.09f, 1.4f, -7.3f);
		    glVertex3f(1.09f, 1.4f, -3.0f);
		    glVertex3f(1.09f, 3.1f, -3.0f);
		    glVertex3f(1.09f, 3.1f, -7.3f); 
	    glEnd();

	    //Handle Pintu Kiri
	    glColor3f(0.0f, 0.0f, 0.0f); 
	    glBegin(GL_POLYGON); 
		    glVertex3f(0.9f, 0.9f, -2.6f); 
		    glVertex3f(0.9f, 1.2f, -2.6f); 
		    glVertex3f(0.09f, 1.2f, -2.6f); 
		    glVertex3f(0.09f, 0.9f, -2.6f); 
	    glEnd();
	    
	    //Handle Pintu Kanan
	    glColor3f(0.0f, 0.0f, 0.0f); 
	    glTranslatef(0.0, 0.0, -5.15);
	    glBegin(GL_POLYGON); 
		    glVertex3f(0.9f, 0.9f, -2.6f); 
		    glVertex3f(0.9f, 1.2f, -2.6f); 
		    glVertex3f(0.09f, 1.2f, -2.6f); 
		    glVertex3f(0.09f, 0.9f, -2.6f); 
	    glEnd();
	    
	    //Tangki Bensin
	    glColor3f(0.0f, 0.0f, 0.0f);
		glTranslatef(0.0, 0.0, 5.15); 
	    glBegin(GL_POLYGON); 
		    glVertex3f(1.6f, 0.0f, -2.5f); 
		    glVertex3f(1.6f, -0.6f, -2.5f); 
		    glVertex3f(0.9f, -0.6f, -2.5f); 
		    glVertex3f(0.9f, 0.0f, -2.5f); 
	    glEnd();
	    
	    //Pegangan Belakang Kiri
	    glLineWidth(5.0f);
		glBegin(GL_LINES);
		glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(1.05f,2.7f,-2.8f);
			glVertex3f(2.0f,2.7f,-2.8f);
		glEnd();
		
		glLineWidth(5.0f);
		glBegin(GL_LINES);
		glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(2.0f,2.7f,-2.8f);
			glVertex3f(2.0f,1.2f,-2.8f);
		glEnd();
		
		glLineWidth(5.0f);
		glBegin(GL_LINES);
		glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(2.0f,2.7f,-2.8f);
			glVertex3f(4.0f,1.0f,-2.8f);
		glEnd();
	    
	    //Pegangan Belakang Kanan
	    glLineWidth(5.0f);
		glBegin(GL_LINES);
		glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(1.05f,2.7f,-7.4f);
			glVertex3f(2.0f,2.7f,-7.4f);
		glEnd();
		
		glLineWidth(5.0f);
		glBegin(GL_LINES);
		glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(2.0f,2.7f,-7.4f);
			glVertex3f(2.0f,1.2f,-7.4f);
		glEnd();
		
		glLineWidth(5.0f);
		glBegin(GL_LINES);
		glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(2.0f,2.7f,-7.4f);
			glVertex3f(4.0f,1.0f,-7.4f);
		glEnd();
	    
	    //List Body Bawah Kiri
	    glColor3f(0.6f, 0.0f, 0.0f); 
	    glBegin(GL_POLYGON); 
		    glVertex3f(5.1f, -0.25f, -2.6f); 
		    glVertex3f(5.1f, -1.25f, -2.6f); 
		    glVertex3f(-5.1f, -1.25f, -2.6f); 
		    glVertex3f(-5.1f, -0.25f, -2.6f);  
	    glEnd();
	    
	    //List Body Bawah Kanan
	    glColor3f(0.6f, 0.0f, 0.0f); 
	    glTranslatef(0.0, 0.0, -5.15);
	    glBegin(GL_POLYGON); 
		    glVertex3f(5.1f, -0.25f, -2.6f); 
		    glVertex3f(5.1f, -1.25f, -2.6f); 
		    glVertex3f(-5.1f, -1.25f, -2.6f); 
		    glVertex3f(-5.1f, -0.25f, -2.6f);  
	    glEnd();
	    
	    //List Body Bawah Depan
	    glColor3f(0.6f, 0.0f, 0.0f); 
	    glTranslatef(-0.05, 0.0, 0.0);
	    glBegin(GL_POLYGON); 
		    glVertex3f(-4.99f, -0.25f, -2.6f); 
		    glVertex3f(-4.99f, -1.25f, -2.6f); 
		    glVertex3f(-4.99f, -1.25f, 2.6f); 
		    glVertex3f(-4.99f, -0.25f, 2.6f);  
	    glEnd();
	    
	    //List Body Bawah Belakang
	    glColor3f(0.6f, 0.0f, 0.0f); 
	    glTranslatef(10.1, 0.0, 0.0);
	    glBegin(GL_POLYGON); 
		    glVertex3f(-4.99f, -0.25f, -2.6f); 
		    glVertex3f(-4.99f, -1.25f, -2.6f); 
		    glVertex3f(-4.99f, -1.25f, 2.6f); 
		    glVertex3f(-4.99f, -0.25f, 2.6f);  
	    glEnd();
    glPopMatrix(); 
}

void display() { 
 // Kalau move dan angle tidak nol, gerakkan kamera... 
 	if (deltaMove) 
 		moveMeFlat(deltaMove); 
 	if (deltaAngle) { 
 		angle += deltaAngle; 
 		orientMe(angle); 
 	} 
 	glClearColor(1.0, 1.0, 1.0, 1.0);
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
 	
 // Gambar grid 
 	Grid(); 
 	
 // Gambar objek di sini... 
 	Mobil(); 
 	BagianMobil();
 	glutSwapBuffers(); 
 	glFlush(); 
} 

void pressKey(int key, int x, int y) { 
 // Fungsi ini akan dijalankan saat tombol keyboard ditekan dan belum dilepas 
 // Selama tombol ditekan, variabel angle dan move diubah => kamera bergerak 
 	switch (key) { 
 	case GLUT_KEY_LEFT : deltaAngle = -0.001f;break; 
 	case GLUT_KEY_RIGHT : deltaAngle = 0.001f;break; 
 	case GLUT_KEY_UP : deltaMove = 1;break; 
 	case GLUT_KEY_DOWN : deltaMove = -1;break; 
 	} 
} 

void releaseKey(int key, int x, int y) { 
 // Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas 
 // Saat tombol dilepas, variabel angle dan move diset nol => kamera berhenti 
 	switch (key) { 
 	case GLUT_KEY_LEFT : 
 	if (deltaAngle < 0.0f) 
 		deltaAngle = 0.0f; 
 		break; 
 	case GLUT_KEY_RIGHT : 
	if (deltaAngle > 0.0f) 
 		deltaAngle = 0.0f; 
 		break; 
 	case GLUT_KEY_UP :
	if (deltaMove > 0) 
 		deltaMove = 0; 
 		break; 
 	case GLUT_KEY_DOWN : 
	if (deltaMove < 0) 
 		deltaMove = 0; 
 		break; 
 	} 
} 

// Variable untuk pencahayaan 
	const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f }; 
	const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
	const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
	const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f }; 
	const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f }; 
	const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; 
	const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
	const GLfloat high_shininess[] = { 100.0f }; 
	
void lighting(){ 
 // Fungsi mengaktifkan pencahayaan 
 	glEnable(GL_DEPTH_TEST); 
	glDepthFunc(GL_LESS); 
 	glEnable(GL_LIGHT0); 
 	glEnable(GL_NORMALIZE); 
 	glEnable(GL_COLOR_MATERIAL); 
 	glEnable(GL_LIGHTING); 
 	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); 
 	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); 
 	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); 
 	glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient); 
 	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); 
 	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); 
 	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 
} 

void init(void) 
{ 
 	glEnable (GL_DEPTH_TEST); 
 	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
} 

int main(int argc, char **argv) 
{ 
 	glutInit(&argc, argv); 
 	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
 	glutInitWindowPosition(100,100); 
 	glutInitWindowSize(640,480); 
 	glutCreateWindow("3D CAR"); 
 	glutIgnoreKeyRepeat(1); // Mengabaikan key repeat (saat tombol keyboard dipencet terus) 
 	glutSpecialFunc(pressKey);
 	glutSpecialUpFunc(releaseKey); 
 	glutDisplayFunc(display); 
 	glutIdleFunc(display); // Fungsi display-nya dipanggil terusmenerus 
 	glutReshapeFunc(Reshape); 
 	lighting(); 
 	init(); 
 	glutMainLoop(); 
}
