#include <bits/stdc++.h>

using namespace std;

int main() {
    int width = 1024;
    int height = 1024;
    double cx=width/2;
    double cy=height/2;
    double distanca=sqrt(cx*cx+cy*cy);
    ofstream img("radial_gradient.ppm");
    img << "P3\n" << width << " " << height << "\n255\n";
    for (int i=0 ; i<width; i++) {
        for (int j=0 ; j<height; j++) {
            double dx=i-cx;
            double dy=j-cy;
            double distanca1=sqrt(dx*dx+dy*dy);
            double factor=1.0-(distanca1/distanca);
            if (factor<0) {
                factor=0;
            }
            int r=0;
            int g=0;
            int b=static_cast<int>(factor*180);
            img << r << " " << g << " " << b << "\n";
        }
        img << "\n";
    }
    img.close();
    return 0;
}
