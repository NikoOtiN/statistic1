#ifndef FUNC_HYP_H
#define FUNC_HYP_H
#include <iostream>
#include <vector>
#include <exception>
#include <random>
#include <chrono>
#include <QDebug>
using namespace std;

double sample_mean(vector<double> X);
double sample_variance(vector<double> X, double sample_mean);
double F_test(const double a, const double b);
double F_test_cr(int v1, int v2, double level);
double quantile(double level);
double t_test(double x,double y,double s1, double s2, int m, int n);
double t_test_cr(int v, double level);
double t_test_2(int v);
vector<double> create_sample(int size, double m, double g);
void print_v(vector<double> v);
#endif // FUNC_HYP_H
