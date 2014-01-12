/*
 * ftraffic.cpp
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
	int lines, roomTime[100] = { 0 }, roomNo, time, roomVisits[100] = { 0.0 };
	string buff, io;
	ifstream inf;

	inf.open(argv[1]);
	if ( inf.good() ) getline(inf, buff);
	else cout << "ioerror\n";
	lines = atoi(buff.c_str());

	while ( lines > 0 && inf.good() ) {
		getline(inf, buff, ' ');
		getline(inf, buff, ' ');
		roomNo = atoi(buff.c_str());
		getline(inf, io, ' ');
		getline(inf, buff);
		time = atoi(buff.c_str());
		
		if ( !io.compare("I") ) {
			roomTime[roomNo] -= time;
			roomVisits[roomNo] += 1.0;
		}
		else roomTime[roomNo] += ++time;
		
		lines--;
	}
	inf.close();

	for (int i = 0; i < 100; i++)
		if ( roomVisits[i] != 0 )
			cout << "Room " << i << ", " << roomTime[i]/roomVisits[i] << 
			" minute average visit, " << roomVisits[i] << " visitor(s) total\n";

	return 0;
}
