#include "stdio.h"
#include "ordercontrol.h"

#define CONFIRM 1            //принято
#define REJECT 0             //отклонено


    int data_analyze(double cargo_weight, double distance, int trucks_num, double max_truck_load) {  //проверка
        double weight_per_truck = cargo_weight / trucks_num;
        if (cargo_weight >= 50 && weight_per_truck <= max_truck_load && distance <= 4000) {
            order_calculation(2, 5, 20, cargo_weight, distance);                                     //расчёт заказа
            return CONFIRM;
        }
        else {
            return REJECT;
        }
    }

    void order_calculation(double rate_per_kilometer, double insurance_expenses, double max_truck_load, double cargo_weight,
        double distance) {
        int needed_trucks = (int)(cargo_weight / max_truck_load);                         //необходимое к-во грузовиков 
        double transportation_cost = needed_trucks * rate_per_kilometer * distance;       //стоимость транспортировки 
        double insurance_cost = (transportation_cost * insurance_expenses) / 100;         //стоимость страховки
        double total_cost = transportation_cost + insurance_cost;                         //итоговая цена
        details_output(needed_trucks, insurance_cost, total_cost);
    }

    void details_output(int needed_trucks, double insurance_cost, double total_cost) {
        printf("\n\nCONFIRMED order");
        printf("\nOrder details:\n1. involved trucks - %d,\n2. insurance cost - %0.5f$,\n3. total cost - %0.2f$.", needed_trucks, insurance_cost, total_cost);
    }
