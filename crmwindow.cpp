#include "crmwindow.h"
#include "ui_crmwindow.h"

CRMWindow::CRMWindow(QWidget *parent) : QWidget(parent), ui(new Ui::CRMWindow) {
  ui->setupUi(this);

  init();
}

CRMWindow::~CRMWindow() { delete ui; }

void CRMWindow::showLayout() {

  QTreeWidget *tw = new QTreeWidget();
  QStringList menu1list, menu2list;
  menu1list << "首页"
            << "学生信息"
            << "课程信息"
            << "在职人员"
            << "遵纪作风";

  menu2list << "学生查询"
            << "学生修改"
            << "课程查询"
            << "课程修改"
            << "在职人员查询"
            << "在职人员修改";

  tw->setFixedWidth(220);
  tw->setColumnCount(1);
  tw->setHeaderHidden(true);
  tw->setFont(QFont("华文楷体", 20));
  tw->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
  tw->header()->setStretchLastSection(false);
  QTreeWidgetItem *item = new QTreeWidgetItem(tw, {"crm"});
  int menucount = 0, index = 0;
  foreach (QString menu1, menu1list) {
    QTreeWidgetItem *ii = new QTreeWidgetItem(item, {menu1});
    if (menucount > 0 && index < menu2list.size()) {
      for (int i = 0; i < 2; i++) {
        new QTreeWidgetItem(ii, {menu2list[index]});
        index++;
      }
    }
    menucount++;
  }

  hbox->addWidget(tw, 1);
  QVBoxLayout *vbox2 = new QVBoxLayout();
  QLabel *titleLabel = new QLabel("CRM");
  titleLabel->setFont(QFont("华文楷体", 20));
  titleLabel->setAlignment(Qt::AlignCenter);
  vbox2->addWidget(titleLabel);
  vbox2->setAlignment(Qt::AlignCenter);
  hbox->addLayout(vbox2);
  vbox->addLayout(hbox, 1);
  hbox = new QHBoxLayout();
  chartView = chartwind.ShowStudentChart(StudentInfoList);
  barView = chartwind.ShowStudentBarSeries(StudentInfoList);
  teacherView = chartwind.ShowTeacherView(TeacherInfoList);
  closeView();
  hbox->addWidget(chartView);
  hbox->addWidget(barView);
  vbox2->addLayout(hbox);
  vbox2->addWidget(teacherView);
  showStudentFindLayout(vbox2);
  connect(tw, &QTreeWidget::clicked, this, [=]() {
    QString currentName = tw->currentItem()->text(tw->currentColumn());
    if (currentName.compare("首页") == 0) {
      titleLabel->setText("首页");
      showView();
    } else if (currentName.compare("学生信息") == 0) {
      titleLabel->setText("学生信息");
      clickedValue = 0;
      showControl();
    } else if (currentName.compare("学生查询") == 0) {
      titleLabel->setText("学生查询");
      clickedValue = 0;
      studentFind();
    } else if (currentName.compare("学生修改") == 0) {
      titleLabel->setText("学生修改");
      clickedValue = 0;
      changeStudent();
    } else if (currentName.compare("课程信息") == 0) {
      titleLabel->setText("课程信息");
      clickedValue = 1;
      showControl();
    } else if (currentName.compare("课程查询") == 0) {
      titleLabel->setText("课程查询");
      clickedValue = 1;
      studentFind();
    } else if (currentName.compare("课程修改") == 0) {
      titleLabel->setText("课程修改");
      clickedValue = 1;
      changeStudent();
    } else if (currentName.compare("在职人员") == 0) {
      titleLabel->setText("在职人员");
      clickedValue = 2;
      showControl();
    } else if (currentName.compare("在职人员查询") == 0) {
      titleLabel->setText("在职人员查询");
      clickedValue = 2;
      addNewWindow.clickvalue = 2;
      studentFind();
    } else if (currentName.compare("在职人员修改") == 0) {
      titleLabel->setText("在职人员修改");
      clickedValue = 2;
      addNewWindow.clickvalue = 2;
      changeStudent();
    } else if (currentName.compare("遵纪作风") == 0) {
      titleLabel->setText("听党指挥能打胜仗");
      closeControl();
    }
  });
}

void CRMWindow::closeView() {
  barView->setHidden(true);
  chartView->setHidden(true);
  teacherView->setHidden(true);
}

