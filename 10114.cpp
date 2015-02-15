#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    int months,dep_records;
    double down_payment, loan;
    do{
        std::cin>>months>>down_payment>>loan>>dep_records;
        if(months < 0)
            break;

        std::vector<double> dep_values; // depreciation values per month
        int last_month_read = 0; // last month for which the depreciation value was read
        double old_depreciation = 0.0; // the old depreciation value
        for(int i = 0; i < dep_records; i++)
        {
            int month;
            double depreciation;
            std::cin>>month>>depreciation;
            for(int j = last_month_read + 1; j < month; j++)
                // fill in the months missing from the input
                dep_values.push_back(old_depreciation);
            dep_values.push_back(depreciation);
            old_depreciation = depreciation;
            last_month_read = month;
        }
        for(int i = last_month_read + 1; i <= months; i++)
            // fill in remaining months
            dep_values.push_back(old_depreciation);
        
        double car_value = (loan + down_payment) * (1 - dep_values[0]);
        double owed = loan;

        double monthly_payment = loan / months;
        int nr_months = 0;
        while(car_value <= owed)
        {
            //std::cout<<"After "<<nr_months<<" months: Car value = "<<car_value<<" and owed = "<<owed<<std::endl;
            nr_months++;
            car_value *= (1 - dep_values[nr_months]);
            owed -= monthly_payment;
        }
        
        std::cout<<nr_months<<(nr_months==1?" month":" months")<<std::endl;
    }while(true);
    return 0;
}
