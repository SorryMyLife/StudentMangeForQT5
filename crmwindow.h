#ifndef CRMWINDOW_H
#define CRMWINDOW_H

#include <QAction>
#include <QCheckBox>
#include <QCloseEvent>
#include <QComboBox>
#include <QDebug>
#include <QEvent>
#include <QFontDialog>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QInputDialog>
#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include <QRegExp>
#include <QTableWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVBoxLayout>
#include <QWidget>
#include <QtCharts>

#include "addnewwindow.h"
#include "chartwindow.h"
#include "studentinfo.h"
#include "teacherinfo.h"

namespace Ui {
class CRMWindow;
}

class CRMWindow : public QWidget {
  Q_OBJECT

public:
  QList<StudentInfo> StudentInfoList, FindStudentInfoList;
  QList<TeacherInfo> TeacherInfoList, FindTeacherInfoList;
  AddNewWindow addNewWindow;
  chartWindow chartwind;
  QLineEdit *searchEdit;
  QComboBox *showSearchValues;
  QPushButton *searchButton, *addButton, *removeButton, *changeButton,
      *refButton;
  bool studentFindIsOK = false, studentChangeIsOK = false,
       studentSubjectFindIsOK = false, studentSubjectChangeIsOK = false;
  QChartView *chartView = NULL, *barView = NULL, *teacherView = NULL;
  int clickedValue = -1;

public:
  void showLayout();
  void init();
  void checkValues();
  void closeEvent(QCloseEvent *event);
  QTableWidget *addTableWidget(QStringList l);
  void studentFind();
  void showStudentFindLayout(QVBoxLayout *vbox2);
  void listStudent(QList<StudentInfo> StudentInfoList);
  void addStudent(StudentInfo studentInfo);
  void removeStudent(int id);
  void changeStudent();
  void addTable(StudentInfo studentInfo, int index);
  void listCourse(QList<StudentInfo> StudentInfoList);
  void listTeacher(QList<TeacherInfo> TeacherInfoList);
  void addTeacher(TeacherInfo teacherInfo);
  void addTable(TeacherInfo teacherInfo, int index);
  void checkClickValue();
  void showTable();
  void showCombox();
  void closeControl();
  void showControl();
  void closeView();
  void showView();

public:
  QHBoxLayout *hbox;
  QVBoxLayout *vbox;
  QTableWidget *table, *table2, *table3;

public:
  explicit CRMWindow(QWidget *parent = nullptr);
  ~CRMWindow();

private:
  Ui::CRMWindow *ui;
};

#endif // CRMWINDOW_H
