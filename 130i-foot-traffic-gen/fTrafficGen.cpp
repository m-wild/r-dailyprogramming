/*
 * fTrafficGen.cpp
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
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv)
{
	if (argc < 6) return 1;
	int visitors[100][2] = { 0 }, numEvents = atoi(argv[1]), numVisitors = atoi(argv[2]), 
	numRooms = atoi(argv[3]), minTime = atoi(argv[4]), maxTime = atoi(argv[5]);
	ofstream outf;

	outf.open("output.txt");
	if (!outf.good()) return 2;
	outf << numEvents * 2 << "\n";

	srand (time(NULL));

	int i = 0, j = 1;
	while (j < numEvents) {
		while (i <= numVisitors && i < numEvents) {
			visitors[i][0] = rand() % (numRooms + 1);
			visitors[i][1] = rand() % (maxTime - minTime) + minTime;
			outf << i << " " << visitors[i][0] << " I " << visitors[i][1] << "\n";
			i++;
			j++;
		}
		i--;
		j--;
		while (i >= 0) {
			outf << i << " " << visitors[i][0] << " O " << 
			(rand() % (maxTime - visitors[i][1] + 1) + visitors[i][1]) << "\n";
			i--;
		}
		i++;
	}

	outf.close();
	
	return 0;
}

