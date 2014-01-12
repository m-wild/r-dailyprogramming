/*
 * vectorOps.cpp
 * 
 * Copyright 2013 Michael Wildman <michael@timon>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

float getLength(vector<float> vect);
void printNorm(vector<float> vect);
void printDotProd(vector<float> vect1, vector<float> vect2);

int main(int argc, char **argv) 
{
	if (argc < 2) return 1;
	int n, d, index;
	
	ifstream inf;
	inf.open(argv[1]);
	if (!inf.good()) return 2;
	
	inf >> n;
	vector< vector<float> > vectors;
	vectors.reserve(n);
	
	for (int i = 0; i < n; i++) {
		inf >> d;
		vectors[i] = vector<float> (d);
		for (int j = 0; j < d; j++) {
			inf >> vectors[i][j];
		}
	}
	inf >> n;
	while (n > 0) {
		char op;
		inf >> op;
		switch (op) {
			case 'l': inf >> index; 
				printf("%.5f\n", getLength(vectors[index]));
				break;
			case 'n': inf >> index;
				printNorm(vectors[index]);
				break;
			case 'd': int index2;
				inf >> index >> index2;
				printDotProd(vectors[index], vectors[index2]);
				break;
			default: return 3;
		}
		n--;
	}
	inf.close();	
	return 0;
}

float getLength(vector<float> vect) {
	float result = 0.0;
	for (float i : vect) result += i * i;
	return sqrt(result);
}

void printNorm(vector<float> vect) {
	float denom = getLength(vect);
	for (float i : vect) printf("%.5f ", i / denom);
	cout << endl;
}

void printDotProd(vector<float> vect1, vector<float> vect2) {
	if (vect1.size() != vect2.size()) cout << "vectors must be same length\n";
	float result = 0.0;
	for (int i = 0; i < vect1.size(); i++) result += vect1[i] * vect2[i];
	printf("%.5f\n", result);
}
