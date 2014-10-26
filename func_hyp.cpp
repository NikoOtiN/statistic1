#include "func_hyp.h"

void print_v(vector<double> v)
{
    for(auto e : v)
    {
        cout << e << " ";
    }
}


vector<double> create_sample(int size, double m, double g,int i)
{
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count()*i;
    std::default_random_engine generator(seed1);
    std::normal_distribution<double> distribution(m,g);
    vector<double> tmp;
    for(int i = 0; i <size; i++)
    {
        tmp.push_back(distribution(generator));
    }
    return tmp;
}


//Выброчное среднее
double sample_mean(vector<double> X)
{
    double sum=0;
    if(X.empty())
    {
        //throw length_error("sample_mean: error empty vector!");
    }
    for(auto i : X)
    {
        sum+=i;
    }
    return sum/X.size();
}

//Выборочная дисперсия
double sample_variance(vector<double> X, double sample_mean)
{
    double sum=0;
    if(X.empty())
    {
       // throw length_error("sample_variance: error empty vector!");
    }
    for(auto i: X)
    {
        sum+=pow(i-sample_mean,2);
    }
    return sum/(X.size()-1);
}

//Статистика Фишера
double F_test(const double a, const double b)
{
    return a>b ? a/b : b/a;
}

//Критическое значение статистики Фишера
double F_test_cr(int v1, int v2, double level)
{
    double u = quantile(1-level);
    qDebug() << "quantile F" << u;
    double h = 2.0*(v1-1)*(v2-1)/(v1+v2-2);
    double l = (pow(u,2)-3)/6;
    double w = (u*sqrt(h+l)/h) - (1.0/(v1-1)-1.0/(v2-1))*(l+5.0/6.0-2.0/(3.0*h));
    return exp(2*w);
}

//Расчет квантили норм. распределения.
double quantile(double level)
{
   double q, t;
   double one = 1;

   t = level < 0.5 ? level : one - level;
   t = sqrt(-2 * log(t));
   q = t - ((0.010328 * t + 0.802853) * t + 2.515517) /
      (((0.001308 * t + 0.189269) * t + 1.432788) * t + 1);
   return level > 0.5 ? q : -q;
}


double t_test(double x,double y,double s1, double s2, int m, int n)
{
    double s_midle = ((m-1)*s1+(n-1)*s2)/(m+n-2);
    double S = sqrt(s_midle)*sqrt(1.0/m+1.0/n);
    double t = (x-y)/S;
    return abs(t);
}

double t_test_cr(int v, double level)
{
    double u = quantile(1-level/2);
    qDebug() << "quantile" << u;
    double q1 = (u*u+1)*u/4;
    double q2 = ((5*u*u+16)*pow(u,2) + 3)*u/96;
    double q3 = (((3*u*u+19)*u*u+17)*u*u-15)*u/384;
    double q4 = ((((79*u*u+776)*u*u + 1482)*u*u -1920)*u*u-945)*u/92160;
    double t = u + q1/v + q2/pow(v,2) + q3/pow(v,3) + q4/pow(v,4);
    return t;
}

