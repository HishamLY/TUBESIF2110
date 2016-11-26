// File : Map.h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tipedata.h"

void RandomMap (Map * M);
/*	I.S. Map Terdefinisi
	F.S. Map telah dirandom dan siap untuk digunakan */

void CreateLinkSource (Maps * MS, int N);
/*	I.S. Maps Terdefinisi
	F.S. Telah dibuat Link antara Map */

void CreateLinkDest (Maps * MS, int N);
/*	I.S. Map Terdefinisi
	F.S. Telah dibuat Link antara Map*/

void CreateMap(Maps * MapJelajah);
/*	I.S. Map Belum Terdefinisi
	F.S. Map telah dibuat dan di load ke FileMap.txt*/