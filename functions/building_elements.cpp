#include "building_elements.h"
#include <cmath>

stair_result  stairs(const building_elements_in& d, double height_floor, int vertical_step, int horizontal_step)
{
    stair_result stair;
    stair.height_stairs = d.height_floor / 2 * 100;// converting m to cm
    stair.n_stairs = std::ceil((double)stair.height_stairs / d.vertical_step);
    stair.length_stairs = stair.n_stairs * d.horizontal_step;

    int comfort = d.horizontal_step + 2 * d.vertical_step;

    stair.rule_valid = (comfort > 55 && comfort < 70);

    return stair;
}

RC_column_result  RC_column(const building_elements_in& d, double S, int G1 ,int G2 ,int n_floors ,
                            int fc28 ,int fe, int Q_rooftop ,int Q_current_floor ,int Q_ground_floor)
{
    RC_column_result column;
    column.Smaj = 1.1 * d.S;
    // Smaj is the majorated surface lifted by the column we multiply S by 1.1
    column.NG = 1.1 * (d.G2 + n_floors * d.G1) * column.Smaj / 100 ;//G2 is the dead load of rooftop converting kg to KN
    //G1 is dead load for all floors including ground floor converting kg to KN
    // n_floors we consider all floors including ground floor
    column.NQ = (d.Q_rooftop + d.Q_current_floor * (1+0.9+0.8+0.7+0.6+(d.n_floors-6)*0.5 )+ d.Q_ground_floor) * column.Smaj / 100;
    column.Nu = (1.35 * column.NG + 1.5 * column.NQ) * pow(10,-3);// converting KN to MN
    column.alpha = 0.85 / 1.2;// we take lambda as 35
    column.gamma_c = 1.5;
    column.gamma_s = 1.15;
    column.Br_min = column.Nu / (  column.alpha * ( d.fc28 /(0.9 * column.gamma_c) + 0.01*(d.fe/column.gamma_s)  )  );
    column.a_min = sqrt(column.Br_min) + 0.02;
    return column;
}
