 parking_wing_status_type *wing_c_ptr = (*parking_lot_status_pptr)->wing_c_ptr ;
         if(vehicle_type == 2)
         {
               for(int i=0;i<no_of_compact_spots;i++)
               {
                   if(wing_c_ptr->status_compactspots_arr[i]==0)
                   {
                       wing = wing_c_ptr->parking_wing;
                       found =1;
                   }
               }
         }
         else
         {
             for(int i= 0;i<no_of_large_spots;i++)
             {
                 if(wing_c_ptr->status_large_spots_arr[i] == 0)
                 {
                     wing = wing_c_ptr->parking_wing;
                     found =1;
                 }
             }