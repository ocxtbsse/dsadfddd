#include "Scene.hpp"
#include <vector>
#include <iostream>

extern int meshLoadUlta(GameObject& targetObj,char* modelName);
extern unsigned int textureLoad(const char* path);
std::vector<GameObject> sceneObjects;
std::vector<Camera> sceneCamers;

int startSceneCreateOnjects(){
    Camera cam;


    cam.position.vec3[X] = 0.0f;
    cam.position.vec3[Y] = 0.0f;
    cam.position.vec3[Z] = -2.0f;


    cam.front.vec3[X] = 0.0f;
    cam.front.vec3[Y] = 0.0f;
    cam.front.vec3[Z] = -1.0f;

    cam.up.vec3[X] = 0.0f;
    cam.up.vec3[Y] = 1.0f;
    cam.up.vec3[Z] = 0.0f;

    pushBackCamera(cam);









    GameObject cube2;
    cube2.mesh.modelName = "models/cube.obj";
    meshLoadUlta(cube2,cube2.mesh.modelName);

    
    cube2.material.textureName = "textures/wall.jpg";
    cube2.material.textureID = textureLoad(cube2.material.textureName);


    cube2.position.vec3[X] = 0.0f;
    cube2.position.vec3[Y] = -5.0f;
    cube2.position.vec3[Z] = -2.0f;


    cube2.rotate.vec3[X] = 0.0f;
    cube2.rotate.vec3[Y] = 0.0f;
    cube2.rotate.vec3[Z] = 0.0f;

    cube2.scale.vec3[X] = 100.0f;
    cube2.scale.vec3[Y] = 1.0f;
    cube2.scale.vec3[Z] = 100.0f;
    pushBackObject(cube2);










    

    return 0;
}








void pushBackObject(GameObject PtrGMO){
    sceneObjects.push_back(PtrGMO);    
}


void pushBackCamera(Camera PtrCam){
    sceneCamers.push_back(PtrCam);
}


