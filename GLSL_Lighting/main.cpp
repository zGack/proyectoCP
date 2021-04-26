//=============================================================================
// Sample Application: Lighting (Per Fragment Phong)
//=============================================================================

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include <iostream>
#include "glsl.h"
#include <time.h>
#include "malla.h"
#include "mill.h"
#include "Devil.h"
#include "sancho.h"
#include "natural.h"
#include "DonQuijote.h"
#include <FreeImage.h>

//#include <FreeImage.h> //*** Para Textura: Incluir librería
#define DELTA_X 0.04
//-----------------------------------------------------------------------------


class myWindow : public cwc::glutWindow
{
protected:
    cwc::glShaderManager SM;
    cwc::glShader* shader;
    cwc::glShader* shader_tex; //Para Textura: variable para abrir los shader de textura
    GLuint ProgramObject;
    clock_t time0, time1;
    float timer010;  // timer counting 0->1->0
    bool bUp;        // flag if counting up or down.
    Malla baseMundo;
    Mill mill;
    Devil devil;
    Sancho sanchito;
    Natural arbolito;
    DonQuijote quijote;
    /* Variables para el moviento */
    bool movXIzq;
    bool movXDer;
    bool movYArr;
    bool movYAb;
    bool movZAd;
    bool movZAt;
    float camX;
    float camY;
    float camZ;
    /* Variable que almacena el id de textura*/
    GLuint texid;
    

public:
	myWindow(){}

    //*** Para Textura: aqui adiciono un método que abre la textura en JPG
    void initialize_textures(void)
    {
        int w, h;
        GLubyte* data = 0;
        //data = glmReadPPM("soccer_ball_diffuse.ppm", &w, &h);
        //std::cout << "Read soccer_ball_diffuse.ppm, width = " << w << ", height = " << h << std::endl;

        //dib1 = loadImage("soccer_ball_diffuse.jpg"); //FreeImage

        glGenTextures(1, &texid);
        glBindTexture(GL_TEXTURE_2D, texid);
        glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

        // Loading JPG file
        FIBITMAP* bitmap = FreeImage_Load(
            FreeImage_GetFileType("./mallas/grass.jpg", 0),
            "./mallas/grass.jpg");  //*** Para Textura: esta es la ruta en donde se encuentra la textura

        FIBITMAP* pImage = FreeImage_ConvertTo32Bits(bitmap);
        int nWidth = FreeImage_GetWidth(pImage);
        int nHeight = FreeImage_GetHeight(pImage);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
            0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

        FreeImage_Unload(pImage);
        //
        glEnable(GL_TEXTURE_2D);
    }

    void posCamara()
    {
        if (movXIzq == true)
        {
            camX = camX - DELTA_X;
        }
        if (movXDer == true)
        {
            camX = camX + DELTA_X;
        }
        if (movYArr == true)
        {
            camY = camY + DELTA_X;
        }
        if (movYAb == true)
        {
            camY = camY - DELTA_X;
        }
        if (movZAd == true)
        {
            camZ = camZ + DELTA_X;
        }
        if (movZAt == true)
        {
            camZ = camZ - DELTA_X;
        }

    } 

	virtual void OnRender(void)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();

        if (shader) shader->begin();
            //posCamara();
            glPushMatrix();
                glPushMatrix();
                    if (shader) shader->begin();

                    //Se simula el movimiento de la camara trasladando la escena
                    posCamara();
                    glTranslatef(camX, camY, camZ);
                    //glTranslatef(0.0f, 0.0f, 2.0f);
                    glRotated(20, 5, 2, 0);

                    // BASE DEL MUNDO SIN TEXTURA
                    /*glPushMatrix();

                        baseMundo.DibujarMalla(0.0f, 0.07f, 0.0f);

                    glPopMatrix();
                    */
                     
                    // MOLINO 1 DEVIL
                    glPushMatrix();

                        //mill.DibujarMill(0.0f, 0.33f, 0.0f);
                        devil.DibujarDevil(0.0f, 0.33f, 0.0f);
                    
                    glPopMatrix();

                    // MOLINO 2
                    glPushMatrix();

                        mill.DibujarMill(0.3f, 0.33f, 0.0f);

                    glPopMatrix();

                    // MOLINO 3
                    glPushMatrix();

                        mill.DibujarMill(-0.3f, 0.33f, 0.0f);

                    glPopMatrix();


                    // MOLINO 4
                    glPushMatrix();

                        mill.DibujarMill(-0.6f, 0.25f, 0.3f);

                    glPopMatrix();

