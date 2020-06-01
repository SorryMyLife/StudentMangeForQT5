#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include <QString>

class StudentInfo {

public:
  QString name, age, address, sex, id, sum, studentclass, chinese, mathematics,
      English, Physics, Chemistry, history, Geography, Politics, Biology;

public:
  void setName(QString name);
  void setAge(QString age);
  void setAddress(QString address);
  void setSex(QString sex);
  void setId(QString id);
  void setSum(QString sum);
  void setStudentClass(QString studentclass);
  QString getName();
  QString getAge();
  QString getAddress();
  QString getSex();
  QString getId();
  QString getSum();
  QString getStudentClass();

  StudentInfo(QString name, QString age, QString address, QString sex,
              QString id, QString sum, QString studentclass);

  StudentInfo(const QString &chinese, const QString &mathematics,
              const QString &English, const QString &Physics,
              const QString &Chemistry, const QString &history,
              const QString &Geography, const QString &Politics,
              const QString &Biology, const QString &name, const QString &age,
              const QString &address, const QString &sex, const QString &id,
              const QString &sum, const QString &studentclass);

  QString toString();

public:
  StudentInfo();
  QString getChinese() const;
  void setChinese(const QString &value);
  QString getMathematics() const;
  void setMathematics(const QString &value);
  QString getBiology() const;
  void setBiology(const QString &value);
  QString getPolitics() const;
  void setPolitics(const QString &value);
  QString getGeography() const;
  void setGeography(const QString &value);
  QString getHistory() const;
  void setHistory(const QString &value);
  QString getChemistry() const;
  void setChemistry(const QString &value);
  QString getPhysics() const;
  void setPhysics(const QString &value);
  QString getEnglish() const;
  void setEnglish(const QString &value);
};

#endif // STUDENTINFO_H
