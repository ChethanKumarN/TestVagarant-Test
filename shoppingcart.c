#include <stdio.h>
#include <stdlib.h>

struct ShoppingCart {
    char pn[50];
    double unitcost;
    double gst;
    int qty;
};

void printProductDetails(struct ShoppingCart item) {
    printf("%-20s %-20.2f %-10.2f %-8d\n", item.pn, item.unitcost, item.gst, item.qty);
}

int main() {
    struct ShoppingCart pro[4];
    
    // Initializing pro
    strcpy(pro[0].pn, "Leather wallet");
    pro[0].unitcost = 1100;
    pro[0].gst = 18;
    pro[0].qty = 1;

    strcpy(pro[1].pn, "Umbrella");
    pro[1].unitcost = 900;
    pro[1].gst = 12;
    pro[1].qty = 4;

    strcpy(pro[2].pn, "Cigarette");
    pro[2].unitcost = 200;
    pro[2].gst = 28;
    pro[2].qty = 3;

    strcpy(pro[3].pn, "Honey");
    pro[3].unitcost = 100;
    pro[3].gst = 0;
    pro[3].qty = 2;

    printf("%-20s %-20s %-10s %-8s\n", "Product", "Unit Price in Rupees", "GST in %", "Quantity");
    for (int i = 0; i < 4; ++i) {
        printProductDetails(pro[i]);
    }

    double maximumGst = 0;
    char maxGstProduct[50] = "";

    for (int i = 0; i < 4; ++i) {
        double gst = pro[i].gst;
        double price = pro[i].unitcost;
        double calculateGST = (gst * price) / 100;
        if (calculateGST > maximumGst) {
            maximumGst = calculateGST;
            strcpy(maxGstProduct, pro[i].pn);
        }
    }
    printf("Product with maximum GST amount: %s\n", maxGstProduct);

    double totalAmount = 0;
    for (int i = 0; i < 4; ++i) {
        double unitcost = pro[i].unitcost;
        int quantity = pro[i].qty;
        double discount = 0;
        if (unitcost >= 500) {
            discount = (unitcost * 5) / 100;
        }
        double gstAmount = (unitcost * pro[i].gst) / 100;
        totalAmount += ((unitcost - discount + gstAmount) * quantity);
    }
    printf("Total amount to be paid: %.2f\n", totalAmount);

    return 0;
}