                    // Sancho Panza
                    glPushMatrix();
                          
                        //glRotated(-90, 0.2, 0.0f, 0.0f);
                       // glRotatef(-40, 0, 2, 1);
                        sanchito.DibujarSancho(0.0f, 0.15f, 0.6f);

                    glPopMatrix();

                    // Don Quijote
                    glPushMatrix();

                        quijote.DibujarDonQuijote(0.2f, 0.2f, 0.6f);

                    glPopMatrix();
         
                    /* NATURAL ARBOL 1*/
                    glPushMatrix();

                        arbolito.DibujarArbol(0.3f, 0.15f, 0.9f);

                    glPopMatrix();


                    /* NATURAL ARBOL 2*/
                    glPushMatrix();

                        arbolito.DibujarArbol(-0.4f, 0.15f, 0.9f);

                    glPopMatrix();


                    /* NATURAL ARBOL 3*/
                    glPushMatrix();

                        arbolito.DibujarArbol(-0.6f, 0.15f, 0.7f);

                    glPopMatrix();


                    /* NATURAL ARBOL 4*/
                    glPushMatrix();

                        arbolito.DibujarArbol(-0.6f, 0.15f, 0.7f);

                    glPopMatrix();


                    /* NATURAL ARBOL 5*/
                    glPushMatrix();

                        arbolito.DibujarArbol(-0.6f, 0.15f, 0.7f);

                    glPopMatrix();

                    /* NATURAL ARBOL 6*/
                    glPushMatrix();

                        arbolito.DibujarArbol(-0.5f, 0.15f, 0.5f);

                    glPopMatrix();
                   
                    /*NATURAL ARBOL 7*/
                    glPushMatrix();

                        arbolito.DibujarArbol(-0.8f, 0.2f, 0.4f);

                    glPopMatrix();
                    
                    if (shader) shader->end();

                    //*** Para Textura: llamado al shader para objetos texturizados
                    if (shader_tex) shader_tex->begin();

                        // BASE DEL MUNDO CON TEXTURA
                        glPushMatrix();
                            glBindTexture(GL_TEXTURE_2D, texid);
                            baseMundo.DibujarMallaTex(0.0f, 0.07f, 0.0f, GLM_TEXTURE);
                        glPopMatrix();
                        
                    if (shader_tex) shader_tex->end();

                    glutSwapBuffers();
                glPopMatrix();
            glPopMatrix();
        