void CRMWindow::showView() {
  barView->setHidden(false);
  chartView->setHidden(false);
  teacherView->setHidden(false);
}

void CRMWindow::showControl() {
  closeControl();
  switch (clickedValue) {
  case 0:
    chartView->setHidden(false);
    break;
  case 1:
    barView->setHidden(false);
    break;
  case 2:
    teacherView->setHidden(false);
    break;
  }
}

void CRMWindow::closeControl() {
  closeView();
  addButton->setHidden(true);
  changeButton->setHidden(true);
  removeButton->setHidden(true);
  refButton->setHidden(true);
  searchEdit->setHidden(true);
  searchButton->setHidden(true);
  showSearchValues->setHidden(true);
  table->setHidden(true);
  table2->setHidden(true);
  table3->setHidden(true);
}

void CRMWindow::addTable(StudentInfo studentInfo, int index) {
  if (clickedValue == 0) {
    table->setItem(index, 0, new QTableWidgetItem(studentInfo.getName()));
    table->setItem(index, 1, new QTableWidgetItem(studentInfo.getSex()));
    table->setItem(index, 2, new QTableWidgetItem(studentInfo.getAge()));
    table->setItem(index, 3,
                   new QTableWidgetItem(studentInfo.getStudentClass()));
    table->setItem(index, 4, new QTableWidgetItem(studentInfo.getSum()));
    table->setItem(index, 5, new QTableWidgetItem(studentInfo.getId()));
    table->setItem(index, 6, new QTableWidgetItem(studentInfo.getAddress()));
    table->item(index, 0)->setTextAlignment(Qt::AlignCenter);
    table->item(index, 1)->setTextAlignment(Qt::AlignCenter);
    table->item(index, 2)->setTextAlignment(Qt::AlignCenter);
    table->item(index, 3)->setTextAlignment(Qt::AlignCenter);
    table->item(index, 4)->setTextAlignment(Qt::AlignCenter);
    table->item(index, 5)->setTextAlignment(Qt::AlignCenter);
    table->item(index, 6)->setTextAlignment(Qt::AlignCenter);
  } else if (clickedValue == 1) {
    table2->setItem(index, 0, new QTableWidgetItem(studentInfo.getName()));
    table2->setItem(index, 1, new QTableWidgetItem(studentInfo.getSex()));
    table2->setItem(index, 2, new QTableWidgetItem(studentInfo.getId()));
    table2->setItem(index, 3, new QTableWidgetItem(studentInfo.getChinese()));
    table2->setItem(index, 4,
                    new QTableWidgetItem(studentInfo.getMathematics()));
    table2->setItem(index, 5, new QTableWidgetItem(studentInfo.getEnglish()));
    table2->setItem(index, 6, new QTableWidgetItem(studentInfo.getPhysics()));
    table2->setItem(index, 7, new QTableWidgetItem(studentInfo.getPolitics()));
    table2->setItem(index, 8, new QTableWidgetItem(studentInfo.getChemistry()));
    table2->setItem(index, 9, new QTableWidgetItem(studentInfo.getGeography()));
    table2->setItem(index, 10, new QTableWidgetItem(studentInfo.getHistory()));
    table2->setItem(index, 11, new QTableWidgetItem(studentInfo.getBiology()));
    table2->item(index, 0)->setTextAlignment(Qt::AlignCenter);
    table2->item(index, 1)->setTextAlignment(Qt::AlignCenter);
    table2->item(index, 2)->setTextAlignment(Qt::AlignCenter);
    table2->item(index, 3)->setTextAlignment(Qt::AlignCenter);
    table2->item(index, 4)->setTextAlignment(Qt::AlignCenter);
    table2->item(index, 5)->setTextAlignment(Qt::AlignCenter);
    table2->item(index, 6)->setTextAlignment(Qt::AlignCenter);
    table2->item(index, 7)->setTextAlignment(Qt::AlignCenter);
    table2->item(index, 8)->setTextAlignment(Qt::AlignCenter);
    table2->item(index, 9)->setTextAlignment(Qt::AlignCenter);
    table2->item(index, 10)->setTextAlignment(Qt::AlignCenter);
    table2->item(index, 11)->setTextAlignment(Qt::AlignCenter);
  }
}

