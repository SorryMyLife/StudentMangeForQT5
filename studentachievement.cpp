#include "studentachievement.h"

QString StudentAchievement::getBiology() const { return Biology; }

void StudentAchievement::setBiology(const QString &value) { Biology = value; }

QString StudentAchievement::getMathematics() const { return mathematics; }

void StudentAchievement::setMathematics(const QString &value) {
  mathematics = value;
}

QString StudentAchievement::getEnglish() const { return English; }

void StudentAchievement::setEnglish(const QString &value) { English = value; }

QString StudentAchievement::getPhysics() const { return Physics; }

void StudentAchievement::setPhysics(const QString &value) { Physics = value; }

QString StudentAchievement::getChemistry() const { return Chemistry; }

void StudentAchievement::setChemistry(const QString &value) {
  Chemistry = value;
}

QString StudentAchievement::getHistory() const { return history; }

void StudentAchievement::setHistory(const QString &value) { history = value; }

QString StudentAchievement::getGeography() const { return Geography; }

void StudentAchievement::setGeography(const QString &value) {
  Geography = value;
}

QString StudentAchievement::getPolitics() const { return Politics; }

void StudentAchievement::setPolitics(const QString &value) { Politics = value; }

QString StudentAchievement::getChinese() const { return chinese; }

void StudentAchievement::setChinese(const QString &value) { chinese = value; }

StudentAchievement::StudentAchievement(
    const QString &chinese, const QString &mathematics, const QString &English,
    const QString &Physics, const QString &Chemistry, const QString &history,
    const QString &Geography, const QString &Politics, const QString &Biology,
    const QString &name, const QString &age, const QString &address,
    const QString &sex, const QString &id, const QString &sum,
    const QString &studentclass) {

  this->chinese = chinese;
  this->mathematics = mathematics;
  this->English = English;
  this->Physics = Physics;
  this->Chemistry = Chemistry;
  this->history = history;
  this->Geography = Geography;
  this->Politics = Politics;
  this->Biology = Biology;
  this->name = name;
  this->id = id;
  this->address = address;
  this->sex = sex;
  this->sum = sum;
  this->age = age;
  this->studentclass = studentclass;
}

QString StudentAchievement::toString() {
  return StudentInfo::toString() + "[ chinese : " + getChinese() +
         " ][ mathematics : " + getMathematics() +
         " ][ English : " + getEnglish() + " ][ Physics : " + getPhysics() +
         " ][ Chemistry : " + getChemistry() + " ][ history : " + getHistory() +
         " ][ Geography : " + getGeography() +
         " ][ Politics : " + getPolitics() + " ][ Biology : " + getBiology() +
         " ]";
}

StudentAchievement::StudentAchievement() {}
