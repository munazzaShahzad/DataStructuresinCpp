#pragma once

class Transaction
{
public:
	int count;
	double price;
	Transaction(int c, double p) :count(c), price(p) {}
	Transaction() :count(0), price(0) {}
};