void CRMWindow::addTable(TeacherInfo teacherInfo, int index) {
  if (clickedValue == 2) {
    table3->setItem(index, 0, new QTableWidgetItem(teacherInfo.getName()));
    table3->setItem(index, 1, new QTableWidgetItem(teacherInfo.getSex()));
    table3->setItem(index, 2, new QTableWidgetItem(teacherInfo.getAge()));
    table3->setItem(index, 3,
                    new QTableWidgetItem(teacherInfo.getManageClass()));
    table3->setItem(index, 4,
                    new QTableWidgetItem(teacherInfo.getManageSubject()));
    table3->setItem(index, 5, new QTableWidgetItem(teacherInfo.getId()));
    table3->setItem(index, 6, new QTableWidgetItem(teacherInfo.getAddress()));
    table3->setItem(index, 7, new QTableWidgetItem(teacherInfo.getMoney()));

    table3->item(index, 0)->setTextAlignment(Qt::AlignCenter);
    table3->item(index, 1)->setTextAlignment(Qt::AlignCenter);
    table3->item(index, 2)->setTextAlignment(Qt::AlignCenter);
    table3->item(index, 3)->setTextAlignment(Qt::AlignCenter);
    table3->item(index, 4)->setTextAlignment(Qt::AlignCenter);
    table3->item(index, 5)->setTextAlignment(Qt::AlignCenter);
    table3->item(index, 6)->setTextAlignment(Qt::AlignCenter);
    table3->item(index, 7)->setTextAlignment(Qt::AlignCenter);
  }
}

QTableWidget *CRMWindow::addTableWidget(QStringList l) {
  QTableWidget *table = new QTableWidget(l.size(), l.size());
  table->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
  table->verticalHeader()->setHidden(true);
  //设置表格默认为填充
  //  table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  table->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
  table->setSelectionBehavior(QAbstractItemView::SelectRows);
  return table;
}

void CRMWindow::listCourse(QList<StudentInfo> StudentAchievementList) {
  table2->clear();
  table2->setRowCount(StudentAchievementList.size());
  table2->setHorizontalHeaderLabels(addNewWindow.courseList);
  for (int i = 0; i < StudentAchievementList.size(); i++) {
    addTable(StudentAchievementList[i], i);
  }
}

void CRMWindow::listStudent(QList<StudentInfo> StudentInfoList) {
  table->clear();
  table->setRowCount(StudentInfoList.size());
  table->setHorizontalHeaderLabels(addNewWindow.studentList);
  for (int i = 0; i < StudentInfoList.size(); i++) {
    addTable(StudentInfoList[i], i);
  }
}

void CRMWindow::listTeacher(QList<TeacherInfo> TeacherInfoList) {
  table3->clear();
  table3->setRowCount(TeacherInfoList.size());
  table3->setHorizontalHeaderLabels(addNewWindow.teacherList);
  for (int i = 0; i < TeacherInfoList.size(); i++) {
    addTable(TeacherInfoList[i], i);
  }
}

void CRMWindow::addStudent(StudentInfo studentInfo) {
  if (!studentInfo.getName().isNull() || !studentInfo.getName().isEmpty()) {
    StudentInfoList.append(studentInfo);
  }
}

void CRMWindow::addTeacher(TeacherInfo teacherInfo) {
  if (!teacherInfo.getName().isNull() || !teacherInfo.getName().isEmpty()) {
    TeacherInfoList.append(teacherInfo);
  }
}

void CRMWindow::checkClickValue() {
  if (StudentInfoList.size() > 0 || TeacherInfoList.size() > 0) {
    switch (clickedValue) {
    case 0:
      listStudent(StudentInfoList);
      break;
    case 1:
      listCourse(StudentInfoList);
      break;
    case 2:
      listTeacher(TeacherInfoList);
      break;
    }
  }
}

void CRMWindow::showTable() {
  switch (clickedValue) {
  case 0:
    table->setHidden(false);
    table2->setHidden(true);
    table3->setHidden(true);
    break;
  case 1:
    table->setHidden(true);
    table2->setHidden(false);
    table3->setHidden(true);
    break;
  case 2:
    table->setHidden(true);
    table2->setHidden(true);
    table3->setHidden(false);
    break;
  }
}

