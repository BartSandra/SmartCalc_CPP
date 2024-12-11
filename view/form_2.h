#ifndef FORM_2_H
#define FORM_2_H

#include <QWidget>

#include "../controller/controller.h"

namespace Ui {
class Form_2;
}

class Form_2 : public QWidget {
  Q_OBJECT

 public:
  explicit Form_2(QWidget *parent = nullptr);
  ~Form_2();

 private slots:
  void on_checkBox_clicked(bool checked);
  void on_pushButton_clicked();

 private:
  Ui::Form_2 *ui;
  s21::Controller controller_;

 public:
  int globalTer = 1;
  int globalPeriod = 1;
  int globalKap = 0;
};

#endif  // FORM_2_H
