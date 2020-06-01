#include "addnewwindow.h"
#include "ui_addnewwindow.h"

AddNewWindow::AddNewWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::AddNewWindow) {
  ui->setupUi(this);
}

void AddNewWindow::AddStudent(QList<TeacherInfo> &l) {
  showLayout();
  change->setHidden(true);
  add->setHidden(false);
  setWindowTitle("添加一个新教师");
  if (add_teacher_con_count == 0) {
    connect(add, &QPushButton::clicked, [&]() {
      TeacherInfo s = showMsgTeacher({nameEdit->text(), SexEdit->text(),
                                      AgeEdit->text(), ClassEdit->text(),
                                      SubjectEdit->text(), IdEdit->text(),
                                      AddressEdit->text(), MoneyEdit->text()});
      if (!s.getId().isEmpty() && !s.getAge().isEmpty() &&
          !s.getSex().isEmpty() && !s.getManageClass().isEmpty() &&
          !s.getAddress().isEmpty() && !s.getName().isEmpty() &&
          !s.getManageSubject().isEmpty()) {

        if (isID(l, s)) {
          l.append(s);
          close();
        } else {
          QMessageBox::critical(this, "错误",
                                "存在两个相同的教师编号!请重新输入",
                                QMessageBox::Yes);
        }
      }
      add_teacher_con_count = add_teacher_con_count + 1;
    });
  }
  show();
}
void AddNewWindow::ChangeStudent(QList<TeacherInfo> &l, TeacherInfo sss) {
  showLayout();
  add->setHidden(true);
  change->setHidden(false);
  cancel->setText("删除此条");
  setWindowTitle("修改一个职工信息");
  RemoveStudent(l, sss);
  nameEdit->setText(sss.getName());
  SexEdit->setText(sss.getSex());
  AgeEdit->setText(sss.getAge());
  ClassEdit->setText(sss.getManageClass());
  SubjectEdit->setText(sss.getManageSubject());
  IdEdit->setText(sss.getId());
  AddressEdit->setText(sss.getAddress());
  MoneyEdit->setText(sss.getMoney());

  if (teacher_con_count == 0) {
    connect(change, &QPushButton::clicked, [&]() {
      TeacherInfo s = showMsgTeacher({nameEdit->text(), SexEdit->text(),
                                      AgeEdit->text(), ClassEdit->text(),
                                      SubjectEdit->text(), IdEdit->text(),
                                      AddressEdit->text(), MoneyEdit->text()});

      if (!s.getId().isEmpty() && !s.getAge().isEmpty() &&
          !s.getSex().isEmpty() && !s.getManageClass().isEmpty() &&
          !s.getAddress().isEmpty() && !s.getName().isEmpty() &&
          !s.getManageSubject().isEmpty()) {
        if (isID(l, s)) {
          l.append(s);
          close();
        } else {
          QMessageBox::critical(this, "错误",
                                "存在两个相同的教师编号!请重新输入",
                                QMessageBox::Yes);
        }
      }
      teacher_con_count = teacher_con_count + 1;
    });
  }
  show();
}
void AddNewWindow::RemoveStudent(QList<TeacherInfo> &l, TeacherInfo sss) {
  for (int i = 0; i < l.size(); i++) {
    if (l[i].getId().compare(sss.getId()) == 0 &&
        l[i].getAge().compare(sss.getAge()) == 0 &&
        l[i].getSex().compare(sss.getSex()) == 0 &&
        l[i].getManageSubject().compare(sss.getManageSubject()) == 0 &&
        l[i].getName().compare(sss.getName()) == 0 &&
        l[i].getAddress().compare(sss.getAddress()) == 0 &&
        l[i].getManageClass().compare(sss.getManageClass()) == 0) {
      l.removeAt(i);
      break;
    }
  }
}
bool AddNewWindow::isID(QList<TeacherInfo> &l, TeacherInfo s) {
  foreach (TeacherInfo info, l) {
    if (info.getId().compare(s.getId()) == 0) {
      return false;
    }
  }
  return true;
}
TeacherInfo AddNewWindow::showMsgTeacher(QList<QString> editValueList) {

  QString nameText = editValueList[0], SexText = editValueList[1],
          AgeText = editValueList[2], ClassText = editValueList[3],
          SubJect = editValueList[4], IdText = editValueList[5],
          AddressText = editValueList[6], MoneyText = editValueList[7];
  QStringList textList = {nameText, SexText, AgeText,     ClassText,
                          SubJect,  IdText,  AddressText, MoneyText};
  QMessageBox msg;
  msg.setIcon(QMessageBox::Icon::Critical);
  msg.setWindowTitle("错误");
  msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  msg.setButtonText(QMessageBox::Yes, "好的");
  msg.setButtonText(QMessageBox::No, "不行,我拒绝");
  for (int i = 0; i < textList.size(); i++) {
    if (textList[i].isNull() || textList[i].isEmpty()) {
      msg.setText("请确认" + teacherList[i] + "是否为空或者合法字符串");
    }
  }
  if (!msg.text().isNull() || !msg.text().isEmpty()) {
    switch (msg.exec()) {
    case QMessageBox::Yes:
      msg.close();
      break;
    case QMessageBox::No:
      foreach (QLineEdit *e, teacherEditList) { e->clear(); }
      close();
      break;
    }
  }

  return TeacherInfo(nameText, SexText, AgeText, ClassText, SubJect, IdText,
                     AddressText, MoneyText);
}

