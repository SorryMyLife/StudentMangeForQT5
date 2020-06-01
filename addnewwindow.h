#ifndef ADDNEWWINDOW_H
#define ADDNEWWINDOW_H

#include "studentinfo.h"
#include "teacherinfo.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

namespace Ui {
class AddNewWindow;
}

class AddNewWindow : public QWidget {
  Q_OBJECT
  /**


  {"学生名字", "学生性别", "学生年龄", "学生班级",
                               "学生成绩", "学生学号", "学生住址"};

  */
public:
  QStringList studentList = {"学生名字", "学生性别", "学生年龄", "学生班级",
                             "学生成绩", "学生学号", "学生住址"};
  QStringList courseList = {"学生名字", "学生性别", "学生学号", "语文成绩",
                            "数学成绩", "英语成绩", "物理成绩", "政治成绩",
                            "化学成绩", "地理成绩", "历史成绩", "生物成绩"};
  QStringList allTextList = {"学生名字", "学生性别", "学生年龄", "学生班级",
                             "学生成绩", "学生学号", "学生住址", "语文成绩",
                             "数学成绩", "英语成绩", "物理成绩", "政治成绩",
                             "化学成绩", "地理成绩", "历史成绩", "生物成绩"};
  QStringList teacherList = {"教师名字",     "教师性别",     "教师年龄",
                             "教师所管班级", "教师所教科目", "教师执照号码",
                             "教师住址",     "教师工资(元)"};
  QHBoxLayout *hbox;
  QVBoxLayout *vbox;
  QPushButton *change, *cancel, *add;
  QLineEdit *nameEdit = NULL, *SexEdit = NULL, *AgeEdit = NULL,
            *ClassEdit = NULL, *SumEdit = NULL, *IdEdit = NULL,
            *AddressEdit = NULL, *chineseEdit = NULL, *mathematicsEdit = NULL,
            *EnglishEdit = NULL, *PhysicsEdit = NULL, *ChemistryEdit = NULL,
            *historyEdit = NULL, *GeographyEdit = NULL, *PoliticsEdit = NULL,
            *BiologyEdit = NULL, *SubjectEdit = NULL, *MoneyEdit = NULL;

  QList<QLineEdit *> editList, editList2, allEditList, teacherEditList;

  int con_count = 0, add_con_count = 0, clickvalue = -1, teacher_con_count = 0,
      add_teacher_con_count = 0;

public:
  void init();
  void AddStudent(QList<StudentInfo> &l);
  void ChangeStudent(QList<StudentInfo> &l, StudentInfo s);
  void RemoveStudent(QList<StudentInfo> &l, StudentInfo s);
  StudentInfo showMsg(QList<QString> editValueList);
  void showLayout();

  bool isID(QList<StudentInfo> &l, StudentInfo s);

  TeacherInfo showMsgTeacher(QList<QString> editValueList);
  void AddStudent(QList<TeacherInfo> &l);
  void ChangeStudent(QList<TeacherInfo> &l, TeacherInfo s);
  void RemoveStudent(QList<TeacherInfo> &l, TeacherInfo s);
  bool isID(QList<TeacherInfo> &l, TeacherInfo s);

public:
  explicit AddNewWindow(QWidget *parent = nullptr);
  ~AddNewWindow();

private:
  Ui::AddNewWindow *ui;
};

#endif // ADDNEWWINDOW_H
