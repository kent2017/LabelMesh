#include <string.h>
#include <iostream>
#include <assert.h>

#include "common/myMesh.h"
#include "common/myWindow.h"


std::string inputFile = R"(D:\MyProjects\3D_Labeling\src\C01000597025_L.stl)";


int main() {
	MyWindow window(1600, 900);
	if (!window.Init()) {
		return -1;
	}

	window.ReadMeshFile(inputFile);
	window.Run();

	return 0;
}
