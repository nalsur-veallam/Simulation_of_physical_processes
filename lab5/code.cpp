#include <fstream>

int timesteps = 100000;
const double dt = 0.001;
const int c = 10; //how often will the coordinates be output
const int ncol = 8;
const int nstr = 2;
const double a = 0.5; //the coefficient of the derivative of the zero order
const double b = 0.01; //the coefficient of the first - order derivative
double x_0 = 5, v_0 = 0;
double a_0 = -a*x_0 - b*v_0; //initial conditions
double coord_0[] = {x_0, v_0, a_0, x_0, v_0, a_0, x_0, v_0, a_0}; //initial conditions

//Data output
void output(double coord[nstr][ncol], int time)
{
    std::ofstream foute;
    foute.open("points.txt", std::ios::app);
    foute << coord[1][0] << '\t' << coord[1][3] << '\t' << coord[1][1] << '\t' << coord[1][4] << '\t' << time*dt << std::endl;
    foute.close();
}

//Euler's method
void euler(double coord[nstr][ncol])
{
    for(int i = 0; i < ncol; i++)
    {
        coord[0][i] = coord[1][i];
    }
    coord[1][0] += dt*coord[0][1]; //change of position
    coord[1][1] += dt*coord[0][2]; //change of velosity
    coord[1][2] = -(a*coord[1][0] + b*coord[1][2]); //change of acceleration
}

//Hoin's method
void hoin(double coord[nstr][ncol])
{
    coord[1][6] += dt*coord[0][4]; //intermediate change of position
    coord[1][7] += dt*coord[0][5]; //intermediate change of velosity
    coord[1][8] = -(a*coord[1][6] + b*coord[1][7]); //intermediate change of acceleration
    coord[1][3] += dt*(coord[0][4] + coord[1][7])/2; //change of position
    coord[1][4] += dt*(coord[0][5] + coord[1][8])/2; //change of velosity
    coord[1][5] = -(a*coord[1][3] + b*coord[1][4]); //change of acceleration
}

int main()
{
    //initialization
    double coord[nstr][ncol];
    for(int i = 0; i < ncol; i++)
    {
        coord[0][i] = coord_0[i];
        coord[1][i] = coord_0[i];
    }
    //calculation
    for(int time = 0; time < timesteps; time++)
    {
        euler(coord);
        hoin(coord);
        if(time % c == 1){output(coord, time);};
    }
    system("python3 graph.py");
    return 0;
}
