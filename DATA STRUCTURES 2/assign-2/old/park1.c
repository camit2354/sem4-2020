#include<stdio.h>
#include<string.h>


typedef struct Parking_Lot_tag
{

  char Parking_level;
  char dedicated_wing;
  int no_of_compact_spots;
  int no_of_large_spots;
  char  status_compactspots[36];
 char status_large_spots[36];

}Parking_Lot;


typedef struct Flat_Details_tag
{
     char wing_id;
     int flat_id;
     int  no_of_two_wheelers;
     int no_of_four_wheelers;
}Flat_Details;
