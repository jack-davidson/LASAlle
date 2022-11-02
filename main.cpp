
//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 
 *	
 */


#include <iostream>
#include <fstream>
#include <cmath> 
#include "slist.h"

#define AIRPORT(x) ((Airport *)x)

using namespace std;

class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
    double   distance;

    ostream& operator<<(ostream& os)
    {
        os << code << "(" << latitude << ", " << longitude << ") " << distance;
        return os;
    }
};

#define f  cout << "fail" << endl;

void sort(LinkedList &l);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[10] ;
    LinkedList airportArr = LinkedList();
    int   airportCount;
    
    infile.open ("USAirportCodes.csv", ifstream::in);
    if (infile.is_open())
    {
        int   c=0;
        while (infile.good())
        {
            airportArr.add((void *)(new Airport()));
            infile.getline(AIRPORT(airportArr[c])->code, 256, ',');
            infile.getline(cNum, 256, ',');
            AIRPORT(airportArr[c])->latitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            AIRPORT(airportArr[c])->longitude = atof(cNum);
            AIRPORT(airportArr[c])->distance = distanceEarth(
                30.1944, 97.6700, AIRPORT(airportArr[c])->latitude, AIRPORT(airportArr[c])->longitude);
            i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();
        sort(airportArr);
        cout << "Airports within 100 miles" << endl;
        int i = 0;
        while (AIRPORT(airportArr[i])->distance <= 160.934) {
            cout << "[" << i+1 << "] " << AIRPORT(airportArr[i])->code << " " << AIRPORT(airportArr[i])->distance << endl;
            i++;
        }
        cout << AIRPORT(airportArr[airportArr.size()-1])->code << " " << AIRPORT(airportArr[airportArr.size()-1])->distance << endl;


    }
    else
    {
        cout << "Error opening file";
    }


    
}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(LinkedList arr, int low, int high)
{
    double pivot = AIRPORT(arr[high])->distance; // pivot
    int i
        = (low
           - 1); // Index of smaller element and indicates
                 // the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (AIRPORT(arr[j])->distance < pivot) {
            i++; // increment index of smaller element
            arr.swap(i, j);
        }
    }
    arr.swap(i+1, high);
    return (i + 1);
}
  
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(LinkedList arr, int low, int high)
{
    if (low < high) {
        /* p is partitioning index, arr[p] is now
        at right place */
        int p = partition(arr, low, high);
  
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
  

/*
	Provide sort routine on linked list
*/
void sort(LinkedList &l)
{
    quickSort(l, 0, l.size());
}
