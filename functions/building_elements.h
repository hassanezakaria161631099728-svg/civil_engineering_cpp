#pragma once

struct building_elements_in {
    // stairs
    double height_floor;
    int vertical_step,horizontal_step;// stiffness Mass Dynamic matrices
    // column
    double S;
    int G1, G2, n_floors, fc28, fe, Q_rooftop, Q_current_floor, Q_ground_floor;

};

struct stair_result
{
    int height_stairs;
    int n_stairs;
    int length_stairs;
    bool rule_valid;
};

stair_result stairs(const building_elements_in& d, double height_floor, int vertical_step,int horizontal_step);

struct RC_column_result
{
    double Smaj;
    double NG;
    double NQ;
    double Nu;
    double alpha;
    double gamma_c;
    double gamma_s;
    double Br_min;
    double a_min;
};

RC_column_result  RC_column(const building_elements_in& d, double S, int G1 ,int G2 ,int n_floors ,
                            int fc28 ,int fe,int Q_rooftop ,int Q_current_floor ,int Q_gound_floor);
