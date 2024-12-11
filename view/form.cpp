#include "form.h"

#include "ui_form.h"

Form::Form(QWidget *parent) : QWidget(parent), ui(new Ui::Form) {
  ui->setupUi(this);
  ui->lineEdit_4->setText("Расчет ежемесячного платежа");
}

Form::~Form() { delete ui; }

void Form::on_radioButton_clicked() { globalStr = "A"; }

void Form::on_radioButton_2_clicked() { globalStr = "D"; }

void Form::on_pushButton_clicked() {
  bool ok1, ok2, ok3;
  double sum_of_Credit = ui->lineEdit->text().toDouble(&ok1);
  double duration_of_credit = ui->lineEdit_2->text().toDouble(&ok2);
  duration_of_credit *= globalInt;
  double annual_interest_rate = ui->lineEdit_3->text().toDouble(&ok3);
  double month = 0.0, over = 0.0, all = 0.0;

  int error = 0;
  if (ok1 == true && ok2 == true && ok3 == true &&
      duration_of_credit < 601.00 && globalStr.contains("A")) {
      this->controller_.CreditAnnuity(sum_of_Credit, duration_of_credit,
                                  annual_interest_rate, month, over, all);
    if (error == 0) {
      ui->label_9->setText(QString::number(month, 'f', 2));
      ui->label_10->setText(QString::number(over, 'f', 2));
      ui->label_11->setText(QString::number(all, 'f', 2));
    } else {
      ui->label_9->setText("error!");
      ui->label_10->setText("error!");
      ui->label_11->setText("error!");
    }
  } else if (ok1 == true && ok2 == true && ok3 == true &&
             duration_of_credit < 601.00 && globalStr.contains("D")) {
    double month_pay_last = 0.0;
this->controller_.CreditDifferentiated(sum_of_Credit, duration_of_credit,annual_interest_rate, month, month_pay_last, over, all);
    if (error == 0) {
      ui->label_9->setText(QString::number(month, 'f', 2) + " ... " +
                           QString::number(month_pay_last, 'f', 2));
      ui->label_10->setText(QString::number(over, 'f', 2));
      ui->label_11->setText(QString::number(all, 'f', 2));
    } else {
      ui->label_9->setText("error!");
      ui->label_10->setText("error!");
      ui->label_11->setText("error!");
    }
  } else {
    ui->label_9->setText("error!");
    ui->label_10->setText("error!");
    ui->label_11->setText("error!");
  }
}
