#ifndef TEACHERINFO_H
#define TEACHERINFO_H
#include <QString>

class TeacherInfo {
  /**

{"教师名字",     "教师性别",     "教师年龄",
                           "教师所管班级", "教师所教科目", "教师执照号码",
                           "教师住址","教师工资"};

*/

public:
  QString name, sex, age, manageClass, manageSubject, id, address, money;

public:
  QString getName() const;
  void setName(const QString &value);
  QString getSex() const;
  void setSex(const QString &value);
  QString getAge() const;
  void setAge(const QString &value);
  QString getManageClass() const;
  void setManageClass(const QString &value);
  QString getManageSubject() const;
  void setManageSubject(const QString &value);
  QString getId() const;
  void setId(const QString &value);
  QString getAddress() const;
  void setAddress(const QString &value);
  QString getMoney() const;
  void setMoney(const QString &value);
  QString toString();

public:
  TeacherInfo();
  TeacherInfo(const QString &name, const QString &sex, const QString &age,
              const QString &manageClass, const QString &manageSubject,
              const QString &id, const QString &address);
  TeacherInfo(const QString &name, const QString &sex, const QString &age,
              const QString &manageClass, const QString &manageSubject,
              const QString &id, const QString &address, const QString &money);
};

#endif // TEACHERINFO_H