void CRMWindow::changeStudent() {
  closeView();
  addButton->setHidden(false);
  changeButton->setHidden(false);
  removeButton->setHidden(false);
  refButton->setHidden(false);
  showTable();
  searchEdit->setHidden(false);
  searchButton->setHidden(false);
  showSearchValues->setHidden(false);
  void (*changeStudent)(QList<QTableWidgetItem *> t, StudentInfo & s,
                        QList<StudentInfo> StudentInfoList) =
      [](QList<QTableWidgetItem *> t, StudentInfo &s,
         QList<StudentInfo> StudentInfoList) {
        s.setName(t[0]->text());
        s.setSex(t[1]->text());
        s.setAge(t[2]->text());
        s.setStudentClass(t[3]->text());
        s.setSum(t[4]->text());
        s.setId(t[5]->text());
        s.setAddress(t[6]->text());
        foreach (StudentInfo info, StudentInfoList) {
          if (info.getId().compare(s.getId()) == 0) {
            s = info;
            break;
          }
        }
      };
  void (*changeCourse)(QList<QTableWidgetItem *> t, StudentInfo & s,
                       QList<StudentInfo> StudentInfoList) =
      [](QList<QTableWidgetItem *> t, StudentInfo &s,
         QList<StudentInfo> StudentInfoList) {
        s.setName(t[0]->text());
        s.setSex(t[1]->text());
        s.setId(t[2]->text());
        s.setChinese(t[3]->text());
        s.setMathematics(t[4]->text());
        s.setEnglish(t[5]->text());
        s.setPhysics(t[6]->text());
        s.setPolitics(t[7]->text());
        s.setChemistry(t[8]->text());
        s.setGeography(t[9]->text());
        s.setHistory(t[10]->text());
        s.setBiology(t[11]->text());
        foreach (StudentInfo info, StudentInfoList) {
          if (info.getId().compare(s.getId()) == 0) {
            s = info;
            break;
          }
        }
      };

  void (*changeTeacher)(QList<QTableWidgetItem *> t, TeacherInfo & s,
                        QList<TeacherInfo> TeacherInfoList) =
      [](QList<QTableWidgetItem *> t, TeacherInfo &s,
         QList<TeacherInfo> TeacherInfoList) {
        s.setName(t[0]->text());
        s.setSex(t[1]->text());
        s.setAge(t[2]->text());
        s.setManageClass(t[3]->text());
        s.setManageSubject(t[4]->text());
        s.setId(t[5]->text());
        s.setAddress(t[6]->text());
        foreach (TeacherInfo info, TeacherInfoList) {
          if (info.getId().compare(s.getId()) == 0) {
            s = info;
            break;
          }
        }
      };
  showCombox();
  if (!studentChangeIsOK) {
    connect(searchButton, &QPushButton::clicked, this, [=]() {
      FindStudentInfoList.clear();
      FindTeacherInfoList.clear();
      if (clickedValue == 2) {
        switch (showSearchValues->currentIndex()) {
        case 0:
          foreach (TeacherInfo info, TeacherInfoList) {
            if (info.getName().indexOf(
                    searchEdit->text().replace(QRegExp("\\s+"), "")) != -1) {
              FindTeacherInfoList.append(info);
            }
          }
          break;
        case 1:
          foreach (TeacherInfo info, TeacherInfoList) {
            if (info.getSex().indexOf(
                    searchEdit->text().replace(QRegExp("\\s+"), "")) != -1) {
              FindTeacherInfoList.append(info);
            }
          }
          break;
        case 2:
          foreach (TeacherInfo info, TeacherInfoList) {
            if (info.getAge().indexOf(
                    searchEdit->text().replace(QRegExp("\\s+"), "")) != -1) {
              FindTeacherInfoList.append(info);
            }
          }
          break;
        case 3:
          foreach (TeacherInfo info, TeacherInfoList) {
            if (info.getManageClass().indexOf(
                    searchEdit->text().replace(QRegExp("\\s+"), "")) != -1) {
              FindTeacherInfoList.append(info);
            }
          }
          break;
        case 4:
          foreach (TeacherInfo info, TeacherInfoList) {
            if (info.getManageSubject().indexOf(
                    searchEdit->text().replace(QRegExp("\\s+"), "")) != -1) {
              FindTeacherInfoList.append(info);
            }
          }
          break;
        case 5:
          foreach (TeacherInfo info, TeacherInfoList) {
            if (info.getId().indexOf(
                    searchEdit->text().replace(QRegExp("\\s+"), "")) != -1) {
              FindTeacherInfoList.append(info);
            }
          }
          break;
        case 6:
          foreach (TeacherInfo info, TeacherInfoList) {
            if (info.getAddress().indexOf(
                    searchEdit->text().replace(QRegExp("\\s+"), "")) != -1) {
              FindTeacherInfoList.append(info);
            }
          }
          break;
        }
      } else {
        switch (showSearchValues->currentIndex()) {
        case 0:
          qDebug() << showSearchValues->currentText() << " -- 0";
          foreach (StudentInfo info, StudentInfoList) {
            if (info.getName().indexOf(
                    searchEdit->text().replace(QRegExp("\\s+"), "")) != -1) {
              FindStudentInfoList.append(info);
            }
          }
          break;
        case 1:
          qDebug() << showSearchValues->currentText() << " -- 1";
          foreach (StudentInfo info, StudentInfoList) {
            if (info.getSex().indexOf(
                    searchEdit->text().replace(QRegExp("\\s+"), "")) != -1) {
              FindStudentInfoList.append(info);
            }
          }
          break;
        case 2:
          qDebug() << showSearchValues->currentText() << " -- 2";
          foreach (StudentInfo info, StudentInfoList) {
            if (info.getAge().indexOf(
                    searchEdit->text().replace(QRegExp("\\s+"), "")) != -1) {
              FindStudentInfoList.append(info);
            }
          }
          break;
        case 3:
          qDebug() << showSearchValues->currentText() << " -- 3";
          foreach (StudentInfo info, StudentInfoList) {
            if (info.getStudentClass().indexOf(
                    searchEdit->text().replace(QRegExp("\\s+"), "")) != -1) {
              FindStudentInfoList.append(info);
            }
          }
          break;
        case 4:
          qDebug() << showSearchValues->currentText() << " -- 4";
          foreach (StudentInfo info, StudentInfoList) {
            if (info.getSum().indexOf(
                    searchEdit->text().replace(QRegExp("\\s+"), "")) != -1) {
              FindStudentInfoList.append(info);
            }
          }
          break;
        case 5:
          qDebug() << showSearchValues->currentText() << " -- 5";
          foreach (StudentInfo info, StudentInfoList) {
            if (info.getId().indexOf(
                    searchEdit->text().replace(QRegExp("\\s+"), "")) != -1) {
              FindStudentInfoList.append(info);
            }
          }
          break;
        case 6:
          qDebug() << showSearchValues->currentText() << " -- 6";
          foreach (StudentInfo info, StudentInfoList) {
            if (info.getAddress().indexOf(
                    searchEdit->text().replace(QRegExp("\\s+"), "")) != -1) {
              FindStudentInfoList.append(info);
            }
          }
          break;
        }
      }

      if (clickedValue == 0) {
        listStudent(FindStudentInfoList);
      } else if (clickedValue == 1) {
        listCourse(FindStudentInfoList);
      } else if (clickedValue == 2) {
        listTeacher(FindTeacherInfoList);
      }
    });

    connect(removeButton, &QPushButton::clicked, this, [=]() {
      if (clickedValue == 2) {
        TeacherInfo info;
        if (table3->selectedItems().size() > 0) {
          changeTeacher(table3->selectedItems(), info, TeacherInfoList);
        } else {
          int id = QInputDialog::getInt(this, "教师编号", "请输入");
          foreach (TeacherInfo info2, TeacherInfoList) {
            if (info2.getId().compare(QString::number(id)) == 0) {
              info = info2;
            }
          }
        }
        addNewWindow.RemoveStudent(TeacherInfoList, info);
      } else {
        StudentInfo s;
        if (table->selectedItems().size() > 0) {
          changeStudent(table->selectedItems(), s, StudentInfoList);
        } else if (table2->selectedItems().size() > 0) {

          changeCourse(table2->selectedItems(), s, StudentInfoList);
        } else {
          int id = QInputDialog::getInt(this, "学生学号", "请输入");
          foreach (StudentInfo info, StudentInfoList) {
            if (info.getId().compare(QString::number(id)) == 0) {
              s = info;
            }
          }
        }
        qDebug() << "s ::: " << s.getName();
        addNewWindow.RemoveStudent(StudentInfoList, s);
      }
    });

    connect(addButton, &QPushButton::clicked, this, [=]() {
      if (clickedValue == 2) {
        addNewWindow.AddStudent(TeacherInfoList);
      } else {
        addNewWindow.AddStudent(StudentInfoList);
      }
    });

    connect(table, &QTableWidget::doubleClicked, this, [=]() {
      if (clickedValue == 0) {
        StudentInfo s;
        changeStudent(table->selectedItems(), s, StudentInfoList);
        addNewWindow.ChangeStudent(StudentInfoList, s);
      }
    });
    connect(table2, &QTableWidget::doubleClicked, this, [=]() {
      if (clickedValue == 1) {
        StudentInfo s;
        changeCourse(table2->selectedItems(), s, StudentInfoList);
        addNewWindow.ChangeStudent(StudentInfoList, s);
      }
    });
    connect(table3, &QTableWidget::doubleClicked, this, [=]() {
      if (clickedValue == 2) {
        TeacherInfo s;
        changeTeacher(table3->selectedItems(), s, TeacherInfoList);
        addNewWindow.ChangeStudent(TeacherInfoList, s);
      }
    });
    connect(refButton, &QPushButton::clicked, [=]() { checkClickValue(); });

    connect(changeButton, &QPushButton::clicked, this, [=]() {
      if (clickedValue == 2) {
        TeacherInfo s;
        if (table3->selectedItems().size() > 0) {
          changeTeacher(table3->selectedItems(), s, TeacherInfoList);
        } else {
          int id = QInputDialog::getInt(this, "教师编号", "请输入");
          foreach (TeacherInfo info, TeacherInfoList) {
            if (info.getId().compare(QString::number(id)) == 0) {
              s = info;
            }
          }
        }
        addNewWindow.ChangeStudent(TeacherInfoList, s);
      } else {
        StudentInfo s;
        if (table->selectedItems().size() > 0) {
          changeStudent(table->selectedItems(), s, StudentInfoList);
        } else if (table2->selectedItems().size() > 0) {
          changeCourse(table2->selectedItems(), s, StudentInfoList);
        } else {
          int id = QInputDialog::getInt(this, "学生学号", "请输入");
          foreach (StudentInfo info, StudentInfoList) {
            if (info.getId().compare(QString::number(id)) == 0) {
              s = info;
            }
          }
        }
        addNewWindow.ChangeStudent(StudentInfoList, s);
      }
    });
    studentChangeIsOK = true;
  }

  checkClickValue();
}

