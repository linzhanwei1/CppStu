#pragma once

class Operator {
private:
	char mOp;
	double mP1;
	double mP2;
public:
	bool setOperator(char op);
	void SetParameter(double p1, double p2);
	bool result(double& r);
};