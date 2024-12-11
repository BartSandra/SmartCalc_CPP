#include "controller.h"

int s21::Controller::Calculate(std::string &str, double x) {
  return this->model_.Calculate(str, x);
}

std::pair<std::vector<double>, std::vector<double>> s21::Controller::Grafic(
    double min, double max, const std::string &str) {
  return this->model_.Grafic(min, max, str);
}

void s21::Controller::CreditAnnuity(double sum_of_credit,
                                    double duration_of_credit,
                                    double annual_interest_rate,
                                    double &month_pay, double &over_pay,
                                    double &all_sum_of_pay) {
  return this->model_.CreditAnnuity(sum_of_credit, duration_of_credit,
                                    annual_interest_rate, month_pay, over_pay,
                                    all_sum_of_pay);
}
void s21::Controller::CreditDifferentiated(
    double sum_of_credit, double duration_of_credit,
    double annual_interest_rate, double &month_pay_first,
    double &month_pay_last, double &over_pay, double &all_sum_of_pay) {
  return this->model_.CreditDifferentiated(
      sum_of_credit, duration_of_credit, annual_interest_rate, month_pay_first,
      month_pay_last, over_pay, all_sum_of_pay);
}

void s21::Controller::Deposit(double replenishment1[], double replenishment2[],
                              int count_replenishment, double withdrawals1[],
                              double withdrawals2[], int count_withdrawals,
                              double all_sum, double duration_of_credit,
                              double interest_rate, double tax, int period_s,
                              int capitalization, double &all_interest,
                              double &all_tax, double &total_sum) {
  return this->model_.Deposit(replenishment1, replenishment2,
                              count_replenishment, withdrawals1, withdrawals2,
                              count_withdrawals, all_sum, duration_of_credit,
                              interest_rate, tax, period_s, capitalization,
                              all_interest, all_tax, total_sum);
}
