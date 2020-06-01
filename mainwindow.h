#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "crmwindow.h"
#include <QCloseEvent>
#include <QDebug>
#include <QEvent>
#include <QFontDialog>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QRegExp>
#include <QRegExpValidator>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  QHBoxLayout *hbox;
  QVBoxLayout *vbox;

  QPushButton *login;
  QPushButton *quite;

  QLabel *LoginIcon;
  QLabel *LoginUserName;
  QLabel *LoginUserPwd;

  QLineEdit *userNameEdit;
  QLineEdit *userPwdEdit;

  QString userName, userPwd;

public:
  void showLayout();
  void showLoginMenu();
  void init();
  void checkValues();
  //  void closeEvent(QCloseEvent *event);
  void keyPressEvent(QKeyEvent *event);

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
