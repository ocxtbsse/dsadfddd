#include "Scene.hpp"
#include <vector>
#include <iostream>

extern int meshLoadUlta(GameObject& targetObj,char* modelName);
extern unsigned int textureLoad(const char* path);
std::vector<GameObject> sceneObjects;
std::vector<Camera> sceneCamers;

int startSceneCreateOnjects(){
    Camera cam;
    cam.position = glm::vec3(0.0f, 0.0f, -2.0f);
    cam.front = glm::vec3(0.0f, 0.0f, -1.0f);
    cam.up = glm::vec3(0.0f, 1.0f, 0.0f); 
    pushBackCamera(cam);



    GameObject cube;
    cube.mesh.modelName = "models/model2.obj";
    meshLoadUlta(cube,cube.mesh.modelName);


    cube.material.textureName = "textures/treeT.jpg";
    cube.material.textureID = textureLoad(cube.material.textureName);

    cube.position = glm::vec3(0.0f,-4.0f,-2.0f);
    cube.rotation = glm::vec3(-90.0f, 0.0f, 0.0f); 
    cube.scale = glm::vec3(10.0f,10.0f,10.0f);
    pushBackObject(cube);




    GameObject cube3;
    cube3.mesh.modelName = "models/model.obj";
    meshLoadUlta(cube3,cube3.mesh.modelName);


    cube3.material.textureName = "textures/listva.jpg";
    cube3.material.textureID = textureLoad(cube3.material.textureName);

    cube3.position = glm::vec3(0.0f,-4.0f,-2.0f);
    cube3.rotation = glm::vec3(0.0f, 0.0f, 0.0f); 
    cube3.scale = glm::vec3(10.0f,10.0f,10.0f);
    pushBackObject(cube3);





    GameObject cube2;
    cube2.mesh.modelName = "models/cube.obj";
    meshLoadUlta(cube2,cube2.mesh.modelName);

    
    cube2.material.textureName = "textures/wall.jpg";
    cube2.material.textureID = textureLoad(cube2.material.textureName);


    cube2.position = glm::vec3(0.0f,-5.0f,-2.0f);
    cube2.rotation = glm::vec3(0.0f, 0.0f, 0.0f); 
    cube2.scale = glm::vec3(100.0f,1.0f,100.0f);
    pushBackObject(cube2);









    return 0;
}








void pushBackObject(GameObject PtrGMO){
    sceneObjects.push_back(PtrGMO);    
}


void pushBackCamera(Camera PtrCam){
    sceneCamers.push_back(PtrCam);
}


