//
// Created by 36302 on 2023/5/13.
//
#include <stdio.h>
#include <iostream>
struct point3d{
    float x;//x点
    float y;//y点
    float z;//z点
};
//打印函数
void Point3d_print(const point3d* p3d){
    printf("%d,%d,%d\n",p3d->x,p3d->y,p3d->z);
}

class Point3d{
public:
    Point3d(float x=0.0,float y=0.0,float z=0.0):
    x(x),y(y),z(z){}
    float getX() const {
        return x;
    }
    void setX(float x) {
        Point3d::x = x;
    }
    float getY() const {
        return y;
    }
    void setY(float y) {
        Point3d::y = y;
    }
    float getZ() const {
        return z;
    }
    void setZ(float z) {
        Point3d::z = z;
    }
private:
    float x;//x点
    float y;//y点
    float z;//z点
};
std::ostream& operator<<(std::ostream& cout,Point3d p3d){
    cout<<p3d.getX()<<","<<p3d.getY()<<","<<p3d.getZ()<<std::endl;
    return cout;
}