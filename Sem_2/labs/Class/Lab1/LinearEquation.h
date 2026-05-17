#pragma once

class LinearEquation {
private:
    double first;   // coefficient A
    double second;  // coefficient B

    static bool IsZero(double value);

public:
    LinearEquation();
    LinearEquation(double a, double b);

    void Init(double a, double b);
    void Read();
    void Show() const;

    double GetFirst() const;
    double GetSecond() const;
    void SetFirst(double a);
    void SetSecond(double b);

    bool HasUniqueRoot() const;
    bool IsIdentity() const;
    double Root() const;
};

LinearEquation MakeLinearEquation(double a, double b);
