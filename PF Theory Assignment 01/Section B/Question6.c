    #include <stdio.h>


    int main() {
        char vehicle_type; printf("Enter Vehicle Type \n");
        scanf(" %c", &vehicle_type);

        int battery_charge_level; printf("Enter Battery Charge Level \n");
        scanf(" %d", &battery_charge_level);

        int required_charging_level; printf("Enter Required Charging \n");
        scanf(" %d", &required_charging_level);

        int expected_parking_duration; printf("Enter Parking Duration\n");
        scanf(" %d", &expected_parking_duration);

        int current_time ; printf("Enter Current Time \n");
        scanf(" %d", &current_time);

        char Memebership; printf("Enter Membership Y / N \n");
        scanf(" %c", &Memebership);

        char disabled; printf("Enter Disabled Person Priority Status Y / N \n");
        scanf(" %c", &disabled);

        char charging_station; printf("Enter Charging Station \n" );
        scanf(" %c", &charging_station);

        int priority = 0;

        if (charging_station == 'N') 
            
            if (vehicle_type == 'H') 
                printf("Charging Unavailable -- Parking Only \n");
            
            else    
                printf("No Charging Slot Available \n");
        
        else {
            
            if (vehicle_type == 'H' && battery_charge_level >= 40) {
                printf("Vehicle Does not qualify for EV Charging \n");
            }

            else {

            int required_charging = required_charging_level - battery_charge_level;

            if (required_charging_level <= battery_charge_level) {
                    printf("No Charging Required \n");
            }
            
            else 
                if (battery_charge_level <= 15 && required_charging_level >=80 )
                    priority =1;
                
                else if (disabled == 'Y' || (Memebership == 'Y' && battery_charge_level <= 30))
                    priority =2;
                
                else 
                    priority = 3;
            
            float charging_cost = 1;
            float discount = 0;

            if (current_time < 17 || current_time > 22) { 
                charging_cost = required_charging *  35;
                printf("Off Peak \n");

                if (Memebership == 'Y') {
                    discount = 0.2;
                    charging_cost = charging_cost * ( 1 - discount);
                }
            }
            else {
                charging_cost = required_charging * 50; 
                printf("Peak \n");

                if (priority != 1) {
                
                discount = 0.1;
                charging_cost = charging_cost * ( 1 - discount);
                }
            }
            
            float parking_charges = 1;
            
            if (expected_parking_duration <= 2)
                parking_charges = 200;
            
            else if (expected_parking_duration > 2 && expected_parking_duration <= 5)
                parking_charges = 400;

            else  
                parking_charges = 700;

            if (expected_parking_duration > 8)
                printf("Long-stay warning: Please relocate your vehicle after charging. \n");
            
            else 
                printf("Standard Parking Duration \n");

            
            if (Memebership == 'Y')
                parking_charges = parking_charges * 0.8;
            
            if (disabled == 'Y')
                parking_charges = 0;

            
        
            printf("Vehicle Type %c \n", vehicle_type);
            printf("Current Battery Percentage %d \n", battery_charge_level);
            printf("Required Charging Level %d \n", required_charging_level);
            printf("Charging Priority %d \n", priority);
            printf("Charging Cost %f \n", charging_cost);
            printf("Parking Cost %f \n", parking_charges);
            printf("Dicount %f \n", discount * 100);
            printf("Final Payble Amount %f \n", parking_charges + charging_cost);
        }
    }



    }