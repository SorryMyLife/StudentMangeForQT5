#include "studentinfo.h"

QString StudentInfo::getChinese() const { return chinese; }

void StudentInfo::setChinese(const QString &value) { chinese = value; }

QString StudentInfo::getMathematics() const { return mathematics; }

void StudentInfo::setMathematics(const QString &value) { mathematics = value; }

QString StudentInfo::getBiology() const { return Biology; }

void StudentInfo::setBiology(const QString &value) { Biology = value; }

QString StudentInfo::getPolitics() const { return Politics; }

void StudentInfo::setPolitics(const QString &value) { Politics = value; }

QString StudentInfo::getGeography() const { return Geography; }

void StudentInfo::setGeography(const QString &value) { Geography = value; }

QString StudentInfo::getHistory() const { return history; }

void StudentInfo::setHistory(const QString &value) { history = value; }

QString StudentInfo::getChemistry() const { return Chemistry; }

void StudentInfo::setChemistry(const QString &value) { Chemistry = value; }

QString StudentInfo::getPhysics() const { return Physics; }

void StudentInfo::setPhysics(const QString &value) { Physics = value; }

QString StudentInfo::getEnglish() const { return English; }

void StudentInfo::setEnglish(const QString &value) { English = value; }

StudentInfo::StudentInfo(const QString &chinese, const QString &mathematics,
                         const QString &English, const QString &Physics,
                         const QString &Chemistry, const QString &history,
                         const QString &Geography, const QString &Politics,
                         const QString &Biology, const QString &name,
                         const QString &age, const QString &address,
                         const QString &sex, const QString &id,
                         const QString &sum, const QString &studentclass) {
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

void StudentInfo::setName(QString name) { this->name = name; }
void StudentInfo::setAge(QString age) { this->age = age; }
void StudentInfo::setAddress(QString address) { this->address = address; }
void StudentInfo::setSex(QString sex) { this->sex = sex; }
void StudentInfo::setId(QString id) { this->id = id; }
void StudentInfo::setSum(QString sum) { this->sum = sum; }
void StudentInfo::setStudentClass(QString studentclass) {
  this->studentclass = studentclass;
}

QString StudentInfo::getName() { return name; }
QString StudentInfo::getAge() { return age; }
QString StudentInfo::getAddress() { return address; }
QString StudentInfo::getSex() { return sex; }
QString StudentInfo::getId() { return id; }
QString StudentInfo::getSum() { return sum; }
QString StudentInfo::getStudentClass() { return studentclass; }

StudentInfo::StudentInfo(QString name, QString age, QString address,
                         QString sex, QString id, QString sum,
                         QString studentclass) {

  this->name = name;
  this->id = id;
  this->address = address;
  this->sex = sex;
  this->sum = sum;
  this->age = age;
  this->studentclass = studentclass;
}

QString StudentInfo::toString() {
  return "[ name : " + getName() + " ][ id : " + getId() +
         " ][ address : " + getAddress() + " ][ sex : " + getSex() +
         " ][ sum : " + getSum() + " ][ age : " + getAge() +
         " ][ studentclass : " + getStudentClass() + " ]";
}

StudentInfo::StudentInfo() {}