void CRMWindow::studentFind() {

  if (!studentFindIsOK) {
    changeStudent();
    studentFindIsOK = true;
  }
  showCombox();
  closeView();
  addButton->setHidden(true);
  changeButton->setHidden(true);
  removeButton->setHidden(true);
  refButton->setHidden(true);
  searchEdit->setHidden(false);
  searchButton->setHidden(false);
  showSearchValues->setHidden(false);
  showTable();
}

void CRMWindow::showStudentFindLayout(QVBoxLayout *vbox2) {
  searchEdit = new QLineEdit();
  searchEdit->setPlaceholderText("请输入搜索内容");
  searchEdit->setFixedHeight(40);
  showSearchValues = new QComboBox();
  showSearchValues->addItems(addNewWindow.studentList);
  showSearchValues->setFixedHeight(40);
  QPushButton *(*addButtonFunc)(QString text) = [](QString text) {
    QPushButton *B = new QPushButton(text);
    B->setFixedHeight(40);
    return B;
  };

  QHBoxLayout *(*addHbox)(QList<QWidget *> l) = [](QList<QWidget *> l) {
    QHBoxLayout *hbox2 = new QHBoxLayout();
    foreach (QWidget *q, l) { hbox2->addWidget(q); }
    return hbox2;
  };

  searchButton = addButtonFunc("搜索");
  addButton = addButtonFunc("新增");
  changeButton = addButtonFunc("修改");
  removeButton = addButtonFunc("删除");
  refButton = addButtonFunc("刷新");
  vbox2->addLayout(addHbox({searchEdit, showSearchValues, searchButton}));
  vbox2->addLayout(addHbox({addButton, changeButton, removeButton, refButton}));
  table = addTableWidget(addNewWindow.studentList);
  table2 = addTableWidget(addNewWindow.courseList);
  table3 = addTableWidget(addNewWindow.teacherList);
  vbox2->addWidget(table);
  vbox2->addWidget(table2);
  vbox2->addWidget(table3);
  //  addButton->setHidden(true);
  //  changeButton->setHidden(true);
  //  removeButton->setHidden(true);
  //  refButton->setHidden(true);
  //  searchEdit->setHidden(true);
  //  searchButton->setHidden(true);
  //  showSearchValues->setHidden(true);
  //  table->setHidden(true);
  //  table2->setHidden(true);
  //  table3->setHidden(true);
  closeControl();
}
void CRMWindow::init() {
  hbox = new QHBoxLayout();
  vbox = new QVBoxLayout();

  checkValues();
  setWindowTitle("CRMSystem");
  resize(800, 600);
  showLayout();
  setLayout(vbox);
}
void CRMWindow::checkValues() {

  double (*getSum)(QStringList l) = [](QStringList l) {
    double sum = 0;
    foreach (QString n, l) { sum += n.replace(QRegExp("\\s+"), "").toDouble(); }
    return sum;
  };

  QString (*getRandomNum)() = []() {
    return QString::number(QRandomGenerator::global()->bounded(0, 100));
  };

  QString (*getRandomSum)(int min, int max) = [](int min, int max) {
    return QString::number(QRandomGenerator::global()->bounded(min, max));
  };

  //初始化数据
  QString stus[15][16] = {
      {"小明", getRandomSum(15, 30), "123312", "上海虹桥", "666", "男",
       "12计算机系三班", getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum()},
      {"小红", getRandomSum(15, 30), "123313", "上海浦东", "66", "女",
       "12计算机系二班", getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum()},
      {"小王", getRandomSum(15, 30), "123332", "北京海淀", "780", "男",
       "12模具系一班", getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum()},
      {"小李", getRandomSum(15, 30), "143311", "广州番禺", "566", "男",
       "14电商系四班", getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum(), getRandomNum(), "6", getRandomNum(),
       getRandomNum()},
      {"小黑", getRandomSum(15, 30), "153316", "上海虹桥", "666", "男",
       "15计算机系一班", getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum(), getRandomNum(), "80", getRandomNum(),
       getRandomNum()},
      {"唐唐", getRandomSum(15, 30), "123314", "上海虹桥", "667", "男",
       "12计算机系四班", getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum(), getRandomNum(), "10", getRandomNum(),
       getRandomNum()},
      {"张三", getRandomSum(15, 30), "12312", "上海虹桥", "663", "男",
       "13计算机系三班", getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum(), getRandomNum(), "90", getRandomNum(),
       getRandomNum()},
      {"李四", getRandomSum(15, 30), "13312", "上海虹桥", "626", "男",
       "14计算机系三班", getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum(), getRandomNum(), "120", getRandomNum(),
       getRandomNum()},
      {"王五", getRandomSum(15, 30), "123276", "上海虹桥", "166", "男",
       "16计算机系三班", getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum(), getRandomNum(), "130", getRandomNum(),
       getRandomNum()},
      {"仁六", getRandomSum(15, 30), "123319", "上海虹桥", "366", "男",
       "20计算机系三班", getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum()},
      {"二狗", getRandomSum(15, 30), "144276", "广州越秀", "16", "男",
       "20机械系三班", getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum()},
      {"小花", getRandomSum(15, 30), "127319", "深圳龙岗", "766", "女",
       "20电商系三班", getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum()},
      {"老王", getRandomSum(15, 30), "013319", "陕西西安", "566", "男",
       "08计算机系一班", getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum()},
      {"小燕", getRandomSum(15, 30), "203319", "浙江杭州", "766", "女",
       "20幼教系一班", getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum()},
      {"刘备", getRandomSum(15, 30), "173319", "四川成都", "566", "男",
       "17计算机系一班", getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum(), getRandomNum(), getRandomNum(),
       getRandomNum(), getRandomNum()}};
  QString teacherDatas[15][8] = {
      {"王刚", "男", getRandomSum(18, 70), "计算机系",
       "计算机科学与技术、数据结构、操作系统理论", "12138", "北京通城区",
       getRandomSum(500, 10000)},
      {"王二妞", "女", getRandomSum(18, 70), "历史系",
       "中国通史、世界通史，史学理论、中源国史学史、西方史学史、考古学通论、中"
       "外关系史、文化人类学、历史地理学",
       "121145", "北京海淀区", getRandomSum(500, 10000)},
      {"张铁柱", "男", getRandomSum(18, 70), "物理系",
       "力学、热学、光学、电磁学、原子物理", "12553", "上海浦东",
       getRandomSum(500, 10000)},
      {"载淳", "男", getRandomSum(18, 70), "皇家系", "摄政、辅佐", "18601",
       "北京故宫紫禁城", getRandomSum(500, 10000)},
      {"张铁", "男", getRandomSum(18, 70), "物理系",
       "力学、热学、光学、电磁学、原子物理", "12523", "上海浦东",
       getRandomSum(500, 10000)},
      {"张柱", "男", getRandomSum(18, 70), "物理系",
       "力学、热学、光学、电磁学、原子物理", "12551", "上海浦东",
       getRandomSum(500, 10000)},
      {"刘田", "男", getRandomSum(18, 70), "电商系",
       "电子商务专业，简称电商专业，是融计算机科学、市场营销学、管理学、经济学"
       "、法学",
       "10875", "四川成都", getRandomSum(500, 10000)},
      {"张三丰", "男", getRandomSum(18, 70), "化学系",
       "有机化学，无机化学，分析化学，物理化学，环境化学，天然产物化学，化工原"
       "理",
       "13225", "美国圣地亚哥", getRandomSum(500, 10000)},
      {"李敏", "女", getRandomSum(18, 70), "计算机系", "计算机科学与技术",
       "12583", "上海浦东", getRandomSum(500, 10000)},
      {"张铁柱2", "男", getRandomSum(18, 70), "物理系",
       "力学、热学、光学、电磁学、原子物理", "125553", "上海浦东",
       getRandomSum(500, 10000)},
      {"张铁柱3", "男", getRandomSum(18, 70), "物理系",
       "力学、热学、光学、电磁学、原子物理", "125x3", "上海浦东",
       getRandomSum(500, 10000)},
      {"张铁柱4", "男", getRandomSum(18, 70), "物理系",
       "力学、热学、光学、电磁学、原子物理", "125a3", "上海浦东",
       getRandomSum(500, 10000)},
      {"张铁柱5", "男", getRandomSum(18, 70), "物理系",
       "力学、热学、光学、电磁学、原子物理", "125163", "上海浦东",
       getRandomSum(500, 10000)},
      {"张铁柱6", "男", getRandomSum(18, 70), "物理系",
       "力学、热学、光学、电磁学、原子物理", "125538", "上海浦东",
       getRandomSum(500, 10000)},
      {"张铁柱7", "男", getRandomSum(18, 70), "物理系",
       "力学、热学、光学、电磁学、原子物理", "125053", "上海浦东",
       getRandomSum(500, 10000)}};

  for (int i = 0; i < 15; i++) {
    stus[i][4] = QString::number(
        getSum({stus[i][7], stus[i][8], stus[i][9], stus[i][10], stus[i][11],
                stus[i][12], stus[i][13], stus[i][14], stus[i][15]}));
    StudentInfoList.append(
        StudentInfo(stus[i][7], stus[i][8], stus[i][9], stus[i][10],
                    stus[i][11], stus[i][12], stus[i][13], stus[i][14],
                    stus[i][15], stus[i][0], stus[i][1], stus[i][3], stus[i][5],
                    stus[i][2], stus[i][4], stus[i][6]));
    TeacherInfoList.append(TeacherInfo(teacherDatas[i][0], teacherDatas[i][1],
                                       teacherDatas[i][2], teacherDatas[i][3],
                                       teacherDatas[i][4], teacherDatas[i][5],
                                       teacherDatas[i][6], teacherDatas[i][7]));
  }
}

void CRMWindow::closeEvent(QCloseEvent *event) {
  QMessageBox msg;
  msg.setIcon(QMessageBox::Icon::Warning);
  msg.setWindowTitle("警告");
  msg.setText("您是否要退出此程序?");
  msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  msg.setButtonText(QMessageBox::Yes, "是的，我要退出");
  msg.setButtonText(QMessageBox::No, "不,我拒绝");
  if (msg.exec() == QMessageBox::Yes) {
    event->accept();
  } else {
    event->ignore();
  }
}

void CRMWindow::showCombox() {
  switch (clickedValue) {
  case 2:
    for (int i = 0; i < addNewWindow.teacherList.size(); i++) {
      showSearchValues->setItemText(i, addNewWindow.teacherList[i]);
    }
    break;
  default:
    for (int i = 0; i < addNewWindow.studentList.size(); i++) {
      showSearchValues->setItemText(i, addNewWindow.studentList[i]);
    }
    break;
  }
}
