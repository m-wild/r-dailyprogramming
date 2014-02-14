/*
 * vectorOps.java
 * 
 * Michael Wildman 2013 <@mwildman.co.nz>
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

import java.io.*;
import java.util.Scanner;
import java.text.DecimalFormat;


public class vectorOps {
	public static DecimalFormat df = new DecimalFormat("#.#####");

	public static void main (String args[]) throws IOException {		
		if (args.length > 1) System.exit(1);
		Scanner s = null;
		
		try {
			s = new Scanner(new BufferedReader(new FileReader(args[0])));
			int n = Integer.parseInt(s.next());
			double[][] vectors = new double[n][];
			
			for (int i = 0; i < n; i++) {
				int dimension = Integer.parseInt(s.next());
				vectors[i] = new double[dimension];
				for (int j = 0; j < dimension; j++) 
					vectors[i][j] = Double.parseDouble(s.next());
			}
			n = Integer.parseInt(s.next());
			
			for (int i = 0; i < n; i++) {
				switch (s.next()) {
					case "l": System.out.println(df.format(getLength(vectors[Integer.parseInt(s.next())]))); 
						break;
					case "n": printNormalized(vectors[Integer.parseInt(s.next())]);
						break;
					case "d": printDotProd(vectors[Integer.parseInt(s.next())], vectors[Integer.parseInt(s.next())]);
						break;
					default: System.out.println("input format error");
				}
			} 
		} finally {
			if (s != null) s.close();
		}
	}
	
	public static double getLength(double[] vector) {
		double result = 0.0;
		for (double i : vector)
			result += i * i;
		return Math.sqrt(result);
	}
	
	public static void printNormalized(double[] vector) {
		double length = getLength(vector);
		for (double i : vector)
			System.out.print(df.format(i / length) + " ");
		System.out.println();
	}
	
	public static void printDotProd(double[] vector1, double[] vector2){
		if (vector1.length != vector2.length) System.out.println("vectors must have same dimension");
		else {
			double result = 0.0;
			for (int i = 0; i < vector1.length; i++) {
				result += vector1[i] * vector2[i];
			}
			System.out.println(df.format(result));
		}
	}
}

