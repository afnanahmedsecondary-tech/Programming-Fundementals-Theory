#include <stdio.h>

int main() {
    int quantity; printf("Enter Quantity of Products\n");
    scanf("%d", &quantity);

    int price_per_item; printf("Enter Price Per Item\n");
    scanf("%d", &price_per_item);

    int discount; printf("Enter Discount Percentage\n");
    scanf("%d", &discount);

    int tax; printf("Enter Tax Percentage\n");
    scanf("%d", &tax);

    int discounted_amount, sub_total, final_bill;

    if ( quantity <= 0)
        printf("Invalid Quantity\n");
    
    else if (price_per_item <= 0) 
        printf("Invalid Price\n");
    
    else if (discount < 0 || discount > 100)
        printf("Invalid Discount\n");

    else if (tax < 0 || tax > 100)
        printf("Invalid Tax");
    
    else {
        sub_total = (quantity * price_per_item);
        discounted_amount = sub_total - ( sub_total * discount) / 100;
        final_bill = discounted_amount + ( discounted_amount * tax) /100;
        printf("Final Bill %d \n", final_bill);
    }

    
    
}