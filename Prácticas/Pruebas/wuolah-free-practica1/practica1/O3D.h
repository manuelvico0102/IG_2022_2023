#ifndef O3D_H
#define O3D_H

#include <vector>
#include <O3DS.h>

using namespace std;

class O3D : public O3DS{

protected:
    struct Triangulos{
        int _0;
        int _1;
        int _2;

    };
    vector<Triangulos> triangles;
public:

    void draw_lines();
	void draw_fill();
    void draw_chess();

};

#endif
