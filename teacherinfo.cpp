#include "teacherinfo.h"

QString TeacherInfo::toString() {

  return "[ name : " + getName() + " ][ age : " + getAge() +
         " ][ sex : " + getSex() + " ][ manageClass : " + getManageClass() +
         " ][ manageSubject : " + getManageSubject() + " ][ id : " + getId() +
         " ][ address : " + getAddress() + " ][ money : " + getMoney() + " ]";
}

TeacherInfo::TeacherInfo(const QString &name, const QString &sex,
                         const QString &age, const QString &manageClass,
                         const QString &manageSubject, const QString &id,
                         const QString &address, const QString &money) {
  this->name = name;
  this->sex = sex;
  this->age = age;
  this->manageClass = manageClass;
  this->manageSubject = manageSubject;
  this->id = id;
  this->address = address;
  this->money = money;
}

TeacherInfo::TeacherInfo(const QString &name, const QString &sex,
                         const QString &age, const QString &manageClass,
                         const QString &manageSubject, const QString &id,
                         const QString &address) {
  this->name = name;
  this->sex = sex;
  this->age = age;
  this->manageClass = manageClass;
  this->manageSubject = manageSubject;
  this->id = id;
  this->address = address;
}

QString TeacherInfo::getMoney() const { return money; }

void TeacherInfo::setMoney(const QString &value) { money = value; }

QString TeacherInfo::getName() const { return name; }

void TeacherInfo::setName(const QString &value) { name = value; }

QString TeacherInfo::getSex() const { return sex; }

void TeacherInfo::setSex(const QString &value) { sex = value; }

QString TeacherInfo::getAge() const { return age; }

void TeacherInfo::setAge(const QString &value) { age = value; }

QString TeacherInfo::getManageClass() const { return manageClass; }

void TeacherInfo::setManageClass(const QString &value) { manageClass = value; }

QString TeacherInfo::getManageSubject() const { return manageSubject; }

void TeacherInfo::setManageSubject(const QString &value) {
  manageSubject = value;
}

QString TeacherInfo::getId() const { return id; }

void TeacherInfo::setId(const QString &value) { id = value; }

QString TeacherInfo::getAddress() const { return address; }

void TeacherInfo::setAddress(const QString &value) { address = value; }

TeacherInfo::TeacherInfo() {}
