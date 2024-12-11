#include <gtest/gtest.h>

#include "controller/controller.h"
#include "model/model.h"

TEST(test_calc, smartcalc_1) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("5-(-7)");
  c.Calculate(tmp, 25);
  result = (5 - (-7));
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_2) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("5+(+7)");
  c.Calculate(tmp, 25);
  result = (5 + (+7));
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_3) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("123+45*67/89");
  c.Calculate(tmp, 25);
  result = 156.876404;
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_4) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("2^2^3");
  c.Calculate(tmp, 25);
  result = (256);
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_5) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("cos(x)");
  c.Calculate(tmp, 25);
  result = (cos(25));
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_6) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("sin(x)");
  c.Calculate(tmp, 25);
  result = (sin(25));
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_7) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("tan(x)");
  c.Calculate(tmp, 25);
  result = (tan(25));
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_8) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("tan(x)-sin(x)*cos(x)");
  c.Calculate(tmp, 25);
  result = (tan(25) - sin(25) * cos(25));
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_9) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("atan(x)-asin(x)*acos(x)");
  c.Calculate(tmp, 25);
  result = (atan(25) - asin(25) * acos(25));
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_10) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("2+3");
  c.Calculate(tmp, 0);
  result = 2 + 3;
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_11) {
  s21::Controller c;
  s21::Model m;
  std::string tmp = ("15.4+16.7*4.532%5");
  c.Calculate(tmp, 0);
  double result = 16.0844;
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_12) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("sin(cos(0.5*25))");
  c.Calculate(tmp, 0);
  result = sin(cos(0.5 * 25));
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_13) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("sin(cos(0.5*x))");
  c.Calculate(tmp, 25);
  result = sin(cos(0.5 * 25));
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_14) {
  s21::Controller c;
  std::string tmp = ("sin(cos(0.5*x*-))");
  c.Calculate(tmp, 0);
  ASSERT_EQ(tmp, "ERROR");
}

TEST(test_calc, smartcalc_15) {
  s21::Controller c;
  std::string tmp = ("2*-cos()");
  c.Calculate(tmp, 0);
  ASSERT_EQ(tmp, "ERROR");
}

TEST(test_calc, smartcalc_16) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("2*-cos(5)");
  c.Calculate(tmp, 25);
  result = (2 * -cos(5));
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_17) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("sqrt(789)");
  c.Calculate(tmp, 25);
  result = (sqrt(789));
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_18) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("ln(789)");
  c.Calculate(tmp, 25);
  result = (log(789));
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_19) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("log(123)");
  c.Calculate(tmp, 25);
  result = (log10(123));
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_20) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("sqrt(-789)");
  c.Calculate(tmp, 25);
  result = (sqrt(-789));
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_21) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("-(+8)");
  c.Calculate(tmp, 0);
  result = -(+8);
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_22) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("+(-8)");
  c.Calculate(tmp, 0);
  result = +(-8);
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_23) {
  s21::Controller c;
  std::string tmp = ("4-)*(");
  c.Calculate(tmp, 25);
  ASSERT_EQ(tmp, "ERROR");
}

TEST(test_calc, smartcalc_24) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("4%6");
  c.Calculate(tmp, 0);
  result = fmod(4, 6);
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_25) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("6^7");
  c.Calculate(tmp, 0);
  result = pow(6, 7);
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_26) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("34*89e-4");
  c.Calculate(tmp, 0);
  result = (34 * 89e-4);
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_27) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("34*89e+2");
  c.Calculate(tmp, 0);
  result = (34 * 89e+2);
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_28) {
  s21::Controller c;
  std::string tmp = ("cos(");
  c.Calculate(tmp, 25);
  ASSERT_EQ(tmp, "ERROR");
}

TEST(test_calc, smartcalc_29) {
  s21::Controller c;
  std::string tmp = (".");
  c.Calculate(tmp, 25);
  ASSERT_EQ(tmp, "ERROR");
}

TEST(test_calc, smartcalc_30) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = (".3");
  c.Calculate(tmp, 0);
  result = .3;
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_31) {
  s21::Controller c;
  double result = 0;
  std::string tmp = ("34e+3*5e+45");
  c.Calculate(tmp, 0);
  char bubber[50];
  result = (34e+3 * 5e+45);
  sprintf(bubber, "%e", result);
  ASSERT_EQ(tmp, bubber);
}

TEST(test_calc, smartcalc_32) {
  s21::Controller c;
  s21::Model m;
  double result = 0;
  std::string tmp = ("4.+.3");
  c.Calculate(tmp, 0);
  result = (4. + .3);
  std::string res = std::to_string(result);
  m.Check(res);
  ASSERT_EQ(tmp, res);
}

TEST(test_calc, smartcalc_33) {
  s21::Controller c;
  std::string tmp = ("2*x");
  std::pair<std::vector<double>, std::vector<double>> res;
  res = c.Grafic(-1, 1, tmp);
  auto j = res.second.begin();
  auto i = res.first.begin();
  ASSERT_DOUBLE_EQ(*i, -1);
  ASSERT_DOUBLE_EQ(*j, -2);
}

