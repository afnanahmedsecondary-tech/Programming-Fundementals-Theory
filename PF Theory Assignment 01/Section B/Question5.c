#include <stdio.h>
int main (){
	int vehicleType ; 
	int userCategory ;
	int hasPermit ;
	int isEmergency ;
	int acceptedCount = 0  ;
	int rejectedCount = 0 ;
	int bikeCount = 0 ;
	int carCount = 0 ;
	int vanCount = 0 ;
	int zoneACapacity = 20 ;
	int zoneBCapacity = 40 ;
	int zoneCCapacity = 15 ;
	int detailsValid ;
	int vehicleCount ;
	int totalVehicles ;

	printf("Enter Number of Vehicles");
	scanf("%d" , &vehicleCount);
	totalVehicles = vehicleCount;
    
	while (vehicleCount > 0) {
		detailsValid = 0;

		while (detailsValid == 0) {	
			printf("Enter Vehicle type : for Bike enter 1 , for car enter 2 , for van enter 3 ");
			scanf("%d" , &vehicleType);
			printf("Enter User Category : for Faculty enter 1 , for Student enter 2 for Visitor enter 3 ");
			scanf("%d" , &userCategory);
			printf("if permit is available enter 1 if not enter 0 ");
			scanf("%d" , &hasPermit);
			printf("if emergency enter 1 if not enter 0 ");
			scanf("%d" , &isEmergency);

			if ((vehicleType >= 1 && vehicleType <= 3) && (userCategory >= 1 && userCategory <= 3) && (hasPermit == 0 || hasPermit == 1) && (isEmergency == 0 || isEmergency == 1))
			detailsValid = 1;
			else printf("Wrong Details are entered");}

		if (hasPermit == 1 || isEmergency == 1){	

			switch (vehicleType) {

				case 1 :
					switch(userCategory){
						case 1 :
							if (zoneACapacity > 0) { 
							bikeCount = bikeCount + 1;
							acceptedCount = acceptedCount + 1;
							zoneACapacity = zoneACapacity - 1;
							}
							else rejectedCount = rejectedCount + 1;
							break ;

						case 2 :
							if (zoneBCapacity > 0) {
							bikeCount = bikeCount + 1;
							acceptedCount = acceptedCount + 1;
							zoneBCapacity = zoneBCapacity - 1;
							}
							else rejectedCount = rejectedCount - 1;
							break ;		

						case 3 :
							if (zoneCCapacity > 0) {
							bikeCount = bikeCount + 1;
							acceptedCount = acceptedCount + 1;
							zoneCCapacity = zoneCCapacity - 1;
							}
							else rejectedCount = rejectedCount + 1;
							break ; }

					break ;

				case 2 :
					switch(userCategory){

						case 1 :
							if (zoneACapacity > 0) {
							carCount = carCount + 1;
							acceptedCount = acceptedCount + 1;
							zoneACapacity = zoneACapacity - 1;
							}
							else rejectedCount = rejectedCount + 1;
							break ;

						case 2 :
							if (zoneBCapacity > 0) {
							carCount = carCount + 1;
							acceptedCount = acceptedCount + 1;
							zoneBCapacity = zoneBCapacity - 1;
							}
							else rejectedCount = rejectedCount + 1;
							break ;

						case 3 :
							if (zoneCCapacity > 0) {
							carCount = carCount + 1;
							acceptedCount = acceptedCount + 1;
							zoneCCapacity = zoneCCapacity - 1;
							}
							else rejectedCount = rejectedCount + 1;
							break ;}

					break ;

				case 3 :
					switch(userCategory){
						case 1 :
							if (zoneACapacity > 0) {
							vanCount = vanCount + 1;
							acceptedCount = acceptedCount + 1;
							zoneACapacity = zoneACapacity - 2;
							}
							else rejectedCount = rejectedCount + 1;
							break ;

						case 2 :
							if (zoneCCapacity > 0) {
							vanCount = vanCount + 1;
							acceptedCount = acceptedCount + 1;
							zoneCCapacity = zoneCCapacity - 2;
							}
							else rejectedCount = rejectedCount + 1;
							break ;

						case 3 :
							if (zoneCCapacity > 0) {
							vanCount = vanCount + 1;
							acceptedCount = acceptedCount + 1;
							zoneCCapacity = zoneCCapacity - 2;
							}
							else rejectedCount = rejectedCount + 1;
							break ;

					break ;											
					}
			}
		}
		else rejectedCount = rejectedCount + 1;	
        
		vehicleCount = vehicleCount - 1;
	}
	printf("Zone A : %d \n Zone B : %d \n Zone C : %d \n Bikes : %d \n Cars : %d \n Vans : %d \n Accepted : %d \n Rejected : %d \n Processed : %d" , zoneACapacity , zoneBCapacity , zoneCCapacity , bikeCount , carCount , vanCount , acceptedCount , rejectedCount , totalVehicles);
}
