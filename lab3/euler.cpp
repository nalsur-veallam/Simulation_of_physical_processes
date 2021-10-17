#include <fstream>

int TIMENUMBERS  = 100000;
double x_0 = 5;
double v_0 = 0;
double dt = 0.01;
double omega = 0.5;

void output(double *x, double *x1, double *v, double *v1, double *t)
{
    std::ofstream foute;
    foute.open("points.txt", std::ios::app);
    foute << *x << '\t' << *x1 << '\t' << *v << '\t' << *v1 << '\t' << *t << std::endl;
    foute.close();
}



int main()
{
    double x = x_0;
    double x_i;
    double v = v_0;
    double x1 = x_0;
    double x1_i, xz, vz;
    double v1 = v_0;
    double t = 0;
    output(&x, &x1, &v, &v1, &t);
    for(int i = 0; i < TIMENUMBERS; i++)
    {
        x_i = x;
        x += v*dt;
        v -= x_i*omega*dt;
        x1_i = x1;
        xz = x1 + dt*v1;
        vz = v1 - omega*x1*dt;
        x1 += dt*(vz + v1)/2;
        v1 -= omega*dt*(x1_i + xz)/2;
        t += dt;
        if(i%10 == 0){output(&x, &x1, &v, &v1, &t);}
    }
    system("python graph.py");
    return 0;
}
