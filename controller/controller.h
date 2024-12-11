#ifndef SRC_CONTROLLER_CONTROLLER_H
#define SRC_CONTROLLER_CONTROLLER_H

#include "../model/model.h"
namespace s21 {
class Controller {
 public:
  int Calculate(std::string &str, double x);
  std::pair<std::vector<double>, std::vector<double>> Grafic(
      double min, double max, const std::string &str);
  void CreditAnnuity(double sum_of_credit, double duration_of_credit,
                     double annual_interest_rate, double &month_pay,
                     double &over_pay, double &all_sum_of_pay);
  void CreditDifferentiated(double sum_of_credit, double duration_of_credit,
                            double annual_interest_rate,
                            double &month_pay_first, double &month_pay_last,
                            double &over_pay, double &all_sum_of_pay);
  void Deposit(double replenishment1[], double replenishment2[],
               int count_replenishment, double withdrawals1[],
               double withdrawals2[], int count_withdrawals, double all_sum,
               double duration_of_credit, double interest_rate, double tax,
               int period_s, int capitalization, double &all_interest,
               double &all_tax, double &total_sum);

 private:
  s21::Model model_;
};
}  // namespace s21
#endif  // SRC_CONTROLLER_H
