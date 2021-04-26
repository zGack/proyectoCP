#include "DonQuijote.h"

DonQuijote::DonQuijote() {
	objmodel_ptr = NULL;

	if (!objmodel_ptr) {
		objmodel_ptr = glmReadOBJ("./mallas/malla_color/don_quijote.obj");
		if (!objmodel_ptr)
			exit(0);

		glmUnitize(objmodel_ptr);
		glmFacetNormals(objmodel_ptr);
		glmVertexNormals(objmodel_ptr, 90.0);
		glmScale(objmodel_ptr, 0.1);
	}
}

void DonQuijote::DibujarDonQuijote(float aX, float aY, float aZ) {

	glPushMatrix();

	glTranslatef(aX, aY, aZ);
	glmDraw(objmodel_ptr, GLM_SMOOTH | GLM_MATERIAL);

	glPopMatrix();
}



DonQuijote::~DonQuijote() {}