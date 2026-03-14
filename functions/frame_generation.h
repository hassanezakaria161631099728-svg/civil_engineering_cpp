#pragma once
#include <vector>
#include <string>
struct frame_generation_input {
    int nspan,Lspan,nstories,hstory;    // tall building dimensions
    double q,E,Acol, Icol, Abeam, Ibeam; // tall building beams and columns geometric attributes
    double h,n,L,Aver, Iver, Ahor, Ihor, Adiag, Idiag; // bracing frame dimensions and elements geometric attributes
};

struct Node
{int id; double x; double y;};
std::vector<Node> wall_bracing_Nodes(const frame_generation_input& d, double h, int n, double L);
struct Element {int id; int n1; int n2;
double E;
double A;
double I;
double q;
std::string load_type; // "local" or "globalS"
std::string element_type; // "horizontal" "vertical" or "diagonal"
double L,c,s;
};
std::vector<Element> wall_bracing_Elements(const frame_generation_input& d, int n, double E, double Aver, double Iver,
                                      double Ahor, double Ihor, double Adiag,double Idiag, double q);
struct DOF
{
    int id;         // global DOF number
    int nodeId;     // node it belongs to
    std::string type;  // "ux", "uy", "rz"
    bool constrained;
};
std::vector<DOF> wall_bracing_DOFs(const std::vector<Node>& nodes);

void plotStructure(const std::vector<Node>& nodes,
                   const std::vector<Element>& elements,
                   int windowWidth,
                   int windowHeight);

std::vector<int> extractBC(const std::vector<DOF>& dofs);
std::vector<Node> roof_bracing_Nodes(const frame_generation_input& d, double h, int n, double L);
std::vector<Element> roof_bracing_Elements(const frame_generation_input& d, int n,double E,double Aver, double Iver,
double Ahor, double Ihor, double Adiag, double Idiag, double q);
std::vector<DOF> roof_bracing_DOFs(const frame_generation_input& d, int n);
void plotStructure2(const std::vector<Node>& nodes,
                   const std::vector<Element>& elements,
                   int windowWidth,
                   int windowHeight);
std::vector<Node> tall_building_Nodes(const frame_generation_input& d, int nspan,int Lspan,int nstories,int h);
std::vector<Element> tall_building_Elements(const frame_generation_input& d, int nspan,int nstories,
    double E,double Acol, double Icol,
    double Abeam,double Ibeam,double q);
std::vector<DOF> tall_building_DOFs(const std::vector<Node>& nodes);
