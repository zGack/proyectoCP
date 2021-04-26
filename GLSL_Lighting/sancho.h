#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include <iostream>
#include "glsl.h"
#include <time.h>
#include "glm/glm.h"

class Sancho
{
	GLMmodel* objmodel_ptr;

public:
	Sancho();

	void DibujarSancho(float aX, float aY, float aZ);

	~Sancho();
};