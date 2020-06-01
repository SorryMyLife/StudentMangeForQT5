#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include "studentinfo.h"
#include "teacherinfo.h"
#include <QVBoxLayout>
#include <QWidget>
#include <QtCharts>
namespace Ui {
class chartWindow;
}

class chartWindow : public QWidget {
  Q_OBJECT

public:
  QPieSeries *series;
  QBarSeries *studentCourseSum;
  //  QChartView *chartView;
  StudentInfo s;
  int init_ok = 0, courseSum_init_ok = 0;
  //  QChart *chart1 = NULL, *chart2 = NULL;
  QPoint p;

public:
  QChartView *ShowStudentChart(QList<StudentInfo> l);
  QChartView *ShowStudentBarSeries(QList<StudentInfo> l);
  QChartView *ShowTeacherView(QList<TeacherInfo> l);

  void init();

public:
  explicit chartWindow(QWidget *parent = nullptr);
  ~chartWindow();

private:
  Ui::chartWindow *ui;
};

#endif // CHARTWINDOW_H