StudentInfo AddNewWindow::showMsg(QList<QString> editValueList) {
  QString nameText = editValueList[0], SexText = editValueList[1],
          AgeText = editValueList[2], ClassText = editValueList[3],
          SumText = editValueList[4], IdText = editValueList[5],
          AddressText = editValueList[6], chineseText = editValueList[7],
          mathematicsText = editValueList[8], EnglishText = editValueList[9],
          PhysicsText = editValueList[10], ChemistryText = editValueList[11],
          historyText = editValueList[12], GeographyText = editValueList[13],
          PoliticsText = editValueList[14], BiologyText = editValueList[15];
  double (*getSum)(QStringList l) = [](QStringList l) {
    double sum = 0;
    foreach (QString n, l) { sum += n.replace(QRegExp("\\s+"), "").toDouble(); }

    return sum;
  };
  QStringList textList = {
      nameText,        SexText,       AgeText,      ClassText,
      SumText,         IdText,        AddressText,  chineseText,
      mathematicsText, EnglishText,   PhysicsText,  ChemistryText,
      historyText,     GeographyText, PoliticsText, BiologyText};

  QMessageBox msg;

  msg.setIcon(QMessageBox::Icon::Critical);
  msg.setWindowTitle("错误");
  msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  msg.setButtonText(QMessageBox::Yes, "好的");
  msg.setButtonText(QMessageBox::No, "不行,我拒绝");
  for (int i = 0; i < textList.size(); i++) {
    if (textList[i].isNull() || textList[i].isEmpty()) {
      msg.setText("请确认" + allTextList[i] + "是否为空或者合法字符串");
    }
  }
  if (!msg.text().isNull() || !msg.text().isEmpty()) {
    switch (msg.exec()) {
    case QMessageBox::Yes:
      msg.close();
      break;
    case QMessageBox::No:
      foreach (QLineEdit *e, allEditList) { e->clear(); }
      close();
      break;
    }
  }
  SumText = QString::number(getSum({chineseText, mathematicsText, EnglishText,
                                    PhysicsText, ChemistryText, historyText,
                                    GeographyText, PoliticsText, BiologyText}));
  return StudentInfo(chineseText, mathematicsText, EnglishText, PhysicsText,
                     ChemistryText, historyText, GeographyText, PoliticsText,
                     BiologyText, nameText, AgeText, AddressText, SexText,
                     IdText, SumText, ClassText);
}

bool AddNewWindow::isID(QList<StudentInfo> &l, StudentInfo s) {

  foreach (StudentInfo info, l) {
    if (info.getId().compare(s.getId()) == 0) {
      return false;
    }
  }

  return true;
}

