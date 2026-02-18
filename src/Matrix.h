#pragma once

#include <cmath>
const float PI = 3.1415927f;
const float DEGRAD = 0.017453292f;



const int X = 0,Y = 1,Z = 2;












inline float fast_inv_sqrt(float number) {
    uint32_t i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;
    i  = 0x5f3759df - ( i >> 1 );               //AHAHAHAHA
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );

    return y;
}





struct VectorS{
    float vec3[3] = {
        0.0f,0.0f,0.0f
    };



    void multiply(float scalar) {
        vec3[0] *= scalar;
        vec3[1] *= scalar;
        vec3[2] *= scalar;
    }



    float dot(const VectorS& other) {
        return (vec3[0] * other.vec3[0]) + 
               (vec3[1] * other.vec3[1]) + 
               (vec3[2] * other.vec3[2]);
    }


    VectorS cross(const VectorS& b) {
        VectorS result;
        result.vec3[0] = vec3[1] * b.vec3[2] - vec3[2] * b.vec3[1];
        result.vec3[1] = vec3[2] * b.vec3[0] - vec3[0] * b.vec3[2];
        result.vec3[2] = vec3[0] * b.vec3[1] - vec3[1] * b.vec3[0];
        return result;
    }

    void normalize() {
        float dot_val = dot(*this);
        if (dot_val > 0.00001f) {
            float inv_len = fast_inv_sqrt(dot_val);
            multiply(inv_len);
        }
    }

};







struct Matrix
{
    float matrix4x4[16] = {
        1.0f,0.0f,0.0f,0.0f,
        0.0f,1.0f,0.0f,0.0f,
        0.0f,0.0f,1.0f,0.0f,
        0.0f,0.0f,0.0f,1.0f
    };

    void set_transform(float x, float y, float z) {
        matrix4x4[12] = x; 
        matrix4x4[13] = y;
        matrix4x4[14] = z;
    }

    

    void perspective(float fov, float aspect, float znear, float zfar) {
        for (int i = 0; i < 16; i++) matrix4x4[i] = 0.0f;

        float f = 1.0f / tanf(fov * 0.5f * (PI / 180.0f));
        float rangeInv = 1.0f / (znear - zfar);

        matrix4x4[0] = f / aspect;
        matrix4x4[5] = f;
        matrix4x4[10] = (znear + zfar) * rangeInv;
        matrix4x4[11] = -1.0f;
        matrix4x4[14] = (2.0f * znear * zfar) * rangeInv;
        matrix4x4[15] = 0.0f;
    }



    void rotateMat4x4(float angleX, float angleY, float angleZ) {


        matrix4x4[0] = 0.0f;
        matrix4x4[1] = 0.0f;
        matrix4x4[2] = 0.0f;

        matrix4x4[4] = 0.0f;
        matrix4x4[5] = 0.0f;
        matrix4x4[6] = -0.0f;

        matrix4x4[8] = 0.0f;
        matrix4x4[9] = 0.0f;
        matrix4x4[10] = 0.0f;





        matrix4x4[0] = 1.0f; matrix4x4[5] = 1.0f; 
        matrix4x4[10] = 1.0f; matrix4x4[15] = 1.0f;


        float ax = angleX * (PI / 180.0f);
        float ay = angleY * (PI / 180.0f);
        float az = angleZ * (PI / 180.0f);

        float sx = sin(ax), cx = cos(ax);
        float sy = sin(ay), cy = cos(ay);
        float sz = sin(az), cz = cos(az);

  
        matrix4x4[0] = cy * cz + sy * sx * sz;
        matrix4x4[1] = -cy * sz + sy * sx * cz;
        matrix4x4[2] = sy * cx;

        matrix4x4[4] = cx * sz;
        matrix4x4[5] = cx * cz;
        matrix4x4[6] = -sx;

        matrix4x4[8] = -sy * cz + cy * sx * sz;
        matrix4x4[9] = sy * sz + cy * sx * cz;
        matrix4x4[10] = cy * cx;
    }


    void scaleMat4x4(float sizeX, float sizeY, float sizeZ){
            matrix4x4[0] *= sizeX;
            matrix4x4[5] *= sizeY;
            matrix4x4[10] *= sizeZ;
    }


    void lookAt(const VectorS& eye, const VectorS& center, const VectorS& up) {
        VectorS f;
        f.vec3[0] = center.vec3[0] - eye.vec3[0];
        f.vec3[1] = center.vec3[1] - eye.vec3[1];
        f.vec3[2] = center.vec3[2] - eye.vec3[2];
        f.normalize();

        VectorS s;
        s.vec3[0] = f.vec3[1] * up.vec3[2] - f.vec3[2] * up.vec3[1];
        s.vec3[1] = f.vec3[2] * up.vec3[0] - f.vec3[0] * up.vec3[2];
        s.vec3[2] = f.vec3[0] * up.vec3[1] - f.vec3[1] * up.vec3[0];
        s.normalize();

        VectorS u;
        u.vec3[0] = s.vec3[1] * f.vec3[2] - s.vec3[2] * f.vec3[1];
        u.vec3[1] = s.vec3[2] * f.vec3[0] - s.vec3[0] * f.vec3[2];
        u.vec3[2] = s.vec3[0] * f.vec3[1] - s.vec3[1] * f.vec3[0];


        matrix4x4[0] = s.vec3[0];
        matrix4x4[1] = u.vec3[0];
        matrix4x4[2] = -f.vec3[0];
        matrix4x4[3] = 0.0f;

        matrix4x4[4] = s.vec3[1];
        matrix4x4[5] = u.vec3[1];
        matrix4x4[6] = -f.vec3[1];
        matrix4x4[7] = 0.0f;

        matrix4x4[8] = s.vec3[2];
        matrix4x4[9] = u.vec3[2];
        matrix4x4[10] = -f.vec3[2];
        matrix4x4[11] = 0.0f;

        matrix4x4[12] = -(s.vec3[0] * eye.vec3[0] + s.vec3[1] * eye.vec3[1] + s.vec3[2] * eye.vec3[2]);
        matrix4x4[13] = -(u.vec3[0] * eye.vec3[0] + u.vec3[1] * eye.vec3[1] + u.vec3[2] * eye.vec3[2]);
        matrix4x4[14] =  (f.vec3[0] * eye.vec3[0] + f.vec3[1] * eye.vec3[1] + f.vec3[2] * eye.vec3[2]);
        matrix4x4[15] = 1.0f;
    }





};

