#include "Scene.h"

#include "ShaderEyelight.h"
#include "ShaderPhong.h"
#include "PrimTriangle.h"
#include "PrimSphere.h"

#include <fstream>

void CScene::ParseOBJ(const std::string& fileName)
{
	std::cout << "Parsing OBJFile : " << fileName << std::endl;

	std::shared_ptr<IShader> pShader = std::make_shared<CShaderEyelight>(RGB(1, 1, 1));
	// --- PUT YOUR CODE HERE ---

	std::ifstream f(fileName);
	std::vector<Vec3f> vertices;
	char ch;
	float a, b, c;

	while(!f.eof()){
		f >> ch;
		if(ch == 'v'){
			f >> a >> b >> c;
			vertices.push_back(Vec3f(a, b, c) * 100);
		}
		else if(ch == 'f'){
			int x1, x2, x3;
			f >> x1 >> x2 >> x3;
			x1--;
			x2--;
			x3--;
			Add(std::make_shared<CPrimTriangle>(vertices[x1], vertices[x2], vertices[x3], pShader));
		}
	}

	std::cout << "Finished Parsing" << std::endl;
}