TEST(test_calc, smartcalc_34) {
  s21::Model model;
  double loan_amount = 1000, interest_rate = 10, loan_term_in_months = 12,
         monthly_payment, common_payment, overpayment;

  model.CreditAnnuity(loan_amount, loan_term_in_months, interest_rate,
                      monthly_payment, overpayment, common_payment);

  EXPECT_DOUBLE_EQ(monthly_payment, 87.915887230009901);
  EXPECT_DOUBLE_EQ(common_payment, 1054.9906467601188);
  EXPECT_DOUBLE_EQ(overpayment, 54.990646760118807);
}

TEST(test_calc, smartcalc_35) {
  s21::Model model;
  double sum_of_credit = 100000.0;
  double duration_of_credit = 12.0;
  double annual_interest_rate = 5.0;
  double expected_month_pay_first = 8722.22;
  double expected_month_pay_last = 8375.00;
  double expected_over_pay = 44966.67;
  double expected_all_sum_of_pay = 144966.67;
  double month_pay_first, month_pay_last, over_pay, all_sum_of_pay;

  model.CreditDifferentiated(sum_of_credit, duration_of_credit,
                             annual_interest_rate, month_pay_first,
                             month_pay_last, over_pay, all_sum_of_pay);

  EXPECT_EQ(month_pay_first == expected_month_pay_first, false);
  EXPECT_EQ(month_pay_last == expected_month_pay_last, false);
  EXPECT_EQ(over_pay == expected_over_pay, false);
  EXPECT_EQ(all_sum_of_pay == expected_all_sum_of_pay, false);
}

TEST(test_calc, smartcalc_36) {
  s21::Model model;

  double replenishment1[] = {1};
  double replenishment2[] = {100};
  int count_replenishment = 1;
  double withdrawals1[] = {};
  double withdrawals2[] = {};
  int count_withdrawals = 0;
  double all_sum = 0;
  double duration_of_credit = 12;
  double interest_rate = 10;
  double tax = 5;
  int period_s = 1;
  int capitalization = 0;
  double all_interest;
  double all_tax;
  double total_sum;

  model.Deposit(replenishment1, replenishment2, count_replenishment,
                withdrawals1, withdrawals2, count_withdrawals, all_sum,
                duration_of_credit, interest_rate, tax, period_s,
                capitalization, all_interest, all_tax, total_sum);

  EXPECT_EQ(all_interest, 10);
  EXPECT_EQ(all_tax, 0.0);
  EXPECT_EQ(total_sum, 100);
}

TEST(test_calc, smartcalc_37) {
  s21::Controller Controller;

  double sum_of_credit = 100000;
  double duration_of_credit = 12;
  double annual_interest_rate = 10;
  double month_pay;
  double over_pay;
  double all_sum_of_pay;

  Controller.CreditAnnuity(sum_of_credit, duration_of_credit,
                           annual_interest_rate, month_pay, over_pay,
                           all_sum_of_pay);

  EXPECT_NEAR(month_pay, 8791.5887230009903, 0.01);
  EXPECT_NEAR(over_pay, 5499.0646760118834, 0.01);
  EXPECT_NEAR(all_sum_of_pay, 105499.06467601188, 0.01);
}

TEST(test_calc, smartcalc_38) {
  s21::Controller Controller;

  double sum_of_credit = 100000;
  double duration_of_credit = 12;
  double annual_interest_rate = 10;
  double month_pay_first;
  double month_pay_last;
  double over_pay;
  double all_sum_of_pay;

  Controller.CreditDifferentiated(sum_of_credit, duration_of_credit,
                                  annual_interest_rate, month_pay_first,
                                  month_pay_last, over_pay, all_sum_of_pay);

  EXPECT_NEAR(month_pay_first, 9166.6666666666679, 0.01);
  EXPECT_NEAR(month_pay_last, 8402.7777777777792, 0.01);
  EXPECT_NEAR(over_pay, 5416.6666666666861, 0.01);
  EXPECT_NEAR(all_sum_of_pay, 105416.66666666669, 0.01);
}

TEST(test_calc, smartcalc_39) {
  s21::Controller Controller;

  double replenishment1[] = {1};
  double replenishment2[] = {100};
  int count_replenishment = 1;
  double withdrawals1[] = {};
  double withdrawals2[] = {};
  int count_withdrawals = 0;
  double all_sum = 0;
  double duration_of_credit = 12;
  double interest_rate = 10;
  double tax = 5;
  int period_s = 3;
  int capitalization = 1;
  double all_interest;
  double all_tax;
  double total_sum;

  Controller.Deposit(replenishment1, replenishment2, count_replenishment,
                     withdrawals1, withdrawals2, count_withdrawals, all_sum,
                     duration_of_credit, interest_rate, tax, period_s,
                     capitalization, all_interest, all_tax, total_sum);

  EXPECT_NEAR(all_interest, 10.3812890625, 0.01);
  EXPECT_NEAR(all_tax, 0, 0.01);
  EXPECT_NEAR(total_sum, 110.3812890625, 0.01);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
