#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  showLoginMenu();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  qDebug() << event->text();
  if (event->text() == "\r") {
    checkValues();
  }
}

// void MainWindow::closeEvent(QCloseEvent *event) {
//  QMessageBox msg;
//  msg.setIcon(QMessageBox::Icon::Warning);
//  msg.setWindowTitle("警告");
//  msg.setText("您是否要退出此程序?");
//  msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
//  msg.setButtonText(QMessageBox::Yes, "是的，我要退出");
//  msg.setButtonText(QMessageBox::No, "不,我拒绝");
//  if (msg.exec() == QMessageBox::Yes) {
//    event->accept();
//  } else {
//    event->ignore();
//  }
//}

void MainWindow::showLayout() {

  setWindowTitle("学生信息管理系统");
  setFixedSize(800, 260);
  QWidget *widget = new QWidget();
  setCentralWidget(widget);
  vbox = new QVBoxLayout(widget);

  void (*addLable)(QLabel * lable, QString s) = [](QLabel *lable, QString s) {
    lable->setText(s);
    lable->setFont(QFont("华文琥珀", 30));
    lable->setAlignment(Qt::AlignCenter);
  };

  void (*addButton)(QPushButton * lable, QString s) = [](QPushButton *lable,
                                                         QString s) {
    lable->setText(s);
    lable->setFont(QFont("华文琥珀", 30));
  };

  void (*addEdit)(QLineEdit * lable, QString s) = [](QLineEdit *lable,
                                                     QString s) {
    lable->setPlaceholderText(s);
    lable->setFixedHeight(50);
    lable->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9]+")));
  };

  addLable(LoginIcon, "学生信息管理系统登录页面");
  addLable(LoginUserName, "用户名");
  addLable(LoginUserPwd, "密  码");
  addEdit(userNameEdit, "请输入学生姓名");
  addEdit(userPwdEdit, "请输入学生密码");
  userPwdEdit->setEchoMode(QLineEdit::EchoMode::Password);
  addButton(login, "登录");
  addButton(quite, "退出");
  vbox->addWidget(LoginIcon);
  hbox->addWidget(LoginUserName);
  hbox->addWidget(userNameEdit, 1);
  vbox->addLayout(hbox);

  hbox = new QHBoxLayout();
  hbox->addWidget(LoginUserPwd);
  hbox->addWidget(userPwdEdit, 1);
  vbox->addLayout(hbox);
  hbox = new QHBoxLayout();
  hbox->addWidget(login);
  hbox->addWidget(quite);
  vbox->addLayout(hbox);
  vbox->setAlignment(Qt::AlignTop);
  widget->setLayout(vbox);
}

void MainWindow::showLoginMenu() {
  init();
  showLayout();

  userNameEdit->setText("root");
  userPwdEdit->setText("123");

  connect(login, &QPushButton::clicked, this, [=]() { checkValues(); });

  connect(quite, &QPushButton::clicked, this, [=]() { close(); });
}

void MainWindow::checkValues() {
  QMessageBox msg;
  msg.setWindowTitle("登录错误!!!!");
  msg.setText("用户名或者密码错误,请重新输入!!");
  msg.setIcon(QMessageBox::Icon::Critical);
  msg.setStandardButtons(QMessageBox::Ok | QMessageBox::No);
  userName = userNameEdit->text().replace(QRegExp("\\s+"), "");
  userPwd = userPwdEdit->text().replace(QRegExp("\\s+"), "");
  if (userName.compare("root") == 0 && userPwd.compare("123") == 0) {
    CRMWindow *c = new CRMWindow();
    c->show();
    this->close();
  } else {
    switch (msg.exec()) {
    case QMessageBox::Ok:
      userNameEdit->clear();
      userPwdEdit->clear();
      break;
      ;
      ;
    case QMessageBox::No:
      this->close();
      ;
      ;
    }
  }
}

void MainWindow::init() {
  hbox = new QHBoxLayout();
  login = new QPushButton();
  quite = new QPushButton();

  LoginIcon = new QLabel();
  LoginUserName = new QLabel();
  LoginUserPwd = new QLabel();

  userNameEdit = new QLineEdit();
  userPwdEdit = new QLineEdit();
}

MainWindow::~MainWindow() { delete ui; }
