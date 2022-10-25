#ifndef O3DS_H
#define O3DS_H

#include <vector>
#include <vertex.h>

class O3DS{

protected:
    vector<_vertex3f> vertices;
public:
    void draw_points();
};

#endif
