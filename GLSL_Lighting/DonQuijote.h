#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include <iostream>
#include "glsl.h"
#include <time.h>
#include "glm/glm.h"

class DonQuijote
{
	GLMmodel* objmodel_ptr;

public:
	DonQuijote();

	void DibujarDonQuijote(float aX, float aY, float aZ);

	~DonQuijote();
};