#ifndef ROUNGE_KUTTA_H
#define ROUNGE_KUTTA_H

#include<vector>
#include <iostream>
#include <memory>
#include <assert.h>
#include <cmath>
using namespace std;



class ToSolveBase{
    public:
    ToSolveBase() = default;
    virtual ~ToSolveBase() = default;
    virtual double function(double t, double y, double k1, double k2, double k3) = 0;
};

class Example : public ToSolveBase{
    public:
    Example() = default;
    double function(double t, double y, double k1, double k2, double k3) override;
};



// double Example::function(double t, double y, double k1, double k2, double k3) {
//     double ans;
//     ans = k1 + k2 * cos(y) + k3 * sin(y);
//     return ans;
// }

double Example::function(double t, double y, double k1, double k2, double k3) {
    double ans;
    ans = k1 + k2 - k3 * y;
    return ans;
}

class OdmSolve{
public:
    OdmSolve(shared_ptr<ToSolveBase> ToSolveBasePtr) {ToSolveBasePtr_ = ToSolveBasePtr;}
    ~OdmSolve() = default;
    double GetAns(const vector<double>& tspace, double initNum, const double h, double k1, double k2, double k3) const;

private:
    shared_ptr<ToSolveBase> ToSolveBasePtr_;

};

#endif