        glPopMatrix();
        UpdateTimer();
        Repaint();
	}

	virtual void OnIdle() {}

	// When OnInit is called, a render context (in this case GLUT-Window) 
	// is already available!
	virtual void OnInit()
	{
		glClearColor(0.5f, 0.5f, 1.0f, 0.0f);
		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);
           
        baseMundo = Malla();
        mill = Mill();
        devil = Devil();
        sanchito = Sancho();
        arbolito = Natural();
        quijote = DonQuijote();

        time0 = clock();
        timer010 = 0.0f;
        bUp = true;

		shader = SM.loadfromFile("vertexshader.txt","fragmentshader.txt"); // load (and compile, link) from file
		if (shader==0) 
            std::cout << "Error Loading, compiling or linking shader\n";
        else
        {
            ProgramObject = shader->GetProgramObject();
        }

        //*** Para Textura: abre los shaders para texturas
        shader_tex = SM.loadfromFile("vertexshaderT.txt", "fragmentshaderT.txt"); // load (and compile, link) from file
        if (shader_tex == 0)
            std::cout << "Error Loading, compiling or linking shader\n";
        else
        {
            ProgramObject = shader_tex->GetProgramObject();
        }

      initialize_textures(); //*** Para Textura: abrir archivo de textura
      DemoLight();
      camX = 0;
      movXDer = false;
      movXIzq = false;
      movYArr = false;
      movYAb = false;
      movZAd = false;
      movZAt = false;
      camY = 0;
      camZ = 0;
	}

	virtual void OnResize(int w, int h)
   {
      if(h == 0) h = 1;
	   float ratio = 1.0f * (float)w / (float)h;

      glMatrixMode(GL_PROJECTION);
	   glLoadIdentity();
	
	   glViewport(0, 0, w, h);

       gluPerspective(45,ratio,1,100);
	   glMatrixMode(GL_MODELVIEW);
	   glLoadIdentity();
	   gluLookAt(0.0f,0.0f,4.0f, 
		          0.0,0.0,-1.0,
			       0.0f,1.0f,0.0f);
   }
	virtual void OnClose(void){}
	virtual void OnMouseDown(int button, int x, int y) {}    
	virtual void OnMouseUp(int button, int x, int y) {}
	virtual void OnMouseWheel(int nWheelNumber, int nDirection, int x, int y){}

	virtual void OnKeyDown(int nKey, char cAscii)
	{       
        switch (cAscii) {

        case 27:
            this->Close(); // Close Window!
            break;
        case 'a':
            movXIzq = true;
            break;
        case 'd':
            movXDer = true;
            break;
        case 'w':
            movYArr = true;
            break;
        case 's':
            movYAb = true;
            break;

        case 'z':
            movZAt = true;
            break;
        case 'x':
            movZAd = true;
            break;
        }
	};

	virtual void OnKeyUp(int nKey, char cAscii)
	{
        /*if (cAscii == 's')      // s: Shader
                 shader->enable();
              else if (cAscii == 'f') // f: Fixed Function
                 shader->disable();
            */
        switch (cAscii) {

        case 27:
            this->Close(); // Close Window!
            break;
        case 'a':
            movXIzq = false;
            break;
        case 'd':
            movXDer = false;
            break;
        case 'w':
            movYArr = false;
            break;
        case 's':
            movYAb = false;
            break;
        case 'z':
            movZAt = false;
            break;
        case 'x':
            movZAd = false;
            break;

        }
	}

   void UpdateTimer()
   {
      time1 = clock();
      float delta = static_cast<float>(static_cast<double>(time1-time0)/static_cast<double>(CLOCKS_PER_SEC));
      delta = delta / 4;
      if (delta > 0.00005f)
      {
         time0 = clock();
         if (bUp)
         {
            timer010 += delta;
            if (timer010>=1.0f) { timer010 = 1.0f; bUp = false;}
         }
         else
         {
            timer010 -= delta;
            if (timer010<=0.0f) { timer010 = 0.0f; bUp = true;}
         }
      }
   }

   void DemoLight(void)
   {
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glEnable(GL_NORMALIZE);
     
     // Light model parameters:
     // -------------------------------------------
     
    /*s
     GLfloat lmKa[] = {0.0, 0.0, 0.0, 0.0 };
     glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmKa);
     
     glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 0.2);
     glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 0.0);
    * 
     // -------------------------------------------
     // Spotlight Attenuation
     
     GLfloat spot_direction[] = {1.0, -1.0, -1.0 };
     GLint spot_exponent = 30;
     GLint spot_cutoff = 180;
     
     glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
     glLighti(GL_LIGHT0, GL_SPOT_EXPONENT, spot_exponent);
     glLighti(GL_LIGHT0, GL_SPOT_CUTOFF, spot_cutoff);
    
     GLfloat Kc = 1.0;
     GLfloat Kl = 0.0;
     GLfloat Kq = 0.0;
     
     glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION,Kc);
     glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, Kl);
     glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, Kq);
     
     
     // ------------------------------------------- 
     // Lighting parameters:

     GLfloat light_pos[] = {0.0f, 5.0f, 5.0f, 1.0f};
     GLfloat light_Ka[]  = {1.0f, 0.5f, 0.5f, 1.0f};
     GLfloat light_Kd[]  = {1.0f, 0.1f, 0.1f, 1.0f};
     GLfloat light_Ks[]  = {1.0f, 1.0f, 1.0f, 1.0f};

     glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
     glLightfv(GL_LIGHT0, GL_AMBIENT, light_Ka);
     glLightfv(GL_LIGHT0, GL_DIFFUSE, light_Kd);
     glLightfv(GL_LIGHT0, GL_SPECULAR, light_Ks);

     // -------------------------------------------
     // Material parameters:

     GLfloat material_Ka[] = {0.5f, 0.0f, 0.0f, 1.0f};
     GLfloat material_Kd[] = {0.4f, 0.4f, 0.5f, 1.0f};
     GLfloat material_Ks[] = {0.8f, 0.8f, 0.0f, 1.0f};
     GLfloat material_Ke[] = {0.1f, 0.0f, 0.0f, 0.0f};
     GLfloat material_Se = 20.0f;

     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
     glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_Ke);
     glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);*/
   }
};

//-----------------------------------------------------------------------------

class myApplication : public cwc::glApplication
{
public:
	virtual void OnInit() {std::cout << "Hello World!\n"; }
};

//-----------------------------------------------------------------------------

int main(void)
{
	myApplication*  pApp = new myApplication;
	myWindow* myWin = new myWindow();

	pApp->run();
	delete pApp;
	return 0;
}

//-----------------------------------------------------------------------------

