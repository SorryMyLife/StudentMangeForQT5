#ifndef STUDENTACHIEVEMENT_H
#define STUDENTACHIEVEMENT_H

#include "studentinfo.h"

class StudentAchievement : public StudentInfo {
public:
  QString chinese, mathematics, English, Physics, Chemistry, history, Geography,
      Politics, Biology;
  QString getBiology() const;
  void setBiology(const QString &value);
  QString getMathematics() const;
  void setMathematics(const QString &value);
  QString getEnglish() const;
  void setEnglish(const QString &value);
  QString getPhysics() const;
  void setPhysics(const QString &value);
  QString getChemistry() const;
  void setChemistry(const QString &value);
  QString getHistory() const;
  void setHistory(const QString &value);
  QString getGeography() const;
  void setGeography(const QString &value);
  QString getPolitics() const;
  void setPolitics(const QString &value);
  QString getChinese() const;
  void setChinese(const QString &value);
  QString toString();

public:
  StudentAchievement();
  StudentAchievement(const QString &chinese, const QString &mathematics,
                     const QString &English, const QString &Physics,
                     const QString &Chemistry, const QString &history,
                     const QString &Geography, const QString &Politics,
                     const QString &Biology, const QString &name,
                     const QString &age, const QString &address,
                     const QString &sex, const QString &id, const QString &sum,
                     const QString &studentclass);
};

#endif // STUDENTACHIEVEMENT_H
