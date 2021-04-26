#include "Malla.h"

Malla::Malla() {
	objmodel_ptr = NULL;

	if (!objmodel_ptr) {
		//objmodel_ptr = glmReadOBJ("./mallas/base_mundo_creada.obj");
		objmodel_ptr = glmReadOBJ("./mallas/malla_color/base_mundo_creada1.obj");
		if (!objmodel_ptr)
			exit(0);

		glmUnitize(objmodel_ptr);
		glmFacetNormals(objmodel_ptr);
		glmVertexNormals(objmodel_ptr, 90.0);
	}
}

void Malla::DibujarMalla(float aX, float aY, float aZ) {
	
	glPushMatrix();

		glTranslatef(aX, aY, aZ);
		glmDraw(objmodel_ptr, GLM_SMOOTH | GLM_MATERIAL);

	glPopMatrix();
}

void Malla::DibujarMallaTex(float aX, float aY, float aZ, int texture) {

	glPushMatrix();

		glTranslatef(aX, aY, aZ);
		//glBindTexture(GL_TEXTURE_2D, texid);
		glmDraw(objmodel_ptr, GLM_SMOOTH | GLM_MATERIAL | texture);

	glPopMatrix();
}

Malla::~Malla() {}