void AddNewWindow::AddStudent(QList<StudentInfo> &l) {
  showLayout();
  change->setHidden(true);
  add->setHidden(false);
  setWindowTitle("添加一个新同学");
  if (add_con_count == 0) {
    connect(add, &QPushButton::clicked, [&]() {
      StudentInfo s = showMsg(
          {nameEdit->text(), SexEdit->text(), AgeEdit->text(),
           ClassEdit->text(), SumEdit->text(), IdEdit->text(),
           AddressEdit->text(), chineseEdit->text(), mathematicsEdit->text(),
           EnglishEdit->text(), PhysicsEdit->text(), ChemistryEdit->text(),
           historyEdit->text(), GeographyEdit->text(), PoliticsEdit->text(),
           BiologyEdit->text()});
      if (!s.getId().isEmpty() && !s.getAge().isEmpty() &&
          !s.getSex().isEmpty() && !s.getStudentClass().isEmpty() &&
          !s.getAddress().isEmpty() && !s.getName().isEmpty() &&
          !s.getSum().isEmpty()) {

        if (isID(l, s)) {
          l.append(s);
          close();
        } else {
          QMessageBox::critical(this, "错误", "存在两个相同的学号!请重新输入",
                                QMessageBox::Yes);
        }
      }
      add_con_count = add_con_count + 1;
    });
  }
  show();
}

void AddNewWindow::ChangeStudent(QList<StudentInfo> &l, StudentInfo sss) {
  showLayout();

  add->setHidden(true);
  change->setHidden(false);
  cancel->setText("删除此条");
  setWindowTitle("修改一个同学信息");
  RemoveStudent(l, sss);
  nameEdit->setText(sss.getName());
  SexEdit->setText(sss.getSex());
  AgeEdit->setText(sss.getAge());
  ClassEdit->setText(sss.getStudentClass());
  SumEdit->setText(sss.getSum());
  IdEdit->setText(sss.getId());
  AddressEdit->setText(sss.getAddress());
  chineseEdit->setText(sss.getChinese());
  mathematicsEdit->setText(sss.getMathematics());
  EnglishEdit->setText(sss.getEnglish());
  PhysicsEdit->setText(sss.getPhysics());
  ChemistryEdit->setText(sss.getChemistry());
  historyEdit->setText(sss.getHistory());
  GeographyEdit->setText(sss.getGeography());
  PoliticsEdit->setText(sss.getPolitics());
  BiologyEdit->setText(sss.getBiology());
  if (con_count == 0) {
    connect(change, &QPushButton::clicked, [&]() {
      StudentInfo s = showMsg(
          {nameEdit->text(), SexEdit->text(), AgeEdit->text(),
           ClassEdit->text(), SumEdit->text(), IdEdit->text(),
           AddressEdit->text(), chineseEdit->text(), mathematicsEdit->text(),
           EnglishEdit->text(), PhysicsEdit->text(), ChemistryEdit->text(),
           historyEdit->text(), GeographyEdit->text(), PoliticsEdit->text(),
           BiologyEdit->text()});
      qDebug() << "143 :::::: ";
      if (!s.getId().isEmpty() && !s.getAge().isEmpty() &&
          !s.getSex().isEmpty() && !s.getStudentClass().isEmpty() &&
          !s.getAddress().isEmpty() && !s.getName().isEmpty() &&
          !s.getSum().isEmpty()) {

        if (isID(l, s)) {
          l.append(s);
          close();
        } else {
          QMessageBox::critical(this, "错误", "存在两个相同的学号!请重新输入",
                                QMessageBox::Yes);
        }
      }
      con_count = con_count + 1;
      //      close();
    });
  }
  show();
}

void AddNewWindow::RemoveStudent(QList<StudentInfo> &l, StudentInfo sss) {

  for (int i = 0; i < l.size(); i++) {
    if (l[i].getId().compare(sss.getId()) == 0 &&
        l[i].getAge().compare(sss.getAge()) == 0 &&
        l[i].getSex().compare(sss.getSex()) == 0 &&
        l[i].getSum().compare(sss.getSum()) == 0 &&
        l[i].getName().compare(sss.getName()) == 0 &&
        l[i].getAddress().compare(sss.getAddress()) == 0 &&
        l[i].getStudentClass().compare(sss.getStudentClass()) == 0) {
      qDebug() << " find :::: " << sss.getName();
      l.removeAt(i);
      break;
    }
  }
}

void AddNewWindow::showLayout() {
  if (nameEdit == NULL) {
    init();
    QStringList sList;
    QList<QLineEdit *> tmpEdit;
    if (clickvalue == 2) {
      sList = teacherList;
      tmpEdit = teacherEditList;
    } else {
      sList = allTextList;
      tmpEdit = allEditList;
    }
    int index = 0;
    QHBoxLayout *hbox2 = new QHBoxLayout();
    for (int i = 0; i < sList.size(); i++) {
      if (index == 2) {
        vbox->addLayout(hbox);
        hbox2 = new QHBoxLayout();
        hbox = new QHBoxLayout();
        index = 0;
      }

      tmpEdit[i]->setPlaceholderText("请输入" + sList[i]);
      tmpEdit[i]->setFixedHeight(30);
      hbox2->addWidget(new QLabel(sList[i]));
      hbox2->addWidget(tmpEdit[i]);
      hbox->addLayout(hbox2);
      index++;
      if (i == (sList.size() - 1)) {
        vbox->addLayout(hbox);
      }
    }

    hbox2 = new QHBoxLayout();
    hbox2->addWidget(add);
    hbox2->addWidget(change);
    hbox2->addWidget(cancel);
    vbox->addLayout(hbox2);
    setLayout(vbox);
  }
}

void AddNewWindow::init() {

  nameEdit = new QLineEdit();
  SexEdit = new QLineEdit();
  AgeEdit = new QLineEdit();
  ClassEdit = new QLineEdit();
  SumEdit = new QLineEdit();
  IdEdit = new QLineEdit();
  AddressEdit = new QLineEdit();
  chineseEdit = new QLineEdit();
  mathematicsEdit = new QLineEdit();
  EnglishEdit = new QLineEdit();
  PhysicsEdit = new QLineEdit();
  ChemistryEdit = new QLineEdit();
  historyEdit = new QLineEdit();
  GeographyEdit = new QLineEdit();
  PoliticsEdit = new QLineEdit();
  BiologyEdit = new QLineEdit();
  SubjectEdit = new QLineEdit();
  MoneyEdit = new QLineEdit();

  hbox = new QHBoxLayout();
  vbox = new QVBoxLayout();

  change = new QPushButton("修改");
  cancel = new QPushButton("取消");
  add = new QPushButton("添加");
  editList = {nameEdit, SexEdit, AgeEdit,    ClassEdit,
              SumEdit,  IdEdit,  AddressEdit};

  editList2 = {nameEdit,        SexEdit,       AgeEdit,      ClassEdit,
               SumEdit,         IdEdit,        AddressEdit,  chineseEdit,
               mathematicsEdit, EnglishEdit,   PhysicsEdit,  ChemistryEdit,
               historyEdit,     GeographyEdit, PoliticsEdit, BiologyEdit};
  allEditList = {nameEdit,        SexEdit,       AgeEdit,      ClassEdit,
                 SumEdit,         IdEdit,        AddressEdit,  chineseEdit,
                 mathematicsEdit, EnglishEdit,   PhysicsEdit,  ChemistryEdit,
                 historyEdit,     GeographyEdit, PoliticsEdit, BiologyEdit};

  teacherEditList = {nameEdit,    SexEdit, AgeEdit,     ClassEdit,
                     SubjectEdit, IdEdit,  AddressEdit, MoneyEdit};

  connect(cancel, &QPushButton::clicked, [=]() { close(); });
}

AddNewWindow::~AddNewWindow() { delete ui